#include "DialogoProfesor.h"
#include "ui_DialogoProfesor.h"

DialogoProfesor::DialogoProfesor(Profesor *profesor, Asignatura *asignatura, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoProfesor)
{
    ui->setupUi(this);

    this->asignatura = asignatura;
    this->profesor = profesor;
    if (profesor != NULL)
    {
        this->setWindowTitle("Editando profesor");
        ui->lineEditNombre->setText(QString::fromStdString(profesor->getNombre()));
        ui->lineEditEmail->setText(QString::fromStdString(profesor->getEmail()));
    }
    else
    {
        this->setWindowTitle("Añadiendo nuevo profesor");
    }
}

DialogoProfesor::~DialogoProfesor()
{
    delete ui;
}

void DialogoProfesor::on_buttonBox_accepted()
{
    if (profesor == NULL)
    {
        profesor = new Profesor();
        asignatura->anadirProfesor(profesor);
    }

    profesor->setNombre(ui->lineEditNombre->text().toStdString());
    profesor->setEmail(ui->lineEditEmail->text().toStdString());
    asignatura->refrescarVistas();

    close();
}

void DialogoProfesor::on_buttonBox_rejected()
{
    close();
}
