#include <iostream>
using namespace std;

#include <libglademm/xml.h>
#include <gtkmm.h>

int main (int argc, char **argv)
{
    Gtk::Main app (argc, argv);
    Glib::RefPtr<Gnome::Glade::Xml> refXml;
    Gtk::Window* ventana = NULL;

    try
    {
        // Extrae la interfaz desde el fichero "interfaces.glade.h", que contiene el fichero .glade entrecomillado y asignado a interfacesGlade.
        // De esta forma, se añade la interfaz al binario y no es necesario el fichero .glade junto al binario.
        std::string interfacesGlade = "";
        #include "interfaces.glade.h"

        // Carga la interfaz y crea la ventana principal.
        refXml = Gnome::Glade::Xml::create_from_buffer(interfacesGlade.c_str(), interfacesGlade.length());
		//refXml = Gnome::Glade::Xml::create("Vista-gtkmm/interfaces.glade");

        refXml->get_widget("MainWindow", ventana);
        if (ventana)
        {
            app.run(*ventana);
            delete ventana;
        }
    }
    catch (const Gnome::Glade::XmlError& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

