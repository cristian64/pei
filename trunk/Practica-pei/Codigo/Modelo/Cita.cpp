#include "Cita.h"
#include <sstream>

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

std::string Cita::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<cita>" << std::endl;
    flujo << "\t\t<descripcion>" << descripcion << "</descripcion>" << std::endl;
    flujo << "\t\t<fecha>" << fecha.toString() << "</fecha>" << std::endl;
    flujo << "\t\t<duracion>" << duracion << "</duracion>" << std::endl;
    flujo << "\t</cita>" << std::endl;
    return flujo.str();
}

void Cita::fromXml(const std::string &xml)
{
    //TODO: usar tinyxml y leer el fichero y procesar el fichero
}