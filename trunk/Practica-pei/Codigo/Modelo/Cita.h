#ifndef CITA_H
#define CITA_H

#include "Fecha.h"
#include <string>

/**
 * Clase que representa una cita de un examen o una entrega de prácticas.
 */
class Cita
{
public:
    /**
     * Constructor por defecto que inicializa las variables primitivas a su valor por defecto.
     */
    Cita();

    /**
     * Constructor sobrecargado que recibe los atributos en los parámetros.
     * @param descripcion Descripción de la cita.
     * @param fecha Fecha de la cita.
     * @param duracion Duración (minutos) de la cita.
     */
    Cita(const std::string &descripcion, const Fecha &fecha, int duracion);

    /**
     * Obtiene la descripción de la cita.
     * @return Cadena de caracteres con la descripción de la cita.
     */
    std::string getDescripcion() const;

    /**
     * Establece un nuevo valor para la descripción de la cita
     * @param descripcion Cadena de caracteres con la nueva descripción.
     */
    void setDescripcion(const std::string &descripcion);

    /**
     * Obtiene la fecha de la cita.
     * @return Objeto de la clase Fecha con la fecha de la cita.
     */
    Fecha getFecha() const;

    /**
     * Establece una nueva fecha para la cita.
     * @param fecha Nuevo valor para la fecha.
     */
    void setFecha(Fecha fecha);

    /**
     * Obtiene la duración (en minutos) de la cita.
     * @return Valor entero que representa los minutos que dura la cita.
     */
    int getDuracion() const;

    /**
     * Establece una nueva duración para la cita.
     * @param duracion Nuevo duración (en minutos) para la cita.
     */
    void setDuracion(int duracion);

    /**
     * Conviete la cita en un formato XML.
     * @return Cadena de caracteres con la información de la cita en XML.
     */
    std::string toXml() const;

    /**
     * Carga la cita desde un fragmento de XML.
     * @param xml Cadena de caracteres que contiene el XML con la información de la cita.
     */
    void fromXml(const std::string &xml);

    /**
     * Genera la cita en un formato de texto plano en una única línea.
     * @return Cadena de caracteres con la información de la cita en texto plano.
     */
    std::string toString() const;

private:
    std::string descripcion;
    Fecha fecha;
    int duracion;
};

#endif /* CITA_H */
