#include<bits/stdc++.h>
#ifndef DALEMBERT_H
#define DALEMBERT_H
#include "BettingStrategy.h"
#include "Player.h"
using namespace std;
class DAlembert : public BettingStrategy {
private:
    int step = 1;
    const double MAX_LIMIT = 500.0;
public:
    vector<Bet> placeBets(Player& p) override;

    void update(Player&, bool win) override;

    string getName() override;

    BettingStrategy* clone() const override;
};
#endif