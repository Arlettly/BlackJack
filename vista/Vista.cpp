#include "Vista.h"

#include <iostream>

Vista::Vista() {}

void Vista::mostrarTitulo() const {
    limpiarPantalla();
    std::cout << AMARILLO << R"(
╔══════════════════════════════════════════════════════════════════════════════╗
║                                                                              ║
║ ██████╗ ██╗      █████╗  ██████╗██╗  ██╗         ██╗ █████╗  ██████╗██╗  ██╗ ║
║ ██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝         ██║██╔══██╗██╔════╝██║ ██╔╝ ║
║ ██████╔╝██║     ███████║██║     █████╔╝          ██║███████║██║     █████╔╝  ║
║ ██╔══██╗██║     ██╔══██║██║     ██╔═██╗     ██   ██║██╔══██║██║     ██╔═██╗  ║
║ ██████╔╝███████╗██║  ██║╚██████╗██║  ██╗    ╚█████╔╝██║  ██║╚██████╗██║  ██╗ ║
║ ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝     ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ║
║                                                                              ║                                ║
╚══════════════════════════════════════════════════════════════════════════════╝
    )" << RESET << std::endl;
}

void Vista::limpiarPantalla() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Vista::mostrarTexto(const std::string& texto) const {
    std::cout << texto << "\n";
}

void Vista::añadirCartaACola(
    std::vector<std::string>& colSup,
    std::vector<std::string>& colMed,
    std::vector<std::string>& colInf,
    const std::string& valor,
    const std::string& palo,
    bool esRojo)
{
    std::string color = esRojo ? ROJO : NEGRO;

    colSup.push_back("╭" + color + valor + palo + RESET + "──╮ ");
    colMed.push_back("│    │ ");
    colInf.push_back("╰──" + color + valor + palo + RESET + "╯ ");
}

void Vista::imprimirCola(const std::vector<std::string>& cola) {
    for (size_t i = 0; i < cola.size(); i++) {
        std::cout << cola[i];
    }
    std::cout << "\n";
}

void Vista::limpiarColas() {
    colaJugadorCartaSuperior.clear();
    colaJugadorCartaMedio.clear();
    colaJugadorCartaInferior.clear();

    colaCrupierCartaSuperior.clear();
    colaCrupierCartaMedio.clear();
    colaCrupierCartaInferior.clear();
}

void Vista::imprimirMano(
    const std::vector<std::string>& sup,
    const std::vector<std::string>& med,
    const std::vector<std::string>& inf)
{
    imprimirCola(sup);
    imprimirCola(med);
    imprimirCola(med);
    imprimirCola(med);
    imprimirCola(inf);
}

void Vista::actualizarCartasJugador() {
    imprimirMano(colaJugadorCartaSuperior, colaJugadorCartaMedio, colaJugadorCartaInferior);
}

void Vista::actualizarCartasCrupier() {
    imprimirMano(colaCrupierCartaSuperior, colaCrupierCartaMedio, colaCrupierCartaInferior);
}
