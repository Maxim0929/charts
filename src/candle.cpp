#include "candle.h"


// constructors
Candle::Candle() : open(0), close(0), min(0), max(0), width(0), height(0), interval(Interval::HOUR){}

Candle::Candle(float open, float close, float min, float max) : 
open(open), close(close), min(min), max(max), width(0), height(0), interval(Interval::HOUR){
    line.setSize(Vector2f(1, max - min));
    body.setSize(Vector2f(10, abs(close - open)));
}


// geters
float Candle::getOpen(){ return open;}
float Candle::getClose(){ return close;}

float Candle::getMin(){ return min;}
float Candle::getMax(){ return max;}

float Candle::getWidth(){ return width;}
float Candle::getHeight(){ return height;}


//seters
void Candle::setOpen(float open){ this->open = open;}
void Candle::setClose(float close){ this->close = close;}

void Candle::setMin(float min){ this->min = min;}
void Candle::setMax(float max){ this->max = max;}

void Candle::setWidth(float width){ this->width = width;}
void Candle::setHeight(float height){ this->height = height;}


// other
float Candle::relativeChange(){
    return 0;
}
float Candle::absuluteChange(){
    return 0;
}

