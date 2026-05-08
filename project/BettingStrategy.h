#include<bits/stdc++.h>
#ifndef BETTINGSTRATEGY_H
#define BETTINGSTRATEGY_H
using namespace std;
struct Bet {
    int targetNumber;
    double amount;
};
class Player;
class BettingStrategy {
public:
    virtual vector<Bet> placeBets(Player& p) = 0;
    virtual void update(Player& p, bool win) = 0;
    virtual string getName() = 0;
    virtual BettingStrategy* clone() const = 0;
    virtual ~BettingStrategy() {}
};
#endif