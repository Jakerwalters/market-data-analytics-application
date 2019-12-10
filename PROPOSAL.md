<!-- Write your proposal here! Make sure to use properly-formatted Markdown! -->
### Project & Background Knowledge
The project that I will be working on is a market data analytics platform. One of my favorite hobbys is trading in the stock and cryptocurrency markets. This is what ultimately led to me pursuing my major of Computer Science + Economics. I have used many different trading platforms including ETrade, TD Ameritrade, and Robinhood. All of these platforms are unique and have their upsides and downsides in terms of both design and functionality. I have always wished I could combine the things that I like about each of them into one platform which would be perfect for me and my objectives as a trader. My motivation for completion of this project comes from a couple different sources. Firstly, this is something that I could actually use daily to streamline my market research process. More importantly, this is a great type of project to combine many different skills which I have acquired to build a complete product. To complete this project I will need to leverage my knowledge of External Libraries, APIs, JSON, and GUI Design. Ultimately, this is a project that I will be proud of and may continue to develop beyond this class.  

### External Libraries and APIs
* **External Libraries**
  * ofxGraph
    * https://github.com/TetsuakiBaba/ofxGraph
    * This add-on allows for easy creation of graphs and comes with many nice features for analyzing the graphs. This is what I will be using to create visualizations of market data. I would prefer to use the QT framework as it has graphing libraries specifically made for financial data. But since we are using OpenFrameworks, this is the next best thing.
  * JSON for Modern C++
    * https://github.com/nlohmann/json
    * This is an intuitive JSON parsing library which is contained in a single header file. I have chosen this library as it is built for C++11 and supports Clang on OSX. This libarary is necessary to parse all of the data I will be obtaining through various API requests.
* **APIs**
  * World Free Trading Data
    * https://www.worldtradingdata.com/
    * This API will provide access to stock market data. This API provides many key features such as real time market and historical data which will be the main focus of this application.
  * CryptoCompare
    * https://min-api.cryptocompare.com/
    * This API will provide access to all cryptocurrency data. This API provides all the pricing features I could possibly need as well as extra features such as top coins and exchanges which I may also choose to display. 
  * Stock News API
    * https://stocknewsapi.com/
    * This API will provide links to financial news articles which reference certain tickers or coins. These articles can be placed alongside numerical information to aid decision making.
  
### Timeline
* **Week 1**
  * Add ofxGraph and JSON for Modern C++ libraries to project
  * Obtain API keys 
  * Add ability to obtain market data for a specified ticker 
* **Week 2**
  * Create main dashboard user interface 
  * Create user interface to search for a ticker 
  * Create user interface to display ticker data
* **Week 3**
  * Continue to implement dashboard
  * Implement functions for requesting and storing data for use from API
  * Implement functionality for chart generation from data
* **Week 4**
  * Add ability to view news articles related to a ticker from the dashboard
  * Add more options to the charts
  * Finalize implementation of user interface
  
### Stretch Goals
#### Crypto Support
Cryptocurrencies and stocks go hand in hand these days, so support for them would be great. However, this requires a lot of extra work as I will have to create even more functions for requesting data from the cryptocompare API. I will also have to create new functions for adding data to the charts because the data supplied by the API does not include the same points as those supplied by the WorldTradingData API I am using for stocks. Overall, this is something I would love to have in the application and I know I could definitely do it if I have the time.

#### Use of a Database
In order to implement the login system properly I need the ability to save usernames, password, and relavent account information. This is attainable through using text file IO, however this is definitely not ideal. I would rather use a database to store this information. However, my experience using databases is quite limited. Through limited research I have found that SQLite is a good option as it is a serverless database which means that it would be practical for the type of application that I am building. However, it seems a little tricky to use and I havent found much information regarding how to set it up with my specific development environment. 

#### Options Support
Options are a type of stock derivative which are used for a variety of reasons. I would love to add the ability to obtain options contract pricing, expiry dates, greeks, etc. for various tickers. If I were to do this I would also need to create user a interface for viewing all pertinent option information. This is more information which could be displayed on the dashboard.
