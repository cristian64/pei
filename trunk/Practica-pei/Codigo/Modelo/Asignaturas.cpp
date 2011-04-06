#include "Asignaturas.h"

Asignaturas::Asignaturas()
{

}

Asignaturas::~Asignaturas()
{
    std::list<Asignatura*>::iterator i = asignaturas.begin();
    for (; i != asignaturas.end(); i++)
    {
        delete *i;
    }
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

std::list<Asignatura*> Asignaturas::obtenerAsignaturas() const
{
    return asignaturas;
}