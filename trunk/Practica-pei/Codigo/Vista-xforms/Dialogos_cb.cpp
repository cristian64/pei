#include "Dialogos.h"
#include "Modelo.h"
#include "Asignatura.h"

/* Callbacks and freeobj handles for form DialogoProfesor */

/***************************************
 ***************************************/

void input_nombre_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void input_email_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void button_aceptar_cb( FL_OBJECT * ob,
         long        data )
{
    switch (ob->form->u_ldata)
    {
        case 1:
        {
            FD_DialogoProfesor *dialogo = (FD_DialogoProfesor *) ob->form->fdui;

            // Se obtiene el elemento desde los parámetros de usuario.
            Profesor *profesor = (Profesor *) ob->form->u_cdata;

            //  Si fuera NULL, lo creamos (porque significa que se va a añadir uno nuevo).
            if (profesor == NULL)
            {
                profesor = new Profesor();
                ((Asignatura*) ob->form->u_vdata)->anadirProfesor(profesor);
            }

            // Se establecen los valores.
            profesor->setNombre(fl_get_input(dialogo->input_nombre));
            profesor->setEmail(fl_get_input(dialogo->input_email));

            // Se refrescan las vistas.
            ((Asignatura*) ob->form->u_vdata)->refrescarVistas();
            break;
        }
        case 2:
        {
            FD_DialogoCompanero *dialogo = (FD_DialogoCompanero *) ob->form->fdui;

            // Se obtiene el elemento desde los parámetros de usuario.
            Companero *companero = (Companero *) ob->form->u_cdata;

            //  Si fuera NULL, lo creamos (porque significa que se va a añadir uno nuevo).
            if (companero == NULL)
            {
                companero = new Companero();
                ((Asignatura*) ob->form->u_vdata)->anadirCompanero(companero);
            }

            // Se establecen los valores.
            companero->setNombre(fl_get_input(dialogo->input_nombre));
            companero->setEmail(fl_get_input(dialogo->input_email));

            // Se refrescan las vistas.
            ((Asignatura*) ob->form->u_vdata)->refrescarVistas();
            break;
        }
        case 3:
        {
            FD_DialogoSesion *dialogo = (FD_DialogoSesion *) ob->form->fdui;

            // Se obtiene el elemento desde los parámetros de usuario.
            Sesion *sesion = (Sesion *) ob->form->u_cdata;

            //  Si fuera NULL, lo creamos (porque significa que se va a añadir uno nuevo).
            if (sesion == NULL)
            {
                sesion = new Sesion();
                ((Asignatura*) ob->form->u_vdata)->anadirSesion(sesion);
            }

            // Se establecen los valores.
            sesion->setLugar(fl_get_input(dialogo->input_lugar));
            sesion->setDia((Sesion::Dia) fl_get_choice(dialogo->choice_dia));
            sesion->setTipo((Sesion::Tipo) (fl_get_button(dialogo->checkbutton_practicas) == 1));
            Fecha fechaInicio;
            fechaInicio.hora = (int) fl_get_spinner_value(dialogo->spinner_hora);
            fechaInicio.minuto = (int) fl_get_spinner_value(dialogo->spinner_minuto);
            fechaInicio.segundo = (int) fl_get_spinner_value(dialogo->spinner_segundo);
            sesion->setFechaInicio(fechaInicio);
            Fecha fechaFin;
            fechaFin.hora = (int) fl_get_spinner_value(dialogo->spinner_hora2);
            fechaFin.minuto = (int) fl_get_spinner_value(dialogo->spinner_minuto2);
            fechaFin.segundo = (int) fl_get_spinner_value(dialogo->spinner_segundo2);
            sesion->setFechaFin(fechaFin);

            // Se refrescan las vistas.
            ((Asignatura*) ob->form->u_vdata)->refrescarVistas();
            break;
        }
        case 4:
        {
            FD_DialogoCita *dialogo = (FD_DialogoCita *) ob->form->fdui;

            // Se obtiene el elemento desde los parámetros de usuario.
            Cita *cita = (Cita *) ob->form->u_cdata;

            //  Si fuera NULL, lo creamos (porque significa que se va a añadir uno nuevo).
            if (cita == NULL)
            {
                cita = new Cita();
                ((Asignatura*) ob->form->u_vdata)->anadirCita(cita);
            }

            // Se establecen los valores.
            cita->setDescripcion(fl_get_input(dialogo->input_descripcion));
            Fecha fecha;
            fecha.dia = (int) fl_get_spinner_value(dialogo->spinner_dia);
            fecha.mes = (int) fl_get_spinner_value(dialogo->spinner_mes);
            fecha.ano = (int) fl_get_spinner_value(dialogo->spinner_ano);
            fecha.hora = (int) fl_get_spinner_value(dialogo->spinner_hora);
            fecha.minuto = (int) fl_get_spinner_value(dialogo->spinner_minuto);
            fecha.segundo = (int) fl_get_spinner_value(dialogo->spinner_segundo);
            cita->setFecha(fecha);
            cita->setDuracion((int) fl_get_spinner_value(dialogo->spinner_duracion));

            // Se refrescan las vistas.
            ((Asignatura*) ob->form->u_vdata)->refrescarVistas();
            break;
        }
        case 5:
        {
            FD_DialogoNota *dialogo = (FD_DialogoNota *) ob->form->fdui;

            // Se obtiene el elemento desde los parámetros de usuario.
            Nota *nota = (Nota *) ob->form->u_cdata;

            //  Si fuera NULL, lo creamos (porque significa que se va a añadir uno nuevo).
            if (nota == NULL)
            {
                nota = new Nota();
                ((Asignatura*) ob->form->u_vdata)->anadirNota(nota);
            }

            // Se establecen los valores.
            nota->setDescripcion(fl_get_input(dialogo->input_descripcion));
            nota->setNota((float) fl_get_spinner_value(dialogo->spinner_nota));

            // Se refrescan las vistas.
            ((Asignatura*) ob->form->u_vdata)->refrescarVistas();
            break;
        }
    }

    fl_hide_form(ob->form);
    fl_free(ob->form);
}


/***************************************
 ***************************************/

void button_cancelar_cb( FL_OBJECT * ob,
         long        data )
{
    fl_hide_form(ob->form);
    fl_free(ob->form);
}


/* Callbacks and freeobj handles for form DialogoSesion */

/***************************************
 ***************************************/

void input_lugar_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_hora_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_minuto_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_segundo_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void choice_dia_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void checkbutton_practicas_cb( FL_OBJECT * ob,
         long        data )
{
    FD_DialogoSesion *dialogo = (FD_DialogoSesion *) ob->form->fdui;
    fl_set_button(dialogo->checkbutton_teoria, 0);
}


/***************************************
 ***************************************/

void checkbutton_teoria_cb( FL_OBJECT * ob,
         long        data )
{
    FD_DialogoSesion *dialogo = (FD_DialogoSesion *) ob->form->fdui;
    fl_set_button(dialogo->checkbutton_practicas, 0);
}


/***************************************
 ***************************************/

void spinner_hora2_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_minuto2_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_segundo2_cb( FL_OBJECT * ob,
         long        data )
{

}




/* Callbacks and freeobj handles for form DialogoCita */

/***************************************
 ***************************************/

void input_descripcion_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_duracion_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_dia_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_mes_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_ano_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

void spinner_nota_cb( FL_OBJECT * ob,
         long        data )
{

}


/***************************************
 ***************************************/

int form_atclose(FL_FORM *form, void *data)
{
    fl_hide_form(form);
    fl_free(form);
    return 0;
}

