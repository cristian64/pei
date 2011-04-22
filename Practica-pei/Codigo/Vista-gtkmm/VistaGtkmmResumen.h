#ifndef VISTAGTKMMRESUMEN_H
#define	VISTAGTKMMRESUMEN_H

#include "Vista.h"
#include <libglademm/xml.h>
#include <gtkmm.h>

class VistaMini;

class VistaGtkmmResumen : public Vista
{
public:
    VistaGtkmmResumen(Glib::RefPtr<Gnome::Glade::Xml> refXml);
    ~VistaGtkmmResumen();
    void refrescar();
    void recargarCitas();
    void recargarHorario();
    
private:
    std::list<VistaMini*> vistasMini;

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

    void citasPasadas();
    void sabadoDomingo();
};

#endif	/* VISTAGTKMMRESUMEN_H */

