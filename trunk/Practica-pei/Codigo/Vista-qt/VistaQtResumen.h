#ifndef VISTAQTRESUMEN_H
#define VISTAQTRESUMEN_H

#include <QWidget>
#include "Vista.h"
#include <list>

namespace Ui {
    class VistaQtResumen;
}

/**
 * Vista que muestra el resumen de citas de exámenes/prácticas y el horario de la semana.
 */
class VistaQtResumen : public QWidget, public Vista
{
    Q_OBJECT

public:
    /**
     * Constructor por defecto que conecta la vista al paquete de asignaturas.
     * @param parent Widget padre que en este caso siempre coincide con la ventana principal.
     */
    explicit VistaQtResumen(QWidget *parent = 0);

    /**
     * Destructor que libera la memoria.
     */
    ~VistaQtResumen();

    /**
     * Refresca la vista. Normalmente cuando lo notifica el modelo.
     */
    void refrescar();

    /**
     * Método auxiliar que refresca la parte de las citas.
     * Se llama desde void refrescar().
     */
    void recargarCitas();

    /**
     * Método auxiliar que refresca la parte del horario.
     * Se llama desde void refrescar().
     */
    void recargarHorario();

private:
    Ui::VistaQtResumen *ui;
    std::list<void*> vistasMini;

private slots:
    /**
     * Slot conectado al checkbox para permutar entre mostrar citas pasadas o no hacerlo.
     * @param checked Indica si se ha marcado o desmarcado.
     */
    void on_checkBoxCitasPasadas_toggled(bool checked);

    /**
     * Slot conectado al checkbox para permutar entre mostrar sábado y domingo y no hacerlo.
     * @param checked Indica si se ha marcado o desmarcado.
     */
    void on_checkBoxSabadoDomingo_toggled(bool checked);
};

#endif // VISTAQTRESUMEN_H
