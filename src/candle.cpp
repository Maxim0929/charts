#include "candle.h"


// constructors
Candle::Candle() : open(0), close(0), width(0), height(0){}

Candle::Candle(float open, float close) : 
open(open), close(close), width(0), height(0){

    body.setSize(Vector2f(width, height));
    body.setOrigin(Vector2f(0, 0));
    if(open > close) body.setFillColor(Color(187, 13, 13));
    else body.setFillColor(Color(13, 187, 13));
}


// geters
float Candle::getOpen(){ return open;}
float Candle::getClose(){ return close;}

float Candle::getWidth(){ return width;}
float Candle::getHeight(){ return height;}

RectangleShape& Candle::getBody(){return body; }


//seters
void Candle::setOpen(float open){ 
    this->open = open;
    if(open > close) body.setFillColor(Color(187, 13, 13));
    else body.setFillColor(Color(13, 187, 13));
}
void Candle::setClose(float close){ 
    this->close = close;
    if(open > close) body.setFillColor(Color(187, 13, 13));
    else body.setFillColor(Color(13, 187, 13));
}

void Candle::setWidth(float width){ 
    this->width = width;
    body.setSize(Vector2f(width, height));
}
void Candle::setHeight(float height){ 
    this->height = height;
    body.setSize(Vector2f(width, height)); 
}

void Candle::setPos(float x, float y){
    body.setPosition(x, y);
}

// other
float Candle::relativeChange(){
    return 0;
}
float Candle::absuluteChange(){
    return 0;
}



