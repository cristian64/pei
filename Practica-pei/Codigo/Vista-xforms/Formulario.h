/* Header file generated by fdesign on Mon Apr 18 21:56:27 2011 */

#ifndef FD_Formulario_h_
#define FD_Formulario_h_

#include <forms.h>

/* Callbacks, globals and object handlers */

extern void button_abrir_cb( FL_OBJECT *, long );
extern void button_guardar_cb( FL_OBJECT *, long );
extern void button_anadir_cb( FL_OBJECT *, long );
extern void button_quitar_cb( FL_OBJECT *, long );
extern void browser_asignaturas_cb( FL_OBJECT *, long );
extern void browser_asignaturas_dblclick_cb( FL_OBJECT *, long );
extern void seleccionar_pestana(FL_OBJECT *ob);
extern void button_pestana_cb( FL_OBJECT *, long );
extern void button_plus_cb( FL_OBJECT *, long );
extern void button_minus_cb( FL_OBJECT *, long );
extern void browser_asignatura_cb( FL_OBJECT *, long );
extern void browser_asignatura_dblclick_cb( FL_OBJECT *, long );


/* Forms and Objects */

typedef struct {
    FL_FORM   * Formulario;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * button_abrir;
    FL_OBJECT * button_guardar;
    FL_OBJECT * button_anadir;
    FL_OBJECT * button_quitar;
    FL_OBJECT * text_lista;
    FL_OBJECT * browser_asignaturas;
    FL_OBJECT * button_profesores;
    FL_OBJECT * button_companeros;
    FL_OBJECT * button_sesiones;
    FL_OBJECT * button_citas;
    FL_OBJECT * button_notas;
    FL_OBJECT * button_plus;
    FL_OBJECT * button_minus;
    FL_OBJECT * browser_asignatura;
} FD_Formulario;

extern FD_Formulario * create_form_Formulario( void );

#endif /* FD_Formulario_h_ */
