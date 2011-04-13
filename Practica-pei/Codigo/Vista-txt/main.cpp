#include <iostream>
using namespace std;

#include "Asignaturas.h"
#include "VistaTxtAsignaturas.h"

int main()
{
    // Se cargan las asignaturas desde el fichero externo.
    Asignaturas asignaturas;
    asignaturas.cargar("ejemplo1.xml");

    // Se crea la vista de asignaturas y se asocia (internamente, crea más vistas que se asocian a cada asignatura concreta).
    VistaTxtAsignaturas vista;
    vista.ponerModelo(&asignaturas);

    // Refresca la vista general de asignaturas y también una asignatura concreta (para ver que funciona la asociación interna).
    asignaturas.refrescarVistas();
    asignaturas.obtenerAsignaturas().front()->refrescarVistas();
}
