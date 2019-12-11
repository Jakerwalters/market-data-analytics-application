#pragma once

#include "ofMain.h"
#include "ofxGraph.h"
#include "ofxDatGui.h"
#include "main_menu.hpp"
#include "data_panel.hpp"
#include "financial_graph.hpp"
#include "ofImage.h"

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
	
		MenuGui menu = MenuGui();
		DataPanel left_panel = DataPanel();
		DataPanel center_panel = DataPanel();
		DataPanel right_panel = DataPanel();
};
