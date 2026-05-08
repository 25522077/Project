#include<bits/stdc++.h>
#include "Martingale.h"
using namespace std;
 vector<Bet> Martingale::placeBets(Player& p){
    vector<Bet> bets;
    double total = min(p.baseBet * multiplier, p.balance);
    if (total < 0.001) return bets;

    double each = total / p.fixedCount;

    vector<int> nums(37);
    iota(nums.begin(), nums.end(), 0);
    shuffle(nums.begin(), nums.end(), p.rng);

    for (int i = 0; i < p.fixedCount; i++)
            bets.push_back({nums[i], each});

    return bets;
}

void Martingale::update(Player&, bool win){
    if (win) multiplier = 1;
    else multiplier *= 2;
}

string Martingale::getName(){ return "Martingale"; }

BettingStrategy* Martingale::clone() const{
    return new Martingale(*this);
}