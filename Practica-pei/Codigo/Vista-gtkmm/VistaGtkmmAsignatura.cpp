#include "VistaGtkmmAsignatura.h"

VistaGtkmmAsignatura::VistaGtkmmAsignatura(Glib::RefPtr<Gnome::Glade::Xml> refXml)
{
    columnas.add(columnaNombre);
    columnas.add(columnaEmail);
    columnas.add(columnaTipo);
    columnas.add(columnaLugar);
    columnas.add(columnaDia);
    columnas.add(columnaHoraInicio);
    columnas.add(columnaHoraFin);
    columnas.add(columnaDescripcion);
    columnas.add(columnaFecha);
    columnas.add(columnaDuracion);
    columnas.add(columnaNota);

    refXml->get_widget("buttonAnadirProfesor", buttonAnadirProfesor);
    refXml->get_widget("buttonQuitarProfesor", buttonQuitarProfesor);
    refXml->get_widget("treeviewProfesores", treeviewProfesores);
    refXml->get_widget("dialogProfesor", dialogProfesor);
    refXml->get_widget("entryNombreProfesor", entryNombreProfesor);
    refXml->get_widget("entryEmailProfesor", entryEmailProfesor);
    buttonAnadirProfesor->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::anadirProfesor));
    buttonQuitarProfesor->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::quitarProfesor));
    treeviewProfesores->signal_row_activated().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::editarProfesor));
    treemodelProfesores = Gtk::ListStore::create(columnas);
    treeviewProfesores->set_model(treemodelProfesores);
    treeviewProfesores->append_column("Nombre", columnaNombre);
    treeviewProfesores->append_column("Correo electrónico", columnaEmail);
    treeviewProfesores->set_reorderable(false);
    treeselectionProfesores = treeviewProfesores->get_selection();
    treeselectionProfesores->signal_changed().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::seleccionarProfesor));

    refXml->get_widget("buttonAnadirCompanero", buttonAnadirCompanero);
    refXml->get_widget("buttonQuitarCompanero", buttonQuitarCompanero);
    refXml->get_widget("treeviewCompaneros", treeviewCompaneros);
    refXml->get_widget("dialogCompanero", dialogCompanero);
    refXml->get_widget("entryNombreCompanero", entryNombreCompanero);
    refXml->get_widget("entryEmailCompanero", entryEmailCompanero);
    buttonAnadirCompanero->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::anadirCompanero));
    buttonQuitarCompanero->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::quitarCompanero));
    treeviewCompaneros->signal_row_activated().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::editarCompanero));
    treemodelCompaneros = Gtk::ListStore::create(columnas);
    treeviewCompaneros->set_model(treemodelCompaneros);
    treeviewCompaneros->append_column("Nombre", columnaNombre);
    treeviewCompaneros->append_column("Correo electrónico", columnaEmail);
    treeviewCompaneros->set_reorderable(false);
    treeselectionCompaneros = treeviewCompaneros->get_selection();
    treeselectionCompaneros->signal_changed().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::seleccionarCompanero));

    refXml->get_widget("buttonAnadirSesion", buttonAnadirSesion);
    refXml->get_widget("buttonQuitarSesion", buttonQuitarSesion);
    refXml->get_widget("treeviewSesiones", treeviewSesiones);
    refXml->get_widget("dialogSesion", dialogSesion);
    refXml->get_widget("radiobuttonTeoria", radiobuttonTeoria);
    refXml->get_widget("radiobuttonPracticas", radiobuttonPracticas);
    refXml->get_widget("entryLugar", entryLugar);
    refXml->get_widget("comboboxDia", comboboxDia);
    refXml->get_widget("spinbuttonHora", spinbuttonHora);
    refXml->get_widget("spinbuttonMinuto", spinbuttonMinuto);
    refXml->get_widget("spinbuttonSegundo", spinbuttonSegundo);
    refXml->get_widget("spinbuttonHora2", spinbuttonHora2);
    refXml->get_widget("spinbuttonMinuto2", spinbuttonMinuto2);
    refXml->get_widget("spinbuttonSegundo2", spinbuttonSegundo2);
    buttonAnadirSesion->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::anadirSesion));
    buttonQuitarSesion->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::quitarSesion));
    treeviewSesiones->signal_row_activated().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::editarSesion));
    treemodelSesiones = Gtk::ListStore::create(columnas);
    treeviewSesiones->set_model(treemodelSesiones);
    treeviewSesiones->append_column("Tipo de sesión", columnaTipo);
    treeviewSesiones->append_column("Lugar", columnaLugar);
    treeviewSesiones->append_column("Día de la semana", columnaDia);
    treeviewSesiones->append_column("Hora de incio", columnaHoraInicio);
    treeviewSesiones->append_column("Hora de fin", columnaHoraFin);
    treeviewSesiones->set_reorderable(false);
    treeselectionSesiones = treeviewSesiones->get_selection();
    treeselectionSesiones->signal_changed().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::seleccionarSesion));

    refXml->get_widget("buttonAnadirCita", buttonAnadirCita);
    refXml->get_widget("buttonQuitarCita", buttonQuitarCita);
    refXml->get_widget("treeviewCitas", treeviewCitas);
    refXml->get_widget("dialogCita", dialogCita);
    refXml->get_widget("entryDescripcion", entryDescripcion);
    refXml->get_widget("calendarCita", calendarCita);
    refXml->get_widget("spinbuttonHora3", spinbuttonHora3);
    refXml->get_widget("spinbuttonMinuto3", spinbuttonMinuto3);
    refXml->get_widget("spinbuttonSegundo3", spinbuttonSegundo3);
    refXml->get_widget("spinbuttonDuracion", spinbuttonDuracion);
    buttonAnadirCita->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::anadirCita));
    buttonQuitarCita->signal_clicked().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::quitarCita));
    treeviewCitas->signal_row_activated().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::editarCita));
    treemodelCitas = Gtk::ListStore::create(columnas);
    treeviewCitas->set_model(treemodelCitas);
    treeviewCitas->append_column("Descripción", columnaDescripcion);
    treeviewCitas->append_column("Fecha", columnaFecha);
    treeviewCitas->append_column("Duración", columnaDuracion);
    treeviewCitas->set_reorderable(false);
    treeselectionCitas = treeviewCitas->get_selection();
    treeselectionCitas->signal_changed().connect(sigc::mem_fun(*this, &VistaGtkmmAsignatura::seleccionarCita));
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
    vinculosProfesores.clear();

    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        // Se insertan las asignaturas del modelo.
        const std::list<Profesor*> lista = asignatura->obtenerProfesores();
        for (std::list<Profesor*>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            Gtk::TreeModel::Row row = *(treemodelProfesores->append());
            row[columnaNombre] = (*i)->getNombre();
            row[columnaEmail] = (*i)->getEmail();
            vinculosProfesores[*i] = row;
        }
    }

    // Se eliminan todas las asignaturas anteriores.
    children = treemodelCompaneros->children();
    for (Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); )
    {
        Gtk::TreeModel::Children::iterator aux = iter;
        iter++;
        treemodelCompaneros->erase(aux);
    }
    vinculosCompaneros.clear();

    if (asignatura != NULL)
    {
        // Se insertan las asignaturas del modelo.
        const std::list<Companero*> lista = asignatura->obtenerCompaneros();
        for (std::list<Companero*>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            Gtk::TreeModel::Row row = *(treemodelCompaneros->append());
            row[columnaNombre] = (*i)->getNombre();
            row[columnaEmail] = (*i)->getEmail();
            vinculosCompaneros[*i] = row;
        }
    }

    // Se eliminan todas las asignaturas anteriores.
    children = treemodelSesiones->children();
    for (Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); )
    {
        Gtk::TreeModel::Children::iterator aux = iter;
        iter++;
        treemodelSesiones->erase(aux);
    }
    vinculosSesiones.clear();

    if (asignatura != NULL)
    {
        // Se insertan las asignaturas del modelo.
        const std::list<Sesion*> lista = asignatura->obtenerSesiones();
        for (std::list<Sesion*>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            Gtk::TreeModel::Row row = *(treemodelSesiones->append());
            row[columnaTipo] = (*i)->getTipoString();
            row[columnaLugar] = (*i)->getLugar();
            row[columnaDia] = (*i)->getDiaString();
            row[columnaHoraInicio] = (*i)->getFechaInicio().toStringHora();
            row[columnaHoraFin] = (*i)->getFechaFin().toStringHora();
            vinculosSesiones[*i] = row;
        }
    }

    // Se eliminan todas las asignaturas anteriores.
    children = treemodelCitas->children();
    for (Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); )
    {
        Gtk::TreeModel::Children::iterator aux = iter;
        iter++;
        treemodelCitas->erase(aux);
    }
    vinculosCitas.clear();

    if (asignatura != NULL)
    {
        // Se insertan las asignaturas del modelo.
        const std::list<Cita*> lista = asignatura->obtenerCitas();
        for (std::list<Cita*>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            Gtk::TreeModel::Row row = *(treemodelCitas->append());
            row[columnaDescripcion] = (*i)->getDescripcion();
            row[columnaFecha] = (*i)->getFecha().toString();
            row[columnaDuracion] = (*i)->getDuracion();
            vinculosCitas[*i] = row;
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

void VistaGtkmmAsignatura::anadirCompanero()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        entryNombreCompanero->set_text("");
        entryEmailCompanero->set_text("");
        dialogCompanero->set_title("Añadiendo nuevo compañero");
        if (dialogCompanero->run() == Gtk::RESPONSE_OK)
        {
            // Se añade el companero al modelo.
            Companero *companero = new Companero(entryNombreCompanero->get_text(), entryEmailCompanero->get_text());
            asignatura->anadirCompanero(companero);
            asignatura->refrescarVistas(this);

            // Se añade ahora a la lista.
            Gtk::TreeModel::Row row = *(treemodelCompaneros->append());
            row[columnaNombre] = companero->getNombre();
            row[columnaEmail] = companero->getEmail();
            vinculosCompaneros[companero] = row;
        }
        dialogCompanero->hide();
    }
}

void VistaGtkmmAsignatura::quitarCompanero()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        // Extrae los elementos seleccionados (en principio, sólo será 1).
        std::list<Gtk::TreeModel::Path> paths = treeselectionCompaneros->get_selected_rows();

        // Convierte las rutas a RowReferences (que no se invalidan al modificarse el treemodel).
        std::list<Gtk::TreeModel::RowReference> rows;
        for (std::list<Gtk::TreeModel::Path>::iterator pathiter = paths.begin(); pathiter != paths.end(); pathiter++)
        {
            rows.push_back(Gtk::TreeModel::RowReference(treemodelCompaneros, *pathiter));
        }

        // Elimina todas las filas del treemodel.
        for (std::list<Gtk::TreeModel::RowReference>::iterator i = rows.begin(); i != rows.end(); i++)
        {
            Gtk::TreeModel::iterator treeiter = treemodelCompaneros->get_iter(i->get_path());

            // Desvincula la fila eliminada con la asignatura asociada y la elimina en el modelo de asignaturas.
            Gtk::TreeModel::Row row = *treeiter;
            for (std::map<Companero*, Gtk::TreeModel::Row>::iterator j = vinculosCompaneros.begin(); j != vinculosCompaneros.end(); j++)
            {
                if (j->second == row)
                {
                    // Se elimina la fila del treemodel.
                    treemodelCompaneros->erase(treeiter);

                    // Elimina la asignatura del modelo de asignaturas.
                    asignatura->quitarCompanero(j->first);
                    asignatura->refrescarVistas(this);

                    // Desvincula la pareja <Asignatura, Row>.
                    vinculosCompaneros.erase(j);
                    break;
                }
            }
        }
    }
}

void VistaGtkmmAsignatura::seleccionarCompanero()
{
    std::list<Gtk::TreeModel::Path> paths = treeselectionCompaneros->get_selected_rows();

    if (paths.size() > 0)
    {
        Gtk::TreeModel::Row row = *treemodelCompaneros->get_iter(paths.front());
        for (std::map<Companero*, Gtk::TreeModel::Row>::iterator i = vinculosCompaneros.begin(); i != vinculosCompaneros.end(); i++)
        {
            if (i->second == row)
            {
                buttonQuitarCompanero->set_sensitive(true);
                break;
            }
        }
    }
    else
    {
        buttonQuitarCompanero->set_sensitive(false);
    }
}

void VistaGtkmmAsignatura::editarCompanero(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *)
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        Gtk::TreeModel::Row row = *treemodelCompaneros->get_iter(path);
        for (std::map<Companero*, Gtk::TreeModel::Row>::iterator i = vinculosCompaneros.begin(); i != vinculosCompaneros.end(); i++)
        {
            if (i->second == row)
            {
                Companero *companero = i->first;
                entryNombreCompanero->set_text(companero->getNombre());
                entryEmailCompanero->set_text(companero->getEmail());
                dialogCompanero->set_title("Editando compañero");
                if (dialogCompanero->run() == Gtk::RESPONSE_OK)
                {
                    // Se actualiza el elemento.
                    companero->setNombre(entryNombreCompanero->get_text());
                    companero->setEmail(entryEmailCompanero->get_text());
                    asignatura->refrescarVistas(this);

                    // Se actualiza ahora a la lista.
                    row[columnaNombre] = companero->getNombre();
                    row[columnaEmail] = companero->getEmail();
                }
                dialogCompanero->hide();
            }
        }
    }
}

void VistaGtkmmAsignatura::anadirSesion()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        radiobuttonTeoria->set_active(true);
        radiobuttonPracticas->set_active(false);
        entryLugar->set_text("");
        comboboxDia->set_active(0);
        spinbuttonHora->set_value(0);
        spinbuttonMinuto->set_value(0);
        spinbuttonSegundo->set_value(0);
        spinbuttonHora2->set_value(0);
        spinbuttonMinuto2->set_value(0);
        spinbuttonSegundo2->set_value(0);
        dialogSesion->set_title("Añadiendo nueva sesión");
        if (dialogSesion->run() == Gtk::RESPONSE_OK)
        {
            // Se añade el sesion al modelo.
            Sesion *sesion = new Sesion();
            sesion->setTipo(radiobuttonTeoria->get_active() ? Sesion::TEORIA : Sesion::PRACTICAS);
            sesion->setLugar(entryLugar->get_text());
            sesion->setDia((Sesion::Dia) comboboxDia->get_active_row_number());
            sesion->setFechaInicio(Fecha(spinbuttonHora->get_value(), spinbuttonMinuto->get_value(), spinbuttonSegundo->get_value()));
            sesion->setFechaFin(Fecha(spinbuttonHora2->get_value(), spinbuttonMinuto2->get_value(), spinbuttonSegundo2->get_value()));
            asignatura->anadirSesion(sesion);
            asignatura->refrescarVistas(this);

            // Se añade ahora a la lista.
            Gtk::TreeModel::Row row = *(treemodelSesiones->append());
            row[columnaTipo] = sesion->getTipoString();
            row[columnaLugar] = sesion->getLugar();
            row[columnaDia] = sesion->getDiaString();
            row[columnaHoraInicio] = sesion->getFechaInicio().toStringHora();
            row[columnaHoraFin] = sesion->getFechaFin().toStringHora();
            vinculosSesiones[sesion] = row;
        }
        dialogSesion->hide();
    }
}

void VistaGtkmmAsignatura::quitarSesion()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        // Extrae los elementos seleccionados (en principio, sólo será 1).
        std::list<Gtk::TreeModel::Path> paths = treeselectionSesiones->get_selected_rows();

        // Convierte las rutas a RowReferences (que no se invalidan al modificarse el treemodel).
        std::list<Gtk::TreeModel::RowReference> rows;
        for (std::list<Gtk::TreeModel::Path>::iterator pathiter = paths.begin(); pathiter != paths.end(); pathiter++)
        {
            rows.push_back(Gtk::TreeModel::RowReference(treemodelSesiones, *pathiter));
        }

        // Elimina todas las filas del treemodel.
        for (std::list<Gtk::TreeModel::RowReference>::iterator i = rows.begin(); i != rows.end(); i++)
        {
            Gtk::TreeModel::iterator treeiter = treemodelSesiones->get_iter(i->get_path());

            // Desvincula la fila eliminada con la asignatura asociada y la elimina en el modelo de asignaturas.
            Gtk::TreeModel::Row row = *treeiter;
            for (std::map<Sesion*, Gtk::TreeModel::Row>::iterator j = vinculosSesiones.begin(); j != vinculosSesiones.end(); j++)
            {
                if (j->second == row)
                {
                    // Se elimina la fila del treemodel.
                    treemodelSesiones->erase(treeiter);

                    // Elimina la asignatura del modelo de asignaturas.
                    asignatura->quitarSesion(j->first);
                    asignatura->refrescarVistas(this);

                    // Desvincula la pareja <Asignatura, Row>.
                    vinculosSesiones.erase(j);
                    break;
                }
            }
        }
    }
}

void VistaGtkmmAsignatura::seleccionarSesion()
{
    std::list<Gtk::TreeModel::Path> paths = treeselectionSesiones->get_selected_rows();

    if (paths.size() > 0)
    {
        Gtk::TreeModel::Row row = *treemodelSesiones->get_iter(paths.front());
        for (std::map<Sesion*, Gtk::TreeModel::Row>::iterator i = vinculosSesiones.begin(); i != vinculosSesiones.end(); i++)
        {
            if (i->second == row)
            {
                buttonQuitarSesion->set_sensitive(true);
                break;
            }
        }
    }
    else
    {
        buttonQuitarSesion->set_sensitive(false);
    }
}

void VistaGtkmmAsignatura::editarSesion(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *)
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        Gtk::TreeModel::Row row = *treemodelSesiones->get_iter(path);
        for (std::map<Sesion*, Gtk::TreeModel::Row>::iterator i = vinculosSesiones.begin(); i != vinculosSesiones.end(); i++)
        {
            if (i->second == row)
            {
                Sesion *sesion = i->first;
                radiobuttonTeoria->set_active(sesion->getTipo() == Sesion::TEORIA);
                radiobuttonPracticas->set_active(sesion->getTipo() != Sesion::TEORIA);
                entryLugar->set_text(sesion->getLugar());
                comboboxDia->set_active(sesion->getDia());
                spinbuttonHora->set_value(sesion->getFechaInicio().hora);
                spinbuttonMinuto->set_value(sesion->getFechaInicio().minuto);
                spinbuttonSegundo->set_value(sesion->getFechaInicio().segundo);
                spinbuttonHora2->set_value(sesion->getFechaFin().hora);
                spinbuttonMinuto2->set_value(sesion->getFechaFin().minuto);
                spinbuttonSegundo2->set_value(sesion->getFechaFin().segundo);
                dialogSesion->set_title("Editando sesión");
                if (dialogSesion->run() == Gtk::RESPONSE_OK)
                {
                    // Se actualiza el elemento.
                    sesion->setTipo(radiobuttonTeoria->get_active() ? Sesion::TEORIA : Sesion::PRACTICAS);
                    sesion->setLugar(entryLugar->get_text());
                    sesion->setDia((Sesion::Dia) comboboxDia->get_active_row_number());
                    sesion->setFechaInicio(Fecha(spinbuttonHora->get_value(), spinbuttonMinuto->get_value(), spinbuttonSegundo->get_value()));
                    sesion->setFechaFin(Fecha(spinbuttonHora2->get_value(), spinbuttonMinuto2->get_value(), spinbuttonSegundo2->get_value()));
                    asignatura->refrescarVistas(this);

                    // Se actualiza ahora a la lista.
                    row[columnaTipo] = sesion->getTipoString();
                    row[columnaLugar] = sesion->getLugar();
                    row[columnaDia] = sesion->getDiaString();
                    row[columnaHoraInicio] = sesion->getFechaInicio().toStringHora();
                    row[columnaHoraFin] = sesion->getFechaFin().toStringHora();
                }
                dialogSesion->hide();
            }
        }
    }
}

void VistaGtkmmAsignatura::anadirCita()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        entryDescripcion->set_text("");
        Glib::Date date;
        Gtk::Calendar calendarAux;
        calendarAux.get_date(date);
        calendarCita->select_day(date.get_day());
        calendarCita->select_month(date.get_month() - 1, date.get_year());
        spinbuttonHora3->set_value(0);
        spinbuttonMinuto3->set_value(0);
        spinbuttonSegundo3->set_value(0);
        spinbuttonDuracion->set_value(30);
        dialogCita->set_title("Añadiendo nueva cita");
        if (dialogCita->run() == Gtk::RESPONSE_OK)
        {
            // Se añade el cita al modelo.
            Cita *cita = new Cita();
            cita->setDescripcion(entryDescripcion->get_text());
            guint ano, mes, dia;
            calendarCita->get_date(ano, mes, dia);
            cita->setFecha(Fecha(ano, mes + 1, dia, spinbuttonHora3->get_value(), spinbuttonMinuto3->get_value(), spinbuttonSegundo3->get_value()));
            cita->setDuracion(spinbuttonDuracion->get_value());
            asignatura->anadirCita(cita);
            asignatura->refrescarVistas(this);

            // Se añade ahora a la lista.
            Gtk::TreeModel::Row row = *(treemodelCitas->append());
            row[columnaDescripcion] = cita->getDescripcion();
            row[columnaFecha] = cita->getFecha().toString();
            row[columnaDuracion] = cita->getDuracion();
            vinculosCitas[cita] = row;
        }
        dialogCita->hide();
    }
}

void VistaGtkmmAsignatura::quitarCita()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        // Extrae los elementos seleccionados (en principio, sólo será 1).
        std::list<Gtk::TreeModel::Path> paths = treeselectionCitas->get_selected_rows();

        // Convierte las rutas a RowReferences (que no se invalidan al modificarse el treemodel).
        std::list<Gtk::TreeModel::RowReference> rows;
        for (std::list<Gtk::TreeModel::Path>::iterator pathiter = paths.begin(); pathiter != paths.end(); pathiter++)
        {
            rows.push_back(Gtk::TreeModel::RowReference(treemodelCitas, *pathiter));
        }

        // Elimina todas las filas del treemodel.
        for (std::list<Gtk::TreeModel::RowReference>::iterator i = rows.begin(); i != rows.end(); i++)
        {
            Gtk::TreeModel::iterator treeiter = treemodelCitas->get_iter(i->get_path());

            // Desvincula la fila eliminada con la asignatura asociada y la elimina en el modelo de asignaturas.
            Gtk::TreeModel::Row row = *treeiter;
            for (std::map<Cita*, Gtk::TreeModel::Row>::iterator j = vinculosCitas.begin(); j != vinculosCitas.end(); j++)
            {
                if (j->second == row)
                {
                    // Se elimina la fila del treemodel.
                    treemodelCitas->erase(treeiter);

                    // Elimina la asignatura del modelo de asignaturas.
                    asignatura->quitarCita(j->first);
                    asignatura->refrescarVistas(this);

                    // Desvincula la pareja <Asignatura, Row>.
                    vinculosCitas.erase(j);
                    break;
                }
            }
        }
    }
}

void VistaGtkmmAsignatura::seleccionarCita()
{
    std::list<Gtk::TreeModel::Path> paths = treeselectionCitas->get_selected_rows();

    if (paths.size() > 0)
    {
        Gtk::TreeModel::Row row = *treemodelCitas->get_iter(paths.front());
        for (std::map<Cita*, Gtk::TreeModel::Row>::iterator i = vinculosCitas.begin(); i != vinculosCitas.end(); i++)
        {
            if (i->second == row)
            {
                buttonQuitarCita->set_sensitive(true);
                break;
            }
        }
    }
    else
    {
        buttonQuitarCita->set_sensitive(false);
    }
}

void VistaGtkmmAsignatura::editarCita(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *)
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        Gtk::TreeModel::Row row = *treemodelCitas->get_iter(path);
        for (std::map<Cita*, Gtk::TreeModel::Row>::iterator i = vinculosCitas.begin(); i != vinculosCitas.end(); i++)
        {
            if (i->second == row)
            {
                Cita *cita = i->first;
                entryDescripcion->set_text(cita->getDescripcion());
                calendarCita->select_day(cita->getFecha().dia);
                calendarCita->select_month(cita->getFecha().mes - 1, cita->getFecha().ano);
                spinbuttonHora3->set_value(cita->getFecha().hora);
                spinbuttonMinuto3->set_value(cita->getFecha().minuto);
                spinbuttonSegundo3->set_value(cita->getFecha().segundo);
                spinbuttonDuracion->set_value(cita->getDuracion());
                dialogCita->set_title("Editando cita");
                if (dialogCita->run() == Gtk::RESPONSE_OK)
                {
                    // Se actualiza el elemento.
                    cita->setDescripcion(entryDescripcion->get_text());
                    guint ano, mes, dia;
                    calendarCita->get_date(ano, mes, dia);
                    cita->setFecha(Fecha(ano, mes + 1, dia, spinbuttonHora3->get_value(), spinbuttonMinuto3->get_value(), spinbuttonSegundo3->get_value()));
                    cita->setDuracion(spinbuttonDuracion->get_value());
                    asignatura->refrescarVistas(this);

                    // Se actualiza ahora a la lista.
                    row[columnaDescripcion] = cita->getDescripcion();
                    row[columnaFecha] = cita->getFecha().toString();
                    row[columnaDuracion] = cita->getDuracion();
                }
                dialogCita->hide();
            }
        }
    }
}
