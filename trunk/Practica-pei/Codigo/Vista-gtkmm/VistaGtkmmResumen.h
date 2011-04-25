#ifndef VISTAGTKMMRESUMEN_H
#define VISTAGTKMMRESUMEN_H

#include "Vista.h"
#include <libglademm/xml.h>
#include <gtkmm.h>

/**
 * Vista que muestra el resumen de citas de exámenes/prácticas y el horario de la semana.
 */
class VistaGtkmmResumen : public Vista
{
public:
    /**
     * Constructor que recibe la información necesaria para inicializar los widgets.
     * @param refXml Referencia al XML de Glade, para conectar los punteros a los widgets.
     */
    VistaGtkmmResumen(Glib::RefPtr<Gnome::Glade::Xml> refXml);

    /**
     * Destructor que libera la memoria.
     */
    ~VistaGtkmmResumen();

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
    std::list<void*> vistasMini;

    Gtk::TreeModel::ColumnRecord columnas;
    Gtk::TreeModelColumn<Glib::ustring> columnaAsignatura;
    Gtk::TreeModelColumn<Glib::ustring> columnaDescripcion;
    Gtk::TreeModelColumn<Glib::ustring> columnaFecha;
    Gtk::TreeModelColumn<unsigned int> columnaDuracion;
    Gtk::TreeModelColumn<Glib::ustring> columnaLunes;
    Gtk::TreeModelColumn<Glib::ustring> columnaMartes;
    Gtk::TreeModelColumn<Glib::ustring> columnaMiercoles;
    Gtk::TreeModelColumn<Glib::ustring> columnaJueves;
    Gtk::TreeModelColumn<Glib::ustring> columnaViernes;
    Gtk::TreeModelColumn<Glib::ustring> columnaSabado;
    Gtk::TreeModelColumn<Glib::ustring> columnaDomingo;
    Gtk::TreeModelColumn<Gdk::Color> columnaLunesColor;
    Gtk::TreeModelColumn<Gdk::Color> columnaMartesColor;
    Gtk::TreeModelColumn<Gdk::Color> columnaMiercolesColor;
    Gtk::TreeModelColumn<Gdk::Color> columnaJuevesColor;
    Gtk::TreeModelColumn<Gdk::Color> columnaViernesColor;
    Gtk::TreeModelColumn<Gdk::Color> columnaSabadoColor;
    Gtk::TreeModelColumn<Gdk::Color> columnaDomingoColor;

    Gtk::CheckButton *checkbuttonCitasPasadas;
    Gtk::CheckButton *checkbuttonSabadoDomingo;
    Gtk::TreeView *treeviewResumenCitas;
    Gtk::TreeView *treeviewResumenSesiones;
    Glib::RefPtr<Gtk::ListStore> treemodelResumenCitas;
    Glib::RefPtr<Gtk::ListStore> treemodelResumenSesiones;

    /**
     * Slot conectado al checkbox para permutar entre mostrar citas pasadas o no hacerlo.
     */
    void citasPasadas();

    /**
     * Slot conectado al checkbox para permutar entre mostrar sábado y domingo y no hacerlo.
     */
    void sabadoDomingo();
};

#endif /* VISTAGTKMMRESUMEN_H */

