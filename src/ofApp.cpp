#include "ofApp.h"
#include "data_request.hpp"
#include "main_menu.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
	// Set up the window
	ofSetFrameRate(60);
	ofSetWindowPosition(0, 0);
	
	// Setup the data panels
	left_panel.SetupDataPanelGui(0, 0);
	center_panel.SetupDataPanelGui(400, 0);
	right_panel.SetupDataPanelGui(800, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	left_panel.UpdatePanel();
	center_panel.UpdatePanel();
	right_panel.UpdatePanel();
}

//--------------------------------------------------------------
void ofApp::draw(){
	left_panel.DrawPanel();
	center_panel.DrawPanel();
	right_panel.DrawPanel();
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
