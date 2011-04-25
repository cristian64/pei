#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Asignaturas.h"

namespace Ui {
    class MainWindow;
}

/**
 * Ventana principal que contiene las 3 vistas de la Vista de Qt (vista de asignaturas, vista de asignatura y vista resumen).
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Constrctor por defecto que recibe el modelo de Asignaturas al que se conecntan las vistas.
     * @param asignaturas Modelo de Asignaturas al que se conectan las vistas.
     */
    explicit MainWindow(Asignaturas *asignaturas);

    /**
     * Libera la memoria de la interfaz UI.
     */
    ~MainWindow();

private:
    Asignaturas *asignaturas;
    Ui::MainWindow *ui;

public slots:
    /**
     * Slot conectado al botón "Resumen de citas y horario".
     * Muestra el horario y el resumen de citas.
     * @param checked Indica si se ha marcado o desmarcado.
     */
    void on_actionResumen_toggled(bool checked);

    /**
     * Slot que se conecta a una señal personalizada.
     * Esta señal se lanza cuando se selecciona una nueva fila en el QTableWidget que contiene la lista
     * de asignaturas. Al ser personalizada, en vez de devolver un QListWidgetItem, devuelve directamente
     * la referencia a la asignatura seleccionada.
     * @param asignatura Asignatura seleccionada.
     */
    void asignaturaSeleccionadaCambio(Asignatura *asignatura);

    /**
     * Slot conectado al botón "Añadir asignatura".
     * Lanza un diálogo para introducir el nombre de la nueva asignatura.
     */
    void on_actionAnadir_triggered();

    /**
     * Slot conectado al botón "Quitar asignatura".
     * Quita la asignatura seleccionada en la lista.
     */
    void on_actionQuitar_triggered();

    /**
     * Slot conectado al botón "Nuevo".
     * Lanza un diálogo para elegir dónde guardar el nuevo paquete de asignaturas.
     */
    void on_actionNuevo_triggered();

    /**
     * Slot conectado al botón "Abrir".
     * Lanza un diálogo para elegir qué fichero abrir.
     */
    void on_actionAbrir_triggered();

    /**
     * Slot conectado al botón "Guardar".
     * Guarda el paquete de asignaturas en la última ruta conocida. Si no hay ningnua ruta, lanza el diálogo de "Guardar como".
     */
    void on_actionGuardar_triggered();

    /**
     * Slot conectado al botón "Guardar como".
     * Lanza un diálogo para elegir dónde guardar.
     */
    void on_actionGuardarComo_triggered();

    /**
     * Slot conectado al botón "Salir".
     * Cierra la ventana y la ejecución finaliza.
     */
    void on_actionSalir_triggered();

    /**
     * Slot conectado al botón "Acerca de".
     * Lanza el diálogo de "Acerca de".
     */
    void on_actionAcercaDe_triggered();
};

#endif // MAINWINDOW_H
