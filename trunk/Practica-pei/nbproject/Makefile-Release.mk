#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Codigo/Modelo/Nota.o \
	${OBJECTDIR}/Codigo/Modelo/Sesion.o \
	${OBJECTDIR}/Codigo/Modelo/Profesor.o \
	${OBJECTDIR}/Codigo/Vista/Vista.o \
	${OBJECTDIR}/Codigo/Modelo/Fecha.o \
	${OBJECTDIR}/Codigo/Modelo/Cita.o \
	${OBJECTDIR}/Codigo/Modelo/Modelo.o \
	${OBJECTDIR}/Codigo/Modelo/Companero.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/practica-pei

dist/Release/GNU-Linux-x86/practica-pei: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practica-pei ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Codigo/Modelo/Nota.o: Codigo/Modelo/Nota.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Modelo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Modelo/Nota.o Codigo/Modelo/Nota.cpp

${OBJECTDIR}/Codigo/Modelo/Sesion.o: Codigo/Modelo/Sesion.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Modelo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Modelo/Sesion.o Codigo/Modelo/Sesion.cpp

${OBJECTDIR}/Codigo/Modelo/Profesor.o: Codigo/Modelo/Profesor.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Modelo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Modelo/Profesor.o Codigo/Modelo/Profesor.cpp

${OBJECTDIR}/Codigo/Vista/Vista.o: Codigo/Vista/Vista.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Vista
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Vista/Vista.o Codigo/Vista/Vista.cpp

${OBJECTDIR}/Codigo/Modelo/Fecha.o: Codigo/Modelo/Fecha.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Modelo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Modelo/Fecha.o Codigo/Modelo/Fecha.cpp

${OBJECTDIR}/Codigo/Modelo/Cita.o: Codigo/Modelo/Cita.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Modelo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Modelo/Cita.o Codigo/Modelo/Cita.cpp

${OBJECTDIR}/Codigo/Modelo/Modelo.o: Codigo/Modelo/Modelo.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Modelo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Modelo/Modelo.o Codigo/Modelo/Modelo.cpp

${OBJECTDIR}/Codigo/Modelo/Companero.o: Codigo/Modelo/Companero.cpp 
	${MKDIR} -p ${OBJECTDIR}/Codigo/Modelo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Codigo/Modelo/Companero.o Codigo/Modelo/Companero.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/practica-pei

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
