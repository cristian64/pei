#include "Nota.h"
#include <sstream>

Nota::Nota()
{
    nota = 0.0f;
}

std::string Nota::getDescripcion() const
{
    return descripcion;
}

void Nota::setDescripcion(const std::string &descripcion)
{
    this->descripcion = descripcion;
}

float Nota::getNota() const
{
    return nota;
}

void Nota::setEmail(float nota)
{
    this->nota = nota;
}

std::string Nota::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<nota>" << std::endl;
    flujo << "\t\t<descripcion>" << descripcion << "</descripcion>" << std::endl;
    flujo << "\t\t<nota>" << nota << "</nota>" << std::endl;
    flujo << "\t</nota>" << std::endl;
    return flujo.str();
}

void Nota::fromXml(const std::string &xml)
{
    //TODO: usar tinyxml y leer el fichero y procesar el fichero
}