#include "VistaGtkmmAsignaturas.h"
#include "Asignaturas.h"

VistaGtkmmAsignaturas::VistaGtkmmAsignaturas(Glib::RefPtr<Gnome::Glade::Xml> refXml)
{
    refXml->get_widget("window", window);

    refXml->get_widget("imagemenuitemNuevo", imagemenuitemNuevo);
    refXml->get_widget("imagemenuitemAbrir", imagemenuitemAbrir);
    refXml->get_widget("imagemenuitemGuardar", imagemenuitemGuardar);
    refXml->get_widget("imagemenuitemGuardarComo", imagemenuitemGuardarComo);
    refXml->get_widget("imagemenuitemSalir", imagemenuitemSalir);
    refXml->get_widget("imagemenuitemAcercaDe", imagemenuitemAcercaDe);

    refXml->get_widget("toolbuttonNuevo", toolbuttonNuevo);
    refXml->get_widget("toolbuttonAbrir", toolbuttonAbrir);
    refXml->get_widget("toolbuttonGuardar", toolbuttonGuardar);
    refXml->get_widget("toolbuttonGuardarComo", toolbuttonGuardarComo);
    refXml->get_widget("toolbuttonAnadir", toolbuttonAnadir);
    refXml->get_widget("toolbuttonQuitar", toolbuttonQuitar);
    refXml->get_widget("toggletoolbuttonResumen", toggletoolbuttonResumen);

    refXml->get_widget("treeviewAsignaturas", treeviewAsignaturas);
    refXml->get_widget("vboxResumen", vboxResumen);
    refXml->get_widget("notebookDetalles", notebookDetalles);

    imagemenuitemNuevo->signal_activate().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::nuevo));
    imagemenuitemAbrir->signal_activate().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::abrir));
    imagemenuitemGuardar->signal_activate().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::guardar));
    imagemenuitemGuardarComo->signal_activate().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::guardarComo));
    imagemenuitemSalir->signal_activate().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::salir));
    imagemenuitemAcercaDe->signal_activate().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::acercaDe));

    toolbuttonNuevo->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::nuevo));
    toolbuttonAbrir->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::abrir));
    toolbuttonGuardar->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::guardar));
    toolbuttonGuardarComo->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::guardarComo));

    toolbuttonAnadir->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::anadirAsignatura));
    toolbuttonQuitar->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::quitarAsignatura));
    toggletoolbuttonResumen->signal_toggled().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::modoResumen));

    modoResumen();
}

void VistaGtkmmAsignaturas::refrescar()
{
    //TODO: pillar la tabla y meter las asignaturas (primero rapido, reventando siempre y ya esta)
    //en un futuro se hace el periplo...
    Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
    cout << "Hay " << asignaturas->obtenerAsignaturas().size() << " asignaturas" << endl;
}

void VistaGtkmmAsignaturas::nuevo()
{
    Gtk::FileChooserDialog fileChooserDialog("Creando un nuevo paquete de asignaturas", Gtk::FILE_CHOOSER_ACTION_SAVE);
    fileChooserDialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    fileChooserDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    if (fileChooserDialog.run() == Gtk::RESPONSE_OK)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        asignaturas->limpiar();
        asignaturas->guardar(fileChooserDialog.get_filename());
        asignaturas->refrescarVistas();
    }
}

void VistaGtkmmAsignaturas::abrir()
{
    Gtk::FileChooserDialog fileChooserDialog("Abriendo un paquete de asignaturas", Gtk::FILE_CHOOSER_ACTION_OPEN);
    fileChooserDialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    fileChooserDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    if (fileChooserDialog.run() == Gtk::RESPONSE_OK)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        asignaturas->cargar(fileChooserDialog.get_filename());
        asignaturas->refrescarVistas();
    }
}

void VistaGtkmmAsignaturas::guardar()
{
    Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
    if (asignaturas->getRutaFichero() != "")
            asignaturas->guardar(asignaturas->getRutaFichero());
    else
            guardarComo();
}

void VistaGtkmmAsignaturas::guardarComo()
{
    Gtk::FileChooserDialog fileChooserDialog("Guardando el paquete de asignaturas", Gtk::FILE_CHOOSER_ACTION_SAVE);
    fileChooserDialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    fileChooserDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    if (fileChooserDialog.run() == Gtk::RESPONSE_OK)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        asignaturas->guardar(fileChooserDialog.get_filename());
    }
}

void VistaGtkmmAsignaturas::salir()
{
    window->hide();
}

void VistaGtkmmAsignaturas::acercaDe()
{
    cout << "acerca de" << endl;
}

void VistaGtkmmAsignaturas::anadirAsignatura()
{
    Gtk::Entry entry;
    Gtk::Dialog dialog ("Introduce el nombre de la una asignatura");
    dialog.set_default_size(450, 100);
    Gtk::VBox *vbox = dialog.get_vbox();
    vbox->pack_start(entry, false, false, 10);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    dialog.show_all_children();
    if (dialog.run() == Gtk::RESPONSE_OK)
    {
        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        asignaturas->anadirAsignatura(new Asignatura(entry.get_text()));
        asignaturas->refrescarVistas(); //TODO: menos esta...¿?
    }
}

void VistaGtkmmAsignaturas::quitarAsignatura()
{
    cout << "quitar asignatura" << endl;
}

void VistaGtkmmAsignaturas::modoResumen()
{
    if (toggletoolbuttonResumen->get_active())
    {
        vboxResumen->set_visible(true);
        notebookDetalles->set_visible(false);
    }
    else
    {
        vboxResumen->set_visible(false);
        notebookDetalles->set_visible(true);
    }
}
