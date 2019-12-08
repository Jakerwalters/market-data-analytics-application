//
//  data_panel.cpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/7/19.
//

#include "data_panel.hpp"
#include "data_request.hpp"

DataPanel::DataPanel() {
	// Set the ticker type to stock by default
	this->ticker_type_ = "Stock";
}

void DataPanel::SetupDataPanelGui() {
	// Create gui
	data_panel_gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	data_panel_gui->addHeader("Data Panel")->setDraggable(false);
	data_panel_gui->addFooter();
	data_panel_gui->getFooter()->setLabelWhenExpanded("Minimize Data Panel");
	data_panel_gui->getFooter()->setLabelWhenCollapsed("Maximize Data Panel");
	data_panel_gui->addBreak();
	data_panel_gui->setWidth(400);
	
	// Create dropdown menu for choosing to create a data panel for a stock or crypto
	std::vector<std::string> panel_options = {"Stock", "Crypto"};
	panel_type_dropdown = data_panel_gui->addDropdown("Select Panel Type", panel_options);
	panel_type_dropdown->onDropdownEvent(this, &DataPanel::OnDropdownEvent);
	data_panel_gui->addBreak();
	
	// Create a text input for entering a ticker for a stock or crypto
	ticker_input = data_panel_gui->addTextInput("Ticker Input");
	data_panel_gui->addBreak();
	
	// Create a button to intiate an API request for the ticker entered
	search_button = data_panel_gui->addButton("Search");
	search_button->onButtonEvent(this, &DataPanel::OnButtonEvent);
	data_panel_gui->addBreak();
	
	// Create a button to clear the data panel
	clear_button = data_panel_gui->addButton("Clear");
  clear_button->onButtonEvent(this, &DataPanel::OnButtonEvent);
	data_panel_gui->addBreak();
	
	// Create a label to display the information acquired from the API request
	info_label = data_panel_gui->addLabel("Data Here");
	data_panel_gui->addBreak();
}

void DataPanel::OnDropdownEvent(ofxDatGuiDropdownEvent e) {
	if (e.target == panel_type_dropdown) {
		// Numbers correspond to index of the element in the dropdown
		if (e.child == 0) {
			this->ticker_type_ = "Stock";
			std::cout << e.child << std::endl;
		} else if (e.child == 1) {
			this->ticker_type_ = "Crypto";
		}
	}
}

void DataPanel::OnButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == search_button && this->ticker_type_ == "Stock") {
		// Execute a data request for the ticker entered by the user
		std::string api_key = "1bMckVuNko95sGvwrTiHHzSLssOpx6MIKtdufXvbLeKAMfwrNje9QFjjwTl5";
		std::string file_path = "/Users/jakewalters/documents/FantasticFinaleProject/fantastic-finale-Jakerwalters/bin/datafile.json";
		std::map<std::string, std::string> values = ObtainAllTickerValues(api_key, ticker_input->getText(), file_path);
		
		// Output the data to the output label
		std::string output;
		
		for (auto itr = values.begin(); itr != values.end(); itr++) {
			output += itr->first + ": " + itr->second + "\n";
		}
		
		info_label->setLabel(output);
	} else if (e.target == clear_button) {
		ticker_input->setText("");
		info_label->setLabel("");
	}
}
