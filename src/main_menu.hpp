//
//  main_menu.hpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/7/19.
//

#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class MenuGui {
public:
	/*
	 * Default constructor
	 */
	MenuGui();
	
	/*
	 * Method for setting up the gui
	 */
	void SetupMenuGui();
	
	// Event listeners
	void OnDropdownEvent(ofxDatGuiDropdownEvent e);
	
	// Gui elements
	ofxDatGui* menu_gui;
	ofxDatGuiDropdown* panel_type_dropdown;
	ofxDatGuiDropdown* theme_dropdown;
};
