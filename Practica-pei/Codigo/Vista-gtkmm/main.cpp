#include <iostream>
using namespace std;

#include <libglademm/xml.h>
#include <gtkmm.h>
#include "Asignaturas.h"
#include "VistaGtkmmAsignaturas.h"
#include "VistaGtkmmAsignatura.h"
#include "VistaGtkmmResumen.h"

int main (int argc, char **argv)
{
    Gtk::Main app(argc, argv);
    Gtk::Window *ventana = NULL;

    Glib::RefPtr<Gnome::Glade::Xml> refXml;
    refXml = Gnome::Glade::Xml::create("Vista-gtkmm/interfaces.glade");
    refXml->get_widget("window", ventana);

    // Se crea el modelo con todas las asignaturas.
    Asignaturas asignaturas;
    asignaturas.cargar("ejemplo1.xml");

    // Vista para una asignatura concreta.
    VistaGtkmmAsignatura vistaGtkmmAsignatura(refXml);
    vistaGtkmmAsignatura.refrescar();

    // Vista para la lista de asignaturas.
    VistaGtkmmAsignaturas vistaGtkmmAsignaturas(refXml);
    vistaGtkmmAsignaturas.vistaGtkmmAsignatura = &vistaGtkmmAsignatura;
    vistaGtkmmAsignaturas.ponerModelo(&asignaturas);
    vistaGtkmmAsignaturas.refrescar();

    // Otra vista para la lista de asignaturas (para mostrar el resumen).
    VistaGtkmmResumen vistaGtkmmResumen(refXml);
    vistaGtkmmResumen.ponerModelo(&asignaturas);
    vistaGtkmmResumen.refrescar();

    Gtk::Main::run(*ventana);
    delete ventana;

    return 0;
}

