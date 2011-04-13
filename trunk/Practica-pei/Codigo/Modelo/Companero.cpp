#include "Companero.h"
#include <sstream>

std::string Companero::getNombre() const
{
    return nombre;
}

void Companero::setNombre(const std::string &nombre)
{
    this->nombre = nombre;
}

std::string Companero::getEmail() const
{
    return email;
}

void Companero::setEmail(const std::string &email)
{
    this->email = email;
}

std::string Companero::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<companero>" << std::endl;
    flujo << "\t\t<nombre>" << nombre << "</nombre>" << std::endl;
    flujo << "\t\t<email>" << email << "</email>" << std::endl;
    flujo << "\t</companero>" << std::endl;
    return flujo.str();
}

void Companero::fromXml(const std::string &xml)
{
    //TODO: usar tinyxml y leer el fichero y procesar el fichero
}