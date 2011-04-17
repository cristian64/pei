#include <QtGui/QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
	Asignaturas asignaturas;
	asignaturas.cargar("../ejemplo1.xml");

	QApplication a(argc, argv);
	MainWindow w(&asignaturas);
	w.show();
	MainWindow w2(&asignaturas);
	w2.show();

	return a.exec();
}
