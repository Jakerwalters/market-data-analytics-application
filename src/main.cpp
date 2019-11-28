#include "ofApp.h"
#include "ofMain.h"
#include "json.hpp"
#include <curl/curl.h>

using json = nlohmann::json;

#define DISPLAY_MODE OF_WINDOW

int main() {
	
	// setup a curl handler
	CURL *curl = curl_easy_init();
	// create a new file to write JSON to
	FILE *file;
	// this is the returned code
	CURLcode res;
	// this is the url to connect to
	char *url = "https://api.worldtradingdata.com/api/v1/mutualfund?symbol=AAAAX,AAADX,AAAGX&api_token=demo";
	
	//this is the name of the file to write to
	char outfilename[FILENAME_MAX] = "datafile.json";
	
	// if there is information to retrieve then get it
	if(curl) {
		
		// open the new file to write to
		file = fopen(outfilename, "wb");

		// retrieve all of the information on the page
		curl_easy_setopt(curl, CURLOPT_URL, url);
		
		// call the write function to write the data
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
		
		// write all page data to the file
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
		
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		
		//close the file
		fclose(file);
	
	}
	
	//json j;
	
	// setup the GL context
	ofSetupOpenGL(640, 480, DISPLAY_MODE);

	// this kicks off the running of my app
	ofRunApp(new ofApp());
}
