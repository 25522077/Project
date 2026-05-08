#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include "RouletteWheel.h"
#include "Player.h"
#include "BettingStrategy.h"
#include "Martingale.h"
#include "Fibonacci.h"
#include "DAlembert.h"
#include "RouletteSimulation.h"
using namespace std;


int main() {
    RouletteWheel wheel;

    RouletteSimulation sim;

    const double START=1000;
    const double BASE=5;

    const int ROUNDS=500;

    const double TARGET=200;

    const int SIMULATIONS=1000;

    //=================MARTINGALE=================
    cout<<"\n=====MARTINGALE=====\n";

    sim.printHeader();

    for(int i=1;i<=36;i++){

        Martingale m;

        sim.runMultiple(
            &m,
            wheel,
            i,
            SIMULATIONS,
            START,
            BASE,
            ROUNDS,
            TARGET
        );
    }

    //=================FIBONACCI=================
    cout<<"\n=====FIBONACCI=====\n";

    sim.printHeader();

    for(int i=1;i<=36;i++){

        Fibonacci f;

        sim.runMultiple(
            &f,
            wheel,
            i,
            SIMULATIONS,
            START,
            BASE,
            ROUNDS,
            TARGET
        );
    }

    //=================D'ALEMBERT=================
    cout<<"\n=====D'ALEMBERT=====\n";

    sim.printHeader();

    for(int i=1;i<=36;i++){

        DAlembert d;

        sim.runMultiple(
            &d,
            wheel,
            i,
            SIMULATIONS,
            START,
            BASE,
            ROUNDS,
            TARGET
        );
    }

    return 0;
}