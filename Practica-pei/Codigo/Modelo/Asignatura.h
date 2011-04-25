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

/**
 * Clase que representa una asignatura y es un modelo al que pueden conectarse vistas.
 * Una asignatura contiene profesores, compañeros, notas, citas de exámenes y sesiones de clase.
 */
class Asignatura : public Modelo
{
public:
    /**
     * Constructor por defecto que recibe el nombre de la asignatura.
     * @param nombre Nombre dela asignatura.
     */
    Asignatura(const std::string &nombre = "");

    /**
     * Destructor por defecto.
     * Libera la memoria reservada para los profesores, compañeros, etc.
     */
    ~Asignatura();

    /**
     * Obtiene el nombre de la asignatura.
     * @return Cadena de caracteres con el nombre de la asignatura.
     */
    std::string getNombre() const;

    /**
     * Asigna un nuevo nombre a la asignatura.
     * @param nombre Cadena de caracteres con el nuevo nombre de la asignatura.
     */
    void setNombre(const std::string &nombre);

    /**
     * Añade un nuevo profesor a la asignatura.
     * Una vez asignado el puntero, el usuario NO tiene que hacerse cargo de liberar la memoria.
     * @param profesor Referencia al profesor que se va a añadir.
     */
    void anadirProfesor(Profesor *profesor);

    /**
     * Añade un nuevo compañero a la asignatura.
     * Una vez asignado el puntero, el usuario NO tiene que hacerse cargo de liberar la memoria.
     * @param companero Referencia al compañero que se va a añadir.
     */
    void anadirCompanero(Companero *companero);

    /**
     * Añade una nueva nota a la asignatura.
     * Una vez asignado el puntero, el usuario NO tiene que hacerse cargo de liberar la memoria.
     * @param nota Referencia a la nota que se va a añadir.
     */
    void anadirNota(Nota *nota);

    /**
     * Añade una nueva cita a la asignatura.
     * Una vez asignado el puntero, el usuario NO tiene que hacerse cargo de liberar la memoria.
     * @param cita Referencia a la cita que se va a añadir.
     */
    void anadirCita(Cita *cita);

    /**
     * Añade una nueva sesión a la asignatura.
     * Una vez asignado el puntero, el usuario NO tiene que hacerse cargo de liberar la memoria.
     * @param sesion Referencia a la sesión que se va a añadir.
     */
    void anadirSesion(Sesion *sesion);

    /**
     * Quita el profesor de la asignatura y libera la memoria.
     * @param profesor Puntero al profesor que se va a eliminar.
     */
    void quitarProfesor(Profesor *profesor);

    /**
     * Quita el compañero de la asignatura y libera la memoria.
     * @param companero Puntero al compañero que se va a eliminar.
     */
    void quitarCompanero(Companero *companero);

    /**
     * Quita la nota de la asignatura y libera la memoria.
     * @param nota Puntero a la nota que se va a quitar.
     */
    void quitarNota(Nota *nota);

    /**
     * Quita la cita de la asignatura y libera la memoria.
     * @param cita Puntero a la nota que se va a quitar.
     */
    void quitarCita(Cita *cita);

    /**
     * Quita la sesió de la asignatura y libera la memoria.
     * @param sesion Puntero a la sesión que se va a quitar.
     */
    void quitarSesion(Sesion *sesion);

    /**
     * Obtiene la lista de profesores de la asignatura.
     * @return Referencia constante a la lista de profesores de la asignatura.
     */
    const std::list<Profesor*>& obtenerProfesores() const;

    /**
     * Obtiene la lista de compañeros de la asignatura.
     * @return Referencia constante a la lista de compañeros de la asignatura.
     */
    const std::list<Companero*>& obtenerCompaneros() const;

    /**
     * Obtiene la lista de notas de la asignatura.
     * @return Referencia constante a la lista de notas de la asignatura.
     */
    const std::list<Nota*>& obtenerNotas() const;

    /**
     * Obtiene la lista de citas de la asignatura.
     * @return Referencia constante a la lista de citas de la asignatura.
     */
    const std::list<Cita*>& obtenerCitas() const;

    /**
     * Obtiene la lista de sesiones de la asignatura.
     * @return Referencia constante a la lista de sesiones de la asignatura.
     */
    const std::list<Sesion*>& obtenerSesiones() const;

    /**
     * Convierte toda la información de la asignatura en un formato XML.
     * @return Cadena de caracteres con contenido XML.
     */
    std::string toXml() const;

    /**
     * Carga la asignatura desde un fragmento de XML.
     * @param xml Cadena de caracteres que contiene el fragmento de XML que representa la asignatura.
     */
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
