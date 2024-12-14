#define DIS 24*60*60*12
#define MAX_CANDLE 300
#include <iostream>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <math.h>
#include <fstream>

#include "chart.h"

using namespace std;
using namespace sf;
using namespace nlohmann;


size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userData);
size_t getPrice(string name, time_t from, float* price, string vs_currency="usd");
string makeResponse(string URL);
void drawAll(RenderWindow& window, Chart& coin);


namespace fmath{
    float fmin(float arr[], size_t MaxSize);
    float fmax(float arr[], size_t MaxSize);
}

RenderWindow window(VideoMode(1200, 700), "chart");



int main(){

    cout << "Bitcoin price." << endl;
    float pr[MAX_CANDLE] = {};
    time_t fromInHour = 24 * 20006; //20071
    size_t prSize = getPrice("bitcoin", fromInHour * 60 * 60, pr);// 01.01.2024 60 * 60 * 24 * 19723
    Chart bitcoin(fromInHour, fromInHour + prSize, fmath::fmin(pr, MAX_CANDLE), fmath::fmax(pr, MAX_CANDLE));
    bitcoin.initCandle(pr, window);

    drawAll(window, bitcoin);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            
            // mouse
            if(event.type == Event::MouseWheelScrolled){
                fromInHour += event.mouseWheelScroll.delta;
                prSize = getPrice("bitcoin", fromInHour * 60 * 60, pr);
                if(prSize != 0){
                    bitcoin.newChart(pr, window, fromInHour, fromInHour + prSize, fmath::fmin(pr, MAX_CANDLE), fmath::fmax(pr, MAX_CANDLE));
                    drawAll(window, bitcoin);
                }
            }
        }


    }
}



size_t getPrice(string name, time_t from, float pr[], string vs_currency){

    string URL = "https://api.coingecko.com/api/v3/coins/" + name
    + "/market_chart/range?vs_currency=" + vs_currency + "&from=" 
    + to_string(from) + "&to=" + to_string(from + DIS);

    

    try{

        json price = json::parse(makeResponse(URL));
        if(price["status"]["error_code"] == 429){
            cerr << "You've exceeded the Rate Limit." << endl;
            return 0;
        }
        price.erase("market_caps");
        price.erase("total_volumes");

        ofstream outFile("price.json");
        outFile << price.dump(1);
        outFile.close();
        int j = 0;
        for(auto i : price["prices"]){
            pr[j] = i[1];
            ++j;
        }
        return j - 1;


    }catch(const json::parse_error& e){
        cerr << "JSON parsin error: " << e.what() << endl;
        return 0;
    }


    return 0;
}

string makeResponse(string URL){
    // initialization 
    CURL* curl = curl_easy_init();
    CURLcode result;
    string responseData;

    if(curl){
        // set options
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        // perform
        result = curl_easy_perform(curl);

        if(result != CURLE_OK){
            cerr << "Error: " << curl_easy_strerror(result) << endl;
            responseData.clear();
        }
        // clean and return
        curl_easy_cleanup(curl);
        return responseData;

        
    }else{
        cerr << "Error by curl_easy_init()" << endl;
        return {};
    }
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userData){
    size_t totalSize = size * nmemb;
    userData->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

float fmath::fmin(float arr[], size_t MaxSize){
    if(MaxSize == 0) return 0; 
    float min = arr[0];
    for(int i = 1; i < MaxSize; ++i){
        if(arr[i] == 0) return min;
        if(arr[i] < min) min = arr[i];
    }
    return min;

}
float fmath::fmax(float arr[], size_t MaxSize){

    if(MaxSize == 0) return 0; 
    float max = arr[0];
    for(int i = 1; i < MaxSize; ++i){
        if(arr[i] > max) max = arr[i];
    }
    return max;

}

void drawAll(RenderWindow& window, Chart& coin){
    window.clear(Color(31,31,31));

    coin.draw(window);
        
    window.display();
}





































