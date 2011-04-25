#ifndef DIALOGONOTA_H
#define DIALOGONOTA_H

#include <QDialog>
#include "Asignatura.h"

namespace Ui {
    class DialogoNota;
}

class DialogoNota : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoNota(Nota *nota, Asignatura *asignatura, QWidget *parent = 0);
    ~DialogoNota();

private:
    Ui::DialogoNota *ui;
    Asignatura *asignatura;
    Nota *nota;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // DIALOGONOTA_H
