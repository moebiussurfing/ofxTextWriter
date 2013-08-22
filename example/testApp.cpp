#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    n=0;
    ofBackground(0,0,5);
    ofTrueTypeFont::setGlobalDpi(72);
    myFont.loadFont(OF_TTF_SANS, 18);
    
    tr.setTimeToRender(2);
    tr.setTextToRender("ofxTextWriter makes an oldschool kind of effect where it writes out text slowly, as if it was being typed.\nIt's cool.\n");
    mt.setStageCycleTime(0.1);
	mt.addStage(" ");
	mt.addStage("_");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(0, 255, 0);
    myFont.drawString(tr.whatToRender()+mt.whatToRender(), 20, 40);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(n == 0){ tr.start(); n++;}
    else{
        tr.setSeperateTimeToRender(0.02);
        tr.setTextToRender("Use ofxTextWriter to get that classy typing feel for your apps.\nSee example for usage.\nBest accompanied by ofxMorphingText to add that blinking cursorto the end.\n");
        tr.resetTime();
        tr.start();
    }
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

    if(n == 0){ tr.start(); n++;}
    else{
        tr.setSeperateTimeToRender(0.05);
        tr.setTextToRender("Use ofxTextWriter to get that classy typing feel for your apps.\nSee example for usage.\nBest accompanied by ofxMorphingText to add that blinking cursorto the end.\n");
        tr.resetTime();
        tr.start();
    }
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
