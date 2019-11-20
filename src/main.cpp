#include "ofApp.h"
#include "ofMain.h"
#include "json.hpp"
#include <curl/curl.h>

using json = nlohmann::json;

#define DISPLAY_MODE OF_WINDOW

int main() {
	
	CURL *curl = curl_easy_init();
	if(curl) {
		CURLcode res;
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.worldtradingdata.com/api/v1/mutualfund?symbol=AAAAX,AAADX,AAAGX&api_token=demo");
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	
	json j;
	
	// setup the GL context
	ofSetupOpenGL(640, 480, DISPLAY_MODE);

	// this kicks off the running of my app
	ofRunApp(new ofApp());
}
