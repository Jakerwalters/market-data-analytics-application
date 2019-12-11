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
	// Configure the window settings
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.setSize(1200, 800);
	ofCreateWindow(settings);
	
	// This kicks off the running of my app
	ofRunApp(new ofApp());
}
