#ifndef VISTAQTRESUMEN_H
#define VISTAQTRESUMEN_H

#include <QWidget>
#include "Vista.h"
#include <list>

namespace Ui {
	class VistaQtResumen;
}

class VistaMini;

class VistaQtResumen : public QWidget, public Vista
{
	Q_OBJECT

public:
	explicit VistaQtResumen(QWidget *parent = 0);
	~VistaQtResumen();
	void refrescar();
	void recargarCitas();
	void recargarHorario();

private:
	Ui::VistaQtResumen *ui;
	std::list<VistaMini*> vistasMini;

private slots:
	void on_checkBoxCitasPasadas_toggled(bool checked);
	void on_checkBoxSabadoDomingo_toggled(bool checked);
};

#endif // VISTAQTRESUMEN_H
