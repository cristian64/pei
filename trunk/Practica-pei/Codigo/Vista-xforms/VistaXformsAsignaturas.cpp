#include "VistaXformsAsignaturas.h"
#include "Asignaturas.h"
#include <forms.h>

VistaXformsAsignaturas::VistaXformsAsignaturas()
{

}

void VistaXformsAsignaturas::refrescar()
{
    Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
    if (asignaturas != NULL)
    {
        // Elimina y deselecciona todas las anteriores.
        fl_deselect_browser(formulario->browser_asignaturas);
        fl_clear_browser(formulario->browser_asignaturas);

        // Añade todas las asignaturas.
        const std::list<Asignatura*> lista = asignaturas->obtenerAsignaturas();
        std::list<Asignatura*>::const_iterator i = lista.begin();
        for (; i != lista.end(); i++)
        {
            fl_add_browser_line(formulario->browser_asignaturas, (*i)->getNombre().c_str());
        }

        //TODO: consultar en VistaXformsAsignatura cuál es el modelo seleccionado y, segun su indice, seleccionar el indice
        fl_select_browser_line(formulario->browser_asignaturas, 0);
    }
}
