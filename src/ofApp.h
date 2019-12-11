#pragma once

#include "ofMain.h"
#include "ofxGraph.h"
#include "ofxDatGui.h"
#include "main_menu.hpp"
#include "data_panel.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		DataPanel left_panel = DataPanel();
		DataPanel center_panel = DataPanel();
		DataPanel right_panel = DataPanel();
};
