#ifndef MODELO_H
#define MODELO_H

#include "Vista.h"
#include <list>

/**
 * Clase abstracta que representa un modelo que tiene vistas.
 */
class Modelo
{
public:
    /**
     * Destructor por defecto.
     * Cuando el modelo se destruye, avisa a todas las vistas que tuviera para que dejen de apuntar a este modelo.
     */
    virtual ~Modelo() = 0;

    /**
     * Añade una vista al modelo. Si la vista ya estaba, no la añade.
     * Además, si la vista ya estaba en otro modelo, la saca de ese otro modelo y la apunta a éste.
     * @param vista Vista que se va a añadir.
     */
    void anadirVista(Vista *vista);

    /**
     * Quita una vista del modelo y avisa a la vista de que ya no está en este modelo (para mantener la coherencia).
     * @param vista Vista que se va a quitar.
     */
    void quitarVista(Vista *vista);

    /**
     * Realiza un barrido en todas las vistas forzando el refresco.
     * @param vista Si se especifica este valor, esta vista no se refrescará.
     * Por motivos de eficiencia se asume que ésta es la vista que pidió el refresco y, por tanto, no tiene que refrescarse.
     */
    void refrescarVistas(Vista *vista = NULL);

private:
    std::list<Vista*> vistas;
};

#endif /* MODELO_H */
