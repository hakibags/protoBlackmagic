#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "MotionAmplifier.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
    
	ofVideoGrabber cam;
    MotionAmplifier motionAmplifier;
    
    bool drawMesh;
};