/* Header file generated by fdesign on Wed Apr 20 12:23:57 2011 */

#ifndef FD_DialogoProfesor_h_
#define FD_DialogoProfesor_h_

#include <forms.h>

/* Callbacks, globals and object handlers */

extern void input_nombre_cb( FL_OBJECT *, long );
extern void input_email_cb( FL_OBJECT *, long );
extern void button_aceptar_cb( FL_OBJECT *, long );
extern void button_cancelar_cb( FL_OBJECT *, long );

extern void input_lugar_cb( FL_OBJECT *, long );
extern void spinner_hora_cb( FL_OBJECT *, long );
extern void spinner_minuto_cb( FL_OBJECT *, long );
extern void spinner_segundo_cb( FL_OBJECT *, long );
extern void choice_dia_cb( FL_OBJECT *, long );
extern void checkbutton_practicas_cb( FL_OBJECT *, long );
extern void checkbutton_teoria_cb( FL_OBJECT *, long );
extern void spinner_hora2_cb( FL_OBJECT *, long );
extern void spinner_minuto2_cb( FL_OBJECT *, long );
extern void spinner_segundo2_cb( FL_OBJECT *, long );

extern void input_descripcion_cb( FL_OBJECT *, long );
extern void spinner_duracion_cb( FL_OBJECT *, long );
extern void spinner_dia_cb( FL_OBJECT *, long );
extern void spinner_mes_cb( FL_OBJECT *, long );
extern void spinner_ano_cb( FL_OBJECT *, long );

extern void spinner_nota_cb( FL_OBJECT *, long );
extern int form_atclose(FL_FORM *, void *);

/* Forms and Objects */

typedef struct {
    FL_FORM   * DialogoProfesor;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * input_nombre;
    FL_OBJECT * input_email;
    FL_OBJECT * button_aceptar;
    FL_OBJECT * button_cancelar;
} FD_DialogoProfesor;

extern FD_DialogoProfesor * create_form_DialogoProfesor( void );
typedef struct {
    FL_FORM   * DialogoCompanero;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * input_nombre;
    FL_OBJECT * input_email;
    FL_OBJECT * button_aceptar;
    FL_OBJECT * button_cancelar;
} FD_DialogoCompanero;

extern FD_DialogoCompanero * create_form_DialogoCompanero( void );
typedef struct {
    FL_FORM   * DialogoSesion;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * input_lugar;
    FL_OBJECT * button_aceptar;
    FL_OBJECT * button_cancelar;
    FL_OBJECT * spinner_hora;
    FL_OBJECT * spinner_minuto;
    FL_OBJECT * spinner_segundo;
    FL_OBJECT * choice_dia;
    FL_OBJECT * checkbutton_practicas;
    FL_OBJECT * checkbutton_teoria;
    FL_OBJECT * spinner_hora2;
    FL_OBJECT * spinner_minuto2;
    FL_OBJECT * spinner_segundo2;
} FD_DialogoSesion;

extern FD_DialogoSesion * create_form_DialogoSesion( void );
typedef struct {
    FL_FORM   * DialogoCita;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * input_descripcion;
    FL_OBJECT * button_aceptar;
    FL_OBJECT * button_cancelar;
    FL_OBJECT * spinner_duracion;
    FL_OBJECT * spinner_dia;
    FL_OBJECT * spinner_mes;
    FL_OBJECT * spinner_ano;
    FL_OBJECT * spinner_hora;
    FL_OBJECT * spinner_minuto;
    FL_OBJECT * spinner_segundo;
} FD_DialogoCita;

extern FD_DialogoCita * create_form_DialogoCita( void );
typedef struct {
    FL_FORM   * DialogoNota;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * input_descripcion;
    FL_OBJECT * button_aceptar;
    FL_OBJECT * button_cancelar;
    FL_OBJECT * spinner_nota;
} FD_DialogoNota;

extern FD_DialogoNota * create_form_DialogoNota( void );

#endif /* FD_DialogoProfesor_h_ */
