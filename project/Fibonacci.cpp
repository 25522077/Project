#include<bits/stdc++.h>
#include "Fibonacci.h"
using namespace std;
void Fibonacci::ensure(int n) {
    while ((int)fib.size() <= n)
        fib.push_back(fib.back() + fib[fib.size()-2]);
}
vector<Bet> Fibonacci::placeBets(Player& p){
    vector<Bet> bets;

    ensure(idx);
    double requested = min((double)p.baseBet * fib[idx], MAX_LIMIT);
    double total = min(requested, p.balance);
    if (total < 0.001) return bets;

    double each = total / p.fixedCount;

    vector<int> nums(37);
    iota(nums.begin(), nums.end(), 0);
    shuffle(nums.begin(), nums.end(), p.rng);

    for (int i = 0; i < p.fixedCount; i++)
        bets.push_back({nums[i], each});

    return bets;
}

void Fibonacci::update(Player&, bool win){
    if (win) {
        idx -= 2;
        if (idx < 0) idx = 0;
    } else idx++;
}

string Fibonacci::getName(){ return "Fibonacci"; }

BettingStrategy* Fibonacci::clone() const{
    return new Fibonacci(*this);
}