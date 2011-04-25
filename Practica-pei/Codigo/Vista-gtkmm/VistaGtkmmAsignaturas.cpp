#include "VistaGtkmmAsignaturas.h"
#include "Asignaturas.h"

VistaGtkmmAsignaturas::VistaGtkmmAsignaturas(Glib::RefPtr<Gnome::Glade::Xml> refXml)
{
    refXml->get_widget("window", window);
    refXml->get_widget("dialogAcerdaDe", dialogAcercaDe);
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
    treeviewAsignaturas->signal_row_activated().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::editarAsignatura));

    toolbuttonQuitar->set_sensitive(false);
    notebookDetalles->set_sensitive(false);
    vboxResumen->set_visible(false);
    notebookDetalles->set_visible(true);

    columnas.add(columnaNombre);
    treemodelAsignaturas = Gtk::ListStore::create(columnas);
    treeviewAsignaturas->set_model(treemodelAsignaturas);
    treeviewAsignaturas->append_column("Lista de asignaturas", columnaNombre);
    treeviewAsignaturas->set_reorderable(false);
    treeselection = treeviewAsignaturas->get_selection();
    treeselection->signal_changed().connect(sigc::mem_fun(*this, &VistaGtkmmAsignaturas::seleccionarAsignatura));
}

void VistaGtkmmAsignaturas::refrescar()
{
    // Se eliminan todas las asignaturas anteriores.
    Gtk::TreeModel::Children children = treemodelAsignaturas->children();
    for (Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); )
    {
        Gtk::TreeModel::Children::iterator aux = iter;
        iter++;
        treemodelAsignaturas->erase(aux);
    }
    vinculos.clear();
    
    // Se insertan las asignaturas del modelo.
    Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
    const std::list<Asignatura*> lista = asignaturas->obtenerAsignaturas();
    for (std::list<Asignatura*>::const_iterator i = lista.begin(); i != lista.end(); i++)
    {
        Gtk::TreeModel::Row row = *(treemodelAsignaturas->append());
        row[columnaNombre] = (*i)->getNombre();
        vinculos[*i] = row;
    }
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
    dialogAcercaDe->run();
    dialogAcercaDe->hide();
}

void VistaGtkmmAsignaturas::anadirAsignatura()
{
    Gtk::Entry entry;
    Gtk::Label label;
    label.set_alignment(Gtk::ALIGN_LEFT, Gtk::ALIGN_CENTER);
    label.set_text("Nombre de la asignatura:");
    Gtk::Dialog dialog ("Añadiendo asignatura");
    int width, height;
    dialog.get_default_size(width, height);
    dialog.set_default_size(400, height);
    dialog.set_border_width(5);
    Gtk::VBox *vbox = dialog.get_vbox();
    vbox->pack_start(label, true, false, 0);
    vbox->pack_start(entry, true, false, 10);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    dialog.show_all_children();
    if (dialog.run() == Gtk::RESPONSE_OK)
    {
        // La añade al modelo y refresca todas las vistas menos ésta.
        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        Asignatura *asignatura = new Asignatura(entry.get_text());
        asignaturas->anadirAsignatura(asignatura);
        asignaturas->refrescarVistas(this);

        // Añade la asignatura al treemodel.
        Gtk::TreeModel::Row row = *(treemodelAsignaturas->append());
        row[columnaNombre] = entry.get_text();
        vinculos[asignatura] = row;
    }
}

void VistaGtkmmAsignaturas::quitarAsignatura()
{
    Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);

    // Extrae las asignaturas seleccionadas (en principio, sólo será 1).
    std::list<Gtk::TreeModel::Path> paths = treeselection->get_selected_rows();

    // Convierte las rutas a RowReferences (que no se invalidan al modificarse el treemodel).
    std::list<Gtk::TreeModel::RowReference> rows;
    for (std::list<Gtk::TreeModel::Path>::iterator pathiter = paths.begin(); pathiter != paths.end(); pathiter++)
    {
        rows.push_back(Gtk::TreeModel::RowReference(treemodelAsignaturas, *pathiter));
    }

    // Elimina todas las filas del treemodel.
    for (std::list<Gtk::TreeModel::RowReference>::iterator i = rows.begin(); i != rows.end(); i++)
    {
        Gtk::TreeModel::iterator treeiter = treemodelAsignaturas->get_iter(i->get_path());

        // Desvincula la fila eliminada con la asignatura asociada y la elimina en el modelo de asignaturas.
        Gtk::TreeModel::Row row = *treeiter;
        for (std::map<Asignatura*, Gtk::TreeModel::Row>::iterator j = vinculos.begin(); j != vinculos.end(); j++)
        {
            if (j->second == row)
            {
                // Se elimina la fila del treemodel.
                treemodelAsignaturas->erase(treeiter);

                // Elimina la asignatura del modelo de asignaturas.
                asignaturas->quitarAsignatura(j->first);
                asignaturas->refrescarVistas(this);

                // Desvincula la pareja <Asignatura, Row>.
                vinculos.erase(j);
                break;
            }
        }
    }
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

void VistaGtkmmAsignaturas::seleccionarAsignatura()
{
    std::list<Gtk::TreeModel::Path> paths = treeselection->get_selected_rows();

    if (paths.size() > 0)
    {
        Gtk::TreeModel::Row row = *treemodelAsignaturas->get_iter(paths.front());
        for (std::map<Asignatura*, Gtk::TreeModel::Row>::iterator i = vinculos.begin(); i != vinculos.end(); i++)
        {
            if (i->second == row)
            {
                vistaGtkmmAsignatura->ponerModelo(i->first);
                vistaGtkmmAsignatura->refrescar();
                toolbuttonQuitar->set_sensitive(true);
                notebookDetalles->set_sensitive(true);
                toggletoolbuttonResumen->set_active(false);
                modoResumen();
                break;
            }
        }
    }
    else
    {
        toolbuttonQuitar->set_sensitive(false);
        notebookDetalles->set_sensitive(false);
    }
}

void VistaGtkmmAsignaturas::editarAsignatura(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *)
{
    Gtk::TreeModel::Row row = *treemodelAsignaturas->get_iter(path);
    for (std::map<Asignatura*, Gtk::TreeModel::Row>::iterator i = vinculos.begin(); i != vinculos.end(); i++)
    {
        if (i->second == row)
        {
            Gtk::Entry entry;
            entry.set_text(i->first->getNombre());
            Gtk::Label label;
            label.set_alignment(Gtk::ALIGN_LEFT, Gtk::ALIGN_CENTER);
            label.set_text("Nombre de la asignatura:");
            Gtk::Dialog dialog ("Editando asignatura");
            int width, height;
            dialog.get_default_size(width, height);
            dialog.set_default_size(400, height);
            dialog.set_border_width(5);
            Gtk::VBox *vbox = dialog.get_vbox();
            vbox->pack_start(label, true, false, 0);
            vbox->pack_start(entry, true, false, 10);
            dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
            dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
            dialog.show_all_children();
            if (dialog.run() == Gtk::RESPONSE_OK)
            {
                // Se modifica el modelo y refresca todas las vistas menos ésta.
                i->first->setNombre(entry.get_text());
                Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
                asignaturas->refrescarVistas(this);

                // Modifica el nombre de la fila.
                row[columnaNombre] = entry.get_text();
            }
        }
    }
}
