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
                fl_add_browser_line(formulario->browser_asignatura, (*i)->toString().c_str());
            }
        }
        else if (fl_get_button(formulario->button_companeros) == 0)
        {
            const std::list<Companero*> companeros = asignatura->obtenerCompaneros();
            std::list<Companero*>::const_iterator i = companeros.begin();
            for (; i != companeros.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->toString().c_str());
            }
        }
        else if (fl_get_button(formulario->button_sesiones) == 0)
        {
            const std::list<Sesion*> sesiones = asignatura->obtenerSesiones();
            std::list<Sesion*>::const_iterator i = sesiones.begin();
            for (; i != sesiones.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->toString().c_str());
            }
        }
        else if (fl_get_button(formulario->button_citas) == 0)
        {
            const std::list<Cita*> citas = asignatura->obtenerCitas();
            std::list<Cita*>::const_iterator i = citas.begin();
            for (; i != citas.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->toString().c_str());
            }
        }
        else if (fl_get_button(formulario->button_notas) == 0)
        {
            const std::list<Nota*> notas = asignatura->obtenerNotas();
            std::list<Nota*>::const_iterator i = notas.begin();
            for (; i != notas.end(); i++)
            {
                fl_add_browser_line(formulario->browser_asignatura, (*i)->toString().c_str());
            }
        }

        fl_activate_object(formulario->browser_asignatura);
        fl_activate_object(formulario->button_plus);
        fl_activate_object(formulario->button_minus);
        fl_activate_object(formulario->button_profesores);
        fl_activate_object(formulario->button_companeros);
        fl_activate_object(formulario->button_sesiones);
        fl_activate_object(formulario->button_citas);
        fl_activate_object(formulario->button_notas);

        fl_set_object_lcolor(formulario->browser_asignatura, 0);
        fl_set_object_lcolor(formulario->button_plus, 0);
        fl_set_object_lcolor(formulario->button_minus, 0);
        if (fl_get_button(formulario->button_profesores) == 0)
            seleccionar_pestana(formulario->button_profesores);
        else if (fl_get_button(formulario->button_companeros) == 0)
            seleccionar_pestana(formulario->button_companeros);
        else if (fl_get_button(formulario->button_sesiones) == 0)
            seleccionar_pestana(formulario->button_sesiones);
        else if (fl_get_button(formulario->button_citas) == 0)
            seleccionar_pestana(formulario->button_citas);
        else if (fl_get_button(formulario->button_notas) == 0)
            seleccionar_pestana(formulario->button_notas);
    }
    else
    {
        fl_deactivate_object(formulario->browser_asignatura);
        fl_deactivate_object(formulario->button_plus);
        fl_deactivate_object(formulario->button_minus);
        fl_deactivate_object(formulario->button_profesores);
        fl_deactivate_object(formulario->button_companeros);
        fl_deactivate_object(formulario->button_sesiones);
        fl_deactivate_object(formulario->button_citas);
        fl_deactivate_object(formulario->button_notas);

        fl_set_object_lcolor(formulario->browser_asignatura, 31);
        fl_set_object_lcolor(formulario->button_plus, 31);
        fl_set_object_lcolor(formulario->button_minus, 31);
        fl_set_object_lcolor(formulario->button_profesores, 31);
        fl_set_object_lcolor(formulario->button_companeros, 31);
        fl_set_object_lcolor(formulario->button_sesiones, 31);
        fl_set_object_lcolor(formulario->button_citas, 31);
        fl_set_object_lcolor(formulario->button_notas, 31);
    }
}
