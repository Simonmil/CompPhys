TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jacobi.cpp \
    functions.cpp \
    unittest.cpp

INCLUDEPATH += C:\armadillo\include\
DEPENDPATH += C:\armadillo\include\

LIBS += -LC:/armadillo/newblas -llibblas
LIBS += -LC:/armadillo/newblas -lliblapack

HEADERS += \
    jacobi.h \
    functions.h \
    unittest.h
