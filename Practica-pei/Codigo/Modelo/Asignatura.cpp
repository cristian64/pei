#include "Asignatura.h"

Asignatura::Asignatura(const std::string &nombre) :
    nombre(nombre)
{
    
}

Asignatura::~Asignatura()
{
    
}

std::string Asignatura::getNombre() const
{
    return nombre;
}

void Asignatura::setNombre(const std::string &nombre)
{
    this->nombre = nombre;
}