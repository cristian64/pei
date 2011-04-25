#ifndef VISTAGTKMMASIGNATURA_H
#define VISTAGTKMMASIGNATURA_H

#include "Vista.h"
#include "Asignatura.h"
#include <libglademm/xml.h>
#include <gtkmm.h>

/**
 * Clase que muestra la información de una asignatura en pestañas.
 * Es una vista que muestra la información del modelo de Asignatura seleccionado.
 */
class VistaGtkmmAsignatura : public Vista
{
public:
    /**
     * Constructor que recibe la información necesaria para inicializar los widgets.
     * @param refXml Referencia al XML de Glade, para conectar los punteros a los widgets.
     */
    VistaGtkmmAsignatura(Glib::RefPtr<Gnome::Glade::Xml> refXml);

    /**
     * Refresca todas las pestañas de la asignatura actual.
     * Normalmente es el modelo de la Asignatura quien solicita el refresco.
     */
    void refrescar();
    
private:
    Gtk::TreeModel::ColumnRecord columnas;
    Gtk::TreeModelColumn<Glib::ustring> columnaNombre;
    Gtk::TreeModelColumn<Glib::ustring> columnaEmail;
    Gtk::TreeModelColumn<Glib::ustring> columnaTipo;
    Gtk::TreeModelColumn<Glib::ustring> columnaLugar;
    Gtk::TreeModelColumn<Glib::ustring> columnaDia;
    Gtk::TreeModelColumn<Glib::ustring> columnaHoraInicio;
    Gtk::TreeModelColumn<Glib::ustring> columnaHoraFin;
    Gtk::TreeModelColumn<Glib::ustring> columnaDescripcion;
    Gtk::TreeModelColumn<Glib::ustring> columnaFecha;
    Gtk::TreeModelColumn<unsigned int> columnaDuracion;
    Gtk::TreeModelColumn<Glib::ustring> columnaNota;

    Gtk::Button *buttonAnadirProfesor;
    Gtk::Button *buttonQuitarProfesor;
    Gtk::TreeView *treeviewProfesores;
    Glib::RefPtr<Gtk::ListStore> treemodelProfesores;
    Glib::RefPtr<Gtk::TreeSelection> treeselectionProfesores;
    Gtk::Dialog *dialogProfesor;
    Gtk::Entry *entryNombreProfesor;
    Gtk::Entry *entryEmailProfesor;
    std::map<Profesor*, Gtk::TreeModel::Row> vinculosProfesores;

    Gtk::Button *buttonAnadirCompanero;
    Gtk::Button *buttonQuitarCompanero;
    Gtk::TreeView *treeviewCompaneros;
    Glib::RefPtr<Gtk::ListStore> treemodelCompaneros;
    Glib::RefPtr<Gtk::TreeSelection> treeselectionCompaneros;
    Gtk::Dialog *dialogCompanero;
    Gtk::Entry *entryNombreCompanero;
    Gtk::Entry *entryEmailCompanero;
    std::map<Companero*, Gtk::TreeModel::Row> vinculosCompaneros;

    Gtk::Button *buttonAnadirSesion;
    Gtk::Button *buttonQuitarSesion;
    Gtk::TreeView *treeviewSesiones;
    Glib::RefPtr<Gtk::ListStore> treemodelSesiones;
    Glib::RefPtr<Gtk::TreeSelection> treeselectionSesiones;
    Gtk::Dialog *dialogSesion;
    Gtk::RadioButton *radiobuttonTeoria;
    Gtk::RadioButton *radiobuttonPracticas;
    Gtk::Entry *entryLugar;
    Gtk::ComboBox *comboboxDia;
    Gtk::SpinButton *spinbuttonHora;
    Gtk::SpinButton *spinbuttonMinuto;
    Gtk::SpinButton *spinbuttonSegundo;
    Gtk::SpinButton *spinbuttonHora2;
    Gtk::SpinButton *spinbuttonMinuto2;
    Gtk::SpinButton *spinbuttonSegundo2;
    std::map<Sesion*, Gtk::TreeModel::Row> vinculosSesiones;

    Gtk::Button *buttonAnadirCita;
    Gtk::Button *buttonQuitarCita;
    Gtk::TreeView *treeviewCitas;
    Glib::RefPtr<Gtk::ListStore> treemodelCitas;
    Glib::RefPtr<Gtk::TreeSelection> treeselectionCitas;
    Gtk::Dialog *dialogCita;
    Gtk::Entry *entryDescripcion;
    Gtk::Calendar *calendarCita;
    Gtk::SpinButton *spinbuttonHora3;
    Gtk::SpinButton *spinbuttonMinuto3;
    Gtk::SpinButton *spinbuttonSegundo3;
    Gtk::SpinButton *spinbuttonDuracion;
    std::map<Cita*, Gtk::TreeModel::Row> vinculosCitas;

    Gtk::Button *buttonAnadirNota;
    Gtk::Button *buttonQuitarNota;
    Gtk::TreeView *treeviewNotas;
    Glib::RefPtr<Gtk::ListStore> treemodelNotas;
    Glib::RefPtr<Gtk::TreeSelection> treeselectionNotas;
    Gtk::Dialog *dialogNota;
    Gtk::Entry *entryDescripcionNota;
    Gtk::SpinButton *spinbuttonNota;
    std::map<Nota*, Gtk::TreeModel::Row> vinculosNotas;

    /**
     * Slot conectado al botón "Añadir profesor".
     * Lanza el diálogo para añadir un profesor.
     */
    void anadirProfesor();

    /**
     * Slot conectado al botón "Quitar profesor".
     * Elimina el profesor seleccionado.
     */
    void quitarProfesor();

    /**
     * Slot conectado al click sobre el GtkTreeView que muestra la lista de profesores.
     * Selecciona el profesor clickado y activa el botón de "Quitar profesor".
     */
    void seleccionarProfesor();

    /**
     * Slot conectado al doubleclick sobre el GtkTreeView que muestra la lista de profesores.
     * Lanza un diálogo para editar el profesor.
     * @param path Identificador de la fila que se ha pulsado.
     * @param col Columna que se ha pulsado.
     */
    void editarProfesor(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);

    /**
     * Slot conectado al botón "Añadir compañero".
     * Lanza el diálogo para añadir un compañero.
     */
    void anadirCompanero();

    /**
     * Slot conectado al botón "Quitar compañero".
     * Elimina el compañero seleccionado.
     */
    void quitarCompanero();

    /**
     * Slot conectado al click sobre el GtkTreeView que muestra la lista de compañeros.
     * Selecciona el compañero clickado y activa el botón de "Quitar compañero".
     */
    void seleccionarCompanero();

    /**
     * Slot conectado al doubleclick sobre el GtkTreeView que muestra la lista de compañeros.
     * Lanza un diálogo para editar el compañero.
     * @param path Identificador de la fila que se ha pulsado.
     * @param col Columna que se ha pulsado.
     */
    void editarCompanero(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);

    /**
     * Slot conectado al botón "Añadir sesión".
     * Lanza el diálogo para añadir una sesión.
     */
    void anadirSesion();

    /**
     * Slot conectado al botón "Quitar sesión".
     * Elimina la sesión seleccionada.
     */
    void quitarSesion();

    /**
     * Slot conectado al click sobre el GtkTreeView que muestra la lista de sesiones.
     * Selecciona la sesión clickado y activa el botón de "Quitar sesión".
     */
    void seleccionarSesion();

    /**
     * Slot conectado al doubleclick sobre el GtkTreeView que muestra la lista de sesiones.
     * Lanza un diálogo para editar la sesión.
     * @param path Identificador de la fila que se ha pulsado.
     * @param col Columna que se ha pulsado.
     */
    void editarSesion(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);

    /**
     * Slot conectado al botón "Añadir cita".
     * Lanza el diálogo para añadir una cita.
     */
    void anadirCita();

    /**
     * Slot conectado al botón "Quitar cita".
     * Elimina la cita seleccionada.
     */
    void quitarCita();

    /**
     * Slot conectado al click sobre el GtkTreeView que muestra la lista de citas.
     * Selecciona la cita clickado y activa el botón de "Quitar cita".
     */
    void seleccionarCita();

    /**
     * Slot conectado al doubleclick sobre el GtkTreeView que muestra la lista de citas.
     * Lanza un diálogo para editar la cita.
     * @param path Identificador de la fila que se ha pulsado.
     * @param col Columna que se ha pulsado.
     */
    void editarCita(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);

    /**
     * Slot conectado al botón "Añadir nota".
     * Lanza el diálogo para añadir una nota.
     */
    void anadirNota();

    /**
     * Slot conectado al botón "Quitar nota".
     * Elimina la nota seleccionada.
     */
    void quitarNota();

    /**
     * Slot conectado al click sobre el GtkTreeView que muestra la lista de notas.
     * Selecciona la nota clickado y activa el botón de "Quitar nota".
     */
    void seleccionarNota();

    /**
     * Slot conectado al doubleclick sobre el GtkTreeView que muestra la lista de notas.
     * Lanza un diálogo para editar la nota.
     * @param path Identificador de la fila que se ha pulsado.
     * @param col Columna que se ha pulsado.
     */
    void editarNota(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);
};

#endif /* VISTAGTKMMASIGNATURA_H */

