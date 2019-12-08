//
//  main_menu.cpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/7/19.
//

#include "main_menu.hpp"

MenuGui::MenuGui() {
	
}

void MenuGui::SetupMenuGui() {
	// Create gui
	menu_gui = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
	menu_gui->addHeader("Main Menu")->setDraggable(false);
	menu_gui->addFooter();
	menu_gui->getFooter()->setLabelWhenExpanded("Minimize Main Menu");
	menu_gui->getFooter()->setLabelWhenCollapsed("Maximize Main Menu");
	menu_gui->addBreak();
	menu_gui->setWidth(400);
	
	// Create dropdown menu for choosing to create a new stock or crypto panel
	std::vector<std::string> panel_options = {"Stock", "Crypto"};
	panel_type_dropdown = menu_gui->addDropdown("Select Panel Type", panel_options);
	panel_type_dropdown->onDropdownEvent(this, &MenuGui::OnDropdownEvent);
	menu_gui->addBreak();
	
	// Create dropdown menu for choosing a theme
	std::vector<std::string> theme_options = {"Smoke", "Wireframe", "Midnight", "Aqua", "Charcoal", "Autumn", "Candy"};
	theme_dropdown = menu_gui->addDropdown("Select Theme Type", theme_options);
	theme_dropdown->onDropdownEvent(this, &MenuGui::OnDropdownEvent);
	menu_gui->addBreak();
}

void MenuGui::OnDropdownEvent(ofxDatGuiDropdownEvent e) {
	if (e.target == theme_dropdown) {
		// Numbers correspond to index of the element in the dropdown
		if (e.child == 0) {
			menu_gui->setTheme(new ofxDatGuiThemeSmoke());
		} else if (e.child == 1) {
			menu_gui->setTheme(new ofxDatGuiThemeWireframe());
		} else if (e.child == 2) {
			menu_gui->setTheme(new ofxDatGuiThemeMidnight());
		} else if (e.child == 3) {
			menu_gui->setTheme(new ofxDatGuiThemeAqua());
		} else if (e.child == 4) {
			menu_gui->setTheme(new ofxDatGuiThemeCharcoal());
		} else if (e.child == 5) {
			menu_gui->setTheme(new ofxDatGuiThemeAutumn());
		} else if (e.child == 6) {
			menu_gui->setTheme(new ofxDatGuiThemeCandy());
		}
	}
}
