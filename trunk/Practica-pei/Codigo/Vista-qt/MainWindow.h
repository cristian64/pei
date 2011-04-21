#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Asignaturas.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(Asignaturas *asignaturas, QWidget *parent = 0);
	~MainWindow();

private:
	Asignaturas *asignaturas;
	Ui::MainWindow *ui;
	std::string nombreFichero;

public slots:
	void on_actionResumen_toggled(bool checked);
	void asignaturaSeleccionadaCambio(Asignatura *asignatura);
	void on_actionAnadir_triggered();
	void on_actionQuitar_triggered();
	void on_actionNuevo_triggered();
	void on_actionAbrir_triggered();
	void on_actionGuardar_triggered();
	void on_actionGuardarComo_triggered();
	void on_actionSalir_triggered();
	void on_actionAcercaDe_triggered();
};

#endif // MAINWINDOW_H
