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

std::string ObtainTickerValue(std::string api_key, std::string ticker,
															std::string key, std::string file_path) {
	std::string data_url = "https://api.worldtradingdata.com/api/v1/stock?symbol=" + ticker + "&api_token=" + api_key;
	
	// Request the data from the API
	RequestData(data_url, file_path);
	
	// Load the json file into a json object
	std::ifstream jsonFile(file_path);
	nlohmann::json file;
	jsonFile >> file;
	
	// Check for call errors
	if (file.contains("Message")) {
		std::string error_message = "API error";
		return error_message;
	}
	
	// Retrieve the "data" object
	nlohmann::json data = file["data"];
	return data[0].at(key);
}

std::map<std::string, std::string> ObtainAllTickerValues(std::string api_key, std::string ticker,
																												 std::string file_path) {
	std::string data_url = "https://api.worldtradingdata.com/api/v1/stock?symbol=" + ticker + "&api_token=" + api_key;
	
	// Request the data from the API
	RequestData(data_url, file_path);
	
	// Load the json file into a json object
	std::ifstream jsonFile(file_path);
	nlohmann::json file;
	jsonFile >> file;
	
	// Check for call errors
	if (file.contains("message")) {
		std::map<std::string, std::string> error_messages;
		error_messages.insert(std::pair<std::string, std::string>("message", file.at("message")));
		return error_messages;
	}
	
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

std::map<std::string, std::string> ObtainTickerIntraday(std::string api_key, std::string ticker,
																												std::string file_path, int day_range,
																												int time_interval) {
	std::string formatted_day_range = std::to_string(day_range);
	std::string formatted_time_interval = std::to_string(time_interval);
	std::string data_url = "https://intraday.worldtradingdata.com/api/v1/intraday?symbol=" + ticker + "&range=" + formatted_day_range + "&interval=" + formatted_time_interval + "&api_token=" + api_key;
	
	// Request the data from the API
	RequestData(data_url, file_path);
	
	// Load the json file into a json object
	std::ifstream jsonFile(file_path);
	nlohmann::json file;
	jsonFile >> file;
	
	// Check for call errors
	if (file.contains("message")) {
		std::map<std::string, std::string> error_messages;
		error_messages.insert(std::pair<std::string, std::string>("message", file.at("message")));
		return error_messages;
	}
	
	// Use the system time to make calls to the API
	std::string current_system_time = CurrentDateTime();
	std::string current_system_date = current_system_time.substr(0, 10);
	
	// Retrieve all values from the "intraday" object
	std::map<std::string, std::string> values;
	nlohmann::json all_data = file["intraday"];
	
	// Obtain the current timezone of the system to offset the time in the API request to EST
	char* timezone = std::getenv("TZ");
	tzset();
	std::string formatted_timezone;
	formatted_timezone = formatted_timezone + tzname[0];
	int timezone_offset;
	
	// Application currently supports timezones in the contiguous U.S.
	if (!formatted_timezone.compare("EST")) {
		timezone_offset = 0;
	} else if (!formatted_timezone.compare("CST")) {
		timezone_offset = 1;
	} else if (!formatted_timezone.compare("MST")) {
		timezone_offset = 2;
	} else if (!formatted_timezone.compare("PST")) {
		timezone_offset = 3;
	}

	// Convert the system time to EST
	std::string time_hour = current_system_time.substr(11,2);
	int time_hour_number = std::stoi(time_hour);
	time_hour_number = time_hour_number + timezone_offset;
	current_system_time.replace(11, 2, std::to_string(time_hour_number));
	
	// Loop backwards chronologically through all of the date and time objects provided by the API
	// and extract the close price to form a pair with date and time as the key and close price as the value
	std::string request_time;
	const std::string kMarketOpenTime = "09:30:00";
	std::string decremented_time = current_system_time;
	std::string current_minute_formatted;
	int current_minute = std::stoi(decremented_time.substr(14, 2));
	std::string current_hour_formatted;
	int current_hour = std::stoi(decremented_time.substr(11, 2));
	
	// If the request is initiated during closed hours, change the time of the first request to just before close
	if (current_hour > 15) {
		current_hour = 16;
		current_hour_formatted = std::to_string(current_hour);
		current_minute = 0;
		current_minute_formatted = "0" + std::to_string(current_minute);
		decremented_time.replace(11, 2, current_hour_formatted);
		decremented_time.replace(14, 2, current_minute_formatted);
	}
	
	// Gather data for 1 minute intervals
	if (time_interval == 1) {
		while (request_time.compare(current_system_date + " " + kMarketOpenTime)) {
			if (current_minute > 0 && current_hour != 9) {
				current_minute--;
			} else if (current_minute == 0 && current_hour > 9) {
				current_hour--;
				current_minute = 59;
			} else if (current_minute > 30 && current_hour == 9) {
				current_minute--;
			}
			
			// Account for single digit minutes
			if (current_minute < 10) {
				current_minute_formatted = "0" + std::to_string(current_minute);
			} else {
				current_minute_formatted = std::to_string(current_minute);
			}
			
			current_hour_formatted = std::to_string(current_hour);
			
			// Account for single digit hours
			if (current_hour < 10) {
				decremented_time.replace(11, 7, "0" + current_hour_formatted
																 + ":" + current_minute_formatted + ":" + "0");
				request_time = decremented_time;
			} else {
				decremented_time.replace(11, 2, current_hour_formatted);
				decremented_time.replace(14, 2, current_minute_formatted);
				request_time = decremented_time;
			}
			
			nlohmann::json current_day_data = all_data.at(request_time);
			values.insert(std::pair<std::string, std::string>(request_time,
																												current_day_data.at("close")));
		}
	}

	return values;
}

std::string CurrentDateTime() {
	// code for obtaining local date and time adapted from Stack Overflow, Author: TrungTN
	// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	std::string formatted_date_time = "";
	
	// Format the string to make it usable for API requests
	for (int index = 0; index < std::strlen(buf); index++) {
		formatted_date_time = formatted_date_time + buf[index];
	}
	
	replace(formatted_date_time.begin(), formatted_date_time.end(), '.', ' ');
	formatted_date_time.resize(17);
	formatted_date_time.resize(19, '0');
	
	return formatted_date_time;
}

std::vector<std::string> ObtainTickerNews(std::string api_key, std::string ticker,
																					std::string file_path, int items) {
	std::string formatted_items = std::to_string(items);
	std::string data_url = "https://stocknewsapi.com/api/v1?tickers=" + ticker + "&items=" + formatted_items + "&token=" + api_key;
	
	// Request the data from the API
	RequestData(data_url, file_path);
	
	// Load the json file into a json object
	std::ifstream jsonFile(file_path);
	nlohmann::json file;
	jsonFile >> file;
	
	// Check for call errors
	if (file.contains("error")) {
		std::vector<std::string> error_messages;
		error_messages.push_back("API error");
		return error_messages;
	}
	
	// Extract the specific values needed
	nlohmann::json all_data = file["data"];
	nlohmann::json article = all_data[0];
	std::string article_url = article.at("news_url");
	std::string article_title = article.at("title");
	std::string article_image_url = article.at("image_url");
	
	std::vector<std::string> values;
	values.push_back(article_url);
	values.push_back(article_title);
	values.push_back(article_image_url);
	
	return values;
}
