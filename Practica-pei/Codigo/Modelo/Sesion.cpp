#include "Sesion.h"
#include "tinyxml.h"
#include <cstdlib>
#include <sstream>
#include <iomanip>

Sesion::Sesion() :
	tipo(TEORIA),
	dia(LUNES)
{
}

Sesion::Sesion(Sesion::Tipo tipo, const std::string &lugar, Sesion::Dia dia, const Fecha &fechaInicio, const Fecha &fechaFin) :
	tipo(tipo),
	lugar(lugar),
	dia(dia),
	fechaInicio(fechaInicio),
	fechaFin(fechaFin)
{
}

Sesion::Tipo Sesion::getTipo() const
{
	return tipo;
}
void Sesion::setTipo(Sesion::Tipo tipo)
{
	this->tipo = tipo;
}

std::string Sesion::getTipoString() const
{
	if (tipo == TEORIA)
		return "Teoría";
	else
		return "Prácticas";
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

std::string Sesion::getDiaString() const
{
	switch (dia)
	{
	case LUNES: return "Lunes";
	case MARTES: return "Martes";
	case MIERCOLES: return "Miércoles";
	case JUEVES: return "Jueves";
	case VIERNES: return "Viernes";
	case SABADO: return "Sábado";
	case DOMINGO: return "Domingo";
	}
	return "SIN ASIGNAR";
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
	// Crea un documento XML a partir de la cadena recibida.
	TiXmlDocument documento("");
	documento.Parse(xml.c_str(), NULL, TIXML_ENCODING_UTF8);

	// Extrae la etiqueta raíz..
	TiXmlElement *etiqueta = documento.FirstChildElement("sesion");
	if (etiqueta != NULL)
	{
		// Extraemos los atributos propios.
		TiXmlElement *auxiliar = etiqueta->FirstChildElement("tipo");
		if (auxiliar != NULL)
			tipo = (Tipo) (auxiliar->FirstChild() != NULL ? atoi(auxiliar->FirstChild()->Value()) : TEORIA);
		auxiliar = etiqueta->FirstChildElement("lugar");
		if (auxiliar != NULL)
			lugar = auxiliar->FirstChild() != NULL ? auxiliar->FirstChild()->Value() : "";
		auxiliar = etiqueta->FirstChildElement("dia");
		if (auxiliar != NULL)
			dia = (Dia) (auxiliar->FirstChild() != NULL ? atoi(auxiliar->FirstChild()->Value()) : LUNES);
		auxiliar = etiqueta->FirstChildElement("fechaInicio");
		if (auxiliar != NULL)
			fechaInicio = auxiliar->FirstChild() != NULL ? Fecha(auxiliar->FirstChild()->Value()) : Fecha();
		auxiliar = etiqueta->FirstChildElement("fechaFin");
		if (auxiliar != NULL)
			fechaFin = auxiliar->FirstChild() != NULL ? Fecha(auxiliar->FirstChild()->Value()) : Fecha();
	}
}

std::string Sesion::toString() const
{
    std::stringstream flujo;
    flujo << std::setfill(' ') << std::setw(11) << getTipoString() << " ";
    flujo << std::setfill(' ') << std::setw(11) << getDiaString() << " ";
    flujo << fechaInicio.toStringHora() << " ";
    flujo << fechaFin.toStringHora() << " ";
    flujo << lugar;
    return flujo.str();
}
