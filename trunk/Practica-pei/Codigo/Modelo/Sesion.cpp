#include "Sesion.h"
#include <sstream>

Sesion::Sesion()
{
    tipo = TEORIA;
    dia = LUNES;
}

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

std::string Sesion::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<sesion>" << std::endl;
    flujo << "\t\t<tipo>" << tipo << "</tipo>" << std::endl;
    flujo << "\t\t<lugar>" << lugar << "</lugar>" << std::endl;
    flujo << "\t\t<dia>" << dia << "</dia>" << std::endl;
    flujo << "\t\t<fechaInicio>" << fechaInicio.toString() << "</fechaInicio>" << std::endl;
    flujo << "\t\t<fechaFin>" << fechaFin.toString() << "</fechaFin>" << std::endl;
    flujo << "\t</sesion>" << std::endl;
    return flujo.str();
}

void Sesion::fromXml(const std::string &xml)
{
    //TODO: usar tinyxml y leer el fichero y procesar el fichero
}