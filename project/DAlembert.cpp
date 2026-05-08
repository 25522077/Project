#include<bits/stdc++.h>
#include "DAlembert.h"
using namespace std;

vector<Bet> DAlembert::placeBets(Player& p){
    vector<Bet> bets;

    double total = min(p.baseBet * step, p.balance);
    if (total < 0.001) return bets;

    double each = total / p.fixedCount;

    vector<int> nums(37);
    iota(nums.begin(), nums.end(), 0);
    shuffle(nums.begin(), nums.end(), p.rng);

    for (int i = 0; i < p.fixedCount; i++)
        bets.push_back({nums[i], each});

    return bets;
}

void DAlembert::update(Player&, bool win){
    if (win){
        step--;
        if (step < 1) step = 1;
    } else step++;
}

string DAlembert::getName(){ return "D'Alembert"; }

BettingStrategy* DAlembert::clone() const{
    return new DAlembert(*this);
}