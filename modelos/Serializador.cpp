#include "Serializador.h"

#include <sstream>
#include <fstream>

Serializador::Serializador(const std::string& pNombreArchivo, const Vista& pVista) : nombreArchivo{pNombreArchivo}, vista{pVista} {}

std::string Serializador::serializarDatos(const Jugador& jugador, const Apuesta& apuesta) {
    std::stringstream ss;
    ss << jugador.getNombre() << "," << apuesta.getDineroTotal();
    return ss.str();
}

std::pair<std::string, int> Serializador::deserializarDatos() {
std::ifstream archivoEntrada(nombreArchivo);
    std::string datos;
    
    if (!archivoEntrada.is_open()) {
        // Texto no se pudo abrir
        return {"", 0};
    }
    
    std::getline(archivoEntrada, datos);
    archivoEntrada.close();

    if (datos.empty()) {
        // Texto archivo vacio
        return {"", 0};
    }
    
    std::stringstream ss(datos);
    std::string nombre;
    std::string dinero; 
    
    std::getline(ss, nombre, ','); 
    std::getline(ss, dinero);           
    
    int dineroGuardado = 0;
    
    if (nombre.empty() || dinero.empty()) {
        // Texto formato incorrecto
        return {"", 0};
    }

    try {
        dineroGuardado = std::stoi(dinero); 
    } catch (const std::exception& e) {
        // Texto error tomar dinero
        return {"", 0};
    }

    return {nombre, dineroGuardado};
}

void Serializador::guardarPartida(const Jugador& jugador, const Apuesta& apuesta) {
    std::ofstream archivoSalida(nombreArchivo);
    if(!archivoSalida.is_open()) {
        // Mensaje de error no se pudo abrir
        return;
    }
    archivoSalida << serializarDatos(jugador, apuesta);
    archivoSalida.close();
}