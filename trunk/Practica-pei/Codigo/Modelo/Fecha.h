#ifndef FECHA_H
#define FECHA_H

#include <string>

/**
 * Clase que representa una fecha.
 * No evalúa que la fecha sea correcta.
 */
class Fecha
{
public:
    /**
     * Constructor por defecto que inicializa la fecha a 0.
     */
    Fecha();

    /**
     * Constructor sobre cargado que recibe los parámetros de la fecha completa.
     * @param ano Año de la fecha.
     * @param mes Mes de la fecha.
     * @param dia Dia de la fecha.
     * @param hora Hora de la fecha.
     * @param minuto Minuto de la fecha.
     * @param segundo Segundo de la fecha.
     */
    Fecha(int ano, int mes, int dia, int hora, int minuto, int segundo);

    /**
     * Constructor sobre cargado que recibe los parámetros de la hora.
     * @param hora Hora de la fecha.
     * @param minuto Minuto de la fecha.
     * @param segundo Segundo de la fecha.
     */
    Fecha(int hora, int minuto, int segundo);

    /**
     * Constructor sobre cargado que recibe la fecha en el formato: "aaaa/mm/dd hh:mm:ss"
     * @param cadena Cadena de caracteres que contiene la fecha.
     */
    Fecha(const std::string &cadena);

    /**
     * Operador menor para comparar dos fechas.
     * @param fecha Fecha con la que se va a comprar la fecha que invocó el método.
     * @return Verdadero si la fecha que invocó el método es anterior a la fecha recibida en los parámetros.
     */
    bool operator<(const Fecha &fecha) const;

    /**
     * Genera una salida en formato "aaaa/mm/dd hh:mm:ss".
     * @return Cadena de caracteres con la fecha en el formato indicado.
     */
    std::string toString() const;

    /**
     * Genera una salida en formato "hh:mm:ss".
     * @return Cadena de caracteres con la fecha en el formato indicado.
     */
    std::string toStringHora() const;

    /**
     * Carga una fecha a partir de una cadena en formato: "aaaa/mm/dd hh:mm:ss"
     * @param cadena Cadena de caracteres que contiene la fecha.
     */
    void fromString(const std::string &cadena);

    /**
     * Método estático para extraer un objeto del tipo Fecha con la fecha actual.
     * @return Objeto de tipo Fecha con la fecha actual del sistema.
     */
    static Fecha actual();

    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
};

#endif /* FECHA_H */

