#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ripple.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void dumpOSC(ofxOscMessage m);
    
    vector<Ripple> ripples;
    
private:
    ofxOscSender    sender;
    ofxOscReceiver  receiver;
    
    int radian;
    
    const int PORT = 8080;
    const int PORT2 = 8081;
    const string HOST = "localhost";
};
