FIND_PACKAGE(Qt4 REQUIRED)
include(${QT_USE_FILE})

# Incluye las cabeceras de Qt.
add_definitions(${QT_DEFINITIONS})
include_directories(${QT_INCLUDE_DIR})

SET(VISTAMULTIPLE_SOURCES XformsTimer.cpp)
SET(VISTAMULTIPLE_HEADERS XformsTimer.h)
qt4_wrap_cpp(VISTAMULTIPLE_SOURCES ${VISTAMULTIPLE_HEADERS})

# Los iconos de la vista de Qt hace falta ponerlos como dependencia en el ejecutable (porque en la librería Vista-qt no funciona...).
SET(VISTAQT_RESOURCES ../Vista-qt/icons.qrc)
qt4_add_resources(VISTAQT_RESOURCES_SOURCES ${VISTAQT_RESOURCES})

# Generar el ejecutable con la vista Qt y la vista XForms.
ADD_EXECUTABLE(VistaMultiple main.cpp ${VISTAMULTIPLE_SOURCES} ${VISTAQT_RESOURCES_SOURCES})
TARGET_LINK_LIBRARIES(VistaMultiple Vista-qt Vista-xforms)
