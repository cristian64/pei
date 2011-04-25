#ifndef CITA_H
#define CITA_H

#include "Fecha.h"
#include <string>

class Cita
{
public:
    Cita();
    Cita(const std::string &descripcion, const Fecha &fecha, int duracion);

    std::string getDescripcion() const;
    void setDescripcion(const std::string &descripcion);

    Fecha getFecha() const;
    void setFecha(Fecha fecha);

    int getDuracion() const;
    void setDuracion(int duracion);

    std::string toXml() const;
    void fromXml(const std::string &xml);

    std::string toString() const;

private:
    std::string descripcion;
    Fecha fecha;
    int duracion;
};

#endif /* CITA_H */
