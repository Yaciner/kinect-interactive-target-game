#include "ofApp.h"
int numbers [5] = { };
string leftTop;
string midTop;
string rightTop;
string leftBottom;
string rightBottom;
bool test = false;
int correct;
int score = 0;
int currentTimerSize = 0;
int currentLevel = 0;
bool visible = false;
int frames = 0;
int animationfinished = true;

// SIZES //
int outerLeft = -660;
int outerTop = -480;
int outerRight = 650;
int outerBottom = 140;
int centralTop = -200;
int centralLeft = 400;
bool canScore = true;
bool gameOver = false;
bool playStart = true;

//--------------------------------------------------------------

void ofApp::setup(){
    
    ofToggleFullscreen();
    font.loadFont("happy.ttf", 30);
    kinect.init();
    timerEnd = false;
    startTime = ofGetElapsedTimeMillis();
    kinect.open();
    
    ofSetFrameRate(60);
    
    easyCam.enableMouseInput();
    
    pointCloud.setMode(OF_PRIMITIVE_POINTS);
    
    status = "not connected";
    
    isConnected = false;
    
    loadbtn.addListener(this, &ofApp::loadState);
    
    savebtn.addListener(this, &ofApp::saveState);
    
    gui.setup();
    
    gui.setDefaultWidth(ofGetWidth()/2);
    
    gui.add(kinectDistanceSlider.setup("Kinect distance", 3100, 80, 5000));
    
    gui.add(kinectZSlider.setup("Kinect Scale Z", -0.15, -2, 2));
    
    gui.add(kinectAngleSlider.setup("Kinect Angle", 6.6, -10, 10));
    
    gui.add(statusLabel.setup("status", ofApp::status));
    
    gui.add(hostNameLabel.setup("Connect to", "http://:3000"));
    
    gui.add(savebtn.setup("Save settings"));
    
    gui.add(loadbtn.setup("Load settings"));
    
    
    
    numPointsInRegion = 0;
    
    
    targetSize =  300;
    if(debugMode == false) {
        bg_anim.load("bg_animatie.mp4");
        bg_anim.play();
        pizza_anim.load("scoreanimaties/pizza.mp4");
        brocolli_anim.load("scoreanimaties/brocolli.mp4");
        burger_anim.load("scoreanimaties/burger.mp4");
        ei_anim.load("scoreanimaties/ei.mp4");
        fruitmand_anim.load("scoreanimaties/fruitmand.mp4");
        garnaal_anim.load("scoreanimaties/garnaal.mp4");
        hotdog_anim.load("scoreanimaties/hotdog.mp4");
        ijs_anim.load("scoreanimaties/ijs.mp4");
        kers_anim.load("scoreanimaties/kers.mp4");
        kip_anim.load("scoreanimaties/kip.mp4");
        koekjes_anim.load("scoreanimaties/koekjes.mp4");
        popcorn_anim.load("scoreanimaties/popcorn.mp4");
        snoep_anim.load("scoreanimaties/snoep.mp4");
        steak_anim.load("scoreanimaties/steak.mov");
        zalm_anim.load("scoreanimaties/zalm.mp4");
        start_anim.load("start_scherm.mp4");
        end_anim.load("eind_scherm.mp4");
        yay_sound.load("sounds/win.mp3");
        soundtrack_sound.load("sounds/soundtrack.mp3");
        soundtrack_sound.play();
        soundtrack_sound.setVolume(0.5f);
    }

}



//--------------------------------------------------------------

void ofApp::update(){
    
    kinect.setCameraTiltAngle(kinectAngleSlider);
    bg_anim.update();
    pizza_anim.update();
    brocolli_anim.update();
    burger_anim.update();
    ei_anim.update();
    fruitmand_anim.update();
    garnaal_anim.update();
    hotdog_anim.update();
    ijs_anim.update();
    kers_anim.update();
    kip_anim.update();
    koekjes_anim.update();
    popcorn_anim.update();
    snoep_anim.update();
    steak_anim.update();
    zalm_anim.update();
    start_anim.update();
    end_anim.update();
    kinect.update();
    
    numPointsInRegion = 0;
    
    if(kinect.isFrameNewDepth()) {
        
        pointCloud.clear();
        
        for(int y = 0; y < kinect.height; y++) {
            
            for(int x= 0; x < kinect.width; x++) {
                
                int z = kinect.getDistanceAt(x, y);
                
                if(z > 0) {
                    
                    pointCloud.addColor(kinect.getColorAt(x, y));
                    
                    ofVec3f pt = kinect.getWorldCoordinateAt(x, y);
                    
                    pointCloud.addVertex(pt);
                    
                    
                    //LINKS BOVEN
              int targetRegionleftTop = (targetSize)/2;

                    if((pt.x > outerLeft - targetRegionleftTop && pt.x < outerLeft + targetRegionleftTop)

                       && (pt.y > outerTop - targetRegionleftTop && pt.y < outerTop + targetRegionleftTop)

                       && (pt.z > kinectDistanceSlider-targetRegionleftTop && pt.z < kinectDistanceSlider + targetRegionleftTop)){
                        
                        if (correct == 0){
                            numPointsInRegion += 1;
                           
                        }
                    }
                    

                    
                    
                    //MIDDEN

                    int targetRegionmidTop = (targetSize) / 2;

                    if((pt.x > centralTop - targetRegionmidTop && pt.x < centralTop + targetRegionmidTop)

                       && (pt.y > centralLeft - targetRegionmidTop && pt.y < centralLeft + targetRegionmidTop)

                       && (pt.z > kinectDistanceSlider-targetRegionmidTop && pt.z < kinectDistanceSlider + targetRegionmidTop)){
                        
                        if (correct == 1){
                            numPointsInRegion += 1;
                         
                        }

                    }
                    
                    //RECHTS BOVEN
                    int targetRegionrightTop = (targetSize) / 2;

                    if((pt.x > outerRight - targetRegionrightTop && pt.x < outerRight + targetRegionrightTop)

                       && (pt.y > outerTop - targetRegionrightTop && pt.y < outerTop + targetRegionrightTop)

                       && (pt.z > kinectDistanceSlider-targetRegionrightTop && pt.z < kinectDistanceSlider + targetRegionrightTop)){
                        
                        if (correct == 2){
                            numPointsInRegion += 1;
                           
                        }

                    }
                    
                    
                    //LINKS BENEDEN
                    int targetRegionleftBottom = (targetSize) / 2;

                    if((pt.x > outerLeft - targetRegionleftBottom && pt.x < outerLeft + targetRegionleftBottom)

                       && (pt.y > outerBottom - targetRegionleftBottom && pt.y < outerBottom + targetRegionleftBottom)

                       && (pt.z > kinectDistanceSlider-targetRegionleftBottom && pt.z < kinectDistanceSlider + targetRegionleftBottom)){
                        
                        if (correct == 3){
                            numPointsInRegion += 1;
                        }

                    }
                    
                    //RECHTS BENEDEN
                    int targetRegionrightBottom = (targetSize) / 2;
                    
                    if((pt.x > outerRight - 20 - targetRegionrightBottom && pt.x < outerRight - 20 + targetRegionrightBottom)
                       
                       && (pt.y > outerBottom -20 - targetRegionrightBottom && pt.y < outerBottom - 20 + targetRegionrightBottom)
                       
                       && (pt.z > kinectDistanceSlider-targetRegionrightBottom && pt.z < kinectDistanceSlider + targetRegionrightBottom)){
                        
                        if (correct == 4){
                            numPointsInRegion += 1;
                        }
                        
                    }
                     //ofDrawBox(0, -200, kinectDistanceSlider-220, 1700, 1000, 400);
                    if(currentLevel == 0) {
                        int startRegion = 1000;
                        
                        if((pt.x > -850 && pt.x < 850)
                           
                           && (pt.y > -700 && pt.y < 300)
                           
                           && (pt.z > kinectDistanceSlider - 200 && pt.z < kinectDistanceSlider -120)){
                                numPointsInRegion += 1;
//                                cout << "scoresssssss";
                            }
                    

                    }
                    
                }
                
            }
            
        }
        
    }
    
}



void ofApp::saveState() {
    
    state.setValue("state:kinectDistanceSlider", kinectDistanceSlider);
    
    state.setValue("state:kinectZSlider", kinectZSlider);
    
    state.saveFile("state.xml");
    
}



void ofApp::loadState() {
    
    state.loadFile("state.xml");
    
    kinectZSlider = state.getValue("state:kinectZSlider", 2850);
    
    kinectDistanceSlider = state.getValue("state:kinectDistanceSlider", -0.239999995);
    
}



//--------------------------------------------------------------

void ofApp::draw(){
    easyCam.begin();
    
    ofPushMatrix();
    
    ofScale(1, -1, kinectZSlider);
    
    ofTranslate(0, 0, -1000);
    if(debugMode) {
        
        ofEnableDepthTest();
        
        pointCloud.drawVertices();
        
        ofDisableDepthTest();
        
    }
    

    if(numPointsInRegion > 50) {
        playStart = false;
        doStuff();
        canScore = false;
    } else {

        ofNoFill();

    }
    
    
//
    
    if(debugMode) {
        //links boven
        ofDrawBox(-660, -480, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //middenboven
        ofDrawBox(0, -220, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //rechtsboven
        ofDrawBox(650, -480, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        
        //linksbeneden
        ofDrawBox(-660, 140, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //rechtsbeneden
        ofDrawBox(650   , 120, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        ofDrawBox(0, -200, kinectDistanceSlider-450, 1700, 1000, 400);
    }
    
    
    
    ofPushMatrix();
    
    ofTranslate(0, 0, kinectDistanceSlider-220);
    
    ofPopMatrix();
    ofPopMatrix();
    easyCam.end();
    
    bg_anim.draw(0, 0, ofGetWidth(), ofGetHeight());

    if(visible) {
        if (gameOver == false){
            if(food[numbers[correct]] == "pizza") {
                
                pizza_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "brocolli") {
                
                brocolli_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "burger") {
                
                burger_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "ei") {
                
                ei_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "fruitmand") {
                
                fruitmand_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "garnaal") {
                
                garnaal_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "hotdog") {
                
                hotdog_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "ijs") {
                ijs_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "kers") {
                kers_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "kip") {
                kip_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "koekjes") {
                koekjes_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "popcorn") {
                popcorn_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "snoep") {
                snoep_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "steak") {
                steak_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
            if(food[numbers[correct]] == "zalm") {
                zalm_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            }
        }

        if(gameOver) {
            cout << "supposed to draw end now";
            end_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
            roundStarted = false;
        }
        
        frames ++;
    }
    
    if (frames >= 50 && gameOver == false){
        visible = false;
        frames = 0;
        animationfinished = true;
        pizza_anim.stop();
        brocolli_anim.stop();
        burger_anim.stop();
        ei_anim.stop();
        fruitmand_anim.stop();
        garnaal_anim.stop();
        hotdog_anim.stop();
        ijs_anim.stop();
        kers_anim.stop();
        kip_anim.stop();
        koekjes_anim.stop();
        popcorn_anim.stop();
        snoep_anim.stop();
        steak_anim.stop();
        zalm_anim.stop();
        startTime = ofGetElapsedTimeMillis();
        canScore = true;
    }
    
    if (frames >= 120 && gameOver == true){
        end_anim.stop();
        numbers [5] = { };
        test = false;
        score = 0;
        currentTimerSize = 0;
        currentLevel = 0;
        visible = false;
        frames = 0;
        animationfinished = true;
        canScore = false;
        roundStarted = false;
        timerEnd = false;
        playStart = true;
        gameOver = false;
    }
    
    
    if(timerEnd) {
        startTime = ofGetElapsedTimeMillis();
        gameOver = true;
        animationfinished = false;
        visible = true;
        end_anim.play();
        ofSetColor(233, 33, 45);
        font.drawString(to_string(score), 198, 195);
        ofSetColor(255);
        
    }
    
    
    if (animationfinished){
        if(roundStarted) {
    
            float barWidth = 300;
            float timer = ofGetElapsedTimeMillis() - startTime;
            
            if(timer >= (60000.0)) {
                timerEnd = true;
            }
            
            float timerBar = ofMap(timer, 0.0, 60000.0 , 1.0, 0.0, true);
            if(timerBar >= 0.6){
                ofSetColor(0,255,0);
                
            }
            
            if(timerBar < 0.6 && timerBar > 0.3){
                ofSetColor(255,165,0);
                
            }
            
            if(timerBar <= 0.3){
                ofSetColor(255,0,0);
                
            }
            ofFill();
            ofRect(ofGetWidth()/2-150, 30, barWidth*timerBar, 30);
            ofSetColor(255);
            
            
            if (test){
                canScore = true;
                currentLevel = currentLevel + 1;
                //startTimer(currentLevel);
                
                correct = ofRandom(0, 5) - 1;
                int index = 0;
                while (index < 5)
                {
                    int randomNumber = rand () % 15; // 15 is de maximum value hier
                    
                    bool next = false;
                    
                    for (int i = 0; i < 5; i++){
                        
                        if (numbers[i] == randomNumber){
                            next = true;
                        }
                    }
                    if (next == false){
                        numbers[index] = randomNumber;
                        index++;
                        
                    }
                }
            }
            
            ofSetColor(255);
            font.drawString(to_string(score), 20, 70);
            ofFill();
            
            img.load("ingredients/" + food[numbers[correct]] + "_1.png");
            texture.allocate(240, 240, GL_RGB);
            img.draw(ofGetWidth()/2-100/2, ofGetHeight()-110);
            leftTop = food[numbers[0]];
            
            img.load("recipes/" + food[numbers[0]] + "_2.png");
            texture.allocate(240, 240, GL_RGB);
            img.draw(150, 100);
            leftTop = food[numbers[0]];
            
            
            img.load("recipes/" + food[numbers[1]] + "_2.png");
            texture.allocate(200, 200, GL_RGB);
            img.draw(ofGetWidth()/2-90, 250);
            midTop = food[numbers[1]];
            
            
            img.load("recipes/" + food[numbers[2]] + "_2.png");
            imageWidth = img.getWidth();
            imageHeight = img.getHeight();
            texture.allocate(200, 200, GL_RGB);
            img.draw(950, 100);
            rightTop = food[numbers[2]];
            
            
            img.load("recipes/" + food[numbers[3]] + "_2.png");
            texture.allocate(200, 200, GL_RGB);
            img.draw(150, 500);
            leftBottom = food[numbers[3]];
            
            
            img.load("recipes/" + food[numbers[4]] + "_2.png");
            texture.allocate(200, 200, GL_RGB);
            img.draw(950, 500);
            rightBottom = food[numbers[4]];
            
            test = false;

        }
        
        
    }

    
    if(playStart){
        start_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
        startVideo();
    }
    
    if(debugMode) {
        
        gui.draw();
        
        kinect.setCameraTiltAngle(kinectAngleSlider);
        
    }
    
    
    
}



void ofApp::onConnection () {
    
    isConnected = true;
    
    bindEvents();
    
}



void ofApp::bindEvents () {
    
    std::string hoopPlacedEventName = "drawHoop";
    
    //socketIO.bindEvent(hoopPlacedEvent, hoopPlacedEventName);
    
    //ofAddListener(hoopPlacedEvent, this, &ofApp::drawHoop);
    
}

void ofApp::gotEvent(string& name) {
    
    ofLogNotice("ofxSocketIO[gotEvent]", name);
    
    status = name;
    
}


//--------------------------------------------------------------

void ofApp::doStuff() {
    if(currentLevel == 0) {
        test = true;
        roundStarted = true;
        startTime = ofGetElapsedTimeMillis();
    }
    if(canScore){
        if(currentLevel > 0){
            ofFill();
            score = score + 100;
            animationfinished = false;
            ofLogNotice("Je hebt gescoord");
            if(food[numbers[correct]] == "pizza") {
                pizza_anim.play();
            }
            if(food[numbers[correct]] == "brocolli") {
                
                brocolli_anim.play();
            }
            if(food[numbers[correct]] == "burger") {
                
                burger_anim.play();
            }
            if(food[numbers[correct]] == "ei") {
                
                ei_anim.play();
            }
            if(food[numbers[correct]] == "fruitmand") {
                
                fruitmand_anim.play();
            }
            if(food[numbers[correct]] == "garnaal") {
                
                garnaal_anim.play();
            }
            if(food[numbers[correct]] == "hotdog") {
                
                hotdog_anim.play();
            }
            if(food[numbers[correct]] == "ijs") {
                ijs_anim.play();
            }
            if(food[numbers[correct]] == "kers") {
                kers_anim.play();
            }
            if(food[numbers[correct]] == "kip") {
                kip_anim.play();
            }
            if(food[numbers[correct]] == "koekjes") {
                koekjes_anim.play();
            }
            if(food[numbers[correct]] == "popcorn") {
                popcorn_anim.play();
            }
            if(food[numbers[correct]] == "snoep") {
                snoep_anim.play();
            }
            if(food[numbers[correct]] == "steak") {
                steak_anim.play();
            }
            if(food[numbers[correct]] == "zalm") {
                zalm_anim.play();
            }
            yay_sound.play();
            visible = true;
            numbers[5] = { };
            test = true;
            roundStarted = true;
        }
        currentLevel ++;
    }
    
}

void ofApp::keyPressed(int key){
    
    if(key == 'd') {
        if(debugMode == true) {
            
            debugMode = false;
            
        }
        
        else if(debugMode == false) {
            
            debugMode = true;
            
        }
    }
    
    if(key == 's') {
        playStart = false;
        doStuff();
        start_anim.stop();
        test = true;
        roundStarted = true;
    }
    
    if(key == 't') {
        playStart = false;
        doStuff();
        canScore = false;
    }
}

void ofApp::startTimer(int currentLevel){

}

void ofApp::startVideo(){
    start_anim.play();
    cout << start_anim.isPlaying();
}


