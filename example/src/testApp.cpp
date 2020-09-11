#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(30);
    n=0;
    ofBackground(0,0,0);
    ofTrueTypeFont::setGlobalDpi(72);
    myFont.loadFont(OF_TTF_MONO, 30);
    

    text="Use ofxTextWriter to get that classy typing feel for your apps.\n"
    "See example for usage.\nBest accompanied by ofxMorphingText to add"
    " that blinking cursorto the end.\n";

    tr.setTextToRender(text);

//    mt.setStageCycleTime(0.1);
//    mt.addStage(" ");
//    mt.addStage("_");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
//    string str = tr.whatToRender()+mt.whatToRender();
    string str = tr.whatToRender();

    cout << str << endl;

    ofSetColor(255, 255, 255);
    myFont.drawString(str, 20, 40);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//    if(n == 0){
//        tr.start();
//        n++;}
//    else
    {
//        tr.setTimeToRender(15);
        tr.setSeperateTimeToRender(0.08);
        tr.setTextToRender(text);
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
