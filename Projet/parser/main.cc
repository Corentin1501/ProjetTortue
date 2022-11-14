#include "jardin.hh"

#include <iostream>
#include <fstream>

#include <cstring>

#include <QtGui>
#include <QApplication>


int main( int  argc, char* argv[]) {
    if (argc > 2){
        std::cerr << "Trop d'arguments, format attendu ./tortue *jardin* < programme " << std::endl;
        return 0;
    }
    else{
        Jardin * J;
        QApplication app(argc,argv);
        if (argc == 2) J = new Jardin(argv[1]);
        else J = new Jardin;
        
        J->show();

        return app.exec();
    }

}
