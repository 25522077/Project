#include<bits/stdc++.h>
#ifndef MARTINGALE_H
#define MARTINGALE_H
#include "BettingStrategy.h"
#include "Player.h"
class Martingale : public BettingStrategy {
private:
    double multiplier = 1.0;
public:
    vector<Bet> placeBets(Player& p) override;

    void update(Player&, bool win) override;

    string getName() override;

    BettingStrategy* clone() const override;
};
#endif