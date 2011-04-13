#ifndef CITA_H
#define	CITA_H

#include "Fecha.h"
#include <string>

class Cita
{
public:
    Cita();

    std::string getDescripcion() const;
    void setDescripcion(const std::string &descripcion);

    Fecha getFecha() const;
    void setFecha(Fecha fecha);

    int getDuracion() const;
    void setDuracion(int duracion);

    std::string toXml() const;
    void fromXml(const std::string &xml);

private:
    std::string descripcion;
    Fecha fecha;
    int duracion;
};

#endif	/* CITA_H */
