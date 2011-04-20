#include "Companero.h"
#include "tinyxml.h"
#include <sstream>

Companero::Companero()
{
}

Companero::Companero(const std::string &nombre, const std::string &email) :
    nombre(nombre),
    email(email)
{
}

std::string Companero::getNombre() const
{
    return nombre;
}

void Companero::setNombre(const std::string &nombre)
{
    this->nombre = nombre;
}

std::string Companero::getEmail() const
{
    return email;
}

void Companero::setEmail(const std::string &email)
{
    this->email = email;
}

std::string Companero::toXml() const
{
    std::stringstream flujo;
    flujo << "\t<companero>" << std::endl;
    flujo << "\t\t<nombre>" << nombre << "</nombre>" << std::endl;
    flujo << "\t\t<email>" << email << "</email>" << std::endl;
    flujo << "\t</companero>" << std::endl;
    return flujo.str();
}

void Companero::fromXml(const std::string &xml)
{
    // Crea un documento XML a partir de la cadena recibida.
    TiXmlDocument documento("");
    documento.Parse(xml.c_str(), NULL, TIXML_ENCODING_UTF8);

    // Extrae la etiqueta raíz.
    TiXmlElement *etiqueta = documento.FirstChildElement("companero");
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

std::string Companero::toString() const
{
    std::stringstream flujo;
    flujo << nombre << " ";
    flujo << "(" << email << ")";
    return flujo.str();
}