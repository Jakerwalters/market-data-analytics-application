## Market Data Analytics App
![panels example](https://github.com/CS126FA19/fantastic-finale-Jakerwalters/blob/master/README_assets/Screen%20Shot%202019-12-11%20at%202.30.36%20PM.png)
## Dependencies
* Xcode 11+
* [OpenFrameworks](https://openframeworks.cc/download/) 0.11.0
## API Keys Needed
* [World Trading Data API](https://www.worldtradingdata.com/)
* [Stock News API](https://stocknewsapi.com/)
## MacOS Install Instructions
* Click Download ZIP in top right corner
![zip download](https://github.com/CS126FA19/fantastic-finale-Jakerwalters/blob/master/README_assets/Screen%20Shot%202019-12-11%20at%207.08.20%20PM.png)

* Copy and paste the folders ofxDatGui-master and ofxGraph-master into the addons folder of the OpenFrameworks directory
* **Note: you must use the addons specifically in this repository as they contain extra functions that their respective  public release versions do not**

* to the file ofxDatGui.hpp add the function
```C++
bool getExpanded();
```

* to the file ofxDatGui.cpp add the function

```C++
bool ofxDatGui::getExpanded() {
  return mExpanded;
}
```

* to the file ofxDatGuiGroups.h add the function
```C++
bool getExpanded() {return mIsExpanded;}
```

* to the file ofxGraph.cpp add set the following values
```C++
max_length_of_data = 450; 
panel.add(slider_bufsize.setup("BufSize", 450, 32, 512));
```

* Launch OpenFrameworks project generator
    * Set Project Name to "fantastic-finale-Jakerwalters"
    * Set Project Path to the directory where you have saved the file
    * Make sure to include the following addons:
        * ofxDatGui-master
        * ofxGraph-master
        * ofxGui
        * ofxXmlSettings    
        
![generator](https://github.com/CS126FA19/fantastic-finale-Jakerwalters/blob/master/README_assets/Screen%20Shot%202019-12-11%20at%207.17.47%20PM.png)

* Locate the file user_information.txt in fantastic-finale-Jakerwalters/bin/
* Open the file
    * On the first line paste your API key for [World Trading Data API](https://www.worldtradingdata.com/)
    * On the second line paste your API key for [Stock News API](https://stocknewsapi.com/)
    * On the third line paste the exact file path to datafile.json also located in fantastic-finale-Jakerwalters/bin/
    
* Open the project in Xcode and run
## How to Use
* To use the application simply enter a stock ticker into the input box labeled "ticker input" and click the search button

## Features
* Various information points regarding tickers such as 
    * Current Price
    * Day High
    * Day Low
* Chart displaying minute by minute percent change information 
* Related news stories with links
