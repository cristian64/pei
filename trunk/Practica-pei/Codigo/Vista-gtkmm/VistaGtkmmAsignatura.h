#ifndef VISTAGTKMMASIGNATURA_H
#define	VISTAGTKMMASIGNATURA_H

#include "Vista.h"
#include "Asignatura.h"
#include <libglademm/xml.h>
#include <gtkmm.h>

class VistaGtkmmAsignatura : public Vista
{
public:
    VistaGtkmmAsignatura(Glib::RefPtr<Gnome::Glade::Xml> refXml);
    void refrescar();
private:

};

#endif	/* VISTAGTKMMASIGNATURA_H */

