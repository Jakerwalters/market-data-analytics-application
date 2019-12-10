#include "ofApp.h"
#include "ofMain.h"
#include <iostream>
#include <fstream>
#include "data_request.hpp"
#include <chrono>
#include <ctime>
#include "time.h"

#define DISPLAY_MODE OF_WINDOW

int main() {
	// setup the GL context
	//ofSetupOpenGL(640, 480, DISPLAY_MODE);
	
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.setSize(1200, 800);
	ofCreateWindow(settings);
	
	// this kicks off the running of my app
	ofRunApp(new ofApp());
}
