#include "Profesor.h"
#include <sstream>
#include "tinyxml.h"

Profesor::Profesor()
{
}

Profesor::Profesor(const std::string &nombre, const std::string &email) :
    nombre(nombre),
    email(email)
{
}

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

std::string Profesor::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<profesor>" << std::endl;
    flujo << "\t\t<nombre>" << nombre << "</nombre>" << std::endl;
    flujo << "\t\t<email>" << email << "</email>" << std::endl;
    flujo << "\t</profesor>" << std::endl;
    return flujo.str();
}

void Profesor::fromXml(const std::string &xml)
{
    // Crea un documento XML a partir de la cadena recibida.
    TiXmlDocument documento("");
    documento.Parse(xml.c_str(), NULL, TIXML_ENCODING_UTF8);

    // Extrae la etiqueta raíz..
    TiXmlElement *etiqueta = documento.FirstChildElement("profesor");
    if (etiqueta != NULL)
    {
        // Extraemos los atributos propios.
        TiXmlElement *auxiliar = etiqueta->FirstChildElement("nombre");
        if (auxiliar != NULL)
            nombre = auxiliar->FirstChild() != NULL ? auxiliar->FirstChild()->Value() : "";
        auxiliar = etiqueta->FirstChildElement("email");
        if (auxiliar != NULL)
            email = auxiliar->FirstChild() != NULL ? auxiliar->FirstChild()->Value() : "";
    }
}

std::string Profesor::toString() const
{
    std::stringstream flujo;
    flujo << nombre << " ";
    flujo << email;
    return flujo.str();
}