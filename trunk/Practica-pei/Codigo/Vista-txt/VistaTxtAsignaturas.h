#ifndef VISTATXTASIGNATURAS_H
#define	VISTATXTASIGNATURAS_H

#include "Vista.h"
#include "Asignaturas.h"
#include <list>
#include "VistaTxtAsignatura.h"

class VistaTxtAsignaturas : public Vista
{
public:
    VistaTxtAsignaturas(Asignaturas *asignaturas = NULL);
    ~VistaTxtAsignaturas();
    void refrescar();
    
private:
    std::list<VistaTxtAsignatura*> vistasTxtAsignatura;
    const static int columnas = 80;
};

#endif	/* VISTATXTASIGNATURAS_H */

