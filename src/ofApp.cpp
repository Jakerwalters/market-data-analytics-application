#include "ofApp.h"
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
	// Set up the window
	int x = ofGetWindowWidth() / 2;
	int y = ofGetWindowHeight() / 2;
	int p = 15;
	ofSetWindowPosition(0, 0);
	ofSetWindowShape(1920, 1080);
	font.load("ofxbraitsch/fonts/Verdana.ttf", 24);
	
	// Create a new text input to enter a ticker to search for
	ticker_input = new ofxDatGuiTextInput("ticker input", "enter a ticker here");
	ticker_input->setFocused(true);
	ticker_input->setPosition(x, y);
	ticker_input->onTextInputEvent(this, &ofApp::onTextInputEvent);
	components.push_back(ticker_input);
	
	// Create a new button to trigger an API request for the ticker entered
	y += ticker_input->getHeight() + p;
	search_button = new ofxDatGuiButton("Search");
	search_button->setPosition(x, y);
	search_button->onButtonEvent(this, &ofApp::onButtonEvent);
	components.push_back(search_button);
	
	// Create a new button to clear the API data displayed from the last request
	y += search_button->getHeight() + p;
	clear_button = new ofxDatGuiButton("Clear");
	clear_button->setPosition(x, y);
	clear_button->onButtonEvent(this, &ofApp::onButtonEvent);
	components.push_back(clear_button);
	
	// Create a new label to display the data collected from the API request
	y += clear_button->getHeight() + p;
	output_label = new ofxDatGuiLabel("");
	output_label->setPosition(x, y);
	components.push_back(output_label);
	
	for(int i=0; i<components.size(); i++) {
		
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for(int i=0; i<components.size(); i++) {
		components[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i=0; i<components.size(); i++) {
		components[i]->draw();
	}
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

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	if (e.target == search_button){
		search_button->setLabel("Search Clicked");
		output_label->ofxDatGuiComponent::setWidth(output_label->getWidth() + ticker_input->getText().length(), ticker_input->getText().length());
		output_label->setLabel(ticker_input->getText());
	} else if (e.target == clear_button) {
		clear_button->setLabel("Clear Clicked");
		ticker_input->setText("");
		output_label->setLabel("");
	}
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
	if (e.target == ticker_input) {
		
	}
}
