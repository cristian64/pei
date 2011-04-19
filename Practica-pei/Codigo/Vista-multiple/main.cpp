#include <QtGui/QApplication>
#include "Asignaturas.h"
#include "MainWindow.h"
#include "Formulario.h"
#include "VistaXformsAsignaturas.h"
#include "VistaXformsAsignatura.h"
#include "../Vista-xforms/VistaXformsAsignaturas.h"
#include <pthread.h>
#include <iostream>
using namespace std;

typedef struct
{
    int argc;
    char **argv;
    Asignaturas *asignaturas;
} Parameters;

void* vistaXforms(void *parameters)
{
    FD_Formulario *fd_Formulario;

    fl_initialize(&(((Parameters*) parameters)->argc), ((Parameters*) parameters)->argv, 0, 0, 0 );
    fd_Formulario = create_form_Formulario( );

    // Se crea el modelo y la vista.
    VistaXformsAsignaturas vistaXformsAsignaturas;
    vistaXformsAsignaturas.formulario = fd_Formulario;
    vistaXformsAsignaturas.ponerModelo(((Parameters*) parameters)->asignaturas);
    vistaXformsAsignaturas.refrescar();
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
    
    pthread_exit(0);
}

int main(int argc, char **argv)
{
    Asignaturas asignaturas;
    asignaturas.cargar("ejemplo1.xml");
    asignaturas.refrescarVistas();
    QApplication a(argc, argv);
    MainWindow w(&asignaturas);
    w.show();
    
    Parameters parameters;
    parameters.argc = argc;
    parameters.argv = argv;
    parameters.asignaturas = &asignaturas;
    
    pthread_t vistaQt_thread;
    pthread_create(&vistaQt_thread, NULL, vistaXforms, &parameters);
    
    return a.exec();
    pthread_join(vistaQt_thread, NULL);
}

