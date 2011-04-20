#ifndef VISTAXFORMSASIGNATURAS_H
#define	VISTAXFORMSASIGNATURAS_H

#include "Vista.h"
#include "Formulario.h"
#include "VistaXformsAsignatura.h"

class VistaXformsAsignaturas : public Vista
{
public:
    VistaXformsAsignaturas();
    void refrescar();
    
    FD_Formulario *formulario;
    VistaXformsAsignatura *vistaXformsAsignatura;
};

#endif	/* VISTAXFORMSASIGNATURAS_H */

