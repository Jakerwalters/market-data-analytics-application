//
//  financial_graph.cpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/8/19.
//

#include "financial_graph.hpp"

FinancialGraph::FinancialGraph() {
	// Set the default position of the graph to (0, 0)
	this->x_position_ = 0;
	this->y_position_ = 0;
}

void FinancialGraph::SetupFinancialGraph(int x_position, int y_position, int width, int height) {
	// Keep track of the home position of the graph
	this->x_position_ = x_position;
	this->y_position_ = y_position;
	
	ofxGuiSetFont(ofToDataPath("ofxGraph/DIN_Alternate_Bold.ttf"), 10);
	fin_graph = new ofxGraph();
	fin_graph->setup("");
	fin_graph->setDx(1.0);
	fin_graph->setColor(ofColor::white);
	fin_graph->setSize(width, height);
	fin_graph->setPosition(x_position, y_position);
}

void FinancialGraph::DrawFinancialGraph() {
	fin_graph->draw();
}

void FinancialGraph::UpdateFinancialGraph(bool gui_expanded, bool type_dropdown_expanded) {
	// Move the graph off screen to hide it if the gui is collapsed
	if (gui_expanded && !type_dropdown_expanded) {
		fin_graph->setPosition(x_position_, y_position_);
	} else if (gui_expanded && type_dropdown_expanded) {
		fin_graph->setPosition(x_position_, y_position_ + 54);
	} else {
		fin_graph->setPosition(-1000, -1000);
	}
}

void FinancialGraph::DrawFinancialGraph(std::string api_key, std::string ticker, std::string file_path, int day_range, int time_interval, double open_price) {
	std::map<std::string, std::string> values = ObtainTickerIntraday(api_key, ticker, file_path, day_range, time_interval);
	fin_graph->add(0);
	
	for (auto itr = values.begin(); itr != values.end(); itr++) {
		fin_graph->add((1 - (std::stod(itr->second) / open_price)) * 100);
	}
}
