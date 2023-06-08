#include "../lib/knight.hpp"

Knight::Knight() {
    this->pos = Coord{0, 0};
}

int Knight::getX() {
    return this->pos.x;
}

int Knight::getY() {
    return this->pos.y;
}

// To be implemented.
bool Knight::move(int board[][SIZE]) {

    return false;
}

// To be implemented
// SHORT Right Up/Down
bool Knight::sRight(char board[][SIZE], bool uord) {
    return false;
}

// To be implemented
// LONG Right Up/Down
bool Knight::lRight(char board[][SIZE], bool uord) {

}