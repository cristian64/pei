#ifndef NOTA_H
#define	NOTA_H

#include <string>

class Nota
{
public:
    std::string getDescripcion() const;
    void setDescripcion(const std::string &descripcion);

    float getNota() const;
    void setEmail(float nota);

private:
    std::string descripcion;
    float nota;
};

#endif	/* NOTA_H */
