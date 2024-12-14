#pragma once
#include <SFML/Graphics.hpp>
#include <Math.h>
#include <iostream>

using namespace sf;


class Candle{
private:
    RectangleShape body;

    float open;
    float close;

    float width;
    float height;

public:
    // constructors
    Candle();
    Candle(float open, float close);

    // geters
    float getOpen();
    float getClose();


    float getWidth();
    float getHeight();

    RectangleShape& getBody();


    //seters
    void setOpen(float open);
    void setClose(float close);


    void setWidth(float width);
    void setHeight(float height);

    void setPos(float x, float y);

    //other
    float relativeChange();
    float absuluteChange();


};