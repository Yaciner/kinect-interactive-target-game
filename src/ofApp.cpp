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
<<<<<<< HEAD
int tijd = 0;
int level = 0.0;

// SIZES //
int outerLeft = -670;
int outerTop = -450;
int outerRight = 540;
int outerBottom = 140;
int centralTop = -90;
int centralLeft = -260;
=======

>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62


//--------------------------------------------------------------

void ofApp::setup(){
<<<<<<< HEAD
    
=======
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
    //ofToggleFullscreen();
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
    
    gui.add(kinectDistanceSlider.setup("Kinect distance", 3000, 80, 5000));
    
    gui.add(kinectZSlider.setup("Kinect Scale Z", -0.15, -2, 2));
    
<<<<<<< HEAD
    gui.add(kinectAngleSlider.setup("Kinect Angle", 1.75, -10, 10));
=======
    gui.add(kinectAngleSlider.setup("Kinect Angle", 0.40, -10, 10));
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
    
    gui.add(statusLabel.setup("status", ofApp::status));
    
    gui.add(hostNameLabel.setup("Connect to", "http://:3000"));
    
    gui.add(savebtn.setup("Save settings"));
    
    gui.add(loadbtn.setup("Load settings"));
    
    
    
    numPointsInRegion = 0;
    
    
<<<<<<< HEAD
    targetSize =  230;
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
        vis_anim.load("scoreanimaties/vis.mp4");
        start_anim.load("start_scherm.mp4");
        start_anim.play();
=======
    targetSize =  260;
    if(debugMode == false) {
        bg_anim.load("bg_animatie.mp4");
        bg_anim.play();
        pizza_anim.load("pizza_anim.mp4");
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
    }

}



//--------------------------------------------------------------

void ofApp::update(){
    
    kinect.setCameraTiltAngle(kinectAngleSlider);
    
    
    bg_anim.update();
    pizza_anim.update();
<<<<<<< HEAD
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
    start_anim.update();
=======
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
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

<<<<<<< HEAD
                    if((pt.x > outerLeft - targetRegionleftTop && pt.x < outerLeft + targetRegionleftTop)

                       && (pt.y > outerTop - targetRegionleftTop && pt.y < outerTop + targetRegionleftTop)
=======
                    if((pt.x > -600-targetRegionleftTop && pt.x < -600 + targetRegionleftTop)

                       && (pt.y > -600-targetRegionleftTop && pt.y < -600 + targetRegionleftTop)
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62

                       && (pt.z > kinectDistanceSlider-targetRegionleftTop && pt.z < kinectDistanceSlider + targetRegionleftTop)){
                        
                        if (correct == 0){
                            numPointsInRegion += 1;
<<<<<<< HEAD
                           
=======
                            cout << leftTop;
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
                        }
                    }
                    

                    
                    
                    //MIDDEN

                    int targetRegionmidTop = (targetSize) / 2;

<<<<<<< HEAD
                    if((pt.x > centralTop - targetRegionmidTop && pt.x < centralTop + targetRegionmidTop)
=======
                    if((pt.x > -50 - targetRegionmidTop && pt.x < -50 + targetRegionmidTop)
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62

                       && (pt.y > centralLeft - targetRegionmidTop && pt.y < centralLeft + targetRegionmidTop)

                       && (pt.z > kinectDistanceSlider-targetRegionmidTop && pt.z < kinectDistanceSlider + targetRegionmidTop)){
                        
                        if (correct == 1){
                            numPointsInRegion += 1;
<<<<<<< HEAD
                         
=======
                            cout << midTop;
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
                        }

                    }
                    
                    //RECHTS BOVEN
                    int targetRegionrightTop = (targetSize) / 2;

<<<<<<< HEAD
                    if((pt.x > outerRight - targetRegionrightTop && pt.x < outerRight + targetRegionrightTop)

                       && (pt.y > outerTop - targetRegionrightTop && pt.y < outerTop + targetRegionrightTop)
=======
                    if((pt.x > 650 - targetRegionrightTop && pt.x < 650 + targetRegionrightTop)

                       && (pt.y > -700-targetRegionrightTop && pt.y < -700 + targetRegionrightTop)
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62

                       && (pt.z > kinectDistanceSlider-targetRegionrightTop && pt.z < kinectDistanceSlider + targetRegionrightTop)){
                        
                        if (correct == 2){
                            numPointsInRegion += 1;
<<<<<<< HEAD
                           
=======
                            cout << rightTop;
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
                        }

                    }
                    
                    
                    //LINKS BENEDEN
                    int targetRegionleftBottom = (targetSize) / 2;

<<<<<<< HEAD
                    if((pt.x > outerLeft - targetRegionleftBottom && pt.x < outerLeft + targetRegionleftBottom)

                       && (pt.y > outerBottom - targetRegionleftBottom && pt.y < outerBottom + targetRegionleftBottom)
=======
                    if((pt.x > -600 - targetRegionleftBottom && pt.x < -600 + targetRegionleftBottom)

                       && (pt.y > 50-targetRegionleftBottom && pt.y < 50 + targetRegionleftBottom)
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62

                       && (pt.z > kinectDistanceSlider-targetRegionleftBottom && pt.z < kinectDistanceSlider + targetRegionleftBottom)){
                        
                        if (correct == 3){
                            numPointsInRegion += 1;
<<<<<<< HEAD
=======
                            cout << leftBottom;
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
                        }

                    }
                    
                    //RECHTS BENEDEN
                    int targetRegionrightBottom = (targetSize) / 2;
                    
<<<<<<< HEAD
                    if((pt.x > outerRight - 20 - targetRegionrightBottom && pt.x < outerRight - 20 + targetRegionrightBottom)
                       
                       && (pt.y > outerBottom -20 - targetRegionrightBottom && pt.y < outerBottom - 20 + targetRegionrightBottom)
=======
                    if((pt.x > 650 - targetRegionrightBottom && pt.x < 650 + targetRegionrightBottom)
                       
                       && (pt.y > 25 - targetRegionrightBottom && pt.y < 25 + targetRegionrightBottom)
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
                       
                       && (pt.z > kinectDistanceSlider-targetRegionrightBottom && pt.z < kinectDistanceSlider + targetRegionrightBottom)){
                        
                        if (correct == 4){
                            numPointsInRegion += 1;
<<<<<<< HEAD
=======
                            cout << rightBottom;
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
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

<<<<<<< HEAD
            ofFill();
            score = score + 100;
            animationfinished = false;
            ofLogNotice("Je hebt gescoord");
            
            std::string hoopHitEventName = "detectHit";
            
            std::string param = "param";
            
            //socketIO.emit(hoopHitEventName, param);

            //scoreSound.play();
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
            if(food[numbers[correct]] == "vis") {
                vis_anim.play();
            }
            visible = true;
            //targetSize = 0;
            numbers[5] = { };
            showmsg = true;
            test = true;
            roundStarted = true;
=======
        ofNoFill();
        score = score + 100;
        ofLogNotice("Je hebt gescoord");
//        std::string hoopHitEventName = "detectHit";
//
//        std::string param = "param";

        //socketIO.emit(hoopHitEventName, param);
        
        //scoreSound.play();

        //targetSize = 0;

        showmsg = true;
        test = true;
        roundStarted = true;
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62

    } else {

        ofNoFill();

    }
//
    
    if(debugMode) {
        //links boven
<<<<<<< HEAD
        ofDrawBox(-670, -450, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //middenboven
        ofDrawBox(-90, -260, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //rechtsboven
        ofDrawBox(540, -450, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        
        //linksbeneden
        ofDrawBox(-670, 140, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //rechtsbeneden
        ofDrawBox(520, 120, kinectDistanceSlider-220, targetSize, targetSize, 400);
=======
        ofDrawBox(-600, -600, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //middenboven
        ofDrawBox(-50, -200, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //rechtsboven
        ofDrawBox(650, -700, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        
        //linksbeneden
        ofDrawBox(-600, 50, kinectDistanceSlider-220, targetSize, targetSize, 400);
        
        //rechtsbeneden
        ofDrawBox(700, 25, kinectDistanceSlider-220, targetSize, targetSize, 400);
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
    }
    
    
    if(showmsg) {
        
        ofPushMatrix();
        
        ofScale(1, -1, 1);
        
        ofTranslate(0, 0, kinectDistanceSlider-220);
        
        //score_anim.draw(-320,-240, 640, 480);
        
        ofPopMatrix();
        
    } else {
        
        //score_anim.draw(-320,-240, 0, 0);
        
    }
    
    
    
    ofPushMatrix();
    
    ofTranslate(0, 0, kinectDistanceSlider-220);
    
    ofPopMatrix();
    ofPopMatrix();
    easyCam.end();
<<<<<<< HEAD
    
    bg_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
    start_anim.draw(0, 0, ofGetWidth(), ofGetHeight());

    if(visible) {
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
        if(food[numbers[correct]] == "vis") {
            vis_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
        }
        frames ++;
    }
    if (frames >= 120){
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
        vis_anim.stop();
        startTime = ofGetElapsedTimeMillis();
    }
    
    
    
    if(timerEnd) {
        startTime = ofGetElapsedTimeMillis();
        cout << "game over!";
        timerEnd = false;
    }
    
    if (animationfinished){
        if(roundStarted) {
    
            float barWidth = 300;
            float timer = ofGetElapsedTimeMillis() - startTime;
            
            if(timer >= (20000.0)) {
                timerEnd = true;
            }
            
            float timerBar = ofMap(timer, 0.0, 20000.0 , 1.0, 0.0, true);
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
                currentLevel = currentLevel + 1;
                //startTimer(currentLevel);
                
=======
    
    bg_anim.draw(0, 0, ofGetWidth(), ofGetHeight());
    if(visible) {
        pizza_anim.draw(ofGetWidth()/2-195, ofGetHeight()/2-300, 390, 500);
        frames ++;
    }
    if (frames > 120){
        visible = false;
        frames = 0;
        animationfinished = true;
    }
    
    if (animationfinished){
        if(roundStarted) {
            if (test){
                
                currentLevel = currentLevel + 1;
                //startTimer(currentLevel);
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
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
<<<<<<< HEAD
=======
                //            for(int i = 0; i < 5; i++){
                //                std::cout << numbers[i] << std::endl;
                //            }
                
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            }
            
            ofSetColor(255);
            font.drawString(to_string(score), 20, 70);
            ofFill();
<<<<<<< HEAD
=======
            ofSetColor(230, 230, 230);
            ofDrawRectangle(ofGetWidth()/2 - 125 , 0, currentTimerSize, 50);
            ofNoFill();
            ofSetColor(255, 255);
            
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            
            img.load("ingredients/" + food[numbers[correct]] + "_1.png");
            texture.allocate(240, 240, GL_RGB);
            img.draw(ofGetWidth()/2-100/2, ofGetHeight()-110);
            leftTop = food[numbers[0]];
            
            img.load("recipes/" + food[numbers[0]] + "_2.png");
            texture.allocate(240, 240, GL_RGB);
<<<<<<< HEAD
            img.draw(150, 100);
=======
            img.draw(200, 100);
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            leftTop = food[numbers[0]];
            
            
            img.load("recipes/" + food[numbers[1]] + "_2.png");
            texture.allocate(200, 200, GL_RGB);
<<<<<<< HEAD
            img.draw(ofGetWidth()/2-90, 250);
=======
            img.draw(600, 250);
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            midTop = food[numbers[1]];
            
            
            img.load("recipes/" + food[numbers[2]] + "_2.png");
            imageWidth = img.getWidth();
            imageHeight = img.getHeight();
            texture.allocate(200, 200, GL_RGB);
<<<<<<< HEAD
            img.draw(950, 100);
=======
            img.draw(1000, 100);
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            rightTop = food[numbers[2]];
            
            
            img.load("recipes/" + food[numbers[3]] + "_2.png");
            texture.allocate(200, 200, GL_RGB);
<<<<<<< HEAD
            img.draw(150, 500);
=======
            img.draw(200, 500);
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            leftBottom = food[numbers[3]];
            
            
            img.load("recipes/" + food[numbers[4]] + "_2.png");
            texture.allocate(200, 200, GL_RGB);
<<<<<<< HEAD
            img.draw(950, 500);
=======
            img.draw(1000, 500);
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            rightBottom = food[numbers[4]];
            
            test = false;

        }
        
        
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



//void ofApp::drawHoop () {

//    showmsg = false;

//}



//--------------------------------------------------------------

void ofApp::keyPressed(int key){
    
<<<<<<< HEAD
    
    start_anim.close();
=======
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
    if(key == 't') {
            ofFill();
            score = score + 100;
            animationfinished = false;
            ofLogNotice("Je hebt gescoord");
            
            std::string hoopHitEventName = "detectHit";
<<<<<<< HEAD
            level = level + 1000.0;
            std::string param = "param";
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
            if(food[numbers[correct]] == "vis") {
                vis_anim.play();
            }
=======
            
            std::string param = "param";
            
            //socketIO.emit(hoopHitEventName, param);
        
            //scoreSound.play();
            pizza_anim.play();
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
            visible = true;
            //targetSize = 0;
            numbers[5] = { };
            showmsg = true;
            test = true;
            roundStarted = true;
<<<<<<< HEAD
    }
    
    
    test = true;
    roundStarted = true;
=======
        
    }
    
    roundStarted = true;
    test = true;
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
    
    if (key == ' '){
        
        if(debugMode == true) {
            
            debugMode = false;
            
        }
        
        else if(debugMode == false) {
            
            debugMode = true;
            
        }
        
    }
    
}

void ofApp::startTimer(int currentLevel){
<<<<<<< HEAD

=======
    currentTimerSize = 200 - currentLevel;
    
    for(int i = currentTimerSize; i > 0;i--) {
        sleep(1);
        currentTimerSize = currentTimerSize - 10;
        cout << i;
        continue;
        
    }
>>>>>>> e3c175ce61cea28b18055979024a7af0ddefaa62
}


