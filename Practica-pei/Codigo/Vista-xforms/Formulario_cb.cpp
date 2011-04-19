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

void button_profesores_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void button_companeros_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void button_sesiones_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void button_citas_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void button_notas_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void button_plus_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void button_minus_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void browser_asignatura_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}

/***************************************
 ***************************************/

void browser_asignatura_dblclick_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}
