//
//  data_request.hpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/5/19.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "ofURLFileLoader.h"
#include "json.hpp"

/*
 * Function for initiating a request to a web API and saving the contents in a file
 */
void RequestData(std::string data_url, std::string file_path);

/*
 * Function for obtaining a specific data value for a specified key from a ticker
 */
std::string ObtainTickerValue(std::string api_key, std::string ticker,
															std::string key, std::string file_path);

/*
 * Function for obtaining all data values from a ticker
 */
std::map<std::string, std::string> ObtainAllTickerValues(std::string api_key,
																												 std::string ticker, std::string file_path);

/*
 * Function for obtaining intraday prices to graph for stocks
 */
std::map<std::string, std::string> ObtainTickerIntraday(std::string api_key, std::string ticker,
																												std::string file_path, int day_range, int time_interval);

/*
 * Function for obtaining the current system date and time formatted to use for API requests
 */
std::string CurrentDateTime();

/*
 * Function for obtaining news data for a ticker
 */
std::vector<std::string> ObtainTickerNews(std::string api_key, std::string ticker, std::string file_path, int items);
