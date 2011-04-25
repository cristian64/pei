FIND_PACKAGE(Qt4 REQUIRED)
include(${QT_USE_FILE})

# Incluye las cabeceras de Qt.
add_definitions(${QT_DEFINITIONS})
include_directories(${QT_INCLUDE_DIR})

# Fuentes y cabeceras.
SET(VISTAQT_SOURCES MainWindow.cpp VistaQtAsignaturas.cpp VistaQtAsignatura.cpp DialogoProfesor.cpp DialogoCompanero.cpp DialogoSesion.cpp DialogoCita.cpp DialogoNota.cpp DialogoAcercaDe.cpp VistaQtResumen.cpp)
SET(VISTAQT_HEADERS MainWindow.h VistaQtAsignaturas.h VistaQtAsignatura.h DialogoProfesor.h DialogoCompanero.h DialogoSesion.h DialogoCita.h DialogoNota.h DialogoAcercaDe.h VistaQtResumen.h)
SET(VISTAQT_UIS MainWindow.ui VistaQtAsignaturas.ui VistaQtAsignatura.ui DialogoProfesor.ui DialogoCompanero.ui DialogoSesion.ui DialogoCita.ui DialogoNota.ui DialogoAcercaDe.ui VistaQtResumen.ui)
SET(VISTAQT_RESOURCES icons.qrc)

# Genera los ficheros moc y las cabeceras de los ficheros ui.
qt4_wrap_cpp(VISTAQT_SOURCES ${VISTAQT_HEADERS})
qt4_wrap_ui(VISTAQT_UIS_H ${VISTAQT_UIS})
qt4_add_resources(VISTAQT_RESOURCES_SOURCES ${VISTAQT_RESOURCES})

# Genera la librería y la enlaza con Qt y Modelo y Vista.
ADD_LIBRARY(Vista-qt ${VISTAQT_SOURCES} ${VISTAQT_UIS_H})
TARGET_LINK_LIBRARIES(Vista-qt Modelo Vista ${QT_LIBRARIES})

# Genera el ejecutable y se enlaza con la librería anterior.
ADD_EXECUTABLE(VistaQt main.cpp ${VISTAQT_RESOURCES_SOURCES})
TARGET_LINK_LIBRARIES(VistaQt Vista-qt)

