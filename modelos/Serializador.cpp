#include "Serializador.h"

#include <sstream>
#include <fstream>

Serializador::Serializador(const std::string& pNombreArchivo, const Vista& pVista, const Controlador& pControlador)
    : nombreArchivo{pNombreArchivo}, vista{pVista}, controlador{pControlador} {}

std::string Serializador::serializarDatos(const Jugador& jugador, const Apuesta& apuesta) {
    std::stringstream ss;
    ss << jugador.getNombre() << "," << apuesta.getDineroTotal();
    return ss.str();
}

std::pair<std::string, int> Serializador::deserializarDatos() {
std::ifstream archivoEntrada(nombreArchivo);
    std::string datos;
    
    if (!archivoEntrada.is_open()) {
        controlador.esperarInput("No se pudo abrir el archivo");
        return {"", 0};
    }
    
    std::getline(archivoEntrada, datos);
    archivoEntrada.close();

    if (datos.empty()) {
        controlador.esperarInput("Archivo vacio");
        return {"", 0};
    }
    
    std::stringstream ss(datos);
    std::string nombre;
    std::string dineroStr; 
    
    std::getline(ss, nombre, ','); 
    std::getline(ss, dineroStr);           
    
    int dinero = 0;
    
    if (nombre.empty() || dineroStr.empty()) {
        controlador.esperarInput("Archivo corrupto");
        return {"", 0};
    }

    try {
        dinero = std::stoi(dineroStr); 
    } catch (const std::exception& e) {
        controlador.esperarInput("Archivo corrupto");
        return {"", 0};
    }

    return {nombre, dinero};
}

void Serializador::guardarPartida(const Jugador& jugador, const Apuesta& apuesta) {
    std::ofstream archivoSalida(nombreArchivo);
    if(!archivoSalida.is_open()) {
        controlador.esperarInput("No se pudo abrir el archivo");
        return;
    }
    archivoSalida << serializarDatos(jugador, apuesta);
    archivoSalida.close();
}