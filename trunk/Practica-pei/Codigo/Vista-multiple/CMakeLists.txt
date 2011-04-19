# Cabeceras de Qt.
include_directories(/usr/include/qt4)
include_directories(/usr/include/qt4/QtGui)
include_directories(/usr/include/qt4/QtCore)

# Los iconos de la vista de Qt hace falta ponerlos como dependencia en el ejecutable (porque en la librería Vista-qt no funciona...).
SET(VISTAQT_RESOURCES ../Vista-qt/icons.qrc)
qt4_add_resources(VISTAQT_RESOURCES_SOURCES ${VISTAQT_RESOURCES})

# Generar el ejecutable con la vista Qt y la vista XForms.
ADD_EXECUTABLE(VistaMultiple main.cpp ${VISTAQT_RESOURCES_SOURCES})
TARGET_LINK_LIBRARIES(VistaMultiple Vista-qt Vista-xforms)

