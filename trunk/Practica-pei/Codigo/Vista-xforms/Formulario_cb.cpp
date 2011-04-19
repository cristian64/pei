#include "Formulario.h"
#include "Asignaturas.h"
#include "VistaXformsAsignatura.h"
#include "VistaXformsAsignaturas.h"

/* Callbacks and freeobj handles for form Formulario */

/***************************************
 ***************************************/

void button_abrir_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);
    
    fl_set_fselector_title("Selecciona el fichero");
    const char *rutaFichero = fl_show_fselector(NULL, "./", "", "");
    if (rutaFichero != NULL)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas *>(((Vista*) formulario->vdata)->obtenerModelo());
        asignaturas->cargar(rutaFichero);
        asignaturas->refrescarVistas();
    }
}


/***************************************
 ***************************************/

void button_guardar_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    fl_set_fselector_title("Selecciona el fichero");
    const char *rutaFichero = fl_show_fselector(NULL, "./", "", "");
    if (rutaFichero != NULL)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas *>(((Vista*) formulario->vdata)->obtenerModelo());
        asignaturas->guardar(rutaFichero);
    }
}


/***************************************
 ***************************************/

void button_anadir_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    // Solicita el nombre para la nueva asignatura.
    const char *nombre = fl_show_input("Nombre de la asignatura:", "");
    if (nombre != NULL)
    {
        // Añade la asignatura a la lista.
        fl_addto_browser(formulario->browser_asignaturas, nombre);

        // Referencia al modelo a través de los punteros auxiliares y crea la asignatura y refresca.
        Asignaturas *asignaturas = dynamic_cast<Asignaturas *>(((Vista*) formulario->vdata)->obtenerModelo());
        asignaturas->anadirAsignatura(new Asignatura(nombre));
        asignaturas->refrescarVistas((Vista*) formulario->vdata);
    }
}


/***************************************
 ***************************************/

void button_quitar_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    int seleccionada = fl_get_browser(formulario->browser_asignaturas);
    if (seleccionada > 0)
    {
        // Elimina la asignatura del modelo y refresca todas las vistas menos esta.
        Asignaturas *asignaturas = dynamic_cast<Asignaturas *>(((Vista*) formulario->vdata)->obtenerModelo());
        std::list<Asignatura*>::const_iterator i = asignaturas->obtenerAsignaturas().begin();
        std::advance(i, seleccionada - 1);
        asignaturas->quitarAsignatura(*i);
        asignaturas->refrescarVistas((Vista*) formulario->vdata);

        // Elimina la asignatura de la lista y, si hay más asignaturas, selecciona la de abajo.
        fl_delete_browser_line(formulario->browser_asignaturas, seleccionada);
        int lineas = fl_get_browser_maxline(formulario->browser_asignaturas);
        fl_select_browser_line(formulario->browser_asignaturas, (lineas < seleccionada) ? lineas : seleccionada);

        // Invoca el callback porque es como si se hubiera seleccionado una nueva asignatura.
        browser_asignaturas_cb(formulario->browser_asignaturas, 0);
    }
}


/***************************************
 ***************************************/

void browser_asignaturas_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    int seleccionada = fl_get_browser(formulario->browser_asignaturas);
    if (seleccionada > 0)
    {
        // Establece una nueva asignatura en la vista principal (que está guardada en cdata del formulario).
        Asignaturas *asignaturas = dynamic_cast<Asignaturas *>(((Vista*) formulario->vdata)->obtenerModelo());
        std::list<Asignatura*>::const_iterator i = asignaturas->obtenerAsignaturas().begin();
        std::advance(i, seleccionada - 1);
        ((VistaXformsAsignatura *) formulario->cdata)->ponerModelo(*i);
    }
    else
    {
        ((VistaXformsAsignatura *) formulario->cdata)->ponerModelo(NULL);
    }
    ((VistaXformsAsignatura *) formulario->cdata)->refrescar();
}


/***************************************
 ***************************************/

void browser_asignaturas_dblclick_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    int seleccionada = fl_get_browser(formulario->browser_asignaturas);
    if (seleccionada > 0)
    {
        // Elimina la asignatura del modelo y refresca todas las vistas menos esta.
        Asignaturas *asignaturas = dynamic_cast<Asignaturas *>(((Vista*) formulario->vdata)->obtenerModelo());
        std::list<Asignatura*>::const_iterator i = asignaturas->obtenerAsignaturas().begin();
        std::advance(i, seleccionada - 1);

        // Solicita el nombre para la nueva asignatura.
        const char *nombre = fl_show_input("Nuevo nombre para la asignatura:", (*i)->getNombre().c_str());
        if (nombre != NULL)
        {
            // Actualiza la asignatura y refresca las vistas (menos la nuestra).
            (*i)->setNombre(nombre);
            asignaturas->refrescarVistas((Vista*) formulario->vdata);

            // Actualiza el nombre en la lista.
            fl_replace_browser_line(formulario->browser_asignaturas, seleccionada, nombre);
        }
    }
}

/***************************************
 ***************************************/

void button_pestana_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    fl_set_button(formulario->button_profesores, 1);
    fl_set_button(formulario->button_companeros, 1);
    fl_set_button(formulario->button_sesiones, 1);
    fl_set_button(formulario->button_citas, 1);
    fl_set_button(formulario->button_notas, 1);
    fl_set_object_lstyle(formulario->button_profesores, 0);
    fl_set_object_lstyle(formulario->button_companeros, 0);
    fl_set_object_lstyle(formulario->button_sesiones, 0);
    fl_set_object_lstyle(formulario->button_citas, 0);
    fl_set_object_lstyle(formulario->button_notas, 0);
    fl_set_object_lcolor(formulario->button_profesores, 17);
    fl_set_object_lcolor(formulario->button_companeros, 17);
    fl_set_object_lcolor(formulario->button_sesiones, 17);
    fl_set_object_lcolor(formulario->button_citas, 17);
    fl_set_object_lcolor(formulario->button_notas, 17);
    fl_set_object_lsize(formulario->button_profesores, 8);
    fl_set_object_lsize(formulario->button_companeros, 8);
    fl_set_object_lsize(formulario->button_sesiones, 8);
    fl_set_object_lsize(formulario->button_citas, 8);
    fl_set_object_lsize(formulario->button_notas, 8);

    fl_set_button(ob, 0);
    fl_set_object_lstyle(ob, 1);
    fl_set_object_lcolor(ob, 0);
    fl_set_object_lsize(ob, 9);
    
    VistaXformsAsignatura *vistaXformsAsignatura = (VistaXformsAsignatura *) formulario->cdata;
    if (vistaXformsAsignatura != NULL)
        vistaXformsAsignatura->refrescar();
}


/***************************************
 ***************************************/

void button_plus_cb( FL_OBJECT * ob,
         long        data )
{

    //TODO: crear formulario correspondiente con el objeto indicado a NULL
}


/***************************************
 ***************************************/

void button_minus_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    int seleccionada = fl_get_browser(formulario->browser_asignatura);
    if (seleccionada > 0)
    {
        Asignatura *asignatura = dynamic_cast<Asignatura *>(((Vista*) formulario->cdata)->obtenerModelo());
        if (asignatura != NULL)
        {
            if (fl_get_button(formulario->button_profesores) == 0)
            {
                // Elimina el profesor del modelo y actualiza todas las vistas menos esta.
                std::list<Profesor*>::const_iterator i = asignatura->obtenerProfesores().begin();
                std::advance(i, seleccionada - 1);
                asignatura->quitarProfesor(*i);
                asignatura->refrescarVistas((Vista*) formulario->cdata);
            }
            else if (fl_get_button(formulario->button_companeros) == 0)
            {
                // Elimina el compañero del modelo y actualiza todas las vistas menos esta.
                std::list<Companero*>::const_iterator i = asignatura->obtenerCompaneros().begin();
                std::advance(i, seleccionada - 1);
                asignatura->quitarCompanero(*i);
                asignatura->refrescarVistas((Vista*) formulario->cdata);
            }
            else if (fl_get_button(formulario->button_sesiones) == 0)
            {
                // Elimina la sesión del modelo y actualiza todas las vistas menos esta.
                std::list<Sesion*>::const_iterator i = asignatura->obtenerSesiones().begin();
                std::advance(i, seleccionada - 1);
                asignatura->quitarSesion(*i);
                asignatura->refrescarVistas((Vista*) formulario->cdata);
            }
            else if (fl_get_button(formulario->button_citas) == 0)
            {
                // Elimina la cita del modelo y actualiza todas las vistas menos esta.
                std::list<Cita*>::const_iterator i = asignatura->obtenerCitas().begin();
                std::advance(i, seleccionada - 1);
                asignatura->quitarCita(*i);
                asignatura->refrescarVistas((Vista*) formulario->cdata);
            }
            else if (fl_get_button(formulario->button_notas) == 0)
            {
                // Elimina la nota del modelo y actualiza todas las vistas menos esta.
                std::list<Nota*>::const_iterator i = asignatura->obtenerNotas().begin();
                std::advance(i, seleccionada - 1);
                asignatura->quitarNota(*i);
                asignatura->refrescarVistas((Vista*) formulario->cdata);
            }

            // Elimina el elemento de la lista y, si hay más elementos, selecciona el siguiente.
            fl_delete_browser_line(formulario->browser_asignatura, seleccionada);
            int lineas = fl_get_browser_maxline(formulario->browser_asignatura);
            fl_select_browser_line(formulario->browser_asignatura, (lineas < seleccionada) ? lineas : seleccionada);
        }
    }
}


/***************************************
 ***************************************/

void browser_asignatura_cb( FL_OBJECT * ob,
         long        data )
{
    
}

/***************************************
 ***************************************/

void browser_asignatura_dblclick_cb( FL_OBJECT * ob,
         long        data )
{
    //TODO: crear formulario correspondiente indicandole el objeto a editar
}
