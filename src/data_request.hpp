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
#include "ofURLFileLoader.h"
#include "json.hpp"

/*
 * Function for initiating a request to a web API and saving the contents in a file
 */
void RequestData(std::string data_url, std::string file_path);

/*
 * Function for obtaining a specific data value for a specified key from a ticker
 */
std::string ObtainTickerValue(std::string api_key, std::string ticker, std::string key, std::string file_path);

/*
 * Function for obtaining all data values from a ticker
 */
std::map<std::string, std::string> ObtainAllTickerValues(std::string api_key, std::string ticker, std::string file_path);


