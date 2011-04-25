#ifndef NOTA_H
#define NOTA_H

#include <string>

/**
 * Clase que representa una nota de una asignatura.
 */
class Nota
{
public:
    /**
     * Constructor por defecto.
     */
    Nota();

    /**
     * Constructor sobrecargado que recibe los atributos.
     * @param descripcion Descripción de la nota.
     * @param nota Valor de la nota entre 0 y 10.
     */
    Nota(const std::string &descripcion, float nota);

    /**
     * Obtiene la descripción de la nota.
     * @return Cadena de caracteres con la descripción de la nota.
     */
    std::string getDescripcion() const;

    /**
     * Establece la descripción de la nota.
     * @param descripcion Nueva descripción para la nota.
     */
    void setDescripcion(const std::string &descripcion);

    /**
     * Obtiene la puntuación de la nota.
     * @return Valor flotante entre 0 y 10 con la nota.
     */
    float getNota() const;

    /**
     * Obtiene la puntuación de la nota en cadena de caracteres.
     * @return Cadena de caracteres con el valor de la nota.
     */
    std::string getNotaString() const;

    /**
     * Establece un nuevo valor para la nota,
     * @param nota Nuevo valor para la nota.
     */
    void setNota(float nota);

    /**
     * Genera un framgento XML con la información de la nota.
     * @return Cadena de caracteres con el fragmento en XML.
     */
    std::string toXml() const;

    /**
     * Carga la asignatura desde un fragmento XML.
     * @param xml Cadena de caracteres con la información en XML.
     */
    void fromXml(const std::string &xml);

    /**
     * Genera la nota en un formato de texto plano en una única línea.
     * @return Cadena de caracteres con la información de la nota en texto plano.
     */
    std::string toString() const;

private:
    std::string descripcion;
    float nota;
};

#endif /* NOTA_H */
