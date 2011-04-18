#ifndef DIALOGOSESION_H
#define DIALOGOSESION_H

#include <QDialog>
#include "Asignatura.h"

namespace Ui {
	class DialogoSesion;
}

class DialogoSesion : public QDialog
{
	Q_OBJECT

public:
	explicit DialogoSesion(Sesion *sesion, Asignatura *asignatura, QWidget *parent = 0);
	~DialogoSesion();

private:
	Ui::DialogoSesion *ui;
	Asignatura *asignatura;
	Sesion *sesion;

private slots:
	void on_buttonBox_rejected();
	void on_buttonBox_accepted();
};

#endif // DIALOGOSESION_H
