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
};

#endif	/* VISTAGTKMMASIGNATURA_H */

