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
        refXml = Gnome::Glade::Xml::create("interfaces.glade");

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

