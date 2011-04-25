PROJECT(PEI)
cmake_minimum_required(VERSION 2.8)

# Definiciones generales a la hora de compilar.
ADD_DEFINITIONS("-Wall -g -W -Wextra -O2")

# Especificamos dónde se generan las librerías (.a, .lib) y los ejecutables.
SET(LIBRARY_OUTPUT_PATH ${PEI_SOURCE_DIR}/Lib)
SET(EXECUTABLE_OUTPUT_PATH ${PEI_SOURCE_DIR})

# Espeficicamos los directorios con las cabeceras.
include_directories(${PEI_SOURCE_DIR}/Modelo
    ${PEI_SOURCE_DIR}/Vista
    ${PEI_SOURCE_DIR}/Vista-qt
    ${PEI_SOURCE_DIR}/Vista-gtkmm
    ${PEI_SOURCE_DIR}/Vista-txt
    ${PEI_SOURCE_DIR}/Vista-xforms
    ${PEI_SOURCE_DIR}/Vista-multiple
)

# Especificamos los directorios con las librerias
# (si hubiera .so con los que enlazar (o .a o .lib generados previamente), también se indican aquí).
link_directories(${PEI_SOURCE_DIR}/Lib)

# Especificamos los subdirectorios a los que hay que profundizar.
ADD_SUBDIRECTORY(Modelo)
ADD_SUBDIRECTORY(Vista)
ADD_SUBDIRECTORY(Vista-qt)
ADD_SUBDIRECTORY(Vista-gtkmm)
ADD_SUBDIRECTORY(Vista-txt)
ADD_SUBDIRECTORY(Vista-xforms)
ADD_SUBDIRECTORY(Vista-multiple)

