#include<bits/stdc++.h>
#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "BettingStrategy.h"
#include "Player.h"
using namespace std;
class Fibonacci : public BettingStrategy {
private:
    vector<int> fib = {1,1};
    int idx = 0;
    const double MAX_LIMIT = 500.0;
    void ensure(int n);

public:
    vector<Bet> placeBets(Player& p) override;

    void update(Player&, bool win) override;

    string getName() override;

    BettingStrategy* clone() const override;
};
#endif