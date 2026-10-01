#include <cstdio>

// not sure if this needs to be here
enum class Ficha {
    X,
    O,
    Vacio
};

class Tictactoe {
    public:
        Tictactoe(): celdas{} {
            for (int i = 0; i < maxCells; i++) {
                celdas[i] = Ficha::Vacio;
            }
        };

        // OBSERVACION
        Ficha winCondition() const;
        bool isGameEnded() const;
        Ficha nextPlayer() const;
        Ficha getCell(int slot) const;
        void assignPosition(int slot, Ficha coin);

        static const int maxCells = 9;

    private:
        Ficha celdas[maxCells];
};
