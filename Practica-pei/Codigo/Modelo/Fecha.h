#ifndef FECHA_H
#define	FECHA_H

#include <string>

class Fecha
{
public:
    Fecha();

    std::string toString() const;
    void fromString(const std::string &cadena);

    int segundo;
    int minuto;
    int hora;
    int dia;
    int mes;
    int ano;
};

#endif	/* FECHA_H */

