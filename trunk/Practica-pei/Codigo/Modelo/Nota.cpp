#include "Nota.h"
#include "tinyxml.h"
#include <sstream>
#include <cstdlib>

Nota::Nota() :
    nota(0.0f)
{
}

Nota::Nota(const std::string &descripcion, float nota) :
    descripcion(descripcion),
    nota(nota)
{
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

void Nota::setNota(float nota)
{
    this->nota = nota;
}

std::string Nota::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<nota>" << std::endl;
    flujo << "\t\t<descripcion>" << descripcion << "</descripcion>" << std::endl;
    flujo << "\t\t<nota>" << nota << "</nota>" << std::endl;
    flujo << "\t</nota>" << std::endl;
    return flujo.str();
}

void Nota::fromXml(const std::string &xml)
{
    // Crea un documento XML a partir de la cadena recibida.
    TiXmlDocument documento("");
    documento.Parse(xml.c_str(), NULL, TIXML_ENCODING_UTF8);

    // Extrae la etiqueta raíz.
    TiXmlElement *etiqueta = documento.FirstChildElement("nota");
    if (etiqueta != NULL)
    {
        // Extraemos los atributos propios.
        TiXmlElement *auxiliar = etiqueta->FirstChildElement("descripcion");
        if (auxiliar != NULL)
            descripcion = auxiliar->FirstChild() != NULL ? auxiliar->FirstChild()->Value() : "";
        auxiliar = etiqueta->FirstChildElement("nota");
        if (auxiliar != NULL)
            nota = auxiliar->FirstChild() != NULL ? atof(auxiliar->FirstChild()->Value()) : 0.0f;
    }
}
