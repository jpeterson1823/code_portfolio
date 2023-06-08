#include "headsAndTails.hpp"
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>

Coin::Coin() {};


// will return either a 0 or 1
int Coin::flip() {
    return rand() % 2;
};

/*
Flip a coin twice (to simulate two coins) and
add the results to a separate vector which will
represent each round played, e.g. numFlips.
Then add the round results to the game results 
vector "results".
*/
Game::Game(int numFlips) :numFlips(numFlips) {
    Coin coin;
    for (int i = 0; i < numFlips; i++) {
        // flip coin twice and record results
        vector<int> result;
        result.push_back(coin.flip());
        result.push_back(coin.flip());
        // add to game results
        this->results.push_back(result);
    }
};

// returns game results
vector<vector<int>> Game::getResults() {
    return this->results;
};


Judge::Judge(Game game) :game(game) {
    this->gaWins = 0;
    this->gbWins = 0;
    this->profWins = 0;
    this->countWins();
};

/*
Determines the winner via the mathmatic formula:
    (a == b && b == c) -> a == c
Uses a fuck ton of if statements which probably isn't
the fastest way so this needs a refactor.
*/
char Judge::determineWinner() {
    // if no ties
    if (this->profWins != this->gaWins && this->gaWins != this->gbWins) {
        int winner = max(this->profWins, max(this->gaWins, this->gbWins));
        
        if (winner == this->gaWins)
            return 'a';
        else if (winner == this->gbWins)
            return 'b';
        else
            return 'p';
    }
    // if there is a three-way tie
    else if (this->profWins == this->gaWins && this->gaWins == this->gbWins) {
        int num = rand() % 3;
        if (num == 0)
            return 'p';
        else if (num == 1)
            return 'a';
        else
            return 'b';
    }
    // if there is a two way tie
    else if (this->profWins == this->gaWins && this->gaWins != this->gbWins) {
        int num = rand() % 2;
        if (num == 0)
            return 'p';
        else
            return 'a';
    }
    // if there is the other two way tie
    else if (this->profWins != this->gaWins && this->gaWins == this->gbWins) {
        int num = rand() % 2;
        if (num == 0)
            return 'a';
        else
            return 'b';
    }
    // if there is the other, other two way tie
    else {
        int num = rand() % 2;
        if (num == 0)
            return 'p';
        else
            return 'b';
    }
};

// Counts the wins of each game and stores their value
void Judge::countWins() {
    vector<vector<int>> gameResults = this->game.getResults();
    for (int i = 0; i < gameResults.size(); i++) {
        if (gameResults[i][0] == 0 && gameResults[i][1] == 0)
            this->gaWins += 1;
        else if (gameResults[i][0] == 1 && gameResults[i][1] == 1)
            this->gbWins += 1;
        else
            this->profWins += 1;
    }
};

// returns prof's wins
int Judge::getProfWins() {
    return this->profWins;
};

// returns ga's wins
int Judge::getGaWins() {
    return this->gaWins;
};

// returns gb's wins
int Judge::getGbWins() {
    return this->gbWins;
};