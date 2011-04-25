#ifndef DIALOGOCOMPANERO_H
#define DIALOGOCOMPANERO_H

#include <QDialog>
#include "Asignatura.h"

namespace Ui {
    class DialogoCompanero;
}

class DialogoCompanero : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoCompanero(Companero *companero, Asignatura *asignatura, QWidget *parent = 0);
    ~DialogoCompanero();

private:
    Ui::DialogoCompanero *ui;
    Asignatura *asignatura;
    Companero *companero;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // DIALOGOCOMPANERO_H
