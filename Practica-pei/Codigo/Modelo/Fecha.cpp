#include "Fecha.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>

Fecha::Fecha()
{
    segundo = 0;
    minuto = 0;
    hora = 0;
    dia = 1;
    mes = 1;
    ano = 2011;
}

std::string Fecha::toString() const
{
    std::stringstream flujo;
    flujo << ano << "/" << mes << "/" << dia << " " << hora << ":" << minuto << ":" << segundo;
    return flujo.str();
}

void Fecha::fromString(const std::string &cadena)
{
    ano = atoi(cadena.substr(0, 3).c_str());
    mes = atoi(cadena.substr(5, 6).c_str());
    dia = atoi(cadena.substr(8, 9).c_str());
    hora = atoi(cadena.substr(11, 12).c_str());
    minuto = atoi(cadena.substr(14, 15).c_str());
    segundo = atoi(cadena.substr(17, 18).c_str());
}