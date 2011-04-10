#ifndef VISTATXTASIGNATURAS_H
#define	VISTATXTASIGNATURAS_H

#include "Vista.h"
#include "Asignaturas.h"

class VistaTxtAsignaturas : public Vista
{
public:
    VistaTxtAsignaturas(Asignaturas *asignaturas);
    void refrescar();
    
private:
    const static int columnas = 80;
};

#endif	/* VISTATXTASIGNATURAS_H */

