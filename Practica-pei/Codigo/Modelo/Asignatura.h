#ifndef ASIGNATURA_H
#define	ASIGNATURA_H

#include "Modelo.h"
#include "Profesor.h"
#include "Companero.h"
#include "Nota.h"
#include "Cita.h"
#include "Sesion.h"
#include <string>
#include <list>

class Asignatura : public Modelo
{
public:
    Asignatura(const std::string &nombre);
    ~Asignatura();

private:
    std::string nombre;
    std::list<Profesor*> profesores;
    std::list<Companero*> companeros;
    std::list<Nota*> notas;
    std::list<Cita*> citas;
    std::list<Sesion*> sesionesTeoria;
    std::list<Sesion*> sesionesPracticas;
};

#endif	/* ASIGNATURA_H */
