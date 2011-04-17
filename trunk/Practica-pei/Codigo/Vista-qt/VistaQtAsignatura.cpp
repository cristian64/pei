#include "VistaQtAsignatura.h"
#include "ui_VistaQtAsignatura.h"

#include <algorithm>
#include <iostream>
#include "DialogoProfesor.h"
#include "DialogoCompanero.h"
#include "DialogoCita.h"
#include "DialogoNota.h"

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
	ui->tableWidgetCompaneros->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui->tableWidgetCitas->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui->tableWidgetNotas->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
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

		// Los companeros que no estuvieran en la lista, se eliminan del widget.
		rows = ui->tableWidgetCompaneros->rowCount();
		for (int i = 0; i < rows; i++)
		{
			QTableWidgetItem *item = ui->tableWidgetCompaneros->item(i, 0);
			Companero *companero = vinculoCompanero(item);
			const std::list<Companero*> companeros = asignatura->obtenerCompaneros();
			if (std::find(companeros.begin(), companeros.end(), companero) == companeros.end())
			{
				desvincularCompanero(companero);
				ui->tableWidgetCompaneros->removeRow(i);
				i--;
				rows--;
			}
		}

		// Se añaden los companero nuevos (o se actualizan).
		const std::list<Companero*> companeros = asignatura->obtenerCompaneros();
		std::list<Companero*>::const_iterator companero = companeros.begin();
		for (; companero != companeros.end(); companero++)
		{
			// Si el companero ya estaba, se modifica la fila. Si no estaba, se crea una fila nueva.
			int row = filaCompanero(*companero);
			if (row == -1)
			{
				row = ui->tableWidgetCompaneros->rowCount();
				ui->tableWidgetCompaneros->insertRow(row);
			}
			else
			{
				desvincularCompanero(*companero);
			}
			QTableWidgetItem *nombre = new QTableWidgetItem(QString::fromStdString((*companero)->getNombre()));
			nombre->setFlags(nombre->flags() & ~Qt::ItemIsEditable);
			QTableWidgetItem *email = new QTableWidgetItem(QString::fromStdString((*companero)->getEmail()));
			email->setFlags(email->flags() & ~Qt::ItemIsEditable);
			ui->tableWidgetCompaneros->setItem(row, 0, nombre);
			ui->tableWidgetCompaneros->setItem(row, 1, email);
			vinculosCompaneros[nombre] = *companero;
			vinculosCompaneros[email] = *companero;
		}

		// Los notas que no estuvieran en la lista, se eliminan del widget.
		rows = ui->tableWidgetNotas->rowCount();
		for (int i = 0; i < rows; i++)
		{
			QTableWidgetItem *item = ui->tableWidgetNotas->item(i, 0);
			Nota *nota = vinculoNota(item);
			const std::list<Nota*> notas = asignatura->obtenerNotas();
			if (std::find(notas.begin(), notas.end(), nota) == notas.end())
			{
				desvincularNota(nota);
				ui->tableWidgetNotas->removeRow(i);
				i--;
				rows--;
			}
		}

		// Los citas que no estuvieran en la lista, se eliminan del widget.
		rows = ui->tableWidgetCitas->rowCount();
		for (int i = 0; i < rows; i++)
		{
			QTableWidgetItem *item = ui->tableWidgetCitas->item(i, 0);
			Cita *cita = vinculoCita(item);
			const std::list<Cita*> citas = asignatura->obtenerCitas();
			if (std::find(citas.begin(), citas.end(), cita) == citas.end())
			{
				desvincularCita(cita);
				ui->tableWidgetCitas->removeRow(i);
				i--;
				rows--;
			}
		}

		// Se añaden los cita nuevos (o se actualizan).
		const std::list<Cita*> citas = asignatura->obtenerCitas();
		std::list<Cita*>::const_iterator cita = citas.begin();
		for (; cita != citas.end(); cita++)
		{
			// Si el cita ya estaba, se modifica la fila. Si no estaba, se crea una fila nueva.
			int row = filaCita(*cita);
			if (row == -1)
			{
				row = ui->tableWidgetCitas->rowCount();
				ui->tableWidgetCitas->insertRow(row);
			}
			else
			{
				desvincularCita(*cita);
			}
			QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString((*cita)->getDescripcion()));
			item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
			QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString((*cita)->getFecha().toString()));
			item2->setFlags(item2->flags() & ~Qt::ItemIsEditable);
			QTableWidgetItem *item3 = new QTableWidgetItem(QString::number((*cita)->getDuracion()));
			item3->setFlags(item3->flags() & ~Qt::ItemIsEditable);
			ui->tableWidgetCitas->setItem(row, 0, item1);
			ui->tableWidgetCitas->setItem(row, 1, item2);
			ui->tableWidgetCitas->setItem(row, 2, item3);
			vinculosCitas[item1] = *cita;
			vinculosCitas[item2] = *cita;
			vinculosCitas[item3] = *cita;
		}

		// Se añaden los nota nuevos (o se actualizan).
		const std::list<Nota*> notas = asignatura->obtenerNotas();
		std::list<Nota*>::const_iterator nota = notas.begin();
		for (; nota != notas.end(); nota++)
		{
			// Si el nota ya estaba, se modifica la fila. Si no estaba, se crea una fila nueva.
			int row = filaNota(*nota);
			if (row == -1)
			{
				row = ui->tableWidgetNotas->rowCount();
				ui->tableWidgetNotas->insertRow(row);
			}
			else
			{
				desvincularNota(*nota);
			}
			QTableWidgetItem *nombre = new QTableWidgetItem(QString::fromStdString((*nota)->getDescripcion()));
			nombre->setFlags(nombre->flags() & ~Qt::ItemIsEditable);
			QTableWidgetItem *email = new QTableWidgetItem(QString::number((*nota)->getNota()));
			email->setFlags(email->flags() & ~Qt::ItemIsEditable);
			ui->tableWidgetNotas->setItem(row, 0, nombre);
			ui->tableWidgetNotas->setItem(row, 1, email);
			vinculosNotas[nombre] = *nota;
			vinculosNotas[email] = *nota;
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
	while (ui->tableWidgetCompaneros->rowCount())
		ui->tableWidgetCompaneros->removeRow(0);
	vinculosCompaneros.clear();
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

void VistaQtAsignatura::on_tableWidgetCompaneros_itemDoubleClicked(QTableWidgetItem *item)
{
	DialogoCompanero dialogoCompanero(vinculoCompanero(item), (Asignatura*) modelo, this);
	dialogoCompanero.exec();
}

Companero* VistaQtAsignatura::vinculoCompanero(QTableWidgetItem *item) const
{
	std::map<QTableWidgetItem*, Companero*>::const_iterator i = vinculosCompaneros.begin();
	for (; i != vinculosCompaneros.end(); i++)
	{
		if (i->first == item)
			return i->second;
	}
	return NULL;
}

int VistaQtAsignatura::filaCompanero(Companero *companero) const
{
	std::map<QTableWidgetItem*, Companero*>::const_iterator i = vinculosCompaneros.begin();
	for (; i != vinculosCompaneros.end(); i++)
	{
		if (i->second == companero)
			return ui->tableWidgetCompaneros->row(i->first);
	}
	return -1;
}

void VistaQtAsignatura::desvincularCompanero(Companero *companero)
{
	std::map<QTableWidgetItem*, Companero*>::iterator i = vinculosCompaneros.begin();
	while (i != vinculosCompaneros.end())
	{
		if (i->second == companero)
		{
			std::map<QTableWidgetItem*, Companero*>::iterator aux = i++;
			vinculosCompaneros.erase(aux);
		}
		else
		{
			i++;
		}
	}
}

void VistaQtAsignatura::quitarCompaneroSeleccionado()
{
	if (ui->tableWidgetCompaneros->selectedItems().size() > 0)
	{
		Companero *companero = vinculoCompanero(ui->tableWidgetCompaneros->selectedItems().first());
		Asignatura *asignatura = static_cast<Asignatura*>(modelo);
		if (asignatura != NULL && companero != NULL)
		{
			ui->tableWidgetCompaneros->removeRow(ui->tableWidgetCompaneros->row(ui->tableWidgetCompaneros->selectedItems().first()));
			desvincularCompanero(companero);
			asignatura->quitarCompanero(companero);
			asignatura->refrescarVistas(this);
		}
	}
}

void VistaQtAsignatura::on_pushButtonQuitarCompanero_clicked()
{
	quitarCompaneroSeleccionado();
}

void VistaQtAsignatura::on_pushButtonAnadirCompanero_clicked()
{
	DialogoCompanero dialogoCompanero(NULL, (Asignatura*) modelo, this);
	dialogoCompanero.exec();
}

void VistaQtAsignatura::on_tableWidgetNotas_itemDoubleClicked(QTableWidgetItem *item)
{
	DialogoNota dialogoNota(vinculoNota(item), (Asignatura*) modelo, this);
	dialogoNota.exec();
}

Nota* VistaQtAsignatura::vinculoNota(QTableWidgetItem *item) const
{
	std::map<QTableWidgetItem*, Nota*>::const_iterator i = vinculosNotas.begin();
	for (; i != vinculosNotas.end(); i++)
	{
		if (i->first == item)
			return i->second;
	}
	return NULL;
}

int VistaQtAsignatura::filaNota(Nota *nota) const
{
	std::map<QTableWidgetItem*, Nota*>::const_iterator i = vinculosNotas.begin();
	for (; i != vinculosNotas.end(); i++)
	{
		if (i->second == nota)
			return ui->tableWidgetNotas->row(i->first);
	}
	return -1;
}

void VistaQtAsignatura::desvincularNota(Nota *nota)
{
	std::map<QTableWidgetItem*, Nota*>::iterator i = vinculosNotas.begin();
	while (i != vinculosNotas.end())
	{
		if (i->second == nota)
		{
			std::map<QTableWidgetItem*, Nota*>::iterator aux = i++;
			vinculosNotas.erase(aux);
		}
		else
		{
			i++;
		}
	}
}

void VistaQtAsignatura::quitarNotaSeleccionado()
{
	if (ui->tableWidgetNotas->selectedItems().size() > 0)
	{
		Nota *nota = vinculoNota(ui->tableWidgetNotas->selectedItems().first());
		Asignatura *asignatura = static_cast<Asignatura*>(modelo);
		if (asignatura != NULL && nota != NULL)
		{
			ui->tableWidgetNotas->removeRow(ui->tableWidgetNotas->row(ui->tableWidgetNotas->selectedItems().first()));
			desvincularNota(nota);
			asignatura->quitarNota(nota);
			asignatura->refrescarVistas(this);
		}
	}
}

void VistaQtAsignatura::on_pushButtonQuitarNota_clicked()
{
	quitarNotaSeleccionado();
}

void VistaQtAsignatura::on_pushButtonAnadirNota_clicked()
{
	DialogoNota dialogoNota(NULL, (Asignatura*) modelo, this);
	dialogoNota.exec();
}

void VistaQtAsignatura::on_tableWidgetCitas_itemDoubleClicked(QTableWidgetItem *item)
{
	DialogoCita dialogoCita(vinculoCita(item), (Asignatura*) modelo, this);
	dialogoCita.exec();
}

Cita* VistaQtAsignatura::vinculoCita(QTableWidgetItem *item) const
{
	std::map<QTableWidgetItem*, Cita*>::const_iterator i = vinculosCitas.begin();
	for (; i != vinculosCitas.end(); i++)
	{
		if (i->first == item)
			return i->second;
	}
	return NULL;
}

int VistaQtAsignatura::filaCita(Cita *cita) const
{
	std::map<QTableWidgetItem*, Cita*>::const_iterator i = vinculosCitas.begin();
	for (; i != vinculosCitas.end(); i++)
	{
		if (i->second == cita)
			return ui->tableWidgetCitas->row(i->first);
	}
	return -1;
}

void VistaQtAsignatura::desvincularCita(Cita *cita)
{
	std::map<QTableWidgetItem*, Cita*>::iterator i = vinculosCitas.begin();
	while (i != vinculosCitas.end())
	{
		if (i->second == cita)
		{
			std::map<QTableWidgetItem*, Cita*>::iterator aux = i++;
			vinculosCitas.erase(aux);
		}
		else
		{
			i++;
		}
	}
}

void VistaQtAsignatura::quitarCitaSeleccionado()
{
	if (ui->tableWidgetCitas->selectedItems().size() > 0)
	{
		Cita *cita = vinculoCita(ui->tableWidgetCitas->selectedItems().first());
		Asignatura *asignatura = static_cast<Asignatura*>(modelo);
		if (asignatura != NULL && cita != NULL)
		{
			ui->tableWidgetCitas->removeRow(ui->tableWidgetCitas->row(ui->tableWidgetCitas->selectedItems().first()));
			desvincularCita(cita);
			asignatura->quitarCita(cita);
			asignatura->refrescarVistas(this);
		}
	}
}

void VistaQtAsignatura::on_pushButtonQuitarCita_clicked()
{
	quitarCitaSeleccionado();
}

void VistaQtAsignatura::on_pushButtonAnadirCita_clicked()
{
	DialogoCita dialogoCita(NULL, (Asignatura*) modelo, this);
	dialogoCita.exec();
}
