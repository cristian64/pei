#include "VistaQtAsignaturas.h"
#include "ui_VistaQtAsignaturas.h"
#include "MainWindow.h"
#include "Asignaturas.h"
#include <algorithm>
#include <iostream>

VistaQtAsignaturas::VistaQtAsignaturas(QWidget *parent) :
    QListWidget(parent),
    ui(new Ui::VistaQtAsignaturas)
{
    ui->setupUi(this);
    connect(this, SIGNAL(itemSelectionChanged()), SLOT(itemSelectionChanged()));
    connect(this, SIGNAL(itemChanged(QListWidgetItem*)), SLOT(itemChanged(QListWidgetItem*)));
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(itemClicked(QListWidgetItem*)));
}

VistaQtAsignaturas::~VistaQtAsignaturas()
{
    delete ui;
}

void VistaQtAsignaturas::refrescar()
{
    Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
    const std::list<Asignatura*> lista = asignaturas->obtenerAsignaturas();

    // Cada asignatura de "vinculos" que no esté en la lista, se elimina de "vinculos" y de la QListWidget.
    std::map<Asignatura*, QListWidgetItem*>::iterator j = vinculos.begin();
    while (j != vinculos.end())
    {
        if (std::find(lista.begin(), lista.end(), j->first) == lista.end())
        {
            j->second->setSelected(false);
            delete j->second;
            std::map<Asignatura*, QListWidgetItem*>::iterator aux = j++;
            vinculos.erase(aux);
        }
        else
        {
            j++;
        }
    }

    // Cada asignatura de la lista que no este en "vinculos", se añade a "vinculos" y a la QListWidget.
    std::list<Asignatura*>::const_iterator i = lista.begin();
    for (; i != lista.end(); i++)
    {
        // Si no está, se añade; si sí está, sólo se actualiza.
        if (vinculos.find(*i) == vinculos.end())
        {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString((*i)->getNombre()));
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            vinculos[*i] = item;
            addItem(item);
        }
        else
        {
            vinculos[*i]->setText(QString::fromStdString((*i)->getNombre()));
        }
    }
}

void VistaQtAsignaturas::quitarAsignaturaSeleccionada()
{
    QList<QListWidgetItem*> seleccionadas = selectedItems();
    if (seleccionadas.size() > 0)
    {
        QListWidgetItem *seleccionada = seleccionadas.first();
        delete seleccionada;

        Asignaturas *asignaturas = static_cast<Asignaturas*>(modelo);
        std::map<Asignatura*, QListWidgetItem*>::iterator i = vinculos.begin();
        for (; i != vinculos.end(); i++)
        {
            if (i->second == seleccionada)
            {
                asignaturas->quitarAsignatura(i->first);
                asignaturas->refrescarVistas(this);
                vinculos.erase(i);
                break;
            }
        }
    }
}

Asignatura* VistaQtAsignaturas::obtenerSeleccionada() const
{
    QList<QListWidgetItem*> seleccionadas = selectedItems();
    if (seleccionadas.size() > 0)
    {
        QListWidgetItem *seleccionada = seleccionadas.first();

        std::map<Asignatura*, QListWidgetItem*>::const_iterator i = vinculos.begin();
        for (; i != vinculos.end(); i++)
        {
            if (i->second == seleccionada)
            {
                const std::list<Asignatura*> asignaturas = static_cast<Asignaturas*>(modelo)->obtenerAsignaturas();
                if (std::find(asignaturas.begin(), asignaturas.end(), i->first) != asignaturas.end())
                    return i->first;
                else
                    return NULL;
            }
        }
    }
    return NULL;
}

void VistaQtAsignaturas::itemSelectionChanged()
{
    emit asignaturaSeleccionadaCambio(obtenerSeleccionada());
}

void VistaQtAsignaturas::itemChanged(QListWidgetItem *item)
{
    std::map<Asignatura*, QListWidgetItem*>::const_iterator i = vinculos.begin();
    for (; i != vinculos.end(); i++)
    {
        if (i->second == item)
        {
            i->first->setNombre(item->text().toStdString());
            i->first->refrescarVistas();
            modelo->refrescarVistas(this);
            break;
        }
    }
}

void VistaQtAsignaturas::deseleccionar()
{
    if (selectedItems().size() > 0)
        selectedItems().front()->setSelected(false);
}

void VistaQtAsignaturas::itemClicked(QListWidgetItem*)
{
    QObject *root = parent();
    while (root != NULL)
    {
        MainWindow *mainWindow = dynamic_cast<MainWindow*>(root);
        if (mainWindow != NULL)
            mainWindow->on_actionResumen_toggled(false);
        root = root->parent();
    }
}
