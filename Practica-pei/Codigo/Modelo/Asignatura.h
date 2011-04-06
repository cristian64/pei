#ifndef ASIGNATURA_H
#define	ASIGNATURA_H

#include "Modelo.h"
#include "Profesor.h"
#include "Companero.h"
#include "Nota.h"
#include "Cita.h"
#include "Sesion.h"
#include <string>
#include <list>

class Asignatura : public Modelo
{
public:
    Asignatura(const std::string &nombre);
    ~Asignatura();
    
    std::string getNombre() const;
    void setNombre(const std::string &nombre);

    void anadirProfesor(Profesor *profesor);
    void anadirCompanero(Companero *companero);
    void anadirNota(Nota *nota);
    void anadirCita(Cita *cita);
    void anadirSesionTeoria(Sesion *sesion);

    void quitarProfesor(Profesor *profesor);
    void quitarCompanero(Companero *companero);
    void quitarNota(Nota *nota);
    void quitarCita(Cita *cita);
    void quitarSesionTeoria(Sesion *sesion);

    std::list<Profesor*> obtenerProfesores() const;
    std::list<Companero*> obtenerCompaneros() const;
    std::list<Nota*> obtenerNotas() const;
    std::list<Cita*> obtenerCitas() const;
    std::list<Sesion*> obtenerSesiones() const;

private:
    std::string nombre;
    std::list<Profesor*> profesores;
    std::list<Companero*> companeros;
    std::list<Nota*> notas;
    std::list<Cita*> citas;
    std::list<Sesion*> sesiones;
};

#endif	/* ASIGNATURA_H */
