#include<bits/stdc++.h>
#ifndef ROULETTEWHEEL_H
#define ROULETTEWHEEL_H
using namespace std;
struct SpinResult {
    int number;
};

class RouletteWheel {
private:
    mt19937 rng{random_device{}()};
public:
    SpinResult spin();
};
#endif