#include "Codificacion.h"
#include <cstring>

std::string Latin1toUTF8(const char* cadena)
{
    std::string resultado;
    int tamano = strlen(cadena);
    resultado.reserve(2 * tamano + 1);
    
    const unsigned char* ucadena = (const unsigned char*) cadena;
    int caracter = *(ucadena);
    while (caracter)
    {
        if (caracter >= 128)
        {
            resultado += (char) (((caracter & 0x7c0) >> 6) | 0xc0);
            resultado += (char) ((caracter & 0x3f) | 0x80);
        }
        else
            resultado += caracter;
        caracter = *(++ucadena);
    }
    
    return resultado;
}

std::string UTF8ToLatin1(const std::string &cadena)
{
    std::string resultado;
    int tamano = cadena.length();
    resultado.reserve(tamano);

    const unsigned char *ucadena = (const unsigned char *) cadena.c_str();
    for (int i = 0; i < tamano; i++)
    {
        if (ucadena[i] <= 127)
        {
            resultado += ucadena[i];
        }
        else
        {
            char c1 = ucadena[i];
            char c2 = ucadena[i + 1];
            resultado += ((c1 & 0x1f) << 6) + (c2 & 0x3f);
            i++;
        }
    }
    
    return resultado;
}
