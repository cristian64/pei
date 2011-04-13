#include "Cita.h"
#include "tinyxml.h"
#include <sstream>

Cita::Cita() :
    duracion(duracion)
{
}

Cita::Cita(const std::string &descripcion, const Fecha &fecha, int duracion) :
    descripcion(descripcion),
    fecha(fecha),
    duracion(duracion)
{
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
    // Crea un documento XML a partir de la cadena recibida.
    TiXmlDocument documento("");
    documento.Parse(xml.c_str(), NULL, TIXML_ENCODING_UTF8);

    // Extrae la etiqueta raíz.
    TiXmlElement *etiqueta = documento.FirstChildElement("cita");
    if (etiqueta != NULL)
    {
        // Extraemos los atributos propios.
        TiXmlElement *auxiliar = etiqueta->FirstChildElement("descripcion");
        if (auxiliar != NULL)
            descripcion = auxiliar->FirstChild() != NULL ? auxiliar->FirstChild()->Value() : "";
        auxiliar = etiqueta->FirstChildElement("fecha");
        if (auxiliar != NULL)
            fecha = auxiliar->FirstChild() != NULL ? Fecha(auxiliar->FirstChild()->Value()) : Fecha();
        auxiliar = etiqueta->FirstChildElement("duracion");
        if (auxiliar != NULL)
            duracion = auxiliar->FirstChild() != NULL ? atoi(auxiliar->FirstChild()->Value()) : 60;
    }
}