#include<bits/stdc++.h>
#include "Player.h"
using namespace std;
Player::Player(int count, double bal, double bBet, BettingStrategy* s)
        : fixedCount(count), balance(bal), baseBet(bBet) {
        strategy = s->clone();
    }

   Player:: ~Player() {
        delete strategy;
    }

    vector<Bet> Player::placeBets() {
        return strategy->placeBets(*this);
    }

    void Player::update(bool win) {
        roundsPlayed++;
        if (win) winRounds++;
        else lossRounds++;
        strategy->update(*this, win);
    }

    string Player::getName() const {
        return strategy->getName();
    }