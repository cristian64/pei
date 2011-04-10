#include "Cita.h"

Cita::Cita()
{
    duracion = 60;
}

std::string Cita::getDescripcion() const
{
    return descripcion;
}

void Cita::setDescripcion(const std::string &descripcion)
{
    this->descripcion = descripcion;
}

Fecha Cita::getFecha() const
{
    return fecha;
}

void Cita::setFecha(Fecha fecha)
{
    this->fecha = fecha;
}

int Cita::getDuracion() const
{
    return duracion;
}

void Cita::setDuracion(int duracion)
{
    this->duracion = duracion;
}
