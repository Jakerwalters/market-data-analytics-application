 ## Development Log
 * **11/16/19** Created project repository 
 
 * **11/18/19** Began project setup
    * Started development log
    * Cloned repository
    * Generated OFX files
    * Created basic README.md
    * Obtained API keys
    * Set up JSON library header file
    * Included ofxGraph addon

* **11/19/19** Continued project setup and tested demo data acqusition
    * Added Catch2 hpp file to project
    * Created new target for running tests, but there is a problem with libraries not found
    * Found out how to obtain http data using libcurl library
    * Found out how to link libcurl in project
    * Used libcurl to query the demo data for the web APIs I will be using

* **11/25/19** Successfully added testing functionality and began UI design
    * Used piazza post to get catch finally working with project
    * Copied over project proposal to this repository
    * Began sketching preliminary designs for the dashboard UI

* **11/27/19** Researched libcurl commands and file processing
    * Add example ofxGraph to test functionality
    * Decided to use a system which will request JSON, save it in a file, and read the file to parse the JSON
    * Tested functionality for executing a curl GET request and saving the content in a file

* **11/28/19** Researched gui design 
    * Found out that ofxGui is severely lacking key features I need for my project
    * Decided to use ofxDatGui addon which provides much richer gui elements to work with
    * Read through a lot of ofxDatGui documentation
    * Found out that ofxDatGui uses something called "panels" as the main basis for building GUIs
    * Sketched new designs which I will be able to implement using ofxDatGui

* **12/3/19** Continued work with API requests
    * Found out that OpenFrameworks has a built in util for nlohmann JSON and libcurl which are much easier to use
    * Simplified my HTTP GET requests down to 3 lines of code 
    * Spent many hours trying to get the JSON to deserialize properly with no success, I will have to go to office hours for this most likely 
    
* **12/5/19** Began implementation of gui and more work with API requests
    * Created simple gui to take a user's input for a ticker with a button to execute an API request and a button to clear
    * Set up a custom header file for handling API requests and JSON parsing so I can make simple calls to a couple methods when I want to display data in my gui
    * My next goals are to write a few tests for my API requests, begin displaying my parsed data in my gui, and begin creation of graphs using ofxGraph
    
* **12/6/19** Test writing and repo cleanup
    * Discovered that my testing target and testing files were somehow deleted from my project and wouldn't pull correctly from the repository
    * Recreated the testing target and files with many complications due to Xcode's file management system
    * Wrote simple tests for executing data requests to World Trading Data API
    * Deleted the many useless files from earlier accidental duplicate commits and mysteriously deleted testing target
    
* **12/7/19** Gui design and implementation
    * Decided to implement a panel based gui which will consist of multiple panels of information
    * Found out that dynamic creation and deletion of components is not supported by my gui library, so I will have to work around this by utilizing the ability to hide and display panels as separate gui's
    * Created different classes and header files for loading in different types of custom gui's, right now I have built the main menu and the information panels
    * Experimented with various layouts of my panels and window sizing to see what I think works best, but ultimately decided on fixing the screen dimensions
