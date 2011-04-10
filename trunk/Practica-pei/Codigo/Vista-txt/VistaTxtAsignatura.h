#ifndef VISTATXTASIGNATURA_H
#define	VISTATXTASIGNATURA_H

#include "Vista.h"
#include "Asignatura.h"

class VistaTxtAsignatura : public Vista
{
public:
    VistaTxtAsignatura(Asignatura *asignatura);
    void refrescar();
    
private:
    const static int columnas = 150;
};

#endif	/* VISTATXTASIGNATURA_H */

