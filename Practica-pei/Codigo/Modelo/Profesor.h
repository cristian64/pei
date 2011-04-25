#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

class Profesor
{
public:
    Profesor();
    Profesor(const std::string &nombre, const std::string &email);

    std::string getNombre() const;
    void setNombre(const std::string &nombre);

    std::string getEmail() const;
    void setEmail(const std::string &email);

    std::string toXml() const;
    void fromXml(const std::string &xml);

    std::string toString() const;
    
private:
    std::string nombre;
    std::string email;
};

#endif /* PROFESOR_H */
