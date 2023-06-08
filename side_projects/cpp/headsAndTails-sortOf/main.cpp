#include "headsAndTails.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;

float myRound(float var, int precision);

int main() {
    // initalize random seed
    srand(time(NULL));

    // get user provided amount of games
    int games;
    while (true) {
        try {
            cout << "How many games? ";
            cin >> games;
            break;
        } catch(...) {
            cout << "Erronous input found. Please enter a valid integer." << endl;
        }
    }

    // get user proveded amount of games
    int numFlips;
    while (true) {
        try {
            cout << "How many coin tosses per game? ";
            cin >> numFlips;
            break;
        } catch(...) {
            cout << "Erronous input found. Please enter a valid integer." << endl;
        }
    }

    // counter for total wins for each group
    int tprof = 0;
    int tga = 0;
    int tgb = 0;

    // loop for however many games the user decided
    for (int i = 0; i < games; i++) {
        // judge the game that flips however many times the user decided
        Game game(numFlips);
        Judge judge(game);

        // output games' info
        float multiplier = numFlips / 100.0;
        cout << setprecision(2) << fixed;
        cout << "Game " << i << ":\n";
        cout << "     Group A: " << judge.getGaWins() << " (" << judge.getGaWins() / multiplier << "%)";
        cout << " Group B: " << judge.getGbWins() << " (" << judge.getGbWins() / multiplier << "%)";
        cout << " Prof: " << judge.getProfWins() << " (" << judge.getProfWins() / multiplier << "%)";
        cout << endl;

        // determine the winner and add win to total wins for the group
        char winner = judge.determineWinner();
        if (winner == 'p')
            tprof += 1;
        else if (winner == 'a')
            tga += 1;
        else
            tgb += 1;
    }

    // Display wins
    cout << "Wins: Group A=" << tga << " (" << tga / games * 100.0 << "%);";
    cout << " Group B=" << tgb << " (" << tgb / games * 100.0 << "%);";
    cout << " Prof=" << tprof << " (" << tprof / games * 100.0 << "%);";
}