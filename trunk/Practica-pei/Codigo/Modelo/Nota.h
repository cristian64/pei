#ifndef NOTA_H
#define	NOTA_H

#include <string>

class Nota
{
public:
    Nota();
    Nota(const std::string &descripcion, float nota);

    std::string getDescripcion() const;
    void setDescripcion(const std::string &descripcion);

    float getNota() const;
    void setNota(float nota);

    std::string toXml() const;
    void fromXml(const std::string &xml);

    std::string toString() const;

private:
    std::string descripcion;
    float nota;
};

#endif	/* NOTA_H */
