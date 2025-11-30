#include "Controlador.h"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>

Controlador::Controlador(Vista& pVista) : vista{pVista} {}

int Controlador::getOpcionMenuPrincipal(int opcionMin, int opcionMax) const {
    int opcion{};

    while(true) {
        vista.solicitarOpcion();

        if(std::cin >> opcion) {

            if(opcion >= opcionMin && opcion <= opcionMax)
            limpiarBuffer();
            return opcion;
        }

        if(std::cin.fail()) {
            std::cin.clear(); // Limpiar la bandera de error (fallbit) que se presenta en caso de error
            limpiarBuffer();

            vista.mostrarPantallaPrincipal();
            vista.mostrarTexto("Invalido", "\e[1;31m");
        }
    }
}

char Controlador::getOpcionChar(const std::string& opciones, Menu menu) const {
    char opcion{};

    while(true) {
        vista.solicitarOpcion();

        if(std::cin >> opcion) {
            opcion = static_cast<char>(std::toupper(opcion));
            limpiarBuffer();

            if(std::find(opciones.begin(), opciones.end(), opcion) != opciones.end())
            return opcion;
        }

        if(std::cin.fail()) {
            std::cin.clear();
            limpiarBuffer();

            if(APUESTA)
            vista.mostrarPantallaApuesta();

            if(JUEGO)
            vista.mostrarPantallaJuego();
            
            vista.mostrarTexto("Invalido", "\e[1;31m");
        }
    }
}

void Controlador::limpiarBuffer() const {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}