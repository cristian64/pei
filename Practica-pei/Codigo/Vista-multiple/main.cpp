#include <QtGui/QApplication>
#include "MainWindow.h"
#include "Formulario.h"
#include <pthread.h>
#include <iostream>
using namespace std;

typedef struct
{
    int argc;
    char **argv;
} Parameters;

void* vistaXforms(void *parameters)
{
    FD_Calculadora *fd_Calculadora;

    fl_initialize(&(((Parameters*) parameters)->argc), ((Parameters*) parameters)->argv, 0, 0, 0 );
    fd_Calculadora = create_form_Calculadora( );

    /* Fill-in form initialization code */

    /* Show the first form */

    fl_show_form( fd_Calculadora->Calculadora, FL_PLACE_CENTERFREE, FL_FULLBORDER, "Calculadora" );
    fd_Calculadora->button1->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button2->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button3->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button4->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button5->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button6->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button7->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button8->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button9->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button0->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_plus->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_minus->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_div->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_mult->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_equal->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_c->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_clr->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_min->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_mr->u_vdata = fd_Calculadora->lcd;
    fd_Calculadora->button_sign->u_vdata = fd_Calculadora->lcd;

    fl_do_forms( );

    if ( fl_form_is_visible( fd_Calculadora->Calculadora ) )
        fl_hide_form( fd_Calculadora->Calculadora );
    fl_free( fd_Calculadora );
    fl_finish( );
    
    pthread_exit(0);
}

int main(int argc, char **argv)
{    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    Parameters parameters;
    parameters.argc = argc;
    parameters.argv = argv;
    
	pthread_t vistaQt_thread;
	pthread_create(&vistaQt_thread, NULL, vistaXforms, &parameters);
    return a.exec();
	pthread_join(vistaQt_thread, NULL);
}

