#ifndef VISTA_H
#define VISTA_H

/**
 * Declaración forward para evitar dependencias circulares.
 * La referencia a Modelo.h se incluye en el fichero de definición (Vista.cpp).
 */
class Modelo;

/**
 * Clase abstracta que representa una vista del modelo.
 */
class Vista
{
    /**
     * Se permita amistad con la clase Modelo.
     */
    friend class Modelo;
    
public:
    /**
     * Constructor por defecto.
     */
    Vista();

    /**
     * Destructor por defecto.
     * Al destruirse la vista, se desconecta del modelo.
     */
    virtual ~Vista() = 0;

    /**
     * Método virtual puro que todas las clases derivadas deben implementar.
     * Cuando se le solicite al modelo que refresque las vistas, será este método el que se invoque.
     */
    virtual void refrescar() = 0;

    /**
     * Cambia el modelo asociado a la vista. Si la vista ya estaba conectada a otro modelo, se desconecta.
     * @param modelo Nuevo modelo para la vista. Puede ser NULL si se quiere desconectar la vista.
     */
    void ponerModelo(Modelo *modelo);

    /**
     * Obtiene el modelo asociado a la vista.
     * @return Un objeto de la clase Modelo (o que herede de ésta). También puede devolver NULL si no hay ningún modelo
     */
    Modelo* obtenerModelo() const;
    
protected:
    Modelo *modelo;
};

#endif /* VISTA_H */
