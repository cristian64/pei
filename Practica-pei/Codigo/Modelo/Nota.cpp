#include "Nota.h"

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
