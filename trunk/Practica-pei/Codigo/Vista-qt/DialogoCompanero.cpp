#include "DialogoCompanero.h"
#include "ui_DialogoCompanero.h"

DialogoCompanero::DialogoCompanero(Companero *companero, Asignatura *asignatura, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoCompanero)
{
    ui->setupUi(this);

    this->asignatura = asignatura;
    this->companero = companero;
    if (companero != NULL)
    {
        this->setWindowTitle("Editando compañero");
        ui->lineEditNombre->setText(QString::fromStdString(companero->getNombre()));
        ui->lineEditEmail->setText(QString::fromStdString(companero->getEmail()));
    }
    else
    {
        this->setWindowTitle("Añadiendo nuevo compañero");
    }
}

DialogoCompanero::~DialogoCompanero()
{
    delete ui;
}

void DialogoCompanero::on_buttonBox_accepted()
{
    if (companero == NULL)
    {
        companero = new Companero();
        asignatura->anadirCompanero(companero);
    }

    companero->setNombre(ui->lineEditNombre->text().toStdString());
    companero->setEmail(ui->lineEditEmail->text().toStdString());
    asignatura->refrescarVistas();

    close();
}

void DialogoCompanero::on_buttonBox_rejected()
{
    close();
}
