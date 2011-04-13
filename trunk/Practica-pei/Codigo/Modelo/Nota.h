#ifndef NOTA_H
#define	NOTA_H

#include <string>

class Nota
{
public:
    Nota();

    std::string getDescripcion() const;
    void setDescripcion(const std::string &descripcion);

    float getNota() const;
    void setEmail(float nota);

    std::string toXml() const;
    void fromXml(const std::string &xml);

private:
    std::string descripcion;
    float nota;
};

#endif	/* NOTA_H */
