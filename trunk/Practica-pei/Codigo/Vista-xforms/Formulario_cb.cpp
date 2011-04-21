#include "Formulario.h"
#include "Asignaturas.h"
#include "VistaXformsAsignatura.h"
#include "VistaXformsAsignaturas.h"
#include "Dialogos.h"

/* Callbacks and freeobj handles for form Formulario */

/***************************************
 ***************************************/

void button_abrir_cb( FL_OBJECT * ob,
         long         )
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
         long         )
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
         long         )
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
        asignaturas->anadirAsignatura(new Asignatura(Latin1toUTF8(nombre)));
        asignaturas->refrescarVistas((Vista*) formulario->vdata);
    }
}


/***************************************
 ***************************************/

void button_quitar_cb( FL_OBJECT * ob,
         long         )
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
         long         )
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
         long         )
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
            (*i)->setNombre(Latin1toUTF8(nombre));
            asignaturas->refrescarVistas((Vista*) formulario->vdata);

            // Actualiza el nombre en la lista.
            fl_replace_browser_line(formulario->browser_asignaturas, seleccionada, nombre);
        }
    }
}

/***************************************
 ***************************************/

void seleccionar_pestana(FL_OBJECT *ob)
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
    fl_set_object_lsize(ob, 10);
}

void button_pestana_cb( FL_OBJECT * ob,
         long         )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    seleccionar_pestana(ob);
    
    VistaXformsAsignatura *vistaXformsAsignatura = (VistaXformsAsignatura *) formulario->cdata;
    if (vistaXformsAsignatura != NULL)
        vistaXformsAsignatura->refrescar();
}


/***************************************
 ***************************************/

void button_plus_cb( FL_OBJECT * ob,
         long         )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    // Comprobamos si hay alguna asignatura seleccionada.
    int seleccionada = fl_get_browser(formulario->browser_asignaturas);
    if (seleccionada > 0)
    {
        // Extrae la asignatura a la que se va a añadir algo.
        Asignaturas *asignaturas = dynamic_cast<Asignaturas *>(((Vista*) formulario->vdata)->obtenerModelo());
        std::list<Asignatura*>::const_iterator i = asignaturas->obtenerAsignaturas().begin();
        std::advance(i, seleccionada - 1);
        Asignatura *asignatura = *i;

        if (fl_get_button(formulario->button_profesores) == 0)
        {
            FD_DialogoProfesor *fd_DialogoProfesor = create_form_DialogoProfesor();
            fl_show_form(fd_DialogoProfesor->DialogoProfesor, FL_PLACE_CENTERFREE, FL_FULLBORDER, UTF8ToLatin1("Añadir un nuevo profesor").c_str());

            // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
            fd_DialogoProfesor->DialogoProfesor->u_vdata = asignatura;
            fd_DialogoProfesor->DialogoProfesor->u_cdata = NULL;
            fd_DialogoProfesor->DialogoProfesor->u_ldata = 1;
        }
        else if (fl_get_button(formulario->button_companeros) == 0)
        {
            FD_DialogoCompanero *fd_DialogoCompanero = create_form_DialogoCompanero();
            fl_show_form(fd_DialogoCompanero->DialogoCompanero, FL_PLACE_CENTERFREE, FL_FULLBORDER, UTF8ToLatin1("Añadir un nuevo compañero").c_str());

            // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
            fd_DialogoCompanero->DialogoCompanero->u_vdata = asignatura;
            fd_DialogoCompanero->DialogoCompanero->u_cdata = NULL;
            fd_DialogoCompanero->DialogoCompanero->u_ldata = 2;
        }
        else if (fl_get_button(formulario->button_sesiones) == 0)
        {
            FD_DialogoSesion *fd_DialogoSesion = create_form_DialogoSesion();
            fl_show_form(fd_DialogoSesion->DialogoSesion, FL_PLACE_CENTERFREE, FL_FULLBORDER, UTF8ToLatin1("Añadir una nueva sesión").c_str());

            // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
            fd_DialogoSesion->DialogoSesion->u_vdata = asignatura;
            fd_DialogoSesion->DialogoSesion->u_cdata = NULL;
            fd_DialogoSesion->DialogoSesion->u_ldata = 3;
        }
        else if (fl_get_button(formulario->button_citas) == 0)
        {
            FD_DialogoCita *fd_DialogoCita = create_form_DialogoCita();
            fl_show_form(fd_DialogoCita->DialogoCita, FL_PLACE_CENTERFREE, FL_FULLBORDER, UTF8ToLatin1("Añadir una nueva cita").c_str());

            // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
            fd_DialogoCita->DialogoCita->u_vdata = asignatura;
            fd_DialogoCita->DialogoCita->u_cdata = NULL;
            fd_DialogoCita->DialogoCita->u_ldata = 4;
        }
        else if (fl_get_button(formulario->button_notas) == 0)
        {
            FD_DialogoNota *fd_DialogoNota = create_form_DialogoNota();
            fl_show_form(fd_DialogoNota->DialogoNota, FL_PLACE_CENTERFREE, FL_FULLBORDER, UTF8ToLatin1("Añadir una nueva nota").c_str());

            // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
            fd_DialogoNota->DialogoNota->u_vdata = asignatura;
            fd_DialogoNota->DialogoNota->u_cdata = NULL;
            fd_DialogoNota->DialogoNota->u_ldata = 5;
        }
    }
}


/***************************************
 ***************************************/

void button_minus_cb( FL_OBJECT * ob,
         long         )
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

void browser_asignatura_cb( FL_OBJECT * ,
         long         )
{
    // Para que finalice la aplicación al invocar un callback inexistente.
}

/***************************************
 ***************************************/

void browser_asignatura_dblclick_cb( FL_OBJECT * ob,
         long         )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);

    // Comprobamos si hay alguna asignatura seleccionada.
    Asignatura *asignatura = dynamic_cast<Asignatura *>(((Vista*) formulario->cdata)->obtenerModelo());
    if (asignatura != NULL)
    {
        // Comprobamos si hay algún elemento seleccionado.
        int seleccionada = fl_get_browser(formulario->browser_asignatura);
        if (seleccionada > 0)
        {
            if (fl_get_button(formulario->button_profesores) == 0)
            {
                FD_DialogoProfesor *fd_DialogoProfesor = create_form_DialogoProfesor();
                fl_show_form(fd_DialogoProfesor->DialogoProfesor, FL_PLACE_CENTERFREE, FL_FULLBORDER, "Editando el profesor");

                // Extra el elemento e inicializa el diálogo.
                std::list<Profesor*>::const_iterator i = asignatura->obtenerProfesores().begin();
                std::advance(i, seleccionada - 1);
                fl_set_input(fd_DialogoProfesor->input_nombre, UTF8ToLatin1((*i)->getNombre()).c_str());
                fl_set_input(fd_DialogoProfesor->input_email, UTF8ToLatin1((*i)->getEmail()).c_str());

                // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
                fd_DialogoProfesor->DialogoProfesor->u_vdata = asignatura;
                fd_DialogoProfesor->DialogoProfesor->u_cdata = (char*) *i;
                fd_DialogoProfesor->DialogoProfesor->u_ldata = 1;
            }
            else if (fl_get_button(formulario->button_companeros) == 0)
            {
                FD_DialogoCompanero *fd_DialogoCompanero = create_form_DialogoCompanero();
                fl_show_form(fd_DialogoCompanero->DialogoCompanero, FL_PLACE_CENTERFREE, FL_FULLBORDER, UTF8ToLatin1("Editar el compañero").c_str());

                // Extra el elemento e inicializa el diálogo.
                std::list<Companero*>::const_iterator i = asignatura->obtenerCompaneros().begin();
                std::advance(i, seleccionada - 1);
                fl_set_input(fd_DialogoCompanero->input_nombre, UTF8ToLatin1((*i)->getNombre()).c_str());
                fl_set_input(fd_DialogoCompanero->input_email, UTF8ToLatin1((*i)->getEmail()).c_str());

                // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
                fd_DialogoCompanero->DialogoCompanero->u_vdata = asignatura;
                fd_DialogoCompanero->DialogoCompanero->u_cdata = (char*) *i;
                fd_DialogoCompanero->DialogoCompanero->u_ldata = 2;
            }
            else if (fl_get_button(formulario->button_sesiones) == 0)
            {
                FD_DialogoSesion *fd_DialogoSesion = create_form_DialogoSesion();
                fl_show_form(fd_DialogoSesion->DialogoSesion, FL_PLACE_CENTERFREE, FL_FULLBORDER, UTF8ToLatin1("Editar la sesión").c_str());

                // Extra el elemento e inicializa el diálogo.
                std::list<Sesion*>::const_iterator i = asignatura->obtenerSesiones().begin();
                std::advance(i, seleccionada - 1);
                fl_set_input(fd_DialogoSesion->input_lugar, UTF8ToLatin1((*i)->getLugar()).c_str());
                fl_set_choice(fd_DialogoSesion->choice_dia, (*i)->getDia() + 1);
                fl_set_button(fd_DialogoSesion->checkbutton_teoria, (*i)->getTipo() == 0);
                fl_set_button(fd_DialogoSesion->checkbutton_practicas, (*i)->getTipo() == 1);
                fl_set_spinner_value(fd_DialogoSesion->spinner_hora, (*i)->getFechaInicio().hora);
                fl_set_spinner_value(fd_DialogoSesion->spinner_minuto, (*i)->getFechaInicio().minuto);
                fl_set_spinner_value(fd_DialogoSesion->spinner_segundo, (*i)->getFechaInicio().segundo);
                fl_set_spinner_value(fd_DialogoSesion->spinner_hora2, (*i)->getFechaFin().hora);
                fl_set_spinner_value(fd_DialogoSesion->spinner_minuto2, (*i)->getFechaFin().minuto);
                fl_set_spinner_value(fd_DialogoSesion->spinner_segundo2, (*i)->getFechaFin().segundo);

                // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
                fd_DialogoSesion->DialogoSesion->u_vdata = asignatura;
                fd_DialogoSesion->DialogoSesion->u_cdata = (char*) *i;
                fd_DialogoSesion->DialogoSesion->u_ldata = 3;
            }
            else if (fl_get_button(formulario->button_citas) == 0)
            {
                FD_DialogoCita *fd_DialogoCita = create_form_DialogoCita();
                fl_show_form(fd_DialogoCita->DialogoCita, FL_PLACE_CENTERFREE, FL_FULLBORDER, "Editar la cita");

                // Extra el elemento e inicializa el diálogo.
                std::list<Cita*>::const_iterator i = asignatura->obtenerCitas().begin();
                std::advance(i, seleccionada - 1);
                fl_set_input(fd_DialogoCita->input_descripcion, UTF8ToLatin1((*i)->getDescripcion()).c_str());
                fl_set_spinner_value(fd_DialogoCita->spinner_dia, (*i)->getFecha().dia);
                fl_set_spinner_value(fd_DialogoCita->spinner_mes, (*i)->getFecha().mes);
                fl_set_spinner_value(fd_DialogoCita->spinner_ano, (*i)->getFecha().ano);
                fl_set_spinner_value(fd_DialogoCita->spinner_hora, (*i)->getFecha().hora);
                fl_set_spinner_value(fd_DialogoCita->spinner_minuto, (*i)->getFecha().minuto);
                fl_set_spinner_value(fd_DialogoCita->spinner_segundo, (*i)->getFecha().segundo);
                fl_set_spinner_value(fd_DialogoCita->spinner_duracion, (*i)->getDuracion());

                // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
                fd_DialogoCita->DialogoCita->u_vdata = asignatura;
                fd_DialogoCita->DialogoCita->u_cdata = (char*) *i;
                fd_DialogoCita->DialogoCita->u_ldata = 4;
            }
            else if (fl_get_button(formulario->button_notas) == 0)
            {
                FD_DialogoNota *fd_DialogoNota = create_form_DialogoNota();
                fl_show_form(fd_DialogoNota->DialogoNota, FL_PLACE_CENTERFREE, FL_FULLBORDER, "Editar la nota");

                // Extra el elemento e inicializa el diálogo.
                std::list<Nota*>::const_iterator i = asignatura->obtenerNotas().begin();
                std::advance(i, seleccionada - 1);
                fl_set_input(fd_DialogoNota->input_descripcion, UTF8ToLatin1((*i)->getDescripcion()).c_str());
                fl_set_spinner_value(fd_DialogoNota->spinner_nota, (*i)->getNota());

                // Se proporciona el modelo con la asignatura y NULL porque queremos añadir.
                fd_DialogoNota->DialogoNota->u_vdata = asignatura;
                fd_DialogoNota->DialogoNota->u_cdata = (char*) *i;
                fd_DialogoNota->DialogoNota->u_ldata = 5;
            }
        }
    }
}
