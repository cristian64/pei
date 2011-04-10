#include "Auxiliar.h"

std::string rellenar(const std::string &cadena, const std::string &caracter, unsigned int tamano, bool left, bool right)
{
    int negativos = 0;
    for (unsigned int i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] < 0)
            negativos++;
    }
    std::string aux = cadena;
    unsigned int i = aux.length() - negativos/2;
    while (i < tamano)
    {
        if (left)
        {
            aux = caracter + aux;
            i++;
        }
        if (right && i < tamano)
        {
            aux = aux + caracter;
            i++;
        }
    }
    return aux;
}
