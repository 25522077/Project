#ifndef ROULETTESIMULATION_H
#define ROULETTESIMULATION_H
#include "RouletteWheel.h"
#include "Player.h"
#include "BettingStrategy.h"
class RouletteSimulation {
public:
    void run(Player& p, RouletteWheel& w, int maxRounds, double targetProfit);

    void printHeader();

    void runMultiple( BettingStrategy* strategy, RouletteWheel& wheel, int fixedCount, int simulations, double start, double base, int rounds, double target);
};
#endif