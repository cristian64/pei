#ifndef COMPANERO_H
#define COMPANERO_H

#include <string>

/**
 * Clase que representa un compañero en una asignatura.
 */
class Companero
{
public:
    /**
     * Constructor por defecto
     */
    Companero();

    /**
     * Constructor sobrecargado que recibe los atributos.
     * @param nombre Nombre del compañero.
     * @param email Correo electrónico del compañero.
     */
    Companero(const std::string &nombre, const std::string &email);

    /**
     * Obtiene el nombre del compañero.
     * @return Cadena de caracteres con el nombre del compañero.
     */
    std::string getNombre() const;

    /**
     * Establece el nombre del compañero.
     * @param nombre Nuevo nombre del compañero.
     */
    void setNombre(const std::string &nombre);

    /**
     * Obtiene el correo electrónico del compañero.
     * @return Cadena de caracteres con el correo electrónico del compañero.
     */
    std::string getEmail() const;

    /**
     * Establece el correo electrónico del compañero.
     * @param email Nuevo correo electrónico del compañero.
     */
    void setEmail(const std::string &email);

    /**
     * Convierte el compañero en un fragmento XML.
     * @return Cadena de caracteres con la información del compañero en XML.
     */
    std::string toXml() const;

    /**
     * Carga un compañero a partir de un fragmento XML.
     * @param xml Fragmento XML que contiene la información del compañero.
     */
    void fromXml(const std::string &xml);

    /**
     * Genera el compañero en un formato de texto plano en una única línea.
     * @return Cadena de caracteres con la información del compañero en texto plano.
     */
    std::string toString() const;

private:
    std::string nombre;
    std::string email;
};

#endif /* COMPANERO_H */
