#include "Profesor.h"

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
