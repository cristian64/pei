#include "Asignaturas.h"
#include <sstream>
#include <fstream>
#include "tinyxml.h"

Asignaturas::Asignaturas()
{

}

Asignaturas::~Asignaturas()
{
	for (std::list<Asignatura*>::iterator i = asignaturas.begin(); i != asignaturas.end(); i++)
		delete *i;
	asignaturas.clear();
}

void Asignaturas::anadirAsignatura(Asignatura *asignatura)
{
	asignaturas.push_back(asignatura);
}

void Asignaturas::quitarAsignatura(Asignatura *asignatura)
{
	asignaturas.remove(asignatura);
}

const std::list<Asignatura*>& Asignaturas::obtenerAsignaturas() const
{
	return asignaturas;
}

void Asignaturas::limpiar()
{
	rutaFichero = "";
	for (std::list<Asignatura*>::iterator i = asignaturas.begin(); i != asignaturas.end(); i++)
		delete *i;
	asignaturas.clear();
}

std::string Asignaturas::toXml() const
{
	std::stringstream flujo;
	flujo << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" << std::endl;
	for (std::list<Asignatura*>::const_iterator i = asignaturas.begin(); i != asignaturas.end(); i++)
		flujo << (*i)->toXml();
	return flujo.str();
}

void Asignaturas::fromXml(const std::string &xml)
{
	// Limpia la información anterior.
	for (std::list<Asignatura*>::iterator i = asignaturas.begin(); i != asignaturas.end(); i++)
		delete *i;
	asignaturas.clear();

	// Crea un documento XML a partir de la cadena recibida.
	TiXmlDocument documento("");
	documento.Parse(xml.c_str(), NULL, TIXML_ENCODING_UTF8);

	// Busca todas las etiquetas <asignatura> y crea una asignatura a partir de ella.
	TiXmlElement *etiqueta = documento.FirstChildElement("asignatura");
	while (etiqueta != NULL)
	{
		// Convierte el objeto TiXmlElement en std::string usando TiXmlPrinter.
		TiXmlPrinter printer;
		etiqueta->Accept(&printer);

		// Crea, parsea y añade la asignatura.
		Asignatura *asignatura = new Asignatura();
		asignatura->fromXml(printer.CStr());
		asignaturas.push_back(asignatura);

		// Busca la siguiente etiqueta <asignatura>.
		etiqueta = etiqueta->NextSiblingElement();
	}
}

void Asignaturas::guardar(const std::string &rutaFichero) const
{
	std::ofstream fichero(rutaFichero.c_str(), std::ios::out);
	if (fichero.is_open())
	{
		this->rutaFichero = rutaFichero;
		fichero << toXml() << std::endl;
		fichero.close();
	}
}

void Asignaturas::cargar(const std::string &rutaFichero)
{
	std::ifstream fichero(rutaFichero.c_str(), std::ios::in);
	if (fichero.is_open())
	{
		this->rutaFichero = rutaFichero;
		std::stringstream flujo;
		flujo << fichero.rdbuf();
		fromXml(flujo.str());
		fichero.close();
	}
}

std::string Asignaturas::getRutaFichero() const
{
	return rutaFichero;
}

void Asignaturas::setRutaFichero(const std::string &rutaFichero)
{
	this->rutaFichero = rutaFichero;
}
