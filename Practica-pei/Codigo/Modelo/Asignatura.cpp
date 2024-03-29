#include "Asignatura.h"
#include "tinyxml.h"
#include <sstream>

Asignatura::Asignatura(const std::string &nombre) :
    nombre(nombre)
{
    
}

Asignatura::~Asignatura()
{
    for (std::list<Profesor*>::iterator i = profesores.begin(); i != profesores.end(); i++)
        delete *i;
    profesores.clear();
    for (std::list<Companero*>::iterator i = companeros.begin(); i != companeros.end(); i++)
        delete *i;
    companeros.clear();
    for (std::list<Nota*>::iterator i = notas.begin(); i != notas.end(); i++)
        delete *i;
    notas.clear();
    for (std::list<Cita*>::iterator i = citas.begin(); i != citas.end(); i++)
        delete *i;
    citas.clear();
    for (std::list<Sesion*>::iterator i = sesiones.begin(); i != sesiones.end(); i++)
        delete *i;
    sesiones.clear();
}

std::string Asignatura::getNombre() const
{
    return nombre;
}

void Asignatura::setNombre(const std::string &nombre)
{
    this->nombre = nombre;
}

void Asignatura::anadirProfesor(Profesor *profesor)
{
    profesores.push_back(profesor);
}

void Asignatura::anadirCompanero(Companero *companero)
{
    companeros.push_back(companero);
}

void Asignatura::anadirNota(Nota *nota)
{
    notas.push_back(nota);
}

void Asignatura::anadirCita(Cita *cita)
{
    citas.push_back(cita);
}

void Asignatura::anadirSesion(Sesion *sesion)
{
    sesiones.push_back(sesion);
}

void Asignatura::quitarProfesor(Profesor *profesor)
{
    profesores.remove(profesor);
    delete profesor;
}

void Asignatura::quitarCompanero(Companero *companero)
{
    companeros.remove(companero);
    delete companero;
}

void Asignatura::quitarNota(Nota *nota)
{
    notas.remove(nota);
    delete nota;
}

void Asignatura::quitarCita(Cita *cita)
{
    citas.remove(cita);
    delete cita;
}

void Asignatura::quitarSesion(Sesion *sesion)
{
    sesiones.remove(sesion);
    delete sesion;
}

const std::list<Profesor*>& Asignatura::obtenerProfesores() const
{
    return profesores;
}

const std::list<Companero*>& Asignatura::obtenerCompaneros() const
{
    return companeros;
}

const std::list<Nota*>& Asignatura::obtenerNotas() const
{
    return notas;
}

const std::list<Cita*>& Asignatura::obtenerCitas() const
{
    return citas;
}

const std::list<Sesion*>& Asignatura::obtenerSesiones() const
{
    return sesiones;
}

std::string Asignatura::toXml() const
{
    std::stringstream flujo;
    flujo << "<asignatura>" << std::endl;
    flujo << "\t<nombre>" << nombre << "</nombre>" << std::endl;
    for (std::list<Profesor*>::const_iterator i = profesores.begin(); i != profesores.end(); i++)
        flujo << (*i)->toXml();
    for (std::list<Companero*>::const_iterator i = companeros.begin(); i != companeros.end(); i++)
        flujo << (*i)->toXml();
    for (std::list<Nota*>::const_iterator i = notas.begin(); i != notas.end(); i++)
        flujo << (*i)->toXml();
    for (std::list<Cita*>::const_iterator i = citas.begin(); i != citas.end(); i++)
        flujo << (*i)->toXml();
    for (std::list<Sesion*>::const_iterator i = sesiones.begin(); i != sesiones.end(); i++)
        flujo << (*i)->toXml();
    flujo << "</asignatura>" << std::endl;
    return flujo.str();
}

void Asignatura::fromXml(const std::string &xml)
{
    // Limpia la información anterior.
    for (std::list<Profesor*>::iterator i = profesores.begin(); i != profesores.end(); i++)
        delete *i;
    profesores.clear();
    for (std::list<Companero*>::iterator i = companeros.begin(); i != companeros.end(); i++)
        delete *i;
    companeros.clear();
    for (std::list<Nota*>::iterator i = notas.begin(); i != notas.end(); i++)
        delete *i;
    notas.clear();
    for (std::list<Cita*>::iterator i = citas.begin(); i != citas.end(); i++)
        delete *i;
    citas.clear();
    for (std::list<Sesion*>::iterator i = sesiones.begin(); i != sesiones.end(); i++)
        delete *i;
    sesiones.clear();

    // Crea un documento XML a partir de la cadena recibida.
    TiXmlDocument documento("");
    documento.Parse(xml.c_str(), NULL, TIXML_ENCODING_UTF8);

    // Busca todas las etiquetas <asignatura> y crea una asignatura a partir de ella.
    TiXmlElement *etiqueta = documento.FirstChildElement("asignatura");
    if (etiqueta != NULL)
    {
        // Extraemos los atributos propios de la asignatura.
        TiXmlElement *auxiliar = etiqueta->FirstChildElement("nombre");
        if (auxiliar != NULL)
            nombre = auxiliar->FirstChild() != NULL ? auxiliar->FirstChild()->Value() : "";

        // Finalmente, extraemos los profesores, compañeros, etc.
        auxiliar = etiqueta->FirstChildElement();
        while (auxiliar != NULL)
        {
            // Convierte el objeto TiXmlElement en std::string usando TiXmlPrinter.
            TiXmlPrinter printer;
            auxiliar->Accept(&printer);

            // Crea, parsea y añade el tipo de elemento correspondiente.
            if (auxiliar->Value() == std::string("profesor"))
            {
                Profesor *profesor = new Profesor();
                profesor->fromXml(printer.CStr());
                profesores.push_back(profesor);
            }
            else if (auxiliar->Value() == std::string("companero"))
            {
                Companero *companero = new Companero();
                companero->fromXml(printer.CStr());
                companeros.push_back(companero);
            }
            else if (auxiliar->Value() == std::string("sesion"))
            {
                Sesion *sesion = new Sesion();
                sesion->fromXml(printer.CStr());
                sesiones.push_back(sesion);
            }
            else if (auxiliar->Value() == std::string("nota"))
            {
                Nota *nota = new Nota();
                nota->fromXml(printer.CStr());
                notas.push_back(nota);
            }
            else if (auxiliar->Value() == std::string("cita"))
            {
                Cita *cita = new Cita();
                cita->fromXml(printer.CStr());
                citas.push_back(cita);
            }

            // Busca la siguiente etiqueta.
            auxiliar = auxiliar->NextSiblingElement();
        }
    }
}
