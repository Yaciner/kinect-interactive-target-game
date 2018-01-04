#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxXmlSettings.h"
#include "ofxGui.h"
#include <vector>
//#include "ofxSocketIO.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        void startTimer(int currentLevel);
        
        /* - methods - */
        void drawPointCloud();
        void saveState();
        void loadState();
        
        /* - global variables - */
        float targetSize, xPos, yPos;
        int numPointsInRegion, scaleFactorHoop;
        //const char* debugMode = std::getenv("LUMIHOOPDEBUG");
        bool showmsg = false;
        bool debugMode = false;
        bool roundStarted = false;
        void onConnection();
        string food[15] = {"broccoli", "burger", "ei", "fruitmand", "garnaal", "hotdog", "ijs", "kers", "kip", "koekjes", "pizza", "popcorn", "snoep", "steak", "vis"};
        /* - instances - */
//        ofxSocketIO socketIO;
        ofxKinect kinect;
        ofEasyCam easyCam;
        ofMesh pointCloud;
        //  ofSoundPlayer scoreSound;
        void bindEvents();
        void gotEvent(std::string& name);
        ofxPanel gui;
        ofxXmlSettings state;
        ofxFloatSlider kinectDistanceSlider;
        ofxFloatSlider kinectZSlider;
        ofxFloatSlider kinectAngleSlider;
        ofxFloatSlider kinectSphereZSlider;
        ofxLabel statusLabel;
        ofxLabel hostNameLabel;
        ofxButton savebtn;
        ofxButton loadbtn;
        bool isConnected;
        ofImage img;
        int imageWidth;
        int imageHeight;
        ofTexture texture;
        std::string status;
        ofVideoPlayer bg_anim;
        ofVideoPlayer brocolli_anim, pizza_anim, burger_anim, ei_anim, fruitmand_anim, garnaal_anim, hotdog_anim, ijs_anim, kers_anim, kip_anim, koekjes_anim, popcorn_anim, snoep_anim, steak_anim, vis_anim;
        ofVideoPlayer start_anim;
        //ofxLabel scoreLabel;
        ofTrueTypeFont font;
        //ofRectangle timerRectangle;
        float startTime;
        bool timerEnd;
};
