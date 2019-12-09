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
	this->expanded_ = true;
}

void DataPanel::SetupDataPanelGui(int x, int y) {
	// Create gui
	data_panel_gui = new ofxDatGui();
	data_panel_gui->setPosition(x, y);
	data_panel_gui->addHeader("Data Panel")->setDraggable(false);
	data_panel_gui->addFooter();
	data_panel_gui->getFooter()->setLabelWhenExpanded("Minimize Data Panel");
	data_panel_gui->getFooter()->setLabelWhenCollapsed("Maximize Data Panel");
	data_panel_gui->addBreak();
	data_panel_gui->setWidth(400);
	data_panel_gui->setAutoDraw(false);
	
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
	for (int index = 0; index < 50; index++) {
		data_panel_gui->addBreak();
	}
	
	// Create a labels to display the information acquired from the API request
	name_label = data_panel_gui->addLabel("Name: ");
	data_panel_gui->addBreak();
	price_label = data_panel_gui->addLabel("Current Price: ");
	data_panel_gui->addBreak();
	day_high_label = data_panel_gui->addLabel("Day High: ");
	data_panel_gui->addBreak();
	day_low_label = data_panel_gui->addLabel("Day Low: ");
	data_panel_gui->addBreak();
	year_high_label = data_panel_gui->addLabel("Year High: ");
	data_panel_gui->addBreak();
	year_low_label = data_panel_gui->addLabel("Year Low: ");
	data_panel_gui->addBreak();
	day_change_label = data_panel_gui->addLabel("Day Change $: ");
	data_panel_gui->addBreak();
	day_change_pct_label = data_panel_gui->addLabel("Day Change %: ");
	data_panel_gui->addBreak();
	
	// Create graph to visualize information
	fin_graph = new FinancialGraph();
	fin_graph->SetupFinancialGraph(x + 10, 150, 380, 190);
}

void DataPanel::OnDropdownEvent(ofxDatGuiDropdownEvent e) {
	if (e.target == panel_type_dropdown) {
		// Numbers correspond to index of the element in the dropdown
		if (e.child == 0) {
			this->ticker_type_ = "Stock";
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
		std::string user_input = ticker_input->getText();
		
		// Output the data to the output label
		std::string output;
		
		for (auto itr = values.begin(); itr != values.end(); itr++) {
			output += itr->first + ": " + itr->second + "\n";
		}
		
		name_label->setLabel("Name: " + ObtainTickerValue(api_key, user_input, "name", file_path));
		price_label->setLabel("Current Price: " + ObtainTickerValue(api_key, user_input, "price", file_path));
		day_high_label->setLabel("Day High: " + ObtainTickerValue(api_key, user_input, "day_high", file_path));
		day_low_label->setLabel("Day Low: " + ObtainTickerValue(api_key, user_input, "day_low", file_path));
		year_high_label->setLabel("Year High: " + ObtainTickerValue(api_key, user_input, "52_week_high", file_path));
		year_low_label->setLabel("Year Low: " + ObtainTickerValue(api_key, user_input, "52_week_low", file_path));
		day_change_label->setLabel("Day Change $: " + ObtainTickerValue(api_key, user_input, "day_change", file_path));
		day_change_pct_label->setLabel("Day Change %: " + ObtainTickerValue(api_key, user_input, "change_pct", file_path));
	} else if (e.target == clear_button) {
		ticker_input->setText("");
		name_label->setLabel("Name: ");
		price_label->setLabel("Current Price: ");
		day_high_label->setLabel("Day High: ");
		day_low_label->setLabel("Day Low: ");
		year_high_label->setLabel("Year High: ");
		year_low_label->setLabel("Year Low: ");
		day_change_label->setLabel("Day Change $: ");
		day_change_pct_label->setLabel("Day Change %: ");
	}
}

void DataPanel::DrawPanel() {
	data_panel_gui->draw();
	fin_graph->DrawFinancialGraph();
}

void DataPanel::UpdatePanel() {
	data_panel_gui->update();
	
	// Hide the graph when the gui is collapsed
	if (data_panel_gui->getExpanded() && !panel_type_dropdown->getExpanded()) {
		fin_graph->UpdateFinancialGraph(true, false);
	} else if (data_panel_gui->getExpanded() && panel_type_dropdown->getExpanded()) {
		// Shift graph down when panel type dropdown is expanded
		fin_graph->UpdateFinancialGraph(true, true);
	} else {
		// Automatically close dropdown and hide graph when gui is collapsed
		fin_graph->UpdateFinancialGraph(false, false);
		panel_type_dropdown->collapse();
	}
}
