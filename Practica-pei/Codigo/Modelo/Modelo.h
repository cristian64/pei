#ifndef MODELO_H
#define	MODELO_H

#include "Vista.h"
#include <list>
#include <iostream> //TODO:quitar
using std::cout;
using std::endl;

/**
 * Clase abstracta que representa un modelo que tiene vistas.
 */
class Modelo
{
public:
	virtual ~Modelo() = 0;
	void anadirVista(Vista *vista);
	void quitarVista(Vista *vista);
	void refrescarVistas(Vista *vista = NULL);

private:
	std::list<Vista*> vistas;
};

#endif	/* MODELO_H */
