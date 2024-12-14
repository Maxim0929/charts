#define MAX_CANDLE 300
#define SIDE_SPACE 20 
#include "chart.h"
#include <cmath>
using namespace std;

Chart::Chart() : field(nullptr), 
left(0), right(0), PrMin(0), PrMax(0), candleHeight(0), candleWidth(0), space(0), size(0), topBottomSpace(50){}


Chart::Chart(time_t left, time_t right, float PrMin, float PrMax) : 
left(left), right(right), candleHeight(0), candleWidth(0), space(0), size(right - left), topBottomSpace(50){
    this->PrMin = PrMin - (PrMax - PrMin) / 100 * 5;
    this->PrMax = PrMax + (PrMax - PrMin) / 100 * 5;

    if(right - left > MAX_CANDLE) std::cerr << "Chart can not have more than " << MAX_CANDLE << " candles" << std::endl;
    else if(size < 0) std::cerr << "Chart::right has to be bigger then Chart::left" << std::endl;
    else field = new Candle[size];
}

Chart::~Chart(){
    delete[] field;
}

void Chart::initCandle(float prices[], RenderWindow& window){
    candleWidth = ((window.getSize().x - SIDE_SPACE * 2) * 4.0) / (4.0*size + size+1.0); // space = width / 4; windowWidth = size * width + (size + 1) * space
    space = candleWidth / 4; // space = width / 4

    int cnt = 0;
    for(Candle* i = field; cnt < size; ++i){
        i->setOpen(prices[cnt]);
        i->setClose(prices[cnt + 1]);

        i->setWidth(candleWidth);
        candleHeight = abs(prices[cnt] - prices[cnt + 1]) * (window.getSize().y  / (PrMax - PrMin)); // candlePX = candle$ * (windowPX / window$)
        i->setHeight(candleHeight);
        ++cnt;
    }
    setCandlePos(window);
}

void Chart::setCandlePos(RenderWindow& window){
    float x = space + SIDE_SPACE;
    for(int i = 0; i < size; ++i){
        float y = window.getSize().y / (PrMax - PrMin) * (PrMax - fmax(field[i].getOpen(), field[i].getClose()));
        // pxCandle = c * (PrMax - PrMin - PrCandle) c = pxMax / (PrMax - PrMin)
        field[i].setPos(x, y);
        x += candleWidth + space;
        //cout << "y: " << y << "\t x: " << x<< endl;
    }
}

void Chart::draw(RenderWindow& window){
    for(int i = 0; i < size; ++i){
        window.draw(field[i].getBody());
    }
}



void Chart::newChart(float prices[], RenderWindow& window, time_t left, time_t right, float PrMin, float PrMax){
    this->PrMin = PrMin - (PrMax - PrMin) / 100 * 5;
    this->PrMax = PrMax + (PrMax - PrMin) / 100 * 5;
    size = right - left;

    if(right - left > MAX_CANDLE) std::cerr << "Chart can not have more than " << MAX_CANDLE << " candles" << std::endl;
    else if(size < 0) std::cerr << "Chart::right has to be bigger then Chart::left" << std::endl;
    else{
        delete[] field;
        field = new Candle[size];
    }

    initCandle(prices, window);
}
