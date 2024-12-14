#pragma once
#include "candle.h"

class Chart{
private:
    Candle* field;

    int left;
    int right;
    double PrMin;
    double PrMax;
    size_t size;

    float candleWidth;
    float candleHeight;

    float topBottomSpace;

    float space;
public:


    Chart();
    Chart(time_t left, time_t right, float PrMin, float PrMax);

    ~Chart();


    void initCandle(float prices[], RenderWindow& window);
    void setCandlePos(RenderWindow& window);
    void draw(RenderWindow& window);

    void newChart(float prices[], RenderWindow& window, time_t left, time_t right, float PrMin, float PrMax);



    void resizeX(int left, int right);
    void resizeY(float min, float max);
};