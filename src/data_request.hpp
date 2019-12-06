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


void RequestData(std::string data_url, std::string file_path);

std::string ObtainTickerValue(std::string api_key, std::string ticker, std::string key, std::string file_path);

std::map<std::string, std::string> ObtainAllTickerValues(std::string api_key, std::string ticker, std::string file_path);
