#include "ofApp.h"
#include "data_request.hpp"
#include "main_menu.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
	// Set up the window
	int x = ofGetWindowWidth() / 2;
	int y = ofGetWindowHeight() / 2;
	int p = 15;
	ofSetWindowPosition(0, 0);
	ofSetWindowShape(1920, 1080);
	font.load("ofxbraitsch/fonts/Verdana.ttf", 24);
	
	stock_folder = new ofxDatGuiFolder("color picker", ofColor::fromHex(0x2FA1D6));
	
	menu.SetupMenuGui();
	
	// Setup stock gui
	stock_gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	stock_gui->setTheme(new ofxDatGuiThemeSmoke());
	stock_gui->addHeader("Drag me to reposition");
	stock_gui->addFooter();
	stock_gui->getFooter()->setLabelWhenExpanded("CLOSE PANEL 1");
	stock_gui->getFooter()->setLabelWhenCollapsed("EXPAND PANEL 1");
	
	// Create a new text input to enter a ticker to search for
	stock_gui->addTextInput("ticker input", "enter a ticker here");
	
	ticker_input = new ofxDatGuiTextInput("ticker input", "enter a ticker here");
	ticker_input->setFocused(true);
	ticker_input->setPosition(x, y);
	ticker_input->onTextInputEvent(this, &ofApp::onTextInputEvent);
	components.push_back(ticker_input);
	
	// Create a new button to trigger an API request for the ticker entered
	stock_gui->addButton("Help");
	stock_gui->onButtonEvent(this, &ofApp::onButtonEvent);
	
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
		output_label->ofxDatGuiComponent::setWidth(output_label->getWidth() + ticker_input->getText().length(), ticker_input->getText().length());
		
		// Execute a data request for the ticker entered by the user
		std::string api_key = "1bMckVuNko95sGvwrTiHHzSLssOpx6MIKtdufXvbLeKAMfwrNje9QFjjwTl5";
		std::string file_path = "/Users/jakewalters/documents/FantasticFinaleProject/fantastic-finale-Jakerwalters/bin/datafile.json";
		std::map<std::string, std::string> values = ObtainAllTickerValues(api_key, ticker_input->getText(), file_path);
		
		// Output the data to the output label
		std::string output;
		
		for (auto itr = values.begin(); itr != values.end(); itr++) {
			output += itr->first + ": " + itr->second + "\n";
		}
		
		output_label->setLabel(output);
	} else if (e.target == clear_button) {
		ticker_input->setText("");
		output_label->setLabel("");
	} else if (e.target == stock_gui->getButton("help")) {
		output_label->setLabel("gui button clicked");
	}
	
	std::cout << e.target->getLabel() << std::endl;
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
	
}
