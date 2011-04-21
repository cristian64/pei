#ifndef VISTAGTKMMASIGNATURAS_H
#define	VISTAGTKMMASIGNATURAS_H

#include "Vista.h"
#include <libglademm/xml.h>
#include <gtkmm.h>
#include <gdkmm.h>

class VistaGtkmmAsignaturas : public Vista
{
public:
    VistaGtkmmAsignaturas(Glib::RefPtr<Gnome::Glade::Xml> refXml);
    void refrescar();

private:
    Gtk::Window *window;

    Gtk::ImageMenuItem *imagemenuitemNuevo;
    Gtk::ImageMenuItem *imagemenuitemAbrir;
    Gtk::ImageMenuItem *imagemenuitemGuardar;
    Gtk::ImageMenuItem *imagemenuitemGuardarComo;
    Gtk::ImageMenuItem *imagemenuitemSalir;
    Gtk::ImageMenuItem *imagemenuitemAcercaDe;

    Gtk::ToolButton *toolbuttonNuevo;
    Gtk::ToolButton *toolbuttonAbrir;
    Gtk::ToolButton *toolbuttonGuardar;
    Gtk::ToolButton *toolbuttonGuardarComo;
    Gtk::ToolButton *toolbuttonAnadir;
    Gtk::ToolButton *toolbuttonQuitar;
    Gtk::ToggleToolButton *toggletoolbuttonResumen;

    Gtk::TreeView *treeviewAsignaturas;
    Gtk::VBox *vboxResumen;
    Gtk::Notebook *notebookDetalles;

    void nuevo();
    void abrir();
    void guardar();
    void guardarComo();
    void salir();
    void acercaDe();

    void anadirAsignatura();
    void quitarAsignatura();
    void modoResumen();
};

#endif	/* VISTAGTKMMASIGNATURAS_H */

