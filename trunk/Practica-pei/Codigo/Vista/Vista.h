#ifndef VISTA_H
#define VISTA_H

#include <iostream> //TODO:quitar
using std::cout;
using std::endl;

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
    friend class Modelo;
    
public:
    Vista();
    virtual ~Vista() = 0;
    virtual void refrescar() = 0;
    void ponerModelo(Modelo *modelo);
    Modelo* obtenerModelo() const;
    
protected:
    Modelo *modelo;
};

#endif /* VISTA_H */
