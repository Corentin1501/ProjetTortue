#include "instructions.hh"


void Mouvement::executer() const{
        QPoint pos = jardin->position(numeroTortue);
        int x = pos.x();
        int y = pos.y();
        int orientation = static_cast<int>(jardin->orientation(numeroTortue));
        int coeffDirection = (_dir==direction::avant) ? 1 : -1;
        /*
        *         0                   0
        *    270      90        -90      -270
        *        180                -180
        */

        switch(orientation%360){
            case 0:      for (int i(0) ; i<nombreDeFois; i++) jardin->changePosition(numeroTortue, x , y-(1*coeffDirection)); break;
            case 90:     for (int i(0) ; i<nombreDeFois; i++) jardin->changePosition(numeroTortue, x+(1*coeffDirection) , y); break;
            case -270:   for (int i(0) ; i<nombreDeFois; i++) jardin->changePosition(numeroTortue, x+(1*coeffDirection) , y); break;
            case 180:    for (int i(0) ; i<nombreDeFois; i++) jardin->changePosition(numeroTortue, x , y+(1*coeffDirection)); break;
            case -180:   for (int i(0) ; i<nombreDeFois; i++) jardin->changePosition(numeroTortue, x , y+(1*coeffDirection)); break;
            case 270:    for (int i(0) ; i<nombreDeFois; i++) jardin->changePosition(numeroTortue, x-(1*coeffDirection) , y); break;
            case -90:    for (int i(0) ; i<nombreDeFois; i++) jardin->changePosition(numeroTortue, x-(1*coeffDirection) , y); break;
        }
}
void Tourner::executer() const{     
    int orientation = static_cast<int>(jardin->orientation(numeroTortue));

    if(_sens == sens::droite) 
        jardin->changeOrientation(numeroTortue, orientation + 90);
    else if (_sens == sens::gauche) 
        jardin->changeOrientation(numeroTortue, orientation - 90);

}