#pragma once
#include <SFML/Graphics.hpp>
#include <Math.h>

using namespace sf;

enum class Interval{ 
    MINUTE,
    HOUR,
    FOUR_HOUR,
    DAY,
    WEEK
};

class Candle{
private:
    RectangleShape line;
    RectangleShape body;

    float open;
    float close;

    float min;
    float max;

    float width;
    float height;

    Interval interval;
public:
    // constructors
    Candle();
    Candle(float open, float close, float min, float max);

    // geters
    float getOpen();
    float getClose();

    float getMin();
    float getMax();

    float getWidth();
    float getHeight();


    //seters
    void setOpen(float open);
    void setClose(float close);

    void setMin(float min);
    void setMax(float max);

    void setWidth(float width);
    void setHeight(float height);

    //other
    float relativeChange();
    float absuluteChange();


};