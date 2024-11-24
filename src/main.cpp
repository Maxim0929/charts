#include <iostream>
#include <SFML/Graphics.hpp>
#include <curl/curl.h>

#include "chart.h"

using namespace std;
using namespace sf;



RenderWindow window(VideoMode(1200, 700), "chart");
Chart bitcoin(5, 10, 40000, 100000);

int main(){
    CURL* curl = curl_easy_init();
    CURLcode result;

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
        result = curl_easy_perform(curl);

        if(result == CURLE_OK){
            curl_easy_cleanup(curl);
             
        }else{
            cerr << "Error: " << curl_easy_strerror(result);
        }


    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(31,31,31));
        
        window.display();
    }
}