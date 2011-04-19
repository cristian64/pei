#ifndef VISTAXFORMSASIGNATURAS_H
#define	VISTAXFORMSASIGNATURAS_H

#include "Vista.h"
#include "Formulario.h"

class VistaXformsAsignaturas : public Vista
{
public:
    VistaXformsAsignaturas();
    void refrescar();
    
    FD_Formulario *formulario;
};

#endif	/* VISTAXFORMSASIGNATURAS_H */

