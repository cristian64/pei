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
    columnas.add(columnaMartes);
    columnas.add(columnaMiercoles);
    columnas.add(columnaJueves);
    columnas.add(columnaViernes);
    columnas.add(columnaSabado);
    columnas.add(columnaDomingo);
    
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
    treeviewResumenSesiones->append_column("Lunes", columnaLunes);
    treeviewResumenSesiones->append_column("Martes", columnaMartes);
    treeviewResumenSesiones->append_column("Miércoles", columnaMiercoles);
    treeviewResumenSesiones->append_column("Jueves", columnaJueves);
    treeviewResumenSesiones->append_column("Viernes", columnaViernes);
    treeviewResumenSesiones->set_reorderable(false);
    treeviewResumenSesiones->get_column(0)->set_expand(true);
    treeviewResumenSesiones->get_column(1)->set_expand(true);
    treeviewResumenSesiones->get_column(2)->set_expand(true);
    treeviewResumenSesiones->get_column(3)->set_expand(true);
    treeviewResumenSesiones->get_column(4)->set_expand(true);
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

void VistaGtkmmResumen::recargarHorario()
{

}

void VistaGtkmmResumen::citasPasadas()
{
    recargarCitas();
}

void VistaGtkmmResumen::sabadoDomingo()
{
    if (checkbuttonSabadoDomingo->get_active())
    {
        treeviewResumenSesiones->append_column("Sábado", columnaSabado);
        treeviewResumenSesiones->append_column("Domingo", columnaDomingo);
        treeviewResumenSesiones->get_column(5)->set_expand(true);
        treeviewResumenSesiones->get_column(6)->set_expand(true);
    }
    else
    {
        treeviewResumenSesiones->remove_column(*treeviewResumenSesiones->get_column(6));
        treeviewResumenSesiones->remove_column(*treeviewResumenSesiones->get_column(5));
    }
}