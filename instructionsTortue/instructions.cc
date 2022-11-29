#include "instructions.hh"


void Avancer::executer() const{     for (int i(0) ; i<nombreDeFois; i++) driver.avancerTortue(numeroTortue,1);      }
void Reculer::executer() const {    for (int i(0) ; i<nombreDeFois; i++) driver.avancerTortue(numeroTortue,-1);     }
void Tourner::executer() const{     for (int i(0) ; i<nombreDeFois; i++) driver.changerOrientationTortue(numeroTortue, _sens);      }