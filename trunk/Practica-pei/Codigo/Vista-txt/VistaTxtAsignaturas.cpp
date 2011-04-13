#include "VistaTxtAsignaturas.h"
#include <iostream>
#include <iomanip>
#include "Auxiliar.h"

VistaTxtAsignaturas::VistaTxtAsignaturas(Asignaturas *asignaturas)
{
    if (asignaturas != NULL)
    {
        ponerModelo(asignaturas);
        std::list<Asignatura*>::const_iterator i = asignaturas->obtenerAsignaturas().begin();
        for (; i != asignaturas->obtenerAsignaturas().end(); i++)
        {
            VistaTxtAsignatura *vistaTxtAsignatura = new VistaTxtAsignatura(*i);
            vistasTxtAsignatura.push_back(vistaTxtAsignatura);
        }
    }
}

VistaTxtAsignaturas::~VistaTxtAsignaturas()
{
    for (std::list<VistaTxtAsignatura*>::iterator i = vistasTxtAsignatura.begin(); i != vistasTxtAsignatura.end(); i++)
        delete *i;
    vistasTxtAsignatura.clear();
}

void VistaTxtAsignaturas::refrescar()
{
    // Se limpian las vistas anteriores.
    for (std::list<VistaTxtAsignatura*>::iterator i = vistasTxtAsignatura.begin(); i != vistasTxtAsignatura.end(); i++)
        delete *i;
    vistasTxtAsignatura.clear();

    std::cout << "\e[45m\e[1m\e[37m" << rellenar("ASIGNATURAS", " ", columnas, true, true) << "\e[0m" << std::endl;
    std::cout << "\e[45m\e[1m\e[37m" << rellenar("", "-", columnas, true, false) << "\e[0m" << std::endl;

    if (modelo != NULL)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        std::list<Asignatura*>::const_iterator i = asignaturas->obtenerAsignaturas().begin();
        for (; i != asignaturas->obtenerAsignaturas().end(); i++)
        {
            VistaTxtAsignatura *vistaTxtAsignatura = new VistaTxtAsignatura(*i);
            vistasTxtAsignatura.push_back(vistaTxtAsignatura);
            std::cout << "\e[45m\e[1m\e[37m" << rellenar(" " + (*i)->getNombre(), " ", columnas, false, true) << "\e[0m" << std::endl;
        }
    }
    
    std::cout << "\e[45m\e[1m\e[37m" << rellenar("", " ", columnas, true, false) << "\e[0m" << std::endl << std::endl << std::endl;
}