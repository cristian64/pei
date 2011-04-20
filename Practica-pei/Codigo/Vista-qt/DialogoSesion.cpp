#include "DialogoSesion.h"
#include "ui_DialogoSesion.h"

DialogoSesion::DialogoSesion(Sesion *sesion, Asignatura *asignatura, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogoSesion)
{
	ui->setupUi(this);

	this->asignatura = asignatura;
	this->sesion = sesion;
	if (sesion != NULL)
	{
		this->setWindowTitle("Editando sesión");
		ui->radioButtonTeoria->setChecked(sesion->getTipo() == Sesion::TEORIA);
		ui->radioButtonPracticas->setChecked(sesion->getTipo() != Sesion::TEORIA);
		ui->lineEditLugar->setText(QString::fromStdString(sesion->getLugar()));
		ui->comboBoxDia->setCurrentIndex(sesion->getDia());
		QTime timeInicio(sesion->getFechaInicio().hora, sesion->getFechaInicio().minuto, sesion->getFechaInicio().segundo);
		ui->timeEditInicio->setTime(timeInicio);
		QTime timeFin(sesion->getFechaFin().hora, sesion->getFechaFin().minuto, sesion->getFechaFin().segundo);
		ui->timeEditFin->setTime(timeFin);
	}
	else
	{
		this->setWindowTitle("Añadiendo nueva sesión");
	}
}

DialogoSesion::~DialogoSesion()
{
	delete ui;
}

void DialogoSesion::on_buttonBox_accepted()
{
	if (sesion == NULL)
	{
		sesion = new Sesion();
		asignatura->anadirSesion(sesion);
	}

	sesion->setTipo(ui->radioButtonTeoria->isChecked() ? Sesion::TEORIA : Sesion::PRACTICAS);
	sesion->setLugar(ui->lineEditLugar->text().toStdString());
	sesion->setDia((Sesion::Dia) ui->comboBoxDia->currentIndex());
	Fecha fechaInicio(0, 0, 0, ui->timeEditInicio->time().hour(), ui->timeEditInicio->time().minute(), ui->timeEditInicio->time().second());
	sesion->setFechaInicio(fechaInicio);
	Fecha fechaFin(0, 0, 0, ui->timeEditFin->time().hour(), ui->timeEditFin->time().minute(), ui->timeEditFin->time().second());
	sesion->setFechaFin(fechaFin);

	asignatura->refrescarVistas();

	close();
}

void DialogoSesion::on_buttonBox_rejected()
{
	close();
}
