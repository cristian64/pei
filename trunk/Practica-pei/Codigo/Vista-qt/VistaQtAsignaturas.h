#ifndef VISTAQTASIGNATURAS_H
#define VISTAQTASIGNATURAS_H

#include <QListWidget>
#include <map>
#include "Vista.h"
#include "Asignatura.h"

namespace Ui {
	class VistaQtAsignaturas;
}

class VistaQtAsignaturas : public QListWidget, public Vista
{
	Q_OBJECT

public:
	explicit VistaQtAsignaturas(QWidget *parent = 0);
	~VistaQtAsignaturas();
	void refrescar();
	void quitarAsignaturaSeleccionada();
	Asignatura* obtenerSeleccionada() const;

private:
	Ui::VistaQtAsignaturas *ui;
	std::map<Asignatura*, QListWidgetItem*> vinculos;

signals:
	void asignaturaSeleccionadaCambio(Asignatura *asignatura);

private slots:
	void itemSelectionChanged();
	void itemChanged(QListWidgetItem *item);
};

#endif // VISTAQTASIGNATURAS_H
