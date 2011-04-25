#ifndef SESION_H
#define SESION_H

#include <string>
#include "Fecha.h"

/**
 * Clase que representa una sesión de una asignatura.
 */
class Sesion
{
public:
    enum Dia { LUNES = 0, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
    enum Tipo { TEORIA = 0, PRACTICAS };

    /**
     * Constructor por defecto.
     */
    Sesion();

    /**
     * Constructor sobrecargado que recibe los atributos inicializados.
     * @param tipo Tipo de sesión (TEORIA, PRACTICAS).
     * @param lugar Lugar de la sesión.
     * @param dia Día de la semana donde es la sesión (LUNES, MARTES, MIERCOLES, ...).
     * @param fechaInicio Fecha de inicio (que sólo se considera la parte de la hora).
     * @param fechaFin Fecha de fin (que sólo se considera la parte de la hora).
     */
    Sesion(Sesion::Tipo tipo, const std::string &lugar, Sesion::Dia dia, const Fecha &fechaInicio, const Fecha &fechaFin);

    /**
     * Obtiene el tipo de sesión.
     * @return Valor del enumerado con el tipo de sesión.
     */
    Sesion::Tipo getTipo() const;

    /**
     * Obtiene el tipo de sesión como cadena de caracteres.
     * @return Cadena de caracteres con el tipo de sesión: "Teoría" o "Prácticas".
     */
    std::string getTipoString() const;

    /**
     * Establece un nuevo tipo de sesión.
     * @param tipo Nuevo tipo de sesión.
     */
    void setTipo(Sesion::Tipo tipo);

    /**
     * Obtiene el lugar de la sesión.
     * @return Cadena de caracteres con el lugar de la sesión.
     */
    std::string getLugar() const;

    /**
     * Establece el lugar de la sesión.
     * @param lugar Nuevo valor para el lugar de la sesión.
     */
    void setLugar(const std::string &lugar);

    /**
     * Obtiene el día de la semana.
     * @return Valor de enumerado con el día de la semana.
     */
    Sesion::Dia getDia() const;

    /**
     * Obtiene el día de la semana como cadena de caracters.
     * @return Cadena de caracteres con el dia de la semana: "Lunes", "Martes", "Miércoles", ...
     */
    std::string getDiaString() const;

    /**
     * Establece un nuevo día para la sesión.
     * @param dia Nuevo día para la sesión.
     */
    void setDia(Sesion::Dia dia);

    /**
     * Obtiene la fecha de inicio de la sesión (sólo se considera la parte de la hora).
     * @return Hora de inicio de la asignatura.
     */
    Fecha getFechaInicio() const;

    /**
     * Establece una nueva fecha de inicio para la sesión (sólo se considera la parte de la hora).
     * @param fechaInicio Nueva hora de inicio.
     */
    void setFechaInicio(Fecha fechaInicio);

    /**
     * Obtiene la fecha de fin de la sesión (sólo se considera la parte de la hora).
     * @return Hora de fin de la asignatura.
     */
    Fecha getFechaFin() const;

    /**
     * Establece una nueva fecha de fin para la sesión (sólo se considera la parte de la hora).
     * @param fechaFin Nueva hora de fin.
     */
    void setFechaFin(Fecha fechaFin);

    /**
     * Convierte la información de la sesión en XML.
     * @return Cadena de caracteres con la información de la sesión en XML.
     */
    std::string toXml() const;

    /**
     * Carga la sesión desde un fragmento XML.
     * @param xml Cadena de caracteres con la información de la sesión en XML.
     */
    void fromXml(const std::string &xml);

    /**
     * Genera la sesión en un formato de texto plano en una única línea.
     * @return Cadena de caracteres con la información de la sesión en texto plano.
     */
    std::string toString() const;

private:
    Tipo tipo;
    std::string lugar;
    Dia dia;
    Fecha fechaInicio;
    Fecha fechaFin;
};

#endif /* CITA_H */
