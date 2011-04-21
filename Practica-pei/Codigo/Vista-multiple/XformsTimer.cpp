#include "XformsTimer.h"

XformsTimer::XformsTimer(int argc, char **argv, Asignaturas *asignaturas)
{
    connect(this, SIGNAL(timeout()), this, SLOT(ejecutar()));

    fl_initialize(&argc, argv, 0, 0, 0 );
    fd_Formulario = create_form_Formulario( );

    // Se crea el modelo y la vista.
    VistaXformsAsignatura vistaXformsAsignatura;
    vistaXformsAsignatura.formulario = fd_Formulario;
    VistaXformsAsignaturas vistaXformsAsignaturas;
    vistaXformsAsignaturas.formulario = fd_Formulario;
    vistaXformsAsignaturas.vistaXformsAsignatura = &vistaXformsAsignatura;
    vistaXformsAsignaturas.ponerModelo(asignaturas);
    vistaXformsAsignaturas.refrescar();

    // Se asocia a cada objeto del formulario las vistas para que puedan manipular el modelo de cada vista.
    fd_Formulario->vdata = &vistaXformsAsignaturas;
    fd_Formulario->cdata = (char*) (&vistaXformsAsignatura);

    fl_show_form( fd_Formulario->Formulario, FL_PLACE_CENTERFREE, FL_FULLBORDER, "Vista Xforms" );
    fl_check_forms();
}

XformsTimer::~XformsTimer()
{
    if ( fl_form_is_visible( fd_Formulario->Formulario ) )
        fl_hide_form( fd_Formulario->Formulario );
    fl_free( fd_Formulario );
    fl_finish( );
}

void XformsTimer::ejecutar()
{
    fl_check_forms();
}
