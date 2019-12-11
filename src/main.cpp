#include "ofApp.h"
#include "ofMain.h"

#define DISPLAY_MODE OF_WINDOW

int main() {
	// Configure the window settings
  // Application currently does not support resizing
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.setSize(1200, 800);
	ofCreateWindow(settings);
	
	// This kicks off the running of my app
	ofRunApp(new ofApp());
}
