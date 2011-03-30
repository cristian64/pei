#include "Modelo.h"
#include <algorithm>

Modelo::~Modelo()
{
    std::list<Vista*>::iterator i = vistas.begin();
    for (; i != vistas.end(); i++)
    {
        Vista *vistaAux = *i;
        vistaAux->modelo = NULL;
    }
    vistas.clear();
}

void Modelo::anadirVista(Vista *vista)
{
    // Sólo se añade la vista si no estaba previamente.
    std::list<Vista*>::iterator resultado = std::find(vistas.begin(), vistas.end(), vista);
    if (resultado == vistas.end())
    {
        vistas.push_back(vista);
        vista->modelo = this;
    }
}

void Modelo::quitarVista(Vista *vista)
{
    vistas.remove(vista);
    vista->modelo = NULL;
}

void Modelo::refrescarVistas(Vista *vista)
{
    std::list<Vista*>::iterator i = vistas.begin();
    for (; i != vistas.end(); i++)
    {
        Vista *vistaAux = (*i);
        if ((*i) != vista)
            vistaAux->refrescar();
    }
}
