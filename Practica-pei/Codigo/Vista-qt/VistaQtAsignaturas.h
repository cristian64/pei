#ifndef VISTAQTASIGNATURAS_H
#define VISTAQTASIGNATURAS_H

#include <QListWidget>
#include <map>
#include "Vista.h"
#include "Asignatura.h"

namespace Ui {
    class VistaQtAsignaturas;
}

/**
 * Vista de asignaturas que muestra una lista actualizada con las asignaturas que hay en el paquete de asignaturas.
 * Esta vista apunta a un paquete de asignaturas (Asignaturas), que es un modelo que refresca esta vista cuando se añade una asignatura (o se edita o se borra).
 */
class VistaQtAsignaturas : public QListWidget, public Vista
{
    Q_OBJECT

public:
    /**
     * Constructor por defecto que conecta la vista y la subvista de asignatura concreta.
     * @param parent Widget padre que en este caso siempre coincide con la ventana principal.
     */
    explicit VistaQtAsignaturas(QWidget *parent = 0);

    /**
     * Libera la memoria del .ui y desconecta la vista.
     */
    ~VistaQtAsignaturas();

    /**
     * Recarga la lista de asignaturas.
     */
    void refrescar();

    /**
     * Elimina la asignatura seleccionada.
     */
    void quitarAsignaturaSeleccionada();

    /**
     * Obtienela asignatura seleccionada actualmente.
     * @return Referencia a la asignatura seleccionada.
     */
    Asignatura* obtenerSeleccionada() const;

    /**
     * Deselecciona la asignatura seleccionada.
     */
    void deseleccionar();

private:
    Ui::VistaQtAsignaturas *ui;
    std::map<Asignatura*, QListWidgetItem*> vinculos;

signals:
    /**
     * Señal personalizada que se conecta a a la señal itemSelectionChanged de QListWidget.
     * Esta señal tiene el puntero a la Asignatura seleccionada en los parámetros.
     * De esta forma, slots externos a esta clase pueden conectarse a esta señal y recibir la
     * asignatura seleccionada, en vez de recibir un QListWidgetItem.
     * @param asignatura Referencia a la asignatura que se ha seleccionado.
     */
    void asignaturaSeleccionadaCambio(Asignatura *asignatura);

private slots:
    /**
     * Slot que se conecta a la señal itemClicked de QListWidget.
     * Se usa para cambiar al modo de pestañas cuando se pulsa una asignatura (por si estaba en la vista de resumen).
     * @param item Elemento que se ha seleccionado.
     */
    void itemClicked(QListWidgetItem* item);

    /**
     * Slot que se conecta a la señal itemSelectionChanged de QListWidget.
     * Lo único que hace es emitir la señal personalizada asignaturaSeleccionadaCambio(Asignatura*).
     */
    void itemSelectionChanged();

    /**
     * Slot que se conecta a la seal itemChanged de QListWidget.
     * Cuando se modifica el nombre de una asignatura, refresca la asignatura a la que corresponde y refresca el modelo.
     * @param item Elemento que se ha modificado.
     */
    void itemChanged(QListWidgetItem *item);
};

#endif // VISTAQTASIGNATURAS_H
