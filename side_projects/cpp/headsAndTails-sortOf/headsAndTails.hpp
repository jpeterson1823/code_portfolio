#include <string>
#include <vector>
using namespace std;

class Coin {
    public:
    Coin();
    int flip();
};

class Game {
    private:
    int numFlips;
    vector<vector<int>> results;

    public:
    Game(int numFlips);
    vector<vector<int>> getResults();
};

class Judge {
    private:
    Game game;
    int profWins;
    int gaWins;
    int gbWins;
    void countWins();

    public:
    Judge(Game game);
    char determineWinner();
    int getProfWins();
    int getGaWins();
    int getGbWins();
};