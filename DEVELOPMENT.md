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
        * will ask about this in office hours tomorrow
    * Found out how to obtain http data using libcurl library
    * Found out how to link libcurl in project
    * Used libcurl to query the demo data for the web APIs I will be using

* **11/25/19** Successfully added testing functionality and began UI design
    * Used piazza post to get catch finally working with project
    * Copied over project proposal to this repository
    * Began sketching preliminary designs for the dashboard UI

* **11/27/19** Research libcurl commands and file processing
    * Add example ofxGraph to test functionality
    * Decided to use a system which will request JSON, save it in a file, and read the file to parse the JSON
    * Tested functionality for executing a curl GET request and saving the content in a file
