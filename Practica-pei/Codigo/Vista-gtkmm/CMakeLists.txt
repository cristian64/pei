# Comprueba si libgtkmm y libglademm están en la máquina (requiere pkg-config).
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)
pkg_check_modules(GLADEMM libglademm-2.4)

# Añade las cabeceras y las librerías.
link_directories(${GTKMM_LIBRARY_DIRS} ${GLADEMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS} ${GLADEMM_INCLUDE_DIRS})

# Fuentes y cabeceras del código.
SET(OBJ VistaGtkmmAsignaturas.cpp)

# Genera la librería y la enlaza con Gtkmm, Glademm y con Modelo y Vista.
ADD_LIBRARY(Vista-gtkmm ${OBJ})
TARGET_LINK_LIBRARIES(Vista-gtkmm Modelo Vista ${GTKMM_LIBRARIES} ${GLADEMM_LIBRARIES})

# Genera el ejecutable y se enlaza con la librería anterior.
ADD_EXECUTABLE(VistaGtkmm main.cpp)
TARGET_LINK_LIBRARIES(VistaGtkmm Vista-gtkmm)

# Se añade una dependencia de interfaces.glade con el ejecutable para que
# se vuelva a compilar cuando se modifique la interfaz desde Glade
add_dependencies(VistaGtkmm interfaces.glade)

# Comando personalizado para generar un .h a partir del .glade (y así poder incluir el XML dentro del código).
# El fichero que se genera (interfaces.glade.h) es una variable del tipo std::string que se le asigna el contenido del .glade.
# En el código del programa se realiza un #include "interfaces.glade.h" para que el preprocesador coloque ahí la variable std::string ya definida.
add_custom_command(TARGET VistaGtkmm
	PRE_BUILD
	COMMAND echo \"interfacesGlade = \\\"\" >interfaces.glade.aux
	COMMAND sed -e \"s/\\\\\\\"/\\\\\\\\\\\"/g\" interfaces.glade >>interfaces.glade.aux
	COMMAND echo \"\\\"\;\" >>interfaces.glade.aux
	COMMAND tr -d \"\\n\" < interfaces.glade.aux >interfaces.glade.h
	COMMAND rm -f interfaces.glade.aux
	DEPENDS interfaces.glade
	COMMENT "Generating interfaces.glade.h")

#echo "interfacesGlade = \"" >interfaces.glade.aux;
#sed -e "s/\\\"/\\\\\"/g" interfaces.glade >>interfaces.glade.aux;
#echo "\";" >>interfaces.glade.aux;
#tr -d "\n" < interfaces.glade.aux >interfaces.glade.h;
#rm -f interfaces.glade.aux
