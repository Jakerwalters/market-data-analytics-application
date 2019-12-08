#pragma once

#include "ofMain.h"
#include "ofxGraph.h"
#include "ofxDatGui.h"
#include "main_menu.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		ofTrueTypeFont font;
		
		ofxDatGui* stock_gui;
		ofxDatGuiFolder* stock_folder;
		vector<ofxDatGuiComponent*> components;
		ofxDatGuiTextInput* ticker_input;
		ofxDatGuiButton* search_button;
		ofxDatGuiButton* clear_button;
		ofxDatGuiLabel* output_label;
	
		void onButtonEvent(ofxDatGuiButtonEvent e);
		void onTextInputEvent(ofxDatGuiTextInputEvent e);
	
		MenuGui menu = MenuGui();
	
		
};
