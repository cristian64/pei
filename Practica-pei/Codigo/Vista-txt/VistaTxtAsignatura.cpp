#include "VistaTxtAsignatura.h"
#include <iostream>
#include <iomanip>
#include "Auxiliar.h"

VistaTxtAsignatura::VistaTxtAsignatura(Asignatura *asignatura)
{
    ponerModelo(asignatura);
}

void VistaTxtAsignatura::refrescar()
{
    if (modelo != NULL)
    {
        Asignatura *asignatura = static_cast<Asignatura*>(modelo);
        
        std::cout << "\e[46m\e[1m\e[37m" << rellenar(asignatura->getNombre(), " ", columnas, true, true) << "\e[0m" << std::endl;
        std::cout << "\e[46m\e[1m\e[37m" << rellenar("", "-", columnas, true, false) << "\e[0m" << std::endl;

        std::cout << "\e[46m\e[1m\e[37m" << rellenar(" Profesores", " ", columnas, false, true) << "\e[0m" << std::endl;
        const std::list<Profesor*> profesores = asignatura->obtenerProfesores();
        for (std::list<Profesor*>::const_iterator i = profesores.begin(); i != profesores.end(); i++)
        {
            std::cout << "\e[46m\e[1m\e[37m" << rellenar("       · " + (*i)->getNombre(), " ", columnas, false, true) << "\e[0m" << std::endl;
        }

        std::cout << "\e[46m\e[1m\e[37m" << rellenar(" Compañeros", " ", columnas, false, true) << "\e[0m" << std::endl;
        const std::list<Companero*> companeros = asignatura->obtenerCompaneros();
        for (std::list<Companero*>::const_iterator j = companeros.begin(); j != companeros.end(); j++)
        {
            std::cout << "\e[46m\e[1m\e[37m" << rellenar("       · " + (*j)->getNombre(), " ", columnas, false, true) << "\e[0m" << std::endl;
        }

        std::cout << "\e[46m\e[1m\e[37m" << rellenar(" Notas", " ", columnas, false, true) << "\e[0m" << std::endl;
        const std::list<Nota*> notas = asignatura->obtenerNotas();
        for (std::list<Nota*>::const_iterator i = notas.begin(); i != notas.end(); i++)
        {
            std::cout << "\e[46m\e[1m\e[37m" << rellenar("       · " + (*i)->getDescripcion(), " ", columnas, false, true) << "\e[0m" << std::endl;
        }

        std::cout << "\e[46m\e[1m\e[37m" << rellenar(" Citas", " ", columnas, false, true) << "\e[0m" << std::endl;
        const std::list<Cita*> citas = asignatura->obtenerCitas();
        for (std::list<Cita*>::const_iterator i = citas.begin(); i != citas.end(); i++)
        {
            std::cout << "\e[46m\e[1m\e[37m" << rellenar("       · " + (*i)->getDescripcion(), " ", columnas, false, true) << "\e[0m" << std::endl;
        }

        std::cout << "\e[46m\e[1m\e[37m" << rellenar(" Sesiones", " ", columnas, false, true) << "\e[0m" << std::endl;
        const std::list<Sesion*> sesiones = asignatura->obtenerSesiones();
        for (std::list<Sesion*>::const_iterator i = sesiones.begin(); i != sesiones.end(); i++)
        {
            std::cout << "\e[46m\e[1m\e[37m" << rellenar("       · " + (*i)->getLugar(), " ", columnas, false, true) << "\e[0m" << std::endl;
        }
    }
    else
    {
        std::cout << "\e[46m\e[1m\e[37m" << "\e[46m\e[1m\e[37m" << rellenar("Sin asignatura seleccionada en la vista", " ", columnas, true, true) << "\e[0m" << std::endl;
        std::cout << "\e[46m\e[1m\e[37m" << rellenar("", "-", columnas, true, false) << "\e[0m" << std::endl;
    }

    std::cout << "\e[46m\e[1m\e[37m" << rellenar("", " ", columnas, true, false) << "\e[0m" << std::endl << std::endl << std::endl;
}