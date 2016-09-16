TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64/' -llapack_win64_MT
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64/' -llapack_win64_MTd

INCLUDEPATH += $$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64'
DEPENDPATH += $$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64'

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64/' -lblas_win64_MT
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64/' -lblas_win64_MTd

INCLUDEPATH += $$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64'
DEPENDPATH += $$PWD/'../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/lib_win64'
