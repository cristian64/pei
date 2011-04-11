#ifndef PROFESOR_H
#define	PROFESOR_H

#include <string>

class Profesor
{
public:
    std::string getNombre() const;
    void setNombre(const std::string &nombre);

    std::string getEmail() const;
    void setEmail(const std::string &email);

private:
    std::string nombre;
    std::string email;
};

#endif	/* PROFESOR_H */