#include "ofApp.h"
#include "ofMain.h"
#include "json.hpp"

using json = nlohmann::json;

#define DISPLAY_MODE OF_WINDOW

int main() {
	json j;
	
	// setup the GL context
	ofSetupOpenGL(640, 480, DISPLAY_MODE);

	// this kicks off the running of my app
	ofRunApp(new ofApp());
}
