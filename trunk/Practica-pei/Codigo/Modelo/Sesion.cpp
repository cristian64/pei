#include "Sesion.h"

Sesion::Tipo Sesion::getTipo() const
{
    return tipo;
}
void Sesion::setTipo(Sesion::Tipo tipo)
{
    this->tipo = tipo;
}

std::string Sesion::getLugar() const
{
    return lugar;
}

void Sesion::setLugar(const std::string &lugar)
{
    this->lugar = lugar;
}

Sesion::Dia Sesion::getDia() const
{
    return dia;
}

void Sesion::setDia(Dia dia)
{
    this->dia = dia;
}

Fecha Sesion::getFechaInicio() const
{
    return fechaInicio;
}

void Sesion::setFechaInicio(Fecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

Fecha Sesion::getFechaFin() const
{
    return fechaFin;
}

void Sesion::setFechaFin(Fecha fechaFin)
{
    this->fechaFin = fechaFin;
}
