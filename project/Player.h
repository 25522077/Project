#include<bits/stdc++.h>
#ifndef PLAYER_H
#define PLAYER_H
#include "BettingStrategy.h"
using namespace std;
class Player {
public:
    mt19937 rng{random_device{}()};
    double baseBet;
    double balance;
    int fixedCount;

    int winRounds = 0;
    int lossRounds = 0;
    int roundsPlayed = 0;
    bool reachedTarget=false;
    bool busted=false;
    BettingStrategy* strategy;

    Player(int count, double bal, double bBet, BettingStrategy* s);

    ~Player();

    vector<Bet> placeBets();

    void update(bool win);

    string getName() const;
};
#endif