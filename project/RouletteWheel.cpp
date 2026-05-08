#include<bits/stdc++.h>
#include "RouletteWheel.h"
using namespace std;
SpinResult RouletteWheel:: spin(){
    // Roulette tiêu chuẩn có 37 ô: từ 0 đến 36
    uniform_int_distribution<int> dist(0, 36);
     return {dist(rng)};
}
