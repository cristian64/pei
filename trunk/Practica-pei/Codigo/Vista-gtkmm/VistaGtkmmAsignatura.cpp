#include "VistaGtkmmAsignatura.h"

VistaGtkmmAsignatura::VistaGtkmmAsignatura(Glib::RefPtr<Gnome::Glade::Xml> refXml)
{
    
}

void VistaGtkmmAsignatura::refrescar()
{
    Asignatura *asignatura = static_cast<Asignatura*>(modelo);
    if (asignatura != NULL)
    {
        cout << "seleccionando " << asignatura->getNombre() << endl;
    }
    else
    {
        cout << "sin asignatura" << endl;
    }
}