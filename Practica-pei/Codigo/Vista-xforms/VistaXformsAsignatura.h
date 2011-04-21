#ifndef VISTAXFORMSASIGNATURA_H
#define	VISTAXFORMSASIGNATURA_H

#include "Vista.h"
#include "Formulario.h"
#include "Codificacion.h"

class VistaXformsAsignatura : public Vista
{
public:
    VistaXformsAsignatura();
    void refrescar();
    
    FD_Formulario *formulario;
};

#endif	/* VISTAXFORMSASIGNATURA_H */

