#ifndef DIALOGOCITA_H
#define DIALOGOCITA_H

#include <QDialog>
#include "Asignatura.h"

namespace Ui {
    class DialogoCita;
}

class DialogoCita : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoCita(Cita *cita, Asignatura *asignatura, QWidget *parent = 0);
    ~DialogoCita();

private:
    Ui::DialogoCita *ui;
    Asignatura *asignatura;
    Cita *cita;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // DIALOGOCITA_H
