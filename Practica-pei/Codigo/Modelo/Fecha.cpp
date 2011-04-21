#include "Fecha.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

Fecha::Fecha() :
	ano(2011),
	mes(1),
	dia(1),
	hora(0),
	minuto(0),
	segundo(0)
{
}

Fecha::Fecha(int ano, int mes, int dia, int hora, int minuto, int segundo) :
	ano(ano),
	mes(mes),
	dia(dia),
	hora(hora),
	minuto(minuto),
	segundo(segundo)
{
}

Fecha::Fecha(const std::string &cadena)
{
	this->fromString(cadena);
}

bool Fecha::operator<(const Fecha &fecha) const
{
	if (ano < fecha.ano)
		return true;
	else if (ano > fecha.ano)
		return false;

	if (mes < fecha.mes)
		return true;
	else if (mes > fecha.mes)
		return false;

	if (dia < fecha.dia)
		return true;
	else if (dia > fecha.dia)
		return false;

	if (hora < fecha.hora)
		return true;
	else if (hora > fecha.hora)
		return false;

	if (minuto < fecha.minuto)
		return true;
	else if (minuto > fecha.minuto)
		return false;

	if (segundo < fecha.segundo)
		return true;
	else if (segundo > fecha.segundo)
		return false;

	return false;
}

std::string Fecha::toString() const
{
	std::stringstream flujo;
	flujo << std::setfill('0') << std::setw(4) << ano << "/" << std::setfill('0') << std::setw(2) << mes << "/" << std::setfill('0') << std::setw(2) << dia << " " << std::setfill('0') << std::setw(2) << hora << ":" << std::setfill('0') << std::setw(2) << minuto << ":" << std::setfill('0') << std::setw(2) << segundo;
	return flujo.str();
}

std::string Fecha::toStringHora() const
{
	std::stringstream flujo;
	flujo << std::setfill('0') << std::setw(2) << hora << ":" << std::setfill('0') << std::setw(2) << minuto << ":" << std::setfill('0') << std::setw(2) << segundo;
	return flujo.str();
}

void Fecha::fromString(const std::string &cadena)
{
	ano = atoi(cadena.substr(0, 4).c_str());
	mes = atoi(cadena.substr(5, 2).c_str());
	dia = atoi(cadena.substr(8, 2).c_str());
	hora = atoi(cadena.substr(11, 2).c_str());
	minuto = atoi(cadena.substr(14, 2).c_str());
	segundo = atoi(cadena.substr(17, 2).c_str());
}
