#include "VistaXformsAsignatura.h"
#include "Asignaturas.h"
#include <forms.h>

VistaXformsAsignatura::VistaXformsAsignatura()
{

}

void VistaXformsAsignatura::refrescar()
{
    // Elimina y deselecciona todas las anteriores.
    fl_deselect_browser(formulario->browser_asignatura);
    fl_clear_browser(formulario->browser_asignatura);
        
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        if (fl_get_button(formulario->button_profesores) == 0)
        {
            const std::list<Profesor*> profesores = asignatura->obtenerProfesores();
            std::list<Profesor*>::const_iterator i = profesores.begin();
            for (; i != profesores.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->getNombre().c_str());
            }
        }
        else if (fl_get_button(formulario->button_companeros) == 0)
        {
            const std::list<Companero*> companeros = asignatura->obtenerCompaneros();
            std::list<Companero*>::const_iterator i = companeros.begin();
            for (; i != companeros.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->getNombre().c_str());
            }
        }
        else if (fl_get_button(formulario->button_sesiones) == 0)
        {
            const std::list<Sesion*> sesiones = asignatura->obtenerSesiones();
            std::list<Sesion*>::const_iterator i = sesiones.begin();
            for (; i != sesiones.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->getLugar().c_str());
            }
        }
        else if (fl_get_button(formulario->button_citas) == 0)
        {
            const std::list<Cita*> citas = asignatura->obtenerCitas();
            std::list<Cita*>::const_iterator i = citas.begin();
            for (; i != citas.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->getDescripcion().c_str());
            }
        }
        else if (fl_get_button(formulario->button_notas) == 0)
        {
            const std::list<Nota*> notas = asignatura->obtenerNotas();
            std::list<Nota*>::const_iterator i = notas.begin();
            for (; i != notas.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->getDescripcion().c_str());
            }
        }
    }
}
