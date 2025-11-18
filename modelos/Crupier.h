#pragma once

#include "Mazo.h"
#include "Jugador.h" // E incluye Participante.h

class Crupier : public Participante {
    public:
        Crupier();

        void empezarNuevaRonda(Mazo& mazo, Jugador& jugador);
        Carta getSiguienteCarta(Mazo& mazo);
        void darCartaAJugador(Jugador& jugador, Mazo& mazo, size_t cantidad);
        void darCartaACrupier(Mazo& mazo, size_t cantidad);
        void jugarTurno(Mazo& mazo);
};