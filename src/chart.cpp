#include "chart.h"

Chart::Chart() : field(nullptr), 
left(0), right(0), min(0), max(0), candlesInterval(Interval::HOUR){}

Chart::Chart(int left, int right, float min, float max) : 
left(left), right(right), min(min), max(max), candlesInterval(Interval::HOUR){
    field = new Candle[right - left];
}

Chart::~Chart(){
    delete[] field;
}