#ifndef VISTAGTKMMASIGNATURA_H
#define	VISTAGTKMMASIGNATURA_H

#include "Vista.h"
#include "Asignatura.h"
#include <libglademm/xml.h>
#include <gtkmm.h>

class VistaGtkmmAsignatura : public Vista
{
public:
    VistaGtkmmAsignatura(Glib::RefPtr<Gnome::Glade::Xml> refXml);
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

    Gtk::Button *buttonAnadirProfesor;
    Gtk::Button *buttonQuitarProfesor;
    Gtk::TreeView *treeviewProfesores;
    Glib::RefPtr<Gtk::ListStore> treemodelProfesores;
    Glib::RefPtr<Gtk::TreeSelection> treeselectionProfesores;
    Gtk::Dialog *dialogProfesor;
    Gtk::Entry *entryNombreProfesor;
    Gtk::Entry *entryEmailProfesor;
    void anadirProfesor();
    void quitarProfesor();
    void seleccionarProfesor();
    void editarProfesor(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);
    std::map<Profesor*, Gtk::TreeModel::Row> vinculosProfesores;

    Gtk::Button *buttonAnadirCompanero;
    Gtk::Button *buttonQuitarCompanero;
    Gtk::TreeView *treeviewCompaneros;
    Glib::RefPtr<Gtk::ListStore> treemodelCompaneros;
    Glib::RefPtr<Gtk::TreeSelection> treeselectionCompaneros;
    Gtk::Dialog *dialogCompanero;
    Gtk::Entry *entryNombreCompanero;
    Gtk::Entry *entryEmailCompanero;
    void anadirCompanero();
    void quitarCompanero();
    void seleccionarCompanero();
    void editarCompanero(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);
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
    void anadirSesion();
    void quitarSesion();
    void seleccionarSesion();
    void editarSesion(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);
    std::map<Sesion*, Gtk::TreeModel::Row> vinculosSesiones;
};

#endif	/* VISTAGTKMMASIGNATURA_H */

