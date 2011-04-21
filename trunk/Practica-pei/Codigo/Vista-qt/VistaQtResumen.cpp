#include "VistaQtResumen.h"
#include "ui_VistaQtResumen.h"
#include "Asignaturas.h"
#include "Asignatura.h"
#include <algorithm>
#include <QDateTime>

VistaQtResumen::VistaQtResumen(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::VistaQtResumen)
{
	ui->setupUi(this);
	ui->tableWidgetCitas->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui->tableWidgetSesiones->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	ui->tableWidgetSesiones->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);

	ui->tableWidgetSesiones->hideColumn(5);
	ui->tableWidgetSesiones->hideColumn(6);
}

VistaQtResumen::~VistaQtResumen()
{
	delete ui;
}

void VistaQtResumen::refrescar()
{
	// crear una vista para cada asignatura y que su refrescar invoque tambien recargarLista()
	recargarCitas();
	recargarHorario();
}

void VistaQtResumen::recargarCitas()
{
	if (!isVisible())
		return;

	while (ui->tableWidgetCitas->rowCount())
		ui->tableWidgetCitas->removeRow(0);

	Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
	if (asignaturas != NULL)
	{
		// Se recorren todas las citas.
		const std::list<Asignatura*> lista = asignaturas->obtenerAsignaturas();
		for (std::list<Asignatura*>::const_iterator i = lista.begin(); i != lista.end(); i++)
		{
			// Se añaden las citas de la asignatura.
			const std::list<Cita*> citas = (*i)->obtenerCitas();
			std::list<Cita*>::const_iterator cita = citas.begin();
			for (; cita != citas.end(); cita++)
			{
				// Sólo se muestran las citas pendientes (salvo que se haya marcado la casilla).
				Fecha fecha = (*cita)->getFecha();
				QDateTime dateTime = QDateTime(QDate(fecha.ano, fecha.mes, fecha.dia), QTime(fecha.hora, fecha.minuto, fecha.segundo));
				if (ui->checkBoxCitasPasadas->isChecked() || dateTime > QDateTime::currentDateTime())
				{
					int row = ui->tableWidgetCitas->rowCount();
					ui->tableWidgetCitas->insertRow(row);
					QTableWidgetItem *item0 = new QTableWidgetItem(QString::fromStdString((*i)->getNombre()));
					item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
					QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString((*cita)->getDescripcion()));
					item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
					QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString((*cita)->getFecha().toString()));
					item2->setFlags(item2->flags() & ~Qt::ItemIsEditable);
					QTableWidgetItem *item3 = new QTableWidgetItem(QString::number((*cita)->getDuracion()));
					item3->setFlags(item3->flags() & ~Qt::ItemIsEditable);
					ui->tableWidgetCitas->setItem(row, 0, item0);
					ui->tableWidgetCitas->setItem(row, 1, item1);
					ui->tableWidgetCitas->setItem(row, 2, item2);
					ui->tableWidgetCitas->setItem(row, 3, item3);
				}
			}
		}

		ui->tableWidgetCitas->sortItems(2);
	}
}

bool comparadorSesiones(Sesion *a, Sesion *b)
{
	return a->getFechaInicio() < b->getFechaInicio();
}

void VistaQtResumen::recargarHorario()
{
	if (!isVisible())
		return;

	while (ui->tableWidgetSesiones->rowCount())
		ui->tableWidgetSesiones->removeRow(0);

	Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
	if (asignaturas != NULL)
	{
		std::list<Sesion*> todasSesiones;
		std::map<Sesion*, std::string> vinculos;

		// Se recorren todas las citas.
		const std::list<Asignatura*> lista = asignaturas->obtenerAsignaturas();
		for (std::list<Asignatura*>::const_iterator i = lista.begin(); i != lista.end(); i++)
		{
			// Se añaden las sesiones de la asignatura a la lista completa y se guarda el nombre de la asignatura para luego.
			const std::list<Sesion*> sesiones = (*i)->obtenerSesiones();
			std::list<Sesion*>::const_iterator sesion = sesiones.begin();
			for (; sesion != sesiones.end(); sesion++)
			{
				vinculos[*sesion] = (*i)->getNombre();
				todasSesiones.push_back(*sesion);
			}
		}

		// Cuenta cuántas sesiones hay cada día.
		int contadorColumnas[7] = {0, 0, 0, 0, 0, 0, 0};

		// Se ordenan las sesiones y se insertan.
		todasSesiones.sort(comparadorSesiones);
		std::list<Sesion*>::const_iterator sesion = todasSesiones.begin();
		for (; sesion != todasSesiones.end(); sesion++)
		{
			// Si no hay suficientes filas, se inserta una más.
			int dia = (*sesion)->getDia();
			int rows = ui->tableWidgetSesiones->rowCount();
			if (++contadorColumnas[dia] > rows)
			{
				ui->tableWidgetSesiones->insertRow(rows);
			}

			// Finalmente se inserta el elemento con su color correspondiente y en la posición correcta.
			std::string etiqueta = "\n" + (*sesion)->getFechaInicio().toStringHora() + " - " + (*sesion)->getFechaFin().toStringHora();
			etiqueta += "\n\n" + vinculos[*sesion] + "\n";
			QLabel *item = new QLabel(QString::fromStdString(etiqueta));
			if ((*sesion)->getTipo() == Sesion::TEORIA)
				item->setStyleSheet("background-color: #CFEF9E; font-size: 8pt;");
			else
				item->setStyleSheet("background-color: #ACC9EF; font-size: 8pt;");
			item->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			item->setWordWrap(true);
			ui->tableWidgetSesiones->setCellWidget(contadorColumnas[dia] - 1, dia, item);
		}
	}
}

void VistaQtResumen::on_checkBoxSabadoDomingo_toggled(bool checked)
{
	if (checked)
	{
		ui->tableWidgetSesiones->showColumn(5);
		ui->tableWidgetSesiones->showColumn(6);
	}
	else
	{
		ui->tableWidgetSesiones->hideColumn(5);
		ui->tableWidgetSesiones->hideColumn(6);
	}
}

void VistaQtResumen::on_checkBoxCitasPasadas_toggled(bool)
{
	recargarCitas();
}
