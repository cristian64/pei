#ifndef VISTAQTASIGNATURA_H
#define VISTAQTASIGNATURA_H

#include <QTabWidget>
#include <QTableWidgetItem>
#include <map>
#include "Asignatura.h"

namespace Ui {
	class VistaQtAsignatura;
}

class VistaQtAsignatura : public QTabWidget, public Vista
{
	Q_OBJECT

public:
	explicit VistaQtAsignatura(QWidget *parent = 0);
	~VistaQtAsignatura();
	void refrescar();
	void limpiar();

private:
	Ui::VistaQtAsignatura *ui;
	Asignatura *ultimaAsignaturaRefrescada;

	std::map<QTableWidgetItem*, Profesor*> vinculosProfesores;
	Profesor* vinculoProfesor(QTableWidgetItem *item) const;
	int filaProfesor(Profesor *profesor) const;
	void desvincularProfesor(Profesor *profesor);
	void quitarProfesorSeleccionado();

private slots:
	void on_pushButtonAnadirProfesor_clicked();
 void on_pushButtonQuitarProfesor_clicked();
	void on_tableWidgetProfesores_itemDoubleClicked(QTableWidgetItem *item);
};

#endif // VISTAQTASIGNATURA_H
