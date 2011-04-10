SET(OBJ VistaTxtAsignatura VistaTxtAsignaturas Auxiliar)
ADD_LIBRARY(Vista-txt ${OBJ})
TARGET_LINK_LIBRARIES(Vista-txt Modelo Vista)

