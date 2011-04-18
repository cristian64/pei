#ifndef FECHA_H
#define	FECHA_H

#include <string>

class Fecha
{
public:
	Fecha();
	Fecha(int ano, int mes, int dia, int hora, int minuto, int segundo);
	Fecha(const std::string &cadena);

	std::string toString() const;
	std::string toStringHora() const;
	void fromString(const std::string &cadena);

	int ano;
	int mes;
	int dia;
	int hora;
	int minuto;
	int segundo;
};

#endif	/* FECHA_H */

