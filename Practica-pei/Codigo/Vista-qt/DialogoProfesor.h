#ifndef DIALOGOPROFESOR_H
#define DIALOGOPROFESOR_H

#include <QDialog>
#include "Asignatura.h"

namespace Ui {
    class DialogoProfesor;
}

class DialogoProfesor : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoProfesor(Profesor *profesor, Asignatura *asignatura, QWidget *parent = 0);
    ~DialogoProfesor();

private:
    Ui::DialogoProfesor *ui;
    Asignatura *asignatura;
    Profesor *profesor;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // DIALOGOPROFESOR_H
