#include <QtGui/QApplication>
#include "Asignaturas.h"
#include "MainWindow.h"
#include "XformsTimer.h"

int main(int argc, char **argv)
{
    Asignaturas asignaturas;
    asignaturas.cargar("ejemplo1.xml");

    QApplication a(argc, argv);

    // Se crean dos ventanas de la Vista Qt.
    MainWindow w(&asignaturas);
    w.show();
    MainWindow w2(&asignaturas);
    w2.show();

    // Se crea un timer, cuyo constructor crea una Vista Xforms. En cada intervalo, se realiza un fl_check_forms.
    // Se consigue así que no haya corrupción de memoria (antes usaba pthread y a veces daba un cascazo increíble).
    XformsTimer timer(argc, argv, &asignaturas);
    timer.setInterval(100);
    timer.start();
    
    return a.exec();
}

