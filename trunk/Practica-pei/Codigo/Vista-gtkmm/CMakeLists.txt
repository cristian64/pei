# Establecer los módulos a compilar.
#SET(OBJ MainWindow VistaGtkmmAsignatura VistaGtkmmAsignaturas)#TODO: poner los objetos cuando existan... aunque habrá que reventar este CMake porque ni de coña va a rular fácilmente con Gtkmm.

# Compilar la librería, enlazándola con Modelo y Vista.
ADD_LIBRARY(Vista-gtkmm ${OBJ})
TARGET_LINK_LIBRARIES(Vista-gtkmm Modelo Vista)

# Genera el ejecutable enlazándolo con la librería anterior.
ADD_EXECUTABLE(VistaGtkmm main)
TARGET_LINK_LIBRARIES(VistaGtkmm Vista-gtkmm)

