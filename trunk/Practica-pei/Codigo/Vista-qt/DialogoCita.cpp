#include "DialogoCita.h"
#include "ui_DialogoCita.h"

DialogoCita::DialogoCita(Cita *cita, Asignatura *asignatura, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogoCita)
{
	ui->setupUi(this);

	this->asignatura = asignatura;
	this->cita = cita;
	if (cita != NULL)
	{
		this->setWindowTitle("Editando cita");
		ui->lineEditDescripcion->setText(QString::fromStdString(cita->getDescripcion()));
		QDateTime dateTime(QDate(cita->getFecha().ano, cita->getFecha().mes, cita->getFecha().dia),
						   QTime(cita->getFecha().hora, cita->getFecha().minuto, cita->getFecha().segundo));
		ui->dateTimeEdit->setDateTime(dateTime);
		ui->spinBoxDuracion->setValue(cita->getDuracion());
	}
	else
	{
		this->setWindowTitle("Añadiendo nueva cita");
	}
}

DialogoCita::~DialogoCita()
{
	delete ui;
}

void DialogoCita::on_buttonBox_accepted()
{
	if (cita == NULL)
	{
		cita = new Cita();
		asignatura->anadirCita(cita);
	}

	cita->setDescripcion(ui->lineEditDescripcion->text().toStdString());
	QDate date = ui->dateTimeEdit->dateTime().date();
	QTime time = ui->dateTimeEdit->dateTime().time();
	Fecha fecha(date.year(), date.month(), date.day(), time.hour(), time.minute(), time.second());
	cita->setFecha(fecha);
	cita->setDuracion(ui->spinBoxDuracion->value());
	asignatura->refrescarVistas();

	close();
}

void DialogoCita::on_buttonBox_rejected()
{
	close();
}
