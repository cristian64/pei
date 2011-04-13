#include "Profesor.h"
#include <sstream>

std::string Profesor::getNombre() const
{
    return nombre;
}

void Profesor::setNombre(const std::string &nombre)
{
    this->nombre = nombre;
}

std::string Profesor::getEmail() const
{
    return email;
}

void Profesor::setEmail(const std::string &email)
{
    this->email = email;
}

std::string Profesor::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<profesor>" << std::endl;
    flujo << "\t\t<nombre>" << nombre << "</nombre>" << std::endl;
    flujo << "\t\t<email>" << email << "</email>" << std::endl;
    flujo << "\t</profesor>" << std::endl;
    return flujo.str();
}

void Profesor::fromXml(const std::string &xml)
{
    //TODO: usar tinyxml y leer el fichero y procesar el fichero
}