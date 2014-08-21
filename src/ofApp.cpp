#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetFrameRate(120);
//    black magic
//    cam.setup(1920,1080,24);
//    end blackmagic
    
//    quicktime
    cam.setDeviceID(18);
    cam.initGrabber(1920, 1080);

//    end quicktime
    motionAmplifier.setup(cam.getWidth(), cam.getHeight(), 2, .25);
    drawMesh = false;
}

void ofApp::update() {
    motionAmplifier.setStrength(ofMap(mouseX, 0, ofGetWidth(), -10, 10));
    motionAmplifier.setLearningRate(ofMap(mouseY, 0, ofGetHeight(), 0, 1, true));
    motionAmplifier.setBlurAmount(0);
    motionAmplifier.setWindowSize(8);
    
	cam.update();
    
//  black magic
//    motionAmplifier.update(cam.getColorPixels());
//  end black magic

//    quicktime
//    if(cam.isFrameNew()) {
//        motionAmplifier.update(cam);
//	}
//    end quicktime

}

void ofApp::draw() {
    ofBackground(0);
    ofSetupScreenOrtho(ofGetWidth(), ofGetHeight(), -100, +100);
    ofEnableDepthTest();
//    motionAmplifier.draw(cam);
    if (drawMesh) {
        motionAmplifier.drawMesh();
    }
    cam.draw(0, 0);
//    cam.drawColor();
    ofDisableDepthTest();
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 50,50);
    
//    vector<ofVideoDevice> devices = cam.listDevices();
//    stringstream ss;
//    for (vector<ofVideoDevice>::const_iterator it = devices.begin(); it != devices.end(); ++it) {
//        ss << it->deviceName << ": " << it->id << endl;
//    }
//    
//    ofDrawBitmapString(ss.str(), 50, 130);
    
}

void ofApp::keyPressed(int key)
{
    if (key == ' ') {
        drawMesh = !drawMesh;
    }
}

