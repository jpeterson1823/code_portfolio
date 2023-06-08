#define SIZE 5

struct Coord {
    int x;
    int y;
};

class Knight {
    private:
        struct Coord pos;
        bool lRight(char board[][SIZE], bool uord);
        bool sRight(char board[][SIZE], bool uord);
        bool lLeft(char board[][SIZE], bool uord);
        bool sLeft(char board[][SIZE], bool uord);
    public:
        Knight();
        int getX();
        int getY();
        bool move(int board[][SIZE]);
};