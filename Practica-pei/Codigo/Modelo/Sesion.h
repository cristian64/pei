#ifndef SESION_H
#define	SESION_H

#include <string>
#include "Fecha.h"

class Sesion
{
public:
    enum Dia { LUNES = 0, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
    enum Tipo { TEORIA = 0, PRACTICAS };

    Sesion::Tipo getTipo() const;
    void setTipo(Sesion::Tipo tipo);

    std::string getLugar() const;
    void setLugar(const std::string &lugar);

    Sesion::Dia getDia() const;
    void setDia(Sesion::Dia dia);

    Fecha getFechaInicio() const;
    void setFechaInicio(Fecha fechaInicio);

    Fecha getFechaFin() const;
    void setFechaFin(Fecha fechaFin);

private:
    Tipo tipo;
    std::string lugar;
    Dia dia;
    Fecha fechaInicio;
    Fecha fechaFin;
};

#endif	/* CITA_H */
