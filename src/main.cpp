#include "ofApp.h"
#include "ofMain.h"
#include <iostream>
#include <fstream>
#include "data_request.hpp"

#define DISPLAY_MODE OF_WINDOW

int main() {
	// setup the GL context
	ofSetupOpenGL(640, 480, DISPLAY_MODE);

	// this kicks off the running of my app
	ofRunApp(new ofApp());

	std::string api_key = "1bMckVuNko95sGvwrTiHHzSLssOpx6MIKtdufXvbLeKAMfwrNje9QFjjwTl5";
	std::string wtd_demo_url = "https://api.worldtradingdata.com/api/v1/stock?symbol=SNAP,TWTR,VOD.L&api_token=demo";
	std::string ticker_data_file_path = "/Users/jakewalters/documents/FantasticFinaleProject/fantastic-finale-Jakerwalters/bin/datafile.json";
	std::string key = "day_high";

	std::string value = ObtainTickerValue(api_key, "SNAP", key, ticker_data_file_path);
	std::cout << "the value for key " << key << " is: " << value << std::endl;

	std::map<std::string, std::string> values = ObtainAllTickerValues(api_key, "AAPL", ticker_data_file_path);

	for (auto itr = values.begin(); itr != values.end(); ++itr) {
		std::cout << itr->first << ": " << itr->second << std::endl;
	}
}
