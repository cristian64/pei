#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

/**
 * Clase que representa un profesor en una asignatura.
 */
class Profesor
{
public:
    /**
     * Constructor por defecto
     */
    Profesor();

    /**
     * Constructor sobrecargado que recibe los atributos.
     * @param nombre Nombre del profesor.
     * @param email Correo electrónico del profesor.
     */
    Profesor(const std::string &nombre, const std::string &email);

    /**
     * Obtiene el nombre del profesor.
     * @return Cadena de caracteres con el nombre del profesor.
     */
    std::string getNombre() const;

    /**
     * Establece el nombre del profesor.
     * @param nombre Nuevo nombre del profesor.
     */
    void setNombre(const std::string &nombre);

    /**
     * Obtiene el correo electrónico del profesor.
     * @return Cadena de caracteres con el correo electrónico del profesor.
     */
    std::string getEmail() const;

    /**
     * Establece el correo electrónico del profesor.
     * @param email Nuevo correo electrónico del profesor.
     */
    void setEmail(const std::string &email);

    /**
     * Convierte el profesor en un fragmento XML.
     * @return Cadena de caracteres con la información del profesor en XML.
     */
    std::string toXml() const;

    /**
     * Carga un profesor a partir de un fragmento XML.
     * @param xml Fragmento XML que contiene la información del profesor.
     */
    void fromXml(const std::string &xml);

    /**
     * Genera el profesor en un formato de texto plano en una única línea.
     * @return Cadena de caracteres con la información del profesor en texto plano.
     */
    std::string toString() const;
    
private:
    std::string nombre;
    std::string email;
};

#endif /* PROFESOR_H */
