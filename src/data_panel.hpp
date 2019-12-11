//
//  data_panel.hpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/7/19.
//

#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "financial_graph.hpp"

class DataPanel {
public:
	DataPanel();
	
	// Method for setting enviroment variables from the user_information file
	void SetEnviromentVariables();
	
	// Method for adding properties to all the elements which comprise the gui
	void SetupDataPanelGui(int x, int y);
	
	// Method for drawing the panel
	void DrawPanel();
	
	// Method for drawing the thumbnail of an image related to a displayed news article
	void DrawThumbnail();
	
	// Method for updating the panel each frame
	void UpdatePanel();
	
	// Method for hiding and shifting the axis at y = 0 on the graph
	void ToggleGraphAxis(bool panel_enabled, bool dropdown_enabled);
	
	// Method for hiding and shifting the news article image thumbnail
	void ToggleThumbnail(bool panel_enabled);
	
	// Method for calling functions in the data_request header to fill data section elements
	void PopulateDataSection();
	
	// Method for calling functions in the data_request header to fill news section elements
	void PopulateNewsSection();
	
	// Event listeners
	void OnDropdownEvent(ofxDatGuiDropdownEvent e);
	void OnButtonEvent(ofxDatGuiButtonEvent e);
	
	// Gui elements
	ofxDatGui* data_panel_gui;
	ofxDatGuiDropdown* panel_type_dropdown;
	ofxDatGuiTextInput* ticker_input;
	ofxDatGuiButton* search_button;
	ofxDatGuiButton* clear_button;
	ofxDatGuiLabel* name_label;
	ofxDatGuiLabel* price_label;
	ofxDatGuiLabel* day_high_label;
	ofxDatGuiLabel* day_low_label;
	ofxDatGuiLabel* year_high_label;
	ofxDatGuiLabel* year_low_label;
	ofxDatGuiLabel* day_change_label;
	ofxDatGuiLabel* day_change_pct_label;
	ofxDatGuiLabel* news_article_label;
	ofxDatGuiLabel* news_article_link;
	ofPolyline* zero_axis;
	FinancialGraph* fin_graph;
	ofImage* article_thumbnail;
	
private:
	std::string ticker_type_;
	bool expanded_;
	int zero_axis_left_;
	int zero_axis_right_;
	std::string thumbnail_image_url_;
	const int kPanelWidth_ = 400;
	const int kGraphSpaces_ = 50;
	const int kNewsSpaces_ = 19;
	const int kGraphWidth_ = 380;
	const int kGraphHeight_ = 190;
	const int kGraphYCoordinate_ = 150;
	const int kThumbnailWidth_ = 120;
	const int kThumbnailHeight_ = 75;
	const int kThumbnailYCoordinate_ = 620;
};
