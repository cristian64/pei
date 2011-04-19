#include "Vista.h"
#include "Modelo.h"

Vista::Vista()
{
    modelo = NULL;
}

Vista::~Vista()
{
    // Se avisa al modelo de que la vista va a dejar de existir.
    if (modelo != NULL)
    {
        modelo->quitarVista(this);
        modelo = NULL;
    }
}

void Vista::ponerModelo(Modelo *modelo)
{
    // Sólo se modifica si es un modelo diferente al que hubiera.
    if (this->modelo != modelo)
    {
        // Si la vista estaba en otro modelo, se elimina de ese modelo.
        if (this->modelo != NULL)
            this->modelo->quitarVista(this);

        // Si establece el modelo y, si es un modelo válido, se añade la vista a dicho modelo.
        this->modelo = modelo;
        if (modelo != NULL)
            modelo->anadirVista(this);
    }
}

Modelo* Vista::obtenerModelo() const
{
    return modelo;
}