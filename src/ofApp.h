#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "MotionAmplifier.h"
#include "ofxBlackMagic.h"


class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
    
    ofVideoGrabber cam;
//    ofxBlackMagic cam;
    MotionAmplifier motionAmplifier;
   
    
    bool drawMesh;
};