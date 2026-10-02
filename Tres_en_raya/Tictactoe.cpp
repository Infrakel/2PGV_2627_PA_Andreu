#include "Tictactoe.hpp"

bool Tictactoe::winCondition(Ficha currentOne) const {

    // logic to stop the game, first horizontal
    for (int i = 0; i < 3; i++) {
        if (celdas[i * 3] == currentOne &&
            celdas[i * 3 + 1] == currentOne &&
            celdas[i * 3 + 2] == currentOne) {

            return true;
        }
    }

    // seconf vertical
    for (int k = 0; k < 3; k++) {
        if (celdas[k] == currentOne &&
            celdas[k + 3] == currentOne &&
            celdas[k + 6] == currentOne) {

            return true;
        }
    }

    // one rsult too
    if (celdas[0] == currentOne &&
        celdas[4] == currentOne &&
        celdas[8] == currentOne) {

        return true;
    }

    if (celdas[2] == currentOne &&
        celdas[4] == currentOne &&
        celdas[6] == currentOne) {

        return true;
    } 

    return false;
}

bool Tictactoe::isGameEnded() const {

    for (int i = 0; i < maxCells; i++) {
        if (celdas[i] == Ficha::Vacio) {
            return false;
        }
    }

    return true;
}

Ficha Tictactoe::getCell(int slot) const {

    return celdas[slot];
}

void Tictactoe::assignPosition(int slot, Ficha coin) {
    celdas[slot] = coin;
}