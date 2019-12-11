#include "ofApp.h"

void ofApp::setup(){
	// Set up the window
	ofSetFrameRate(60);
	ofSetWindowPosition(0, 0);
	
	// Setup the data panels
	left_panel.SetupDataPanelGui(0, 0);
	center_panel.SetupDataPanelGui(400, 0);
	right_panel.SetupDataPanelGui(800, 0);
}

void ofApp::update(){
	left_panel.UpdatePanel();
	center_panel.UpdatePanel();
	right_panel.UpdatePanel();
}

void ofApp::draw(){
	left_panel.DrawPanel();
	center_panel.DrawPanel();
	right_panel.DrawPanel();
}
