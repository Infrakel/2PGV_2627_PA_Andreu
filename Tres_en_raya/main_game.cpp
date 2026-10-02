#include "Tictactoe.hpp"

// we need to understand for all positions then "x" is columns and then "y" are rows


int askPlayer(const Tictactoe& ttt, int& x, int& y) {

    printf("Said first column: ");
    scanf("%d", &x);

    printf("\nThen said row: ");
    scanf("%d", &y);

    // algorithm to calcule with max columns value set in on fire!
    return (y * 3) + x;
}

void printBadPlay(int position) {

    printf("\n Position [%d] is a bad spot, there is already a coin!!!!! \n", position);
}

void printWinner(int turns) {

    if (turns == 8) {

        printf("Nadie ha ganado!");
        return;
    }

    if (turns % 2 == 0) {
        printf("Player 2 wins the game!!!");
    } else {
        printf("Player 1 wins the game!!!");
    }
}

bool play(Tictactoe& ttt, int position) {
    return ttt.getCell(position) == Ficha::Vacio;
}

void printBoard(const Tictactoe& ttt) {

    for (int i = 0; i < ttt.maxCells; i++) {
        if (i % 3 == 0) {
            printf("\n");printf("    |");
        }

        // map to just put the code on the way we want
        switch(ttt.getCell(i)) {
            case Ficha::X:
                printf("X|");
                break;
            case Ficha::O:
                printf("O|");
                break;
            default:
                printf(" |");
                break;
        }
    
    }

    printf("\n");
}

int main(int, char**) {

    Tictactoe ttt;

    // initial review
    printBoard(ttt);

    int x, y, turns = 0;
    Ficha currentOne = Ficha::Vacio;
    bool winCondition = false;

    while(!ttt.isGameEnded() && !winCondition) {

        printf("\n");
        int position = askPlayer(ttt,x,y);

        if(!play(ttt, position)) {
            printBadPlay(position);
        } else {

            currentOne = turns % 2 == 0 ? Ficha::X : Ficha::O;
            ttt.assignPosition(position, currentOne);
            turns++;

            // check if games end
            winCondition = ttt.winCondition(currentOne);
        }

        printBoard(ttt);
    }

    printWinner(turns);

    return 0;
}