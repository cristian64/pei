#-------------------------------------------------
#
# Project created by QtCreator 2011-03-27T22:53:33
#
#-------------------------------------------------

QT       += core gui network

TARGET = VistaQt
TEMPLATE = app


SOURCES += main.cpp\
		MainWindow.cpp \
		VistaQtAsignatura.cpp \
		VistaQtAsignaturas.cpp \
		../Vista/Vista.cpp \
		../Modelo/Modelo.cpp \
		../Modelo/Asignaturas.cpp \
		../Modelo/Asignatura.cpp \
		../Modelo/Profesor.cpp \
		../Modelo/Companero.cpp \
		../Modelo/Cita.cpp \
		../Modelo/Nota.cpp \
		../Modelo/Sesion.cpp \
		../Modelo/Fecha.cpp \
		../Modelo/tinyxml/tinystr.cpp \
		../Modelo/tinyxml/tinyxml.cpp \
		../Modelo/tinyxml/tinyxmlerror.cpp \
		../Modelo/tinyxml/tinyxmlparser.cpp \
		DialogoProfesor.cpp \
		DialogoCompanero.cpp \
DialogoSesion.cpp \
DialogoCita.cpp \
DialogoNota.cpp

HEADERS  += MainWindow.h \
		VistaQtAsignatura.h \
		VistaQtAsignaturas.h \
		../Vista/Vista.h \
		../Modelo/Asignaturas.h \
		../Modelo/Modelo.h \
		../Modelo/Asignatura.h \
		../Modelo/Profesor.h \
		../Modelo/Companero.h \
		../Modelo/Cita.h \
		../Modelo/Nota.h \
		../Modelo/Sesion.h \
		../Modelo/Fecha.h \
		../Modelo/tinyxml/tinyxml.h \
		../Modelo/tinyxml/tinystr.h \
		DialogoProfesor.h \
		DialogoCompanero.h \
DialogoSesion.h \
DialogoCita.h \
DialogoNota.h

FORMS    += MainWindow.ui \
		VistaQtAsignatura.ui \
		VistaQtAsignaturas.ui \
		DialogoProfesor.ui \
		DialogoCompanero.ui \
DialogoSesion.ui \
DialogoCita.ui \
DialogoNota.ui

RESOURCES += icons.qrc

INCLUDEPATH += ../Modelo ../Modelo/tinyxml ../Vista
