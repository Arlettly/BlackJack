#pragma once

#include "Vista.h"

class Controlador {
    public:
        Controlador(Vista& pVista);

        void obtenerEleccionMenu() const;
        void obtenerAccionJugador() const;

    private:
        Vista vista;
};