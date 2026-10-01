#include "Tictactoe.hpp"

Ficha Tictactoe::winCondition() const {

    Ficha cell = Ficha::Vacio;

    return cell;
}

bool Tictactoe::isGameEnded() const {

    return false;
}
        
Ficha Tictactoe::nextPlayer() const {
    Ficha cell = Ficha::Vacio;

    return cell;
}

Ficha Tictactoe::getCell(int slot) const {

    return celdas[slot];
}

void Tictactoe::assignPosition(int slot, Ficha coin) {
    celdas[slot] = coin;
}