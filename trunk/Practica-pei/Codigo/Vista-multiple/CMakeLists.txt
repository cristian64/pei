# Cabeceras de Qt.
include_directories(/usr/include/qt4)
include_directories(/usr/include/qt4/QtGui)
include_directories(/usr/include/qt4/QtCore)

# Generar el ejecutable con la vista Qt y la vista XForms.
ADD_EXECUTABLE(VistaMultiple main.cpp)
TARGET_LINK_LIBRARIES(VistaMultiple Vista-qt Vista-xforms)

