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
	fin_graph->add(ofRandom(-100,100));
	
	// Move the graph off screen to hide it if the gui is collapsed
	if (gui_expanded && !type_dropdown_expanded) {
		fin_graph->setPosition(x_position_, y_position_);
	} else if (gui_expanded && type_dropdown_expanded) {
		fin_graph->setPosition(x_position_, y_position_ + 54);
	} else {
		fin_graph->setPosition(-1000, -1000);
	}
}
