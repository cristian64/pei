#include "Companero.h"

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

