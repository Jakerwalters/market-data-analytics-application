#include "ofApp.h"
#include "data_request.hpp"
#include "main_menu.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
	// Set up the window
	ofSetFrameRate(60);
	int x = ofGetWindowWidth() / 2;
	int y = ofGetWindowHeight() / 2;
	int p = 15;
	ofSetWindowPosition(0, 0);
	
	// Setup the main menu gui
	menu.SetupMenuGui();
	
	// Setup the data panels
	left_panel.SetupDataPanelGui(0, 0);
	center_panel.SetupDataPanelGui(400, 0);
	right_panel.SetupDataPanelGui(800, 0);
	
	ofxGuiSetFont(ofToDataPath("ofxGraph/DIN_Alternate_Bold.ttf"), 10);
	graph.setup("");
	graph.setDx(1.0); // which means delta of time
	graph.setColor(ofColor::white);  // ofColor(255,255,255)
	graph.setSize(380, 190);
	graph.setPosition(410, 150);
}

//--------------------------------------------------------------
void ofApp::update(){
	graph.add(ofRandom(-100,100));
	left_panel.UpdatePanel();
	center_panel.UpdatePanel();
	right_panel.UpdatePanel();
}

//--------------------------------------------------------------
void ofApp::draw(){
	left_panel.DrawPanel();
	center_panel.DrawPanel();
	right_panel.DrawPanel();
	graph.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
