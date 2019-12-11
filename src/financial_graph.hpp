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
	FinancialGraph();
	
	// Method for setting the attributes of the graph
	void SetupFinancialGraph(int x_position, int y_position, int width, int height);
	
	// Method for drawing the graph which already contains information
	void DrawFinancialGraph();
	
	// Overloaded method for drawing a graph with information obtained by calling for an API request
	// using the given parameters
	bool DrawFinancialGraph(std::string api_key, std::string ticker, std::string file_path,
													int day_range, int time_interval, double open_price);
	
	// Method for updating the graph
	void UpdateFinancialGraph(bool gui_expanded, bool type_dropdown_expanded);
	
	// Method for clearing the graph
	void ClearFinancialGraph();

	// Gui elements
	ofxGraph* fin_graph;
	
private:
	int x_position_;
	int y_position_;
};
