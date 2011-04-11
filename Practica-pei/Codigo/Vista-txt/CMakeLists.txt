# Establecer los módulos a compilar.
SET(OBJ VistaTxtAsignatura VistaTxtAsignaturas Auxiliar)

# Compilar la librería, enlazándola con Modelo y Vista.
ADD_LIBRARY(Vista-txt ${OBJ})
TARGET_LINK_LIBRARIES(Vista-txt Modelo Vista)

# Genera el ejecutable enlazándolo con la librería anterior.
ADD_EXECUTABLE(VistaTxt main)
TARGET_LINK_LIBRARIES(VistaTxt Vista-txt)

