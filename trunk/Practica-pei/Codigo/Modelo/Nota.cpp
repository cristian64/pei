#include "Nota.h"
#include "tinyxml.h"
#include <sstream>
#include <cstdlib>
#include <iomanip>

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

std::string Nota::getNotaString() const
{
    std::stringstream flujo;
    flujo << nota;
    return flujo.str();
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

float atof(const std::string &numero)
{
    std::stringstream flujo(numero);
    float entero;
    float decimal;
    flujo >> entero;
    flujo >> decimal;
    while (decimal > 99)
        decimal /= 10;
    return entero + decimal / 100;
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
            nota = auxiliar->FirstChild() != NULL ? atof(std::string(auxiliar->FirstChild()->Value())) : 0.0f;
    }
}

std::string Nota::toString() const
{
    std::stringstream flujo;
    flujo << std::setfill(' ') << std::setw(5) << nota << " ";
    flujo << descripcion;
    return flujo.str();
}
