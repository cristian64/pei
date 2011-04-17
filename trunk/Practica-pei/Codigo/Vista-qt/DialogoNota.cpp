#include "DialogoNota.h"
#include "ui_DialogoNota.h"

DialogoNota::DialogoNota(Nota *nota, Asignatura *asignatura, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogoNota)
{
	ui->setupUi(this);

	this->asignatura = asignatura;
	this->nota = nota;
	if (nota != NULL)
	{
		this->setWindowTitle("Editando nota");
		ui->lineEditDescripcion->setText(QString::fromStdString(nota->getDescripcion()));
		ui->doubleSpinBoxNota->setValue(nota->getNota());
	}
	else
	{
		this->setWindowTitle("Añadiendo nueva nota");
	}
}

DialogoNota::~DialogoNota()
{
	delete ui;
}

void DialogoNota::on_buttonBox_accepted()
{
	if (nota == NULL)
	{
		nota = new Nota();
		asignatura->anadirNota(nota);
	}

	nota->setDescripcion(ui->lineEditDescripcion->text().toStdString());
	nota->setNota(ui->doubleSpinBoxNota->value());
	asignatura->refrescarVistas();

	close();
}

void DialogoNota::on_buttonBox_rejected()
{
	close();
}
