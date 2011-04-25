#ifndef VISTAQTASIGNATURA_H
#define VISTAQTASIGNATURA_H

#include <QTabWidget>
#include <QTableWidgetItem>
#include <map>
#include "Asignatura.h"

namespace Ui {
    class VistaQtAsignatura;
}

/**
 * Clase que muestra la información de una asignatura en pestañas.
 * Es una vista que muestra la información del modelo de Asignatura seleccionado.
 */
class VistaQtAsignatura : public QTabWidget, public Vista
{
    Q_OBJECT

public:
    /**
     * Constructor por defecto que conecta la vista a una asignatura concreta.
     * @param parent Widget padre que en este caso siempre coincide con la ventana principal.
     */
    explicit VistaQtAsignatura(QWidget *parent = 0);

    /**
     * Libera la memoria reservada del fichero UI.
     */
    ~VistaQtAsignatura();

    /**
     * Refresca todas las pestañas de la asignatura actual.
     * Normalmente es el modelo de la Asignatura quien solicita el refresco.
     */
    void refrescar();

    /**
     * Deja las pestañas sin ningún profesor, compañero...
     */
    void limpiar();

private:
    Ui::VistaQtAsignatura *ui;
    Asignatura *ultimaAsignaturaRefrescada;

    std::map<QTableWidgetItem*, Profesor*> vinculosProfesores;
    std::map<QTableWidgetItem*, Companero*> vinculosCompaneros;
    std::map<QTableWidgetItem*, Sesion*> vinculosSesiones;
    std::map<QTableWidgetItem*, Cita*> vinculosCitas;
    std::map<QTableWidgetItem*, Nota*> vinculosNotas;

    /**
     * Dado un item de la tabla, devuelve la referencia del profesor a la que pertenece.
     * @param item Item de la tabla que se quiere evaluar.
     * @return Referencia al profesor al que corresponde el item de la tabla.
     */
    Profesor* vinculoProfesor(QTableWidgetItem *item) const;

    /**
     * Dado una referencia al profesor, indica en qué fila de la tabla se encuentra.
     * @param profesor Profesor que se quiere comprobar.
     * @return Valor entero de la fila en la que se encuentra el profesor.
     */
    int filaProfesor(Profesor *profesor) const;

    /**
     * Dado un profesor, elimina su relación con cualquier item de la tabla con el que estuviera relacionado.
     * @param profesor Profesor que se quiere desasociar.
     */
    void desvincularProfesor(Profesor *profesor);

    /**
     * Elimina la fila del profesor que esté seleccionado.
     */
    void quitarProfesorSeleccionado();

    /**
     * Dado un item de la tabla, devuelve la referencia del compañero a la que pertenece.
     * @param item Item de la tabla que se quiere evaluar.
     * @return Referencia al compañero al que corresponde el item de la tabla.
     */
    Companero* vinculoCompanero(QTableWidgetItem *item) const;

    /**
     * Dado una referencia al compañero, indica en qué fila de la tabla se encuentra.
     * @param compañero Compañero que se quiere comprobar.
     * @return Valor entero de la fila en la que se encuentra el compañero.
     */
    int filaCompanero(Companero *companero) const;

    /**
     * Dado un compañero, elimina su relación con cualquier item de la tabla con el que estuviera relacionado.
     * @param compañero Compañero que se quiere desasociar.
     */
    void desvincularCompanero(Companero *companero);

    /**
     * Elimina la fila del compañero que esté seleccionado.
     */
    void quitarCompaneroSeleccionado();

    /**
     * Dado un item de la tabla, devuelve la referencia de la sesión a la que pertenece.
     * @param item Item de la tabla que se quiere evaluar.
     * @return Referencia a la sesión a la que corresponde el item de la tabla.
     */
    Sesion* vinculoSesion(QTableWidgetItem *item) const;

    /**
     * Dado una referencia a la sesión, indica en qué fila de la tabla se encuentra.
     * @param sesion Sesión que se quiere comprobar.
     * @return Valor entero de la fila en la que se encuentra la sesión.
     */
    int filaSesion(Sesion *sesion) const;

    /**
     * Dado una sesión, elimina su relación con cualquier item de la tabla con el que estuviera relacionado.
     * @param sesion Sesión que se quiere desasociar.
     */
    void desvincularSesion(Sesion *sesion);

    /**
     * Elimina la fila de la sesión que esté seleccionado.
     */
    void quitarSesionSeleccionado();

    /**
     * Dado un item de la tabla, devuelve la referencia de la cita a la que pertenece.
     * @param item Item de la tabla que se quiere evaluar.
     * @return Referencia a la cita a la que corresponde el item de la tabla.
     */
    Cita* vinculoCita(QTableWidgetItem *item) const;

    /**
     * Dado una referencia a la cita, indica en qué fila de la tabla se encuentra.
     * @param cita Cita que se quiere comprobar.
     * @return Valor entero de la fila en la que se encuentra la cita.
     */
    int filaCita(Cita *cita) const;

    /**
     * Dado una cita, elimina su relación con cualquier item de la tabla con el que estuviera relacionado.
     * @param cita Cita que se quiere desasociar.
     */
    void desvincularCita(Cita *cita);

    /**
     * Elimina la fila de la cita que esté seleccionado.
     */
    void quitarCitaSeleccionado();

    /**
     * Dado un item de la tabla, devuelve la referencia de la nota a la que pertenece.
     * @param item Item de la tabla que se quiere evaluar.
     * @return Referencia a la nota a la que corresponde el item de la tabla.
     */
    Nota* vinculoNota(QTableWidgetItem *item) const;

    /**
     * Dado una referencia a la nota, indica en qué fila de la tabla se encuentra.
     * @param nota Nota que se quiere comprobar.
     * @return Valor entero de la fila en la que se encuentra la nota.
     */
    int filaNota(Nota *nota) const;

    /**
     * Dado una nota, elimina su relación con cualquier item de la tabla con el que estuviera relacionado.
     * @param nota Nota que se quiere desasociar.
     */
    void desvincularNota(Nota *nota);

    /**
     * Elimina la fila de la nota que esté seleccionado.
     */
    void quitarNotaSeleccionado();

private slots:
    /**
     * Slot conectado al botón "Añadir profesor".
     * Lanza el diálogo para añadir un profesor.
     */
    void on_pushButtonAnadirProfesor_clicked();

    /**
     * Slot conectado al botón "Quitar profesor".
     * Elimina el profesor seleccionado.
     */
    void on_pushButtonQuitarProfesor_clicked();

    /**
     * Slot conectado al doubleclick sobre el QTableWidget que muestra la lista de profesores.
     * Lanza un diálogo para editar el profesor.
     * @param item Elemento seleccionado.
     */
    void on_tableWidgetProfesores_itemDoubleClicked(QTableWidgetItem *item);

    /**
     * Slot conectado al botón "Añadir compañero".
     * Lanza el diálogo para añadir un compañero.
     */
    void on_pushButtonAnadirCompanero_clicked();

    /**
     * Slot conectado al botón "Quitar compañero".
     * Elimina el compañero seleccionado.
     */
    void on_pushButtonQuitarCompanero_clicked();

    /**
     * Slot conectado al doubleclick sobre el QTableWidget que muestra la lista de compañeros.
     * Lanza un diálogo para editar el compañero.
     * @param item Elemento seleccionado.
     */
    void on_tableWidgetCompaneros_itemDoubleClicked(QTableWidgetItem *item);

    /**
     * Slot conectado al botón "Añadir sesión".
     * Lanza el diálogo para añadir una sesión.
     */
    void on_pushButtonAnadirSesion_clicked();

    /**
     * Slot conectado al botón "Quitar sesión".
     * Elimina la sesión seleccionada.
     */
    void on_pushButtonQuitarSesion_clicked();

    /**
     * Slot conectado al doubleclick sobre el QTableWidget que muestra la lista de sesiones.
     * Lanza un diálogo para editar la sesión.
     * @param item Elemento seleccionado.
     */
    void on_tableWidgetSesiones_itemDoubleClicked(QTableWidgetItem *item);

    /**
     * Slot conectado al botón "Añadir cita".
     * Lanza el diálogo para añadir una cita.
     */
    void on_pushButtonAnadirCita_clicked();

    /**
     * Slot conectado al botón "Quitar cita".
     * Elimina la cita seleccionada.
     */
    void on_pushButtonQuitarCita_clicked();

    /**
     * Slot conectado al doubleclick sobre el QTableWidget que muestra la lista de citas.
     * Lanza un diálogo para editar la cita.
     * @param item Elemento seleccionado.
     */
    void on_tableWidgetCitas_itemDoubleClicked(QTableWidgetItem *item);

    /**
     * Slot conectado al botón "Añadir nota".
     * Lanza el diálogo para añadir una nota.
     */
    void on_pushButtonAnadirNota_clicked();

    /**
     * Slot conectado al botón "Quitar nota".
     * Elimina la nota seleccionada.
     */
    void on_pushButtonQuitarNota_clicked();

    /**
     * Slot conectado al doubleclick sobre el QTableWidget que muestra la lista de notas.
     * Lanza un diálogo para editar la nota.
     * @param item Elemento seleccionado.
     */
    void on_tableWidgetNotas_itemDoubleClicked(QTableWidgetItem *item);
};

#endif // VISTAQTASIGNATURA_H
