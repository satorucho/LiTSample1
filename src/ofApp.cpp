#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    circleX = 100;
    circleY = 100;
    speedX = 5;
    speedY = 5;
    background = 0;
    ofSetCircleResolution(100);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    circleX = circleX + speedX;
    circleY = circleY + speedY;

    if ( circleX < 100 || circleX > ofGetWidth()-100) speedX = -speedX;
    if ( circleY < 100 || circleY > ofGetHeight()-100) speedY = -speedY;

    background = background - 15;
    if (background < 0) background = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(background,background,0);
    ofSetColor(255, 0, 0, 255);
    
    ofSetLineWidth(2);
    for (int i = 0; i <= ofGetHeight()/128; i++){
        ofLine(0, 128*i, ofGetWidth(), 128*i);
    }
    for (int i = 0; i <= ofGetWidth()/128; i++){
        ofLine(128*i, 0, 128*i, ofGetHeight());
    }
    
    ofSetColor(0, 0, 255, 255);
    ofCircle(circleX, circleY, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'a':
            speedX = speedX * 2;
            speedY = speedY * 2;
            break;
        case 'b':
            speedX = speedX / 2;
            speedY = speedY / 2;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (pow((mouseX-circleX),2.0f)+pow((mouseY-circleY),2.0f)<=10000){
        speedX = -speedX;
        speedY = -speedY;
        background = 255;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
