# Comprueba si libgtkmm y libglademm están en la máquina (requiere pkg-config).
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)
pkg_check_modules(GLADEMM libglademm-2.4)

# Añade las cabeceras y las librerías.
link_directories(${GTKMM_LIBRARY_DIRS} ${GLADEMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS} ${GLADEMM_INCLUDE_DIRS})

# Fuentes y cabeceras del código.
SET(OBJ VistaGtkmmAsignaturas.cpp VistaGtkmmAsignatura.cpp VistaGtkmmResumen.cpp)

# Genera la librería y la enlaza con Gtkmm, Glademm y con Modelo y Vista.
ADD_LIBRARY(Vista-gtkmm ${OBJ})
TARGET_LINK_LIBRARIES(Vista-gtkmm Modelo Vista ${GTKMM_LIBRARIES} ${GLADEMM_LIBRARIES})

# Genera el ejecutable y se enlaza con la librería anterior.
ADD_EXECUTABLE(VistaGtkmm main.cpp)
TARGET_LINK_LIBRARIES(VistaGtkmm Vista-gtkmm)
