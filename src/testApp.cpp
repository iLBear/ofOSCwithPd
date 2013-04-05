#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    receiver.setup(PORT);
    sender.setup(HOST, PORT2);
    
    ofEnableAlphaBlending();
    ofBackground(24);
    ofSetFrameRate(30);
    ofSetCircleResolution(64);
    
    ripples.reserve(1<<10);
    
    ofxOscMessage m;
    m.setAddress("/window/pixel");
    m.addIntArg(ofGetWidth());
    m.addIntArg(ofGetHeight());
    sender.sendMessage(m);
    
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < ripples.size(); i++){
        ripples.at(i).update();
        
        //死亡判定
        if(ripples.at(i).life <= 0){
            std::vector<Ripple>::iterator it = ripples.erase(ripples.begin()+i);
        }
    }
    
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if(m.getAddress() == "/test/bla"){
            int num1, num2, num3 = 9;
            num1 = m.getArgAsInt32(0);
            num2 = m.getArgAsInt32(1);
            num3 = m.getArgAsInt32(2);
        }else if(m.getAddress() == "/of/test"){
            Ripple *rip = new Ripple;
            rip->radian = m.getArgAsInt32(0);
            rip->point.x = m.getArgAsInt32(1);
            rip->point.y = m.getArgAsInt32(2);
            rip->speed = ofRandom(0.1, 2.0);
            rip->color.set(ofRandom(128, 255), ofRandom(128, 255), ofRandom(128, 255));
            rip->life = 100+(int)ofRandom(-25, 25);
            ripples.push_back(*rip);
        }
    }
}

//--------------------------------------------------------------
//OSCメッセージをコンソールに出力する関数
void testApp::dumpOSC(ofxOscMessage m) {
    string msg_string;
    msg_string = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < ripples.size(); i++){
        ofSetColor(ripples.at(i).color);
        ofCircle(ripples.at(i).point, ripples.at(i).radian);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}