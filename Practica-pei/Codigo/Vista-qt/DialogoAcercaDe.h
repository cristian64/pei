#ifndef DIALOGOACERCADE_H
#define DIALOGOACERCADE_H

#include <QDialog>

namespace Ui {
    class DialogoAcercaDe;
}

class DialogoAcercaDe : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoAcercaDe(QWidget *parent = 0);
    ~DialogoAcercaDe();

private:
    Ui::DialogoAcercaDe *ui;

private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOGOACERCADE_H
