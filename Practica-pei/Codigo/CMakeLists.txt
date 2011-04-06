PROJECT(PEI)
cmake_minimum_required(VERSION 2.8)

# Definiciones generales a la hora de compilar.
ADD_DEFINITIONS("-Wall -g -W -Wextra -O2")

# Especificamos dónde se generan las librerías (.a, .lib).
SET(LIBRARY_OUTPUT_PATH ${PEI_SOURCE_DIR}/Lib)

# Espeficicamos los directorios con las cabeceras.
include_directories(${PEI_SOURCE_DIR}/Modelo
	${PEI_SOURCE_DIR}/Vista
	${PEI_SOURCE_DIR}/Vista-qt
	${PEI_SOURCE_DIR}/Vista-gtkmm
	${PEI_SOURCE_DIR}/Vista-txt
)

# Especificamos los directorios con las librerias
# (si hubiera .so con los que enlazar (o .a o .lib generados previamente), también se indican así).
link_directories(${PEI_SOURCE_DIR}/lib)

# Especificamos los subdirectorios a los que hay que profundizar.
ADD_SUBDIRECTORY(Modelo)
ADD_SUBDIRECTORY(Vista)
ADD_SUBDIRECTORY(Vista-qt)
ADD_SUBDIRECTORY(Vista-gtkmm)
ADD_SUBDIRECTORY(Vista-txt)

# Generamos los ejecutables.
ADD_EXECUTABLE(VistaTXT ${PEI_SOURCE_DIR}/Vista-txt/main)
TARGET_LINK_LIBRARIES(VistaTXT Modelo Vista)# Vista-txt)

ADD_EXECUTABLE(VistaQt ${PEI_SOURCE_DIR}/Vista-qt/main)
TARGET_LINK_LIBRARIES(VistaQt Modelo Vista)# Vista-qt)

ADD_EXECUTABLE(VistaGtkmm ${PEI_SOURCE_DIR}/Vista-gtkmm/main)
TARGET_LINK_LIBRARIES(VistaGtkmm Modelo Vista)# Vista-gtkmm)

