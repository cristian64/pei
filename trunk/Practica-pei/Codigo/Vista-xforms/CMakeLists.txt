# Establecer los módulos a compilar.
SET(OBJ Formulario.cpp Formulario_cb.cpp)

# Compilar la librería, enlazándola con Modelo y Vista y sus dependencias externas.
ADD_LIBRARY(Vista-xforms ${OBJ})
TARGET_LINK_LIBRARIES(Vista-xforms forms X11 m Modelo Vista)

# Generar el ejecutable enlazando con la librería previamente creada.
ADD_EXECUTABLE(VistaXforms main.cpp)
TARGET_LINK_LIBRARIES(VistaXforms Vista-xforms)

