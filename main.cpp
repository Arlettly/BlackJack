#include "Vista.h"

#include <iostream>

int main() {
    Vista vista;
    
    vista.añadirCartaACola(JUGADOR, "A", "♥", ROJO);
    vista.añadirCartaACola(JUGADOR, "10", "♥", NEGRO);
    vista.añadirCartaACola(JUGADOR, "8", "♥", ROJO);

    vista.imprimirMano(JUGADOR);

    std::cin.get();

    vista.limpiarColas();

    vista.imprimirMano(JUGADOR);

    std::cin.get();
    return 0;
}