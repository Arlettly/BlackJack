#include "Crupier.h"

Crupier::Crupier(Mazo& pMazo, Vista& pVista) : Participante(pVista), mazo{pMazo} {}

void Crupier::empezarNuevaRonda(Jugador& jugador) {
    limpiarMano();
    jugador.limpiarMano();
    
    // Repartir 2 cartas al jugador y 2 al crupier

    darCartaAJugador(jugador, 2);
    darCartaACrupier(2);
}

Carta Crupier::getSiguienteCarta() {
    mazo.avanzarIndice();
    return mazo.cartasEnMazo[mazo.getIndiceCartaActual()];
}

void Crupier::darCartaAJugador(Jugador& jugador, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        jugador.recibirCarta(getSiguienteCarta());
    }
}

void Crupier::darCartaACrupier(int cantidad) {
        for (int i = 0; i < cantidad; i++) {
        recibirCarta(getSiguienteCarta());
    }
}

void Crupier::jugarTurno() {
    // El crupier debe pedir carta si tiene menos de 17
    while (getValorDeMano() < 17) {
        recibirCarta(getSiguienteCarta());
    }
}