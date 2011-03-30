#ifndef SESION_H
#define	SESION_H

#include <string>
#include "Fecha.h"

class Sesion
{
public:
    enum Dia { LUNES = 0, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
    
    std::string getLugar() const;
    void setLugar(const std::string &lugar);

    Dia getDia() const;
    void setDia(Dia dia);

    Fecha getFechaInicio() const;
    void setFechaInicio(Fecha fechaInicio);

    Fecha getFechaFin() const;
    void setFechaFin(Fecha fechaFin);

private:
    std::string lugar;
    Dia dia;
    Fecha fechaInicio;
    Fecha fechaFin;
};

#endif	/* CITA_H */
