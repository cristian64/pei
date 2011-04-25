#include "VistaGtkmmResumen.h"
#include "Asignaturas.h"

class VistaMini : public Vista
{
public:
    VistaGtkmmResumen *padre;
    void refrescar()
    {
        padre->recargarCitas();
        padre->recargarHorario();
    }
};

VistaGtkmmResumen::VistaGtkmmResumen(Glib::RefPtr<Gnome::Glade::Xml> refXml)
{
    columnas.add(columnaAsignatura);
    columnas.add(columnaDescripcion);
    columnas.add(columnaFecha);
    columnas.add(columnaDuracion);
    columnas.add(columnaLunes);
    columnas.add(columnaLunesColor);
    columnas.add(columnaMartes);
    columnas.add(columnaMartesColor);
    columnas.add(columnaMiercoles);
    columnas.add(columnaMiercolesColor);
    columnas.add(columnaJueves);
    columnas.add(columnaJuevesColor);
    columnas.add(columnaViernes);
    columnas.add(columnaViernesColor);
    columnas.add(columnaSabado);
    columnas.add(columnaSabadoColor);
    columnas.add(columnaDomingo);
    columnas.add(columnaDomingoColor);
    
    refXml->get_widget("checkbuttonCitasPasadas", checkbuttonCitasPasadas);
    refXml->get_widget("checkbuttonSabadoDomingo", checkbuttonSabadoDomingo);    
    refXml->get_widget("treeviewResumenCitas", treeviewResumenCitas);
    refXml->get_widget("treeviewResumenSesiones", treeviewResumenSesiones);
    checkbuttonCitasPasadas->signal_toggled().connect(sigc::mem_fun(*this, &VistaGtkmmResumen::citasPasadas));
    checkbuttonSabadoDomingo->signal_toggled().connect(sigc::mem_fun(*this, &VistaGtkmmResumen::sabadoDomingo));

    treemodelResumenCitas = Gtk::ListStore::create(columnas);
    treeviewResumenCitas->set_model(treemodelResumenCitas);
    treeviewResumenCitas->append_column("Asignatura", columnaAsignatura);
    treeviewResumenCitas->append_column("Descripción", columnaDescripcion);
    treeviewResumenCitas->append_column("Fecha", columnaFecha);
    treeviewResumenCitas->append_column("Duración (minutos)", columnaDuracion);
    treeviewResumenCitas->set_reorderable(false);
    treeviewResumenCitas->get_column(0)->set_expand(true);
    treeviewResumenCitas->get_column(1)->set_expand(true);
    treeviewResumenCitas->get_column(2)->set_expand(true);
    treeviewResumenCitas->get_column(3)->set_expand(true);

    treemodelResumenSesiones = Gtk::ListStore::create(columnas);
    treeviewResumenSesiones->set_model(treemodelResumenSesiones);
    treeviewResumenSesiones->set_reorderable(false);

    Gtk::CellRendererText* pRenderer = Gtk::manage(new Gtk::CellRendererText());
    treeviewResumenSesiones->append_column("Lunes", *pRenderer);
    Gtk::TreeViewColumn* pColumn = treeviewResumenSesiones->get_column(0);
    pColumn->add_attribute(pRenderer->property_text(), columnaLunes);
    pColumn->add_attribute(pRenderer->property_background_gdk(), columnaLunesColor);
    pRenderer->property_wrap_mode() = Pango::WRAP_WORD;
    pRenderer->property_alignment() = Pango::ALIGN_CENTER;
    pRenderer->set_alignment(0.5, 0.5);
    pRenderer->set_padding(10, 10);
    pRenderer->property_font() = "Normal 7";

    pRenderer = Gtk::manage(new Gtk::CellRendererText());
    treeviewResumenSesiones->append_column("Martes", *pRenderer);
    pColumn = treeviewResumenSesiones->get_column(1);
    pColumn->add_attribute(pRenderer->property_text(), columnaMartes);
    pColumn->add_attribute(pRenderer->property_background_gdk(), columnaMartesColor);
    pRenderer->property_wrap_mode() = Pango::WRAP_WORD;
    pRenderer->property_alignment() = Pango::ALIGN_CENTER;
    pRenderer->set_alignment(0.5, 0.5);
    pRenderer->set_padding(10, 10);
    pRenderer->property_font() = "Normal 7";

    pRenderer = Gtk::manage(new Gtk::CellRendererText());
    treeviewResumenSesiones->append_column("Miércoles", *pRenderer);
    pColumn = treeviewResumenSesiones->get_column(2);
    pColumn->add_attribute(pRenderer->property_text(), columnaMiercoles);
    pColumn->add_attribute(pRenderer->property_background_gdk(), columnaMiercolesColor);
    pRenderer->property_wrap_mode() = Pango::WRAP_WORD;
    pRenderer->property_alignment() = Pango::ALIGN_CENTER;
    pRenderer->set_alignment(0.5, 0.5);
    pRenderer->set_padding(10, 10);
    pRenderer->property_font() = "Normal 7";

    pRenderer = Gtk::manage(new Gtk::CellRendererText());
    treeviewResumenSesiones->append_column("Jueves", *pRenderer);
    pColumn = treeviewResumenSesiones->get_column(3);
    pColumn->add_attribute(pRenderer->property_text(), columnaJueves);
    pColumn->add_attribute(pRenderer->property_background_gdk(), columnaJuevesColor);
    pRenderer->property_wrap_mode() = Pango::WRAP_WORD;
    pRenderer->property_alignment() = Pango::ALIGN_CENTER;
    pRenderer->set_alignment(0.5, 0.5);
    pRenderer->set_padding(10, 10);
    pRenderer->property_font() = "Normal 7";

    pRenderer = Gtk::manage(new Gtk::CellRendererText());
    treeviewResumenSesiones->append_column("Viernes", *pRenderer);
    pColumn = treeviewResumenSesiones->get_column(4);
    pColumn->add_attribute(pRenderer->property_text(), columnaViernes);
    pColumn->add_attribute(pRenderer->property_background_gdk(), columnaViernesColor);
    pRenderer->property_wrap_mode() = Pango::WRAP_WORD;
    pRenderer->property_alignment() = Pango::ALIGN_CENTER;
    pRenderer->set_alignment(0.5, 0.5);
    pRenderer->set_padding(10, 10);
    pRenderer->property_font() = "Normal 7";

    pRenderer = Gtk::manage(new Gtk::CellRendererText());
    treeviewResumenSesiones->append_column("Sábado", *pRenderer);
    pColumn = treeviewResumenSesiones->get_column(5);
    pColumn->add_attribute(pRenderer->property_text(), columnaSabado);
    pColumn->add_attribute(pRenderer->property_background_gdk(), columnaSabadoColor);
    pRenderer->property_wrap_mode() = Pango::WRAP_WORD;
    pRenderer->property_alignment() = Pango::ALIGN_CENTER;
    pRenderer->set_alignment(0.5, 0.5);
    pRenderer->set_padding(8, 5);
    pRenderer->property_font() = "Normal 7";

    pRenderer = Gtk::manage(new Gtk::CellRendererText());
    treeviewResumenSesiones->append_column("Domingo", *pRenderer);
    pColumn = treeviewResumenSesiones->get_column(6);
    pColumn->add_attribute(pRenderer->property_text(), columnaDomingo);
    pColumn->add_attribute(pRenderer->property_background_gdk(), columnaDomingoColor);
    pRenderer->property_wrap_mode() = Pango::WRAP_WORD;
    pRenderer->property_alignment() = Pango::ALIGN_CENTER;
    pRenderer->set_alignment(0.5, 0.5);
    pRenderer->set_padding(10, 10);
    pRenderer->property_font() = "Normal 7";
    
    treeviewResumenSesiones->get_column(0)->set_expand(true);
    treeviewResumenSesiones->get_column(1)->set_expand(true);
    treeviewResumenSesiones->get_column(2)->set_expand(true);
    treeviewResumenSesiones->get_column(3)->set_expand(true);
    treeviewResumenSesiones->get_column(4)->set_expand(true);
    treeviewResumenSesiones->get_column(5)->set_expand(true);
    treeviewResumenSesiones->get_column(6)->set_expand(true);
    treeviewResumenSesiones->get_column(5)->set_visible(false);
    treeviewResumenSesiones->get_column(6)->set_visible(false);
}

VistaGtkmmResumen::~VistaGtkmmResumen()
{
    std::list<VistaMini*>::iterator i = vistasMini.begin();
    for (; i != vistasMini.end(); i++)
        delete *i;
    vistasMini.clear();
}

void VistaGtkmmResumen::refrescar()
{
    // Se crea una vista por cada asignatura para que cuando se modifique una asignatura, también se refresque el horario y la lista de citas.
    std::list<VistaMini*>::iterator i = vistasMini.begin();
    for (; i != vistasMini.end(); i++)
        delete *i;
    vistasMini.clear();

    Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
    if (asignaturas != NULL)
    {
        // Se recorren todas las citas.
        const std::list<Asignatura*> lista = asignaturas->obtenerAsignaturas();
        for (std::list<Asignatura*>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            VistaMini *vistaMini = new VistaMini();
            vistaMini->padre = this;
            vistaMini->ponerModelo(*i);
            vistasMini.push_back(vistaMini);
        }
    }

    recargarCitas();
    recargarHorario();
}

// Estructura auxiliar para guardar en la lista las citas pendientes.
typedef struct
{
    std::string asignatura;
    std::string descripcion;
    Fecha fecha;
    int duracion;
} Fila;

// Función auxiliar para reordenar.
bool comparadorFilas(Fila *fila1, Fila *fila2)
{
    return fila1->fecha < fila2->fecha;
}

void VistaGtkmmResumen::recargarCitas()
{    
    // Elimina todas las anteriores.
    Gtk::TreeModel::Children children = treemodelResumenCitas->children();
    for (Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); )
    {
        Gtk::TreeModel::Children::iterator aux = iter;
        iter++;
        treemodelResumenCitas->erase(aux);
    }

    std::list<Fila*> filas;

    // Se recorren todas las citas.
    const std::list<Asignatura*> lista = static_cast<Asignaturas*>(modelo)->obtenerAsignaturas();
    for (std::list<Asignatura*>::const_iterator i = lista.begin(); i != lista.end(); i++)
    {
        // Se añaden las citas de la asignatura.
        const std::list<Cita*> citas = (*i)->obtenerCitas();
        std::list<Cita*>::const_iterator cita = citas.begin();
        for (; cita != citas.end(); cita++)
        {
            // Sólo se muestran las citas futuras (salvo que se haya marcado la casilla).
            if (checkbuttonCitasPasadas->get_active() || Fecha::actual() < (*cita)->getFecha())
            {
                Fila *fila = new Fila();
                fila->asignatura = (*i)->getNombre();
                fila->descripcion = (*cita)->getDescripcion();
                fila->fecha = (*cita)->getFecha();
                fila->duracion = (*cita)->getDuracion();
                filas.push_back(fila);
            }
        }
    }

    // Ordena las filas y las inserta en la tabla.
    filas.sort(comparadorFilas);
    for (std::list<Fila*>::iterator i = filas.begin(); i != filas.end(); i++)
    {
        Gtk::TreeModel::Row row = *(treemodelResumenCitas->append());
        row[columnaAsignatura] = (*i)->asignatura;
        row[columnaDescripcion] = (*i)->descripcion;
        row[columnaFecha] = (*i)->fecha.toString();
        row[columnaDuracion] = (*i)->duracion;
        delete *i;
    }
}

bool comparadorSesiones(Sesion *a, Sesion *b)
{
    return a->getFechaInicio() < b->getFechaInicio();
}

void VistaGtkmmResumen::recargarHorario()
{
    // Elimina todas las anteriores.
    Gtk::TreeModel::Children children = treemodelResumenSesiones->children();
    for (Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); )
    {
        Gtk::TreeModel::Children::iterator aux = iter;
        iter++;
        treemodelResumenSesiones->erase(aux);
    }

    std::list<Sesion*> todasSesiones;
    std::map<Sesion*, std::string> vinculos;

    // Se recorren todas las citas.
    const std::list<Asignatura*> lista = static_cast<Asignaturas*>(modelo)->obtenerAsignaturas();
    for (std::list<Asignatura*>::const_iterator i = lista.begin(); i != lista.end(); i++)
    {
        // Se añaden las sesiones de la asignatura a la lista completa y se guarda el nombre de la asignatura para luego.
        const std::list<Sesion*> sesiones = (*i)->obtenerSesiones();
        std::list<Sesion*>::const_iterator sesion = sesiones.begin();
        for (; sesion != sesiones.end(); sesion++)
        {
            vinculos[*sesion] = (*i)->getNombre();
            todasSesiones.push_back(*sesion);
        }
    }

    // Cuenta cuántas sesiones hay cada día.
    int contadorColumnas[7] = {0, 0, 0, 0, 0, 0, 0};
    //int rows = 0;
    std::vector<Gtk::TreeModel::Row> rows;

    // Se ordenan las sesiones y se insertan.
    todasSesiones.sort(comparadorSesiones);
    std::list<Sesion*>::const_iterator sesion = todasSesiones.begin();
    for (; sesion != todasSesiones.end(); sesion++)
    {
        std::string etiqueta = (*sesion)->getFechaInicio().toStringHora() + " - " + (*sesion)->getFechaFin().toStringHora();
        etiqueta += "\n" + vinculos[*sesion] + "\n";
        etiqueta += "(" + (*sesion)->getLugar() + ")";

        // Si no hay suficientes filas, se inserta una más.
        int dia = (*sesion)->getDia();
        Gtk::TreeModel::Row row;
        if (++contadorColumnas[dia] > (int) rows.size())
        {
            row = *(treemodelResumenSesiones->append());
            rows.push_back(row);
        }
        else
        {
            row = rows[contadorColumnas[dia] - 1];
        }

        Gdk::Color color;
        if ((*sesion)->getTipo() == Sesion::TEORIA)
            color.set_rgb_p(0.82, 0.94, 0.62);
        else
            color.set_rgb_p(0.67, 0.79, 0.94);
        switch (dia)
        {
            case 0:
            {
                row[columnaLunesColor] = color;
                row[columnaLunes] = etiqueta;
                break;
            }
            case 1:
            {
                row[columnaMartesColor] = color;
                row[columnaMartes] = etiqueta;
                break;
            }
            case 2:
            {
                row[columnaMiercolesColor] = color;
                row[columnaMiercoles] = etiqueta;
                break;
            }
            case 3:
            {
                row[columnaJuevesColor] = color;
                row[columnaJueves] = etiqueta;
                break;
            }
            case 4:
            {
                row[columnaViernesColor] = color;
                row[columnaViernes] = etiqueta;
                break;
            }
            case 5:
            {
                row[columnaSabadoColor] = color;
                row[columnaSabado] = etiqueta;
                break;
            }
            case 6:
            {
                row[columnaDomingoColor] = color;
                row[columnaDomingo] = etiqueta;
                break;
            }
        }
    }
}

void VistaGtkmmResumen::citasPasadas()
{
    recargarCitas();
}

void VistaGtkmmResumen::sabadoDomingo()
{
    if (checkbuttonSabadoDomingo->get_active())
    {
        treeviewResumenSesiones->get_column(5)->set_visible(true);
        treeviewResumenSesiones->get_column(6)->set_visible(true);
    }
    else
    {
        treeviewResumenSesiones->get_column(5)->set_visible(false);
        treeviewResumenSesiones->get_column(6)->set_visible(false);
    }
}