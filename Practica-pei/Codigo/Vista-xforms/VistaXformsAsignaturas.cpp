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

        // Comprueba si hay alguna seleccionada ahora mismo.
        Asignatura *asignatura = (Asignatura *) vistaXformsAsignatura->obtenerModelo();
        if (asignatura == NULL)
        {
            //bloquear pestañas y tal
        }
        else
        {
            //desbloquear pestañas y tal
        }

        // Añade todas las asignaturas.
        const std::list<Asignatura*> lista = asignaturas->obtenerAsignaturas();
        std::list<Asignatura*>::const_iterator i = lista.begin();
        for (; i != lista.end(); i++)
        {
            fl_add_browser_line(formulario->browser_asignaturas, (*i)->getNombre().c_str());
            
            // Si había alguna seleccionada, la marcamos en la lista como seleccionada.
            if (*i == asignatura)
            {
                int ultima = fl_get_browser_maxline(formulario->browser_asignaturas);
                fl_select_browser_line(formulario->browser_asignaturas, ultima);
            }
        }
    }
}
