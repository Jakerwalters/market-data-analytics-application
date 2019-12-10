//
//  financial_graph.hpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/8/19.
//

#pragma once

#include "ofMain.h"
#include "ofxGraph.h"
#include "data_request.hpp"

class FinancialGraph {
public:
	/*
	 * Default constructor
	 */
	FinancialGraph();
	
	/*
	 * methods for setting up the graph
	 */
	void SetupFinancialGraph(int x_position, int y_position, int width, int height);
	void DrawFinancialGraph();
	void UpdateFinancialGraph(bool gui_expanded, bool type_dropdown_expanded);
	void DrawFinancialGraph(std::string api_key, std::string ticker, std::string file_path, int day_range, int time_interval, double open_price);

	// graph element
	ofxGraph* fin_graph;
	
private:
	int x_position_;
	int y_position_;
};
