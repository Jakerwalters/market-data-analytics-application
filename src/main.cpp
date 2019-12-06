#include "ofApp.h"
#include "ofMain.h"
#include "ofURLFileLoader.h"
#include "json.hpp"
#include <iostream>
#include <fstream>

#define DISPLAY_MODE OF_WINDOW

int main() {
	// setup the GL context
	ofSetupOpenGL(640, 480, DISPLAY_MODE);

	// this kicks off the running of my app
	ofRunApp(new ofApp());
	
	}
