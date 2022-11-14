#include "driver.hh"
#include "jardinHandler.hh"
#include <iostream>

Driver::Driver(JardinHandler * J) {
    monJardin = J;
}

Driver::~Driver() {
	delete monJardin;
}

const Contexte& Driver::getContexte() const {
    return variables;
}

double Driver::getVariable(const std::string & name) const {
    return variables.get(name);
}

void Driver::setVariable(const std::string & name, double value) {
    variables[name] = value;
}

JardinRendering * Driver::getJardin() {
    return monJardin->getJardinRendering();
}

void Driver::changerPositionTortue0(int x, int y) {
    getJardin()->changePosition(0,x,y);
}

QPoint Driver::getPosition(int n) {
    return getJardin()->position(n);
}

float    Driver::obtenirOrientationTortue(int numeroTortue) {
    return getJardin()->orientation(numeroTortue);
}

void Driver::changerOrientationTortue(int numeroTortue, std::string sens, int nombreFois){
    int orientation = static_cast<int>(obtenirOrientationTortue(0));

    if(sens == "droite") getJardin()->changeOrientation(numeroTortue, orientation+(90*nombreFois));
    else getJardin()->changeOrientation(numeroTortue, orientation-(90*nombreFois));
}

void Driver::avancerTortue(int numeroTortue, int nombreFois){
    QPoint pos = getPosition(numeroTortue);
    int x = pos.x();
    int y = pos.y();
    int orientation = static_cast<int>(obtenirOrientationTortue(numeroTortue));
    /*
    *         0
    *    270      90
    *        180
    */
    switch(orientation%360){
        case 0:     changerPositionTortue0(x , y-nombreFois); break;
        case 90:    changerPositionTortue0(x+nombreFois , y); break;
        case 180:   changerPositionTortue0(x , y+nombreFois); break;
        case 270:   changerPositionTortue0(x-nombreFois , y); break;
    }
}