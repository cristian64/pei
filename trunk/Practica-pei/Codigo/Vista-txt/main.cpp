#include <iostream>
using namespace std;

#include "Asignaturas.h"
#include "VistaTxtAsignaturas.h"
#include "VistaTxtAsignatura.h"

int main()
{
    Asignaturas asignaturas;
    Asignatura *asignatura = new Asignatura("Educación física");
    
    VistaTxtAsignaturas vista(&asignaturas);
    asignaturas.anadirVista(&vista);
    asignaturas.anadirAsignatura(new Asignatura("Matemáticas"));
    asignaturas.refrescarVistas();
    asignaturas.anadirAsignatura(new Asignatura("Química"));
    asignaturas.anadirAsignatura(new Asignatura("Historia"));
    asignaturas.anadirAsignatura(asignatura);
    asignaturas.refrescarVistas();

    VistaTxtAsignatura vista2(asignatura);
    vista2.refrescar();
    Profesor *profesor = new Profesor();
    profesor->setNombre("Antonio Pérez");    
    asignatura->anadirProfesor(profesor);

    Companero *companero = new Companero();
    companero->setNombre("Ernesto García");
    asignatura->anadirCompanero(companero);
    vista2.refrescar();

    cout << asignaturas.toXml() << endl;
    asignaturas.fromXml(asignaturas.toXml());
}
