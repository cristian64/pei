#include "Formulario.h"

/* Callbacks and freeobj handles for form Formulario */

/***************************************
 ***************************************/

void button_abrir_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);
    if (formulario != NULL)
    {
        fl_add_browser_line(formulario->browser_asignaturas, "pollaca");
    }
}


/***************************************
 ***************************************/

void button_guardar_cb( FL_OBJECT * ob,
         long        data )
{
    FD_Formulario *formulario = static_cast<FD_Formulario *>(ob->form->fdui);
    if (formulario != NULL)
    {
        fl_clear_browser(formulario->browser_asignaturas);
    }
}


/***************************************
 ***************************************/

void button_anadir_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void button_quitar_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
}


/***************************************
 ***************************************/

void browser_asignaturas_cb( FL_OBJECT * ob,
         long        data )
{
    /* Fill-in code for callback here */
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




