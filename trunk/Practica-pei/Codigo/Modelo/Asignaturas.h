#ifndef ASIGNATURAS_H
#define ASIGNATURAS_H

#include "Asignatura.h"
#include "Modelo.h"
#include <list>

/**
 * Clase que representa un paquete de asignaturas. Es decir, contiene muchas asignaturas.
 * Es también un modelo al que pueden conectarse vistas.
 */
class Asignaturas : public Modelo
{
public:

    /**
     * Destructor por defecto que libera la memoria de las asignaturas.
     */
    ~Asignaturas();

    /**
     * Añade una asignatura a la lista de asignaturas.
     * El usuario NO debe hacerse cargo de liberar esta memoria una vez añadida.
     * @param asignatura Puntero a la asignatura que se va a añadir.
     */
    void anadirAsignatura(Asignatura *asignatura);

    /**
     * Quita una asignatura de la lista y libera la memoria.
     * @param asignatura Asignatura que se va a eliminar.
     */
    void quitarAsignatura(Asignatura *asignatura);

    /**
     * Obtiene la lista de asignaturas.
     * @return Referencia constante a la lista de asignaturas que contiene el paquete de asignaturas.
     */
    const std::list<Asignatura*>& obtenerAsignaturas() const;

    /**
     * Elimina todas las asignaturas que contiene el paquete de asignaturas.
     * Libera la memoria.
     */
    void limpiar();

    /**
     * Genera un fragmento XML con la información de las asignaturas.
     * @return Cadena de caracteres con el fragmento XML de cada asignatura que contiene el paquete de asignaturas.
     */
    std::string toXml() const;

    /**
     * Carga las asignaturas desde un fragmento de XML recibido en los parámetros.
     * @param xml Cadena de caracteres que contiene el XML de las asignaturas.
     */
    void fromXml(const std::string &xml);

    /**
     * Guarda el paquete de asignaturas en un fichero en formato XML.
     * @param rutaFichero Ruta del fichero donde se guarda el XML.
     */
    void guardar(const std::string &rutaFichero) const;

    /**
     * Carga el paquete de asignaturas desde un fichero que tiene formato XML.
     * @param rutaFichero Ruta del fichero que contiene el XML de las asignaturas.
     */
    void cargar(const std::string &rutaFichero);

    /**
     * Obtiene la ruta del fichero desde el que se cargó (o guardó) el paquete de asignaturas por última vez.
     * Si es una cadena vacía, significa que nunca se ha guardado o cargado desde un fichero.
     * @return
     */
    std::string getRutaFichero() const;

private:
    mutable std::string rutaFichero;
    std::list<Asignatura*> asignaturas;
};

#endif /* ASIGNATURAS_H */
