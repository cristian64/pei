#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTextCodec>
#include <QInputDialog>
#include <QFileDialog>

MainWindow::MainWindow(Asignaturas *asignaturas) :
    QMainWindow(NULL),
    asignaturas(asignaturas),
    ui(new Ui::MainWindow)
{
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);
    QTextCodec::setCodecForCStrings(linuxCodec);
    QTextCodec::setCodecForLocale(linuxCodec);

    ui->setupUi(this);
    ui->vistaQtAsignaturas->ponerModelo(asignaturas);
    ui->vistaQtAsignaturas->refrescar();
    ui->vistaQtResumen->ponerModelo(asignaturas);
    ui->vistaQtResumen->refrescar();
    ui->vistaQtResumen->setVisible(false);

    ui->actionQuitar->setEnabled(false);
    connect(ui->vistaQtAsignaturas, SIGNAL(asignaturaSeleccionadaCambio(Asignatura*)), SLOT(asignaturaSeleccionadaCambio(Asignatura*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAnadir_triggered()
{
    bool ok;
    QString texto = QInputDialog::getText(this, "Nueva asignatura", "Nombre de la asignatura:                          ", QLineEdit::Normal, "", &ok);
    if (ok && !texto.isEmpty())
    {
        asignaturas->anadirAsignatura(new Asignatura(texto.toStdString()));
        asignaturas->refrescarVistas();
    }
}

void MainWindow::on_actionQuitar_triggered()
{
    ui->vistaQtAsignaturas->quitarAsignaturaSeleccionada();
}

void MainWindow::on_actionNuevo_triggered()
{
    // Diálogo para preguntar al usuario dónde guardar el nuevo paquete de asignaturas.
    QFileDialog fileDialog;
    fileDialog.setDirectory("./");
    fileDialog.setConfirmOverwrite(true);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QStringList filtros;
    filtros.push_back("*.xml *.txt");
    filtros.push_back("*");
    fileDialog.setFilters(filtros);
    if (fileDialog.exec())
    {
        ui->vistaQtAsignaturas->deseleccionar();
        QString fileName = fileDialog.selectedFiles().front();
        asignaturas->limpiar();
        asignaturas->guardar(fileName.toStdString());
        asignaturas->refrescarVistas();
    }
}

void MainWindow::on_actionAbrir_triggered()
{
    // Diálogo para preguntar al usuario qué paquete de asignaturas abrir.
    QFileDialog fileDialog;
    fileDialog.setDirectory("./");
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    QStringList filtros;
    filtros.push_back("*.xml *.txt");
    filtros.push_back("*");
    fileDialog.setFilters(filtros);
    if (fileDialog.exec())
    {
        ui->vistaQtAsignaturas->deseleccionar();
        QString fileName = fileDialog.selectedFiles().front();
        asignaturas->cargar(fileName.toStdString());
        asignaturas->refrescarVistas();
    }
}

void MainWindow::on_actionGuardar_triggered()
{
    // Si el fichero ya estaba guardado, simplemente lo guarda. Si no lo estaba, invoca el diálogo de "Guardar como".
    if (asignaturas->getRutaFichero() != "")
        asignaturas->guardar(asignaturas->getRutaFichero());
    else
        on_actionGuardarComo_triggered();
}

void MainWindow::on_actionGuardarComo_triggered()
{
    // Diálogo para preguntar al usuario dónde guardar el paquete de asignaturas actual.
    QFileDialog fileDialog;
    fileDialog.setDirectory("./");
    fileDialog.setConfirmOverwrite(true);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    QStringList filtros;
    filtros.push_back("*.xml *.txt");
    filtros.push_back("*");
    fileDialog.setFilters(filtros);
    if (fileDialog.exec())
    {
        QString fileName = fileDialog.selectedFiles().front();
        asignaturas->guardar(fileName.toStdString());
    }
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionAcercaDe_triggered()
{

}

void MainWindow::asignaturaSeleccionadaCambio(Asignatura *asignatura)
{
    ui->actionQuitar->setEnabled(asignatura != NULL);
    ui->vistaQtAsignatura->ponerModelo(asignatura);
    ui->vistaQtAsignatura->refrescar();
}

void MainWindow::on_actionResumen_toggled(bool checked)
{
    ui->actionResumen->setChecked(checked);
    ui->vistaQtAsignatura->setVisible(!checked);
    ui->vistaQtResumen->setVisible(checked);
    if (checked)
        ui->vistaQtResumen->refrescar();
}
