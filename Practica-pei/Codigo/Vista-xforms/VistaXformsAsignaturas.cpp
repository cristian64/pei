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
        else
        {
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
