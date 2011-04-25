#ifndef VISTAGTKMMASIGNATURAS_H
#define VISTAGTKMMASIGNATURAS_H

#include "Vista.h"
#include <libglademm/xml.h>
#include <gtkmm.h>
#include <map>
#include "Asignatura.h"
#include "VistaGtkmmAsignatura.h"

/**
 * Vista de asignaturas que muestra una lista actualizada con las asignaturas que hay en el paquete de asignaturas.
 * Esta vista apunta a un paquete de asignaturas (Asignaturas), que es un modelo que refresca esta vista cuando se añade una asignatura (o se edita o se borra).
 */
class VistaGtkmmAsignaturas : public Vista
{
public:
    /**
     * Constructor que recibe la información necesaria para inicializar los widgets.
     * @param refXml Referencia al XML de Glade, para conectar los punteros a los widgets.
     */
    VistaGtkmmAsignaturas(Glib::RefPtr<Gnome::Glade::Xml> refXml);

    /**
     * Refresca la lista de asignaturas cuando se añade, se edita, o se quita alguna asignatura.
     * Normalmente es el modelo quien solicita el refresco.
     */
    void refrescar();

    /**
     * Vista concreta de asignatura. Cuando se selecciona una asignatura de la lista, se
     * modifica el modelo de esta otra vista.
     */
    VistaGtkmmAsignatura *vistaGtkmmAsignatura;

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

    Glib::RefPtr<Gtk::ListStore> treemodelAsignaturas;
    Gtk::TreeModel::ColumnRecord columnas;
    Gtk::TreeModelColumn<Glib::ustring> columnaNombre;
    Glib::RefPtr<Gtk::TreeSelection> treeselection;

    std::map<Asignatura*, Gtk::TreeModel::Row> vinculos;
    
    /**
     * Slot conectado al botón "Nuevo".
     * Lanza un diálogo para elegir dónde guardar el nuevo paquete de asignaturas.
     */
    void nuevo();

    /**
     * Slot conectado al botón "Abrir".
     * Lanza un diálogo para elegir qué fichero abrir.
     */
    void abrir();

    /**
     * Slot conectado al botón "Guardar".
     * Guarda el paquete de asignaturas en la última ruta conocida. Si no hay ningnua ruta, lanza el diálogo de "Guardar como".
     */
    void guardar();

    /**
     * Slot conectado al botón "Guardar como".
     * Lanza un diálogo para elegir dónde guardar.
     */
    void guardarComo();

    /**
     * Slot conectado al botón "Salir".
     * Cierra la ventana y la ejecución finaliza.
     */
    void salir();

    /**
     * Slot conectado al botón "Acerca de".
     * Lanza el diálogo de "Acerca de".
     */
    void acercaDe();

    /**
     * Slot conectado al botón "Añadir asignatura".
     * Lanza un diálogo para introducir el nombre de la nueva asignatura.
     */
    void anadirAsignatura();

    /**
     * Slot conectado al botón "Quitar asignatura".
     * Quita la asignatura seleccionada en la lista.
     */
    void quitarAsignatura();

    /**
     * Slot conectado al botón "Resumen de citas y horario".
     * Muestra el horario y el resumen de citas.
     */
    void modoResumen();

    /**
     * Slot conectado al event "click" del GtkTreeView que contiene las asignaturas.
     * Selecciona una nueva y la conecta a la vista principal.
     */
    void seleccionarAsignatura();

    /**
     * Slot conectado al event "doubleclick" del GtkTreeView que contiene las asignaturas.
     * Lanza un diálogo para editar el nombre de la asignatura.
     */
    void editarAsignatura(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *col);
};

#endif /* VISTAGTKMMASIGNATURAS_H */

