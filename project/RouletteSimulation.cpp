#include<bits/stdc++.h>
#include "RouletteSimulation.h"
using namespace std;
void RouletteSimulation::run(Player& p, RouletteWheel& w, int maxRounds, double targetProfit) {

    double startBalance = p.balance;

    for (int i = 0; i < maxRounds; ++i) {

        if (p.balance >= startBalance + targetProfit){
            p.reachedTarget=true;
            break;
        }

        // cháy
        if (p.balance < 0.001) {
            p.balance = 0;
            p.busted=true;
            break;
        }

        vector<Bet> bets = p.placeBets();
        if (bets.empty()) break;

        SpinResult res = w.spin();

        double totalBet = 0, payout = 0;
        bool win = false;

        for (auto &b : bets) {
            totalBet += b.amount;
            if (b.targetNumber == res.number) {
                payout += b.amount * 36;
                win = true;
            }
        }

        p.balance -= totalBet;
        p.balance += payout;

        if (p.balance < 1e-7) p.balance = 0;

        p.update(win);
    }
}

void RouletteSimulation::printHeader() {
    cout << "==================================================================================\n";
    cout << left << setw(15) << "Strategy"
        << setw(6)  << "So"
        << setw(15)  << "BustRate"
        << setw(18) << "AvgBalance"
        <<setw(18)<<"AvgRounds"
        <<setw(18)<<"TargetRate"
        <<"\n";
    cout << "---------------------------------------------------------------------------------\n";
}

void RouletteSimulation::runMultiple(BettingStrategy* strategy, RouletteWheel& wheel, int fixedCount, int simulations, double start, double base, int rounds, double target){

        int bustCount=0;
        int targetCount=0;

        double totalBalance=0;
        double totalRounds=0;

        for(int i=0;i<simulations;i++){

            Player p(fixedCount,start,base,strategy);

            run(p,wheel,rounds,target);

            if(p.busted)
                bustCount++;

            if(p.reachedTarget)
                targetCount++;

            totalBalance+=p.balance;
            totalRounds+=p.roundsPlayed;
        }

        double bustRate=(double)bustCount/simulations*100;
        double targetRate=(double)targetCount/simulations*100;

        double avgBalance=totalBalance/simulations;
        double avgRounds=totalRounds/simulations;

        cout<<left
            <<setw(15)<<strategy->getName()
            <<setw(6)<<fixedCount
            <<setw(15)<<fixed<<setprecision(1)<<bustRate
            <<setw(18)<<fixed<<setprecision(2)<<avgBalance
            <<setw(18)<<fixed<<setprecision(1)<<avgRounds
            <<setw(18)<<fixed<<setprecision(1)<<targetRate
            <<"\n";
}

