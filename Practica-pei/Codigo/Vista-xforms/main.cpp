#include "Formulario.h"
#include "Asignaturas.h"
#include "VistaXformsAsignaturas.h"
#include "VistaXformsAsignatura.h"

int
main( int    argc,
      char * argv[ ] )
{
    FD_Formulario *fd_Formulario;

    fl_initialize( &argc, argv, 0, 0, 0 );
    fd_Formulario = create_form_Formulario( );

    // Se crea el modelo y la vista.
    Asignaturas asignaturas;
    VistaXformsAsignaturas vistaXformsAsignaturas;
    vistaXformsAsignaturas.formulario = fd_Formulario;
    vistaXformsAsignaturas.ponerModelo(&asignaturas);
    asignaturas.cargar("ejemplo1.xml");
    asignaturas.refrescarVistas();
    VistaXformsAsignatura vistaXformsAsignatura;
    vistaXformsAsignatura.formulario = fd_Formulario;

    // Se asocia a cada objeto del formulario las vistas para que puedan manipular el modelo de cada vista.
    fd_Formulario->vdata = &vistaXformsAsignaturas;
    fd_Formulario->cdata = (char*) (&vistaXformsAsignatura);

    /* Show the first form */

    fl_show_form( fd_Formulario->Formulario, FL_PLACE_CENTERFREE, FL_FULLBORDER, "Vista Xforms" );

    fl_do_forms( );

    if ( fl_form_is_visible( fd_Formulario->Formulario ) )
        fl_hide_form( fd_Formulario->Formulario );
    fl_free( fd_Formulario );
    fl_finish( );

    return 0;
}
