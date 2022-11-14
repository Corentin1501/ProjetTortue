TEMPLATE = lib
CONFIG += staticlib
#Input
HEADERS += ./constante.hh ./contexte.hh ./expression.hh ./expressionBinaire.hh ./expressionTernaire.hh ./expressionUnaire.hh ./variable.hh
SOURCES += ./constante.cc ./contexte.cc ./expressionBinaire.cc ./expressionTernaire.cc ./expressionUnaire.cc ./variable.cc
DEFINES += MAKE_TEST_LIB
QT += widgets
