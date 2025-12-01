#pragma once

#include <string>

#include "Jugador.h"
#include "Apuesta.h"
#include "Vista.h"
#include "Controlador.h"

class Serializador {
    public:
        Serializador(const std::string& pNombreArchivo, const Vista& pVista, const Controlador& pControlador);

        std::string serializarDatos(const Jugador& jugador, const Apuesta& apuesta);
        std::pair<std::string, int> deserializarDatos();

        void guardarPartida(const Jugador& jugador, const Apuesta& apuesta);

    private:
        std::string nombreArchivo;
        const Vista& vista;
        const Controlador& controlador;
};