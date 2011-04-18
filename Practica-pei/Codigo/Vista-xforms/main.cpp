#include "Formulario.h"

int
main( int    argc,
      char * argv[ ] )
{
    FD_Formulario *fd_Formulario;

    fl_initialize( &argc, argv, 0, 0, 0 );
    fd_Formulario = create_form_Formulario( );

    /* Fill-in form initialization code */

    /* Show the first form */

    fl_show_form( fd_Formulario->Formulario, FL_PLACE_CENTERFREE, FL_FULLBORDER, "Vista Xforms" );

    fl_do_forms( );

    if ( fl_form_is_visible( fd_Formulario->Formulario ) )
        fl_hide_form( fd_Formulario->Formulario );
    fl_free( fd_Formulario );
    fl_finish( );

    return 0;
}
