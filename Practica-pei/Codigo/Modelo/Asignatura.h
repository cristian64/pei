#ifndef ASIGNATURA_H
#define ASIGNATURA_H

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
    Asignatura(const std::string &nombre = "");
    ~Asignatura();
    
    std::string getNombre() const;
    void setNombre(const std::string &nombre);

    void anadirProfesor(Profesor *profesor);
    void anadirCompanero(Companero *companero);
    void anadirNota(Nota *nota);
    void anadirCita(Cita *cita);
    void anadirSesion(Sesion *sesion);

    void quitarProfesor(Profesor *profesor);
    void quitarCompanero(Companero *companero);
    void quitarNota(Nota *nota);
    void quitarCita(Cita *cita);
    void quitarSesion(Sesion *sesion);

    const std::list<Profesor*>& obtenerProfesores() const;
    const std::list<Companero*>& obtenerCompaneros() const;
    const std::list<Nota*>& obtenerNotas() const;
    const std::list<Cita*>& obtenerCitas() const;
    const std::list<Sesion*>& obtenerSesiones() const;

    std::list<Profesor*>& obtenerProfesores();
    std::list<Companero*>& obtenerCompaneros();
    std::list<Nota*>& obtenerNotas();
    std::list<Cita*>& obtenerCitas();
    std::list<Sesion*>& obtenerSesiones();

    std::string toXml() const;
    void fromXml(const std::string &xml);

private:
    std::string nombre;
    std::list<Profesor*> profesores;
    std::list<Companero*> companeros;
    std::list<Nota*> notas;
    std::list<Cita*> citas;
    std::list<Sesion*> sesiones;
};

#endif /* ASIGNATURA_H */
