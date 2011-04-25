#ifndef ASIGNATURAS_H
#define ASIGNATURAS_H

#include "Asignatura.h"
#include "Modelo.h"
#include <list>

class Asignaturas : public Modelo
{
public:
    Asignaturas();
    ~Asignaturas();

    void anadirAsignatura(Asignatura *asignatura);
    void quitarAsignatura(Asignatura *asignatura);
    const std::list<Asignatura*>& obtenerAsignaturas() const;

    void limpiar();

    std::string toXml() const;
    void fromXml(const std::string &xml);

    void guardar(const std::string &rutaFichero) const;
    void cargar(const std::string &rutaFichero);

    std::string getRutaFichero() const;
    void setRutaFichero(const std::string &rutaFichero);

private:
    mutable std::string rutaFichero;
    std::list<Asignatura*> asignaturas;
};

#endif /* ASIGNATURAS_H */
