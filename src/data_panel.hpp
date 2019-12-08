//
//  data_panel.hpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/7/19.
//

#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class DataPanel {
public:
	/*
	 * Default constructor
	 */
	DataPanel();
	
	/*
	 * method for setting up the gui
	 */
	void SetupDataPanelGui(int x, int y);
	void DrawPanel();
	void UpdatePanel();
	
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
	
private:
	std::string ticker_type_;
};
