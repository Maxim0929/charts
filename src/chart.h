#pragma once
#include "candle.h"

class Chart{
private:
    Candle* field;

    int left;
    int right;
    float min;
    float max;

    Interval candlesInterval;
public:
    Chart();
    Chart(int left, int right, float min, float max);

    ~Chart();

    void resizeX(int left, int right);
    void resizeY(float min, float max);
};