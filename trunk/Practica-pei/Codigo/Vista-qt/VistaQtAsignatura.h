#ifndef VISTAQTASIGNATURA_H
#define VISTAQTASIGNATURA_H

#include <QTabWidget>
#include <QTableWidgetItem>
#include <map>
#include "Asignatura.h"

namespace Ui {
    class VistaQtAsignatura;
}

class VistaQtAsignatura : public QTabWidget, public Vista
{
    Q_OBJECT

public:
    explicit VistaQtAsignatura(QWidget *parent = 0);
    ~VistaQtAsignatura();
    void refrescar();
    void limpiar();

private:
    Ui::VistaQtAsignatura *ui;
    Asignatura *ultimaAsignaturaRefrescada;

    std::map<QTableWidgetItem*, Profesor*> vinculosProfesores;
    Profesor* vinculoProfesor(QTableWidgetItem *item) const;
    int filaProfesor(Profesor *profesor) const;
    void desvincularProfesor(Profesor *profesor);
    void quitarProfesorSeleccionado();

    std::map<QTableWidgetItem*, Companero*> vinculosCompaneros;
    Companero* vinculoCompanero(QTableWidgetItem *item) const;
    int filaCompanero(Companero *companero) const;
    void desvincularCompanero(Companero *companero);
    void quitarCompaneroSeleccionado();

    std::map<QTableWidgetItem*, Sesion*> vinculosSesiones;
    Sesion* vinculoSesion(QTableWidgetItem *item) const;
    int filaSesion(Sesion *sesion) const;
    void desvincularSesion(Sesion *sesion);
    void quitarSesionSeleccionado();

    std::map<QTableWidgetItem*, Cita*> vinculosCitas;
    Cita* vinculoCita(QTableWidgetItem *item) const;
    int filaCita(Cita *cita) const;
    void desvincularCita(Cita *cita);
    void quitarCitaSeleccionado();

    std::map<QTableWidgetItem*, Nota*> vinculosNotas;
    Nota* vinculoNota(QTableWidgetItem *item) const;
    int filaNota(Nota *nota) const;
    void desvincularNota(Nota *nota);
    void quitarNotaSeleccionado();

private slots:
    void on_pushButtonAnadirProfesor_clicked();
    void on_pushButtonQuitarProfesor_clicked();
    void on_tableWidgetProfesores_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButtonAnadirCompanero_clicked();
    void on_pushButtonQuitarCompanero_clicked();
    void on_tableWidgetCompaneros_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButtonAnadirSesion_clicked();
    void on_pushButtonQuitarSesion_clicked();
    void on_tableWidgetSesiones_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButtonAnadirCita_clicked();
    void on_pushButtonQuitarCita_clicked();
    void on_tableWidgetCitas_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButtonAnadirNota_clicked();
    void on_pushButtonQuitarNota_clicked();
    void on_tableWidgetNotas_itemDoubleClicked(QTableWidgetItem *item);
};

#endif // VISTAQTASIGNATURA_H
