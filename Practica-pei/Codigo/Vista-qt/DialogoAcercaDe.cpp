#include "DialogoAcercaDe.h"
#include "ui_DialogoAcercaDe.h"

DialogoAcercaDe::DialogoAcercaDe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoAcercaDe)
{
    ui->setupUi(this);
}

DialogoAcercaDe::~DialogoAcercaDe()
{
    delete ui;
}

void DialogoAcercaDe::on_buttonBox_accepted()
{
    close();
}
