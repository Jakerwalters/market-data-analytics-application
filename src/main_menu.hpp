//
//  main_menu.hpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/7/19.
//

#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

// Main menu is not used in the current build of the application
class MenuGui {
public:
	MenuGui();
	
	// Method for adding properties to all the elements which comprise the menu gui
	void SetupMenuGui();
	
	// Event listeners
	void OnDropdownEvent(ofxDatGuiDropdownEvent e);
	
	// Gui elements
	ofxDatGui* menu_gui;
	ofxDatGuiDropdown* panel_type_dropdown;
	ofxDatGuiDropdown* theme_dropdown;
	
private:
	const int kMenuWidth = 240;
};
