#include "VistaGtkmmAsignatura.h"

VistaGtkmmAsignatura::VistaGtkmmAsignatura(Glib::RefPtr<Gnome::Glade::Xml> refXml)
{
    refXml->get_widget("buttonAnadirProfesor", buttonAnadirProfesor);
    refXml->get_widget("buttonQuitarProfesor", buttonQuitarProfesor);
    refXml->get_widget("treeviewProfesores", treeviewProfesores);
    refXml->get_widget("dialogProfesor", dialogProfesor);
    refXml->get_widget("entryNombreProfesor", entryNombreProfesor);
    refXml->get_widget("entryEmailProfesor", entryEmailProfesor);

    buttonAnadirProfesor->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::anadirProfesor));
    buttonQuitarProfesor->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::quitarProfesor));
    treeviewProfesores->signal_row_activated().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::editarProfesor));

    columnas.add(columnaNombre);
    columnas.add(columnaEmail);
    treemodelProfesores = Gtk::ListStore::create(columnas);
    treeviewProfesores->set_model(treemodelProfesores);
    treeviewProfesores->append_column("Nombre", columnaNombre);
    treeviewProfesores->append_column("Correo electrónico", columnaEmail);
    treeviewProfesores->set_reorderable(false);
    treeselectionProfesores = treeviewProfesores->get_selection();
    treeselectionProfesores->signal_changed().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::seleccionarProfesor));
}

void VistaGtkmmAsignatura::refrescar()
{
    // Se eliminan todas las asignaturas anteriores.
    Gtk::TreeModel::Children children = treemodelProfesores->children();
    for (Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); )
    {
        Gtk::TreeModel::Children::iterator aux = iter;
        iter++;
        treemodelProfesores->erase(aux);
    }

    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        // Se insertan las asignaturas del modelo.
        vinculosProfesores.clear();
        const std::list<Profesor*> lista = asignatura->obtenerProfesores();
        for (std::list<Profesor*>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            Gtk::TreeModel::Row row = *(treemodelProfesores->append());
            row[columnaNombre] = (*i)->getNombre();
            row[columnaEmail] = (*i)->getEmail();
            vinculosProfesores[*i] = row;
        }
    }
}

void VistaGtkmmAsignatura::anadirProfesor()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        entryNombreProfesor->set_text("");
        entryEmailProfesor->set_text("");
        dialogProfesor->set_title("Añadiendo nuevo profesor");
        if (dialogProfesor->run() == Gtk::RESPONSE_OK)
        {
            // Se añade el profesor al modelo.
            Profesor *profesor = new Profesor(entryNombreProfesor->get_text(), entryEmailProfesor->get_text());
            asignatura->anadirProfesor(profesor);
            asignatura->refrescarVistas(this);

            // Se añade ahora a la lista.
            Gtk::TreeModel::Row row = *(treemodelProfesores->append());
            row[columnaNombre] = profesor->getNombre();
            row[columnaEmail] = profesor->getEmail();
            vinculosProfesores[profesor] = row;
        }
        dialogProfesor->hide();
    }
}

void VistaGtkmmAsignatura::quitarProfesor()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        // Extrae los elementos seleccionados (en principio, sólo será 1).
        std::list<Gtk::TreeModel::Path> paths = treeselectionProfesores->get_selected_rows();

        // Convierte las rutas a RowReferences (que no se invalidan al modificarse el treemodel).
        std::list<Gtk::TreeModel::RowReference> rows;
        for (std::list<Gtk::TreeModel::Path>::iterator pathiter = paths.begin(); pathiter != paths.end(); pathiter++)
        {
            rows.push_back(Gtk::TreeModel::RowReference(treemodelProfesores, *pathiter));
        }

        // Elimina todas las filas del treemodel.
        for (std::list<Gtk::TreeModel::RowReference>::iterator i = rows.begin(); i != rows.end(); i++)
        {
            Gtk::TreeModel::iterator treeiter = treemodelProfesores->get_iter(i->get_path());

            // Desvincula la fila eliminada con la asignatura asociada y la elimina en el modelo de asignaturas.
            Gtk::TreeModel::Row row = *treeiter;
            for (std::map<Profesor*, Gtk::TreeModel::Row>::iterator j = vinculosProfesores.begin(); j != vinculosProfesores.end(); j++)
            {
                if (j->second == row)
                {
                    // Se elimina la fila del treemodel.
                    treemodelProfesores->erase(treeiter);

                    // Elimina la asignatura del modelo de asignaturas.
                    asignatura->quitarProfesor(j->first);
                    asignatura->refrescarVistas(this);

                    // Desvincula la pareja <Asignatura, Row>.
                    vinculosProfesores.erase(j);
                    break;
                }
            }
        }
    }
}

void VistaGtkmmAsignatura::seleccionarProfesor()
{
    std::list<Gtk::TreeModel::Path> paths = treeselectionProfesores->get_selected_rows();

    if (paths.size() > 0)
    {
        Gtk::TreeModel::Row row = *treemodelProfesores->get_iter(paths.front());
        for (std::map<Profesor*, Gtk::TreeModel::Row>::iterator i = vinculosProfesores.begin(); i != vinculosProfesores.end(); i++)
        {
            if (i->second == row)
            {
                buttonQuitarProfesor->set_sensitive(true);
                break;
            }
        }
    }
    else
    {
        buttonQuitarProfesor->set_sensitive(false);
    }
}

void VistaGtkmmAsignatura::editarProfesor(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *)
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        Gtk::TreeModel::Row row = *treemodelProfesores->get_iter(path);
        for (std::map<Profesor*, Gtk::TreeModel::Row>::iterator i = vinculosProfesores.begin(); i != vinculosProfesores.end(); i++)
        {
            if (i->second == row)
            {
                Profesor *profesor = i->first;
                entryNombreProfesor->set_text(profesor->getNombre());
                entryEmailProfesor->set_text(profesor->getEmail());
                dialogProfesor->set_title("Editando profesor");
                if (dialogProfesor->run() == Gtk::RESPONSE_OK)
                {
                    // Se actualiza el elemento.
                    profesor->setNombre(entryNombreProfesor->get_text());
                    profesor->setEmail(entryEmailProfesor->get_text());
                    asignatura->refrescarVistas(this);

                    // Se actualiza ahora a la lista.
                    row[columnaNombre] = profesor->getNombre();
                    row[columnaEmail] = profesor->getEmail();
                }
                dialogProfesor->hide();
            }
        }
    }
}
