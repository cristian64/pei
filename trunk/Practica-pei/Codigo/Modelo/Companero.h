#ifndef COMPANERO_H
#define	COMPANERO_H

#include <string>

class Companero
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

#endif	/* COMPANERO_H */
