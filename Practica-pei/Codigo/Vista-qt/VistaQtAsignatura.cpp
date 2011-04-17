#include "VistaQtAsignatura.h"
#include "ui_VistaQtAsignatura.h"

#include <algorithm>
#include <iostream>
#include "DialogoProfesor.h"


VistaQtAsignatura::VistaQtAsignatura(QWidget *parent) :
	QTabWidget(parent),
	ui(new Ui::VistaQtAsignatura)
{
	ui->setupUi(this);
	ui->tabProfesores->setVisible(false);
	ui->tabCompaneros->setVisible(false);
	ui->tabSesiones->setVisible(false);
	ui->tabCitas->setVisible(false);
	ui->tabNotas->setVisible(false);
	tabBar()->setEnabled(false);
	ui->tableWidgetProfesores->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

VistaQtAsignatura::~VistaQtAsignatura()
{
	delete ui;
}

void VistaQtAsignatura::refrescar()
{
	Asignatura *asignatura = static_cast<Asignatura*>(modelo);
	if (asignatura != NULL)
	{
		if (ultimaAsignaturaRefrescada != asignatura)
		{
			limpiar();
		}
		ultimaAsignaturaRefrescada = asignatura;

		// Los profesores que no estuvieran en la lista, se eliminan del widget.
		int rows = ui->tableWidgetProfesores->rowCount();
		for (int i = 0; i < rows; i++)
		{
			QTableWidgetItem *item = ui->tableWidgetProfesores->item(i, 0);
			Profesor *profesor = vinculoProfesor(item);
			const std::list<Profesor*> profesores = asignatura->obtenerProfesores();
			if (std::find(profesores.begin(), profesores.end(), profesor) == profesores.end())
			{
				desvincularProfesor(profesor);
				ui->tableWidgetProfesores->removeRow(i);
				i--;
				rows--;
			}
		}

		// Se añaden los profesor nuevos (o se actualizan).
		const std::list<Profesor*> profesores = asignatura->obtenerProfesores();
		std::list<Profesor*>::const_iterator profesor = profesores.begin();
		for (; profesor != profesores.end(); profesor++)
		{
			// Si el profesor ya estaba, se modifica la fila. Si no estaba, se crea una fila nueva.
			int row = filaProfesor(*profesor);
			if (row == -1)
			{
				row = ui->tableWidgetProfesores->rowCount();
				ui->tableWidgetProfesores->insertRow(row);
			}
			else
			{
				desvincularProfesor(*profesor);
			}
			QTableWidgetItem *nombre = new QTableWidgetItem(QString::fromStdString((*profesor)->getNombre()));
			nombre->setFlags(nombre->flags() & ~Qt::ItemIsEditable);
			QTableWidgetItem *email = new QTableWidgetItem(QString::fromStdString((*profesor)->getEmail()));
			email->setFlags(email->flags() & ~Qt::ItemIsEditable);
			ui->tableWidgetProfesores->setItem(row, 0, nombre);
			ui->tableWidgetProfesores->setItem(row, 1, email);
			vinculosProfesores[nombre] = *profesor;
			vinculosProfesores[email] = *profesor;
		}
	}
	else
	{
		limpiar();
	}

	// Oculta o muestra las pestañas, según si hay o no alguna asignatura seleccionada.
	ui->tabProfesores->setVisible(asignatura != NULL);
	ui->tabCompaneros->setVisible(asignatura != NULL);
	ui->tabSesiones->setVisible(asignatura != NULL);
	ui->tabCitas->setVisible(asignatura != NULL);
	ui->tabNotas->setVisible(asignatura != NULL);
	tabBar()->setEnabled(asignatura != NULL);
}

void VistaQtAsignatura::limpiar()
{
	while (ui->tableWidgetProfesores->rowCount())
		ui->tableWidgetProfesores->removeRow(0);
	vinculosProfesores.clear();
}

void VistaQtAsignatura::on_tableWidgetProfesores_itemDoubleClicked(QTableWidgetItem *item)
{
	DialogoProfesor dialogoProfesor(vinculoProfesor(item), (Asignatura*) modelo, this);
	dialogoProfesor.exec();
}

Profesor* VistaQtAsignatura::vinculoProfesor(QTableWidgetItem *item) const
{
	std::map<QTableWidgetItem*, Profesor*>::const_iterator i = vinculosProfesores.begin();
	for (; i != vinculosProfesores.end(); i++)
	{
		if (i->first == item)
			return i->second;
	}
	return NULL;
}

int VistaQtAsignatura::filaProfesor(Profesor *profesor) const
{
	std::map<QTableWidgetItem*, Profesor*>::const_iterator i = vinculosProfesores.begin();
	for (; i != vinculosProfesores.end(); i++)
	{
		if (i->second == profesor)
			return ui->tableWidgetProfesores->row(i->first);
	}
	return -1;
}

void VistaQtAsignatura::desvincularProfesor(Profesor *profesor)
{
	std::map<QTableWidgetItem*, Profesor*>::iterator i = vinculosProfesores.begin();
	while (i != vinculosProfesores.end())
	{
		if (i->second == profesor)
		{
			std::map<QTableWidgetItem*, Profesor*>::iterator aux = i++;
			vinculosProfesores.erase(aux);
		}
		else
		{
			i++;
		}
	}
}

void VistaQtAsignatura::quitarProfesorSeleccionado()
{
	if (ui->tableWidgetProfesores->selectedItems().size() > 0)
	{
		Profesor *profesor = vinculoProfesor(ui->tableWidgetProfesores->selectedItems().first());
		Asignatura *asignatura = static_cast<Asignatura*>(modelo);
		if (asignatura != NULL && profesor != NULL)
		{
			ui->tableWidgetProfesores->removeRow(ui->tableWidgetProfesores->row(ui->tableWidgetProfesores->selectedItems().first()));
			desvincularProfesor(profesor);
			asignatura->quitarProfesor(profesor);
			asignatura->refrescarVistas(this);
		}
	}
}

void VistaQtAsignatura::on_pushButtonQuitarProfesor_clicked()
{
	quitarProfesorSeleccionado();
}

void VistaQtAsignatura::on_pushButtonAnadirProfesor_clicked()
{
	DialogoProfesor dialogoProfesor(NULL, (Asignatura*) modelo, this);
	dialogoProfesor.exec();
}
