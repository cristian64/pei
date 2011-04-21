#ifndef XFORMSTIMER_H
#define	XFORMSTIMER_H

#include <QObject>
#include "Asignaturas.h"
#include "Formulario.h"
#include "VistaXformsAsignaturas.h"
#include "VistaXformsAsignatura.h"
#include <QTimer>

class XformsTimer : public QTimer
{
    Q_OBJECT

public:
    FD_Formulario *fd_Formulario;
    XformsTimer(int argc, char **argv, Asignaturas *asignaturas);
    ~XformsTimer();

public slots:
    void ejecutar();
};

#endif	/* XFORMSTIMER_H */

