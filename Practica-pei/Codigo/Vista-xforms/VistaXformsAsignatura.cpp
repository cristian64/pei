#include "VistaXformsAsignatura.h"
#include "Asignaturas.h"
#include <forms.h>

VistaXformsAsignatura::VistaXformsAsignatura()
{

}

void VistaXformsAsignatura::refrescar()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        printf("Visualizando %s\n", asignatura->getNombre().c_str());
    }
}
