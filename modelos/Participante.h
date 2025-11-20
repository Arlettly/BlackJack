#pragma once

#include <vector>

#include "Carta.h"
#include "Vista.h"

class Participante {
    public:
        Participante(Vista& pVista);

        void recibirCarta(const Carta& carta);
        void limpiarMano();
        void ajustarMano();

        // Getters

        int getValorDeMano() const;
        size_t getConteoDeCartas() const;
        const std::vector<Carta>& getMano() const;

    private:
        Vista& vista;

    protected:
        std::vector<Carta> mano;
};