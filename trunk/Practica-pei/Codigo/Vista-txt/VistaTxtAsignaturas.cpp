#include "VistaTxtAsignaturas.h"
#include <iostream>
#include <iomanip>
#include "Auxiliar.h"

VistaTxtAsignaturas::VistaTxtAsignaturas(Asignaturas *asignaturas)
{
    ponerModelo(asignaturas);
}

void VistaTxtAsignaturas::refrescar()
{

    std::cout << "\e[45m\e[1m\e[37m" << rellenar("ASIGNATURAS", " ", columnas, true, true) << "\e[0m" << std::endl;
    std::cout << "\e[45m\e[1m\e[37m" << rellenar("", "-", columnas, true, false) << "\e[0m" << std::endl;

    if (modelo != NULL)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        std::list<Asignatura*>::const_iterator i = asignaturas->obtenerAsignaturas().begin();
        for (; i != asignaturas->obtenerAsignaturas().end(); i++)
        {
            std::cout << "\e[45m\e[1m\e[37m" << rellenar(" " + (*i)->getNombre(), " ", columnas, false, true) << "\e[0m" << std::endl;
        }
    }
    
    std::cout << "\e[45m\e[1m\e[37m" << rellenar("", " ", columnas, true, false) << "\e[0m" << std::endl << std::endl << std::endl;
}