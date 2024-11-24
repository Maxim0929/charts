#include <iostream>
#include <SFML/Graphics.hpp>
#include "chart.h"

using namespace std;
using namespace sf;



RenderWindow window(VideoMode(1200, 700), "chart");

int main(){

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