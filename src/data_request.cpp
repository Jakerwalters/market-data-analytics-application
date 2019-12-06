//
//  data_request.cpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/5/19.
//

#include "data_request.hpp"

void RequestData(std::string data_url, std::string path) {
	std::filesystem::path file_path = path;
	ofSaveURLTo(data_url, file_path);
}

std::string ObtainTickerValue(std::string api_key, std::string ticker, std::string key, std::string file_path) {
	std::string data_url = "https://api.worldtradingdata.com/api/v1/stock?symbol=" + ticker + "&api_token=" + api_key;
	std::string formatted_key = "\"" + key + "\"";
	
	// Request the data from the API
	RequestData(data_url, file_path);
	
	// Load the json file into a json object
	std::ifstream jsonFile(file_path);
	nlohmann::json file;
	jsonFile >> file;
	
	// Retrieve the "data" object
	nlohmann::json data = file["data"];
	return data[0].at(key);
}

std::map<std::string, std::string> ObtainAllTickerValues(std::string api_key, std::string ticker, std::string file_path) {
	std::string data_url = "https://api.worldtradingdata.com/api/v1/stock?symbol=" + ticker + "&api_token=" + api_key;
	
	// Request the data from the API
	RequestData(data_url, file_path);
	
	// Load the json file into a json object
	std::ifstream jsonFile(file_path);
	nlohmann::json file;
	jsonFile >> file;
	
	// Retrieve all values from the "data" object
	std::map<std::string, std::string> values;
	nlohmann::json data = file["data"];
	
	for (auto it = data[0].begin(); it != data[0].end(); ++it)
	{
		std::string key = it.key();
		std::string value = it.value();
		values.insert(std::pair<std::string, std::string>(key, value));
	}
	
	return values;
}
