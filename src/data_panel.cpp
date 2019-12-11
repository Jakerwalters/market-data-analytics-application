//
//  data_panel.cpp
//  fantastic-finale-Jakerwalters
//
//  Created by Jake Walters on 12/7/19.
//

#include "data_panel.hpp"
#include "data_request.hpp"

DataPanel::DataPanel() {
	// Set the ticker type to stock by defualt and expand the panel
	this->ticker_type_ = "Stock";
	this->expanded_ = true;
	this->thumbnail_image_url_ = "";
}

void DataPanel::SetEnviromentVariables() {
	// *** CHANGE THIS PATH TO YOUR DIRECTORY ***
  std::string user_info_file_path = "/Users/jakewalters/documents/FantasticFinaleProject/fantastic-finale-Jakerwalters/bin/user_information.txt";
  
  // Load in API keys and path to data file
  // Load values from file
	std::ifstream input(user_info_file_path);
	std::string line;
  std::vector<std::string> user_info;
	
	while (std::getline(input, line)) {
    user_info.push_back(line);
	}
  
	setenv("STOCK_KEY", user_info.at(0).c_str(), 1);
  setenv("NEWS_KEY", user_info.at(1).c_str(), 1);
  setenv("DATA_PATH", user_info.at(2).c_str(), 1);
}

void DataPanel::SetupDataPanelGui(int x, int y) {
	// Set the environment variables to allow API access
	SetEnviromentVariables();
	
	// Create gui
	data_panel_gui = new ofxDatGui();
	data_panel_gui->setPosition(x, y);
	data_panel_gui->addHeader("Data Panel")->setDraggable(false);
	data_panel_gui->addFooter();
	data_panel_gui->getFooter()->setLabelWhenExpanded("Minimize Data Panel");
	data_panel_gui->getFooter()->setLabelWhenCollapsed("Maximize Data Panel");
	data_panel_gui->addBreak();
	data_panel_gui->setWidth(kPanelWidth_);
	data_panel_gui->setAutoDraw(false);
	
	// Create dropdown menu for choosing to create a data panel for a stock or crypto
	std::vector<std::string> panel_options = {"Stock", "Crypto - Not Supported"};
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
	for (int index = 0; index < kGraphSpaces_; index++) {
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
	news_article_label = data_panel_gui->addLabel("News: ");
	
	// Add large break for news section
	for (int index = 0; index < kNewsSpaces_; index++) {
		data_panel_gui->addBreak();
	}
	
	article_thumbnail = new ofImage();
	news_article_link = data_panel_gui->addLabel("Link: ");
	data_panel_gui->addBreak();
	
	// Create graph to visualize information
	zero_axis_left_ = x + 10;
	zero_axis_right_ = x + 390;
	fin_graph = new FinancialGraph();
	fin_graph->SetupFinancialGraph(zero_axis_left_, kGraphYCoordinate_, kGraphWidth_, kGraphHeight_);
	zero_axis = new ofPolyline();
	ToggleGraphAxis(true, false);
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
	std::string user_input = ticker_input->getText();
	
	if (e.target == search_button && this->ticker_type_ == "Stock") {
		if (!user_input.compare("")) {
			ticker_input->setText("Field cannot be empty");
		} else {
			PopulateDataSection();
			PopulateNewsSection();
		}
	} else if (e.target == search_button && this->ticker_type_ == "Crypto") {
		ticker_input->setText("Cryptocurrency support coming soon");
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
		fin_graph->ClearFinancialGraph();
	}
}

void DataPanel::DrawPanel() {
	data_panel_gui->draw();
	fin_graph->DrawFinancialGraph();
	zero_axis->draw();
	DrawThumbnail();
}

void DataPanel::DrawThumbnail() {
	if (article_thumbnail->isAllocated() && !panel_type_dropdown->getExpanded()) {
		article_thumbnail->draw(zero_axis_left_ + 130, kThumbnailYCoordinate_,
														kThumbnailWidth_, kThumbnailHeight_);
	} else if (article_thumbnail->isAllocated() && panel_type_dropdown->getExpanded()) {
		article_thumbnail->draw(zero_axis_left_ + 130, kThumbnailYCoordinate_ + 55,
														kThumbnailWidth_, kThumbnailHeight_);
	}
}

void DataPanel::UpdatePanel() {
	data_panel_gui->update();
	
	// Hide elements when the gui is collapsed
	if (data_panel_gui->getExpanded() && !panel_type_dropdown->getExpanded()) {
		fin_graph->UpdateFinancialGraph(true, false);
		ToggleGraphAxis(true, false);
		ToggleThumbnail(true);
	} else if (data_panel_gui->getExpanded() && panel_type_dropdown->getExpanded()) {
		// Shift elements down when panel type dropdown is expanded
		fin_graph->UpdateFinancialGraph(true, true);
		ToggleGraphAxis(true, true);
		ToggleThumbnail(true);
	} else {
		// Automatically close dropdown and hide elements when gui is collapsed
		fin_graph->UpdateFinancialGraph(false, false);
		ToggleGraphAxis(false, false);
		ToggleThumbnail(false);
		panel_type_dropdown->collapse();
	}
}

void DataPanel::ToggleGraphAxis(bool panel_enabled, bool dropdown_enabled) {
	if (panel_enabled && !dropdown_enabled) {
		zero_axis->clear();
		zero_axis->addVertex(zero_axis_left_, kGraphHeight_ + 50);
		zero_axis->addVertex(zero_axis_right_, kGraphHeight_ + 50);
	} else if (panel_enabled && dropdown_enabled) {
		zero_axis->clear();
		zero_axis->addVertex(zero_axis_left_, kGraphHeight_ + 104);
		zero_axis->addVertex(zero_axis_right_, kGraphHeight_ + 104);
	} else {
		zero_axis->clear();
	}
}

void DataPanel::ToggleThumbnail(bool panel_enabled) {
	if (panel_enabled) {
		if (thumbnail_image_url_ != "") {
			article_thumbnail->load(thumbnail_image_url_);
		}
	} else {
		article_thumbnail->clear();
	}
}

void DataPanel::PopulateDataSection() {
	std::string api_key = getenv("STOCK_KEY");
	std::string file_path = getenv("DATA_PATH");
	std::string user_input = ticker_input->getText();
	
	// Make sure the user's ticker is all uppercase
	if (!ticker_input->getTextUpperCase()) {
		std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
	}
	
	// Check for invalid ticker input
	std::string open_price_value = ObtainTickerValue(api_key, user_input, "price_open", file_path);
	
	if (!open_price_value.compare("API error")) {
		ticker_input->setText("Invalid ticker try again");
	} else {
		//Draw the graph
		std::cout << "open price: " << open_price_value << std::endl;
		double open_price = std::stod(open_price_value);
		
		if (!(fin_graph->DrawFinancialGraph(api_key, user_input, file_path, 1, 1, open_price))) {
			ticker_input->setText("Intraday API Error");
		}
		
		// Output the data to the output label
		//		name_label->setLabel("Name: " + ObtainTickerValue(api_key, user_input, "name", file_path));
		//		price_label->setLabel("Current Price: " + ObtainTickerValue(api_key, user_input, "price", file_path));
		//		day_high_label->setLabel("Day High: " + ObtainTickerValue(api_key, user_input, "day_high", file_path));
		//		day_low_label->setLabel("Day Low: " + ObtainTickerValue(api_key, user_input, "day_low", file_path));
		//		year_high_label->setLabel("Year High: " + ObtainTickerValue(api_key, user_input, "52_week_high", file_path));
		//		year_low_label->setLabel("Year Low: " + ObtainTickerValue(api_key, user_input, "52_week_low", file_path));
		//		day_change_label->setLabel("Day Change $: " + ObtainTickerValue(api_key, user_input, "day_change", file_path));
		//		day_change_pct_label->setLabel("Day Change %: " + ObtainTickerValue(api_key, user_input, "change_pct", file_path));
	}
}

void DataPanel::PopulateNewsSection() {
	std::string api_key = getenv("NEWS_KEY");
	std::string file_path = getenv("DATA_PATH");
	std::string user_input = ticker_input->getText();
	
	// Make sure the user's ticker is all uppercase
	if (!ticker_input->getTextUpperCase()) {
		std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
	}
	
	// Output the data to the respective labels
	std::vector<std::string> data = ObtainTickerNews(api_key, user_input, file_path, 1);
	
	if (!data.at(0).compare("API error")) {
		ticker_input->setText("Invalid ticker try again");
	} else {
		news_article_link->setLabel("Link: " + data.at(0));
		news_article_label->setLabel("News: " + data.at(1));
		thumbnail_image_url_ = data.at(2);
		
		// Display the article thumbnail
		article_thumbnail->load(thumbnail_image_url_);
	}
}
