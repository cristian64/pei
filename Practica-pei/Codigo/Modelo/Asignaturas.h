#ifndef ASIGNATURAS_H
#define	ASIGNATURAS_H

#include "Asignatura.h"
#include "Modelo.h"
#include <list>

class Asignaturas : public Modelo
{
public:
    Asignaturas();
    ~Asignaturas();

    void anadirAsignatura(Asignatura *asignatura);
    void quitarAsignatura(Asignatura *asignatura);
    const std::list<Asignatura*>& obtenerAsignaturas() const;

private:
    std::list<Asignatura*> asignaturas;
};

#endif	/* ASIGNATURAS_H */
