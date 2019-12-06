//
//  tests.cpp
//  fantastic-finale-tests
//
//  Created by Jake Walters on 12/6/19.
//

#include "catch.hpp"
#include "data_request.hpp"

TEST_CASE("a single ticker value request works for valid parameters") {
	std::string api_key = "1bMckVuNko95sGvwrTiHHzSLssOpx6MIKtdufXvbLeKAMfwrNje9QFjjwTl5";
	std::string ticker = "SNAP";
	std::string key = "day_high";
	std::string file_path = "/Users/jakewalters/documents/FantasticFinaleProject/fantastic-finale-Jakerwalters/bin/datafile.json";
	
	REQUIRE(ObtainTickerValue(api_key, ticker, key, file_path) == "14.95");
}

TEST_CASE("a request for all ticker values works for valid parameters") {
	std::string api_key = "1bMckVuNko95sGvwrTiHHzSLssOpx6MIKtdufXvbLeKAMfwrNje9QFjjwTl5";
	std::string ticker = "AAPL";
	std::string file_path = "/Users/jakewalters/documents/FantasticFinaleProject/fantastic-finale-Jakerwalters/bin/datafile.json";
	std::map<std::string, std::string> data_pairs = ObtainAllTickerValues(api_key, ticker, file_path);
	std::vector<std::string> keys;
	std::vector<std::string> values;
	
	for (auto itr = data_pairs.begin(); itr != data_pairs.end(); ++itr) {
		keys.push_back(itr->first);
		values.push_back(itr->second);
		std::cout << itr->first << ": " << itr->second << std::endl;
	}
	
	REQUIRE(keys.at(0) == "52_week_high");
	REQUIRE(values.at(0) == "269.48");
	REQUIRE(keys.at(1) == "52_week_low");
	REQUIRE(values.at(1) == "142.00");
}
