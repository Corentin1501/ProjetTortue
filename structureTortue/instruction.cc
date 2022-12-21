#include "instruction.hh"

void mouvement::executer() const {
    QPoint pos = jardin->position(numeroTortue());
    int x = pos.x();
    int y = pos.y();
    int orientation = static_cast<int>(jardin->orientation(numeroTortue()));
    int coeffDirection = (_dir==direction::avant) ? 1 : -1;
    /*
    *         0                   0
    *    270      90        -90      -270
    *        180                -180
    */

    switch(orientation%360){
        case 0:      jardin->changePosition(numeroTortue(), x , y-(_nombreDeFois*coeffDirection)); break;
        case 90:     jardin->changePosition(numeroTortue(), x+(_nombreDeFois*coeffDirection) , y); break;
        case -270:   jardin->changePosition(numeroTortue(), x+(_nombreDeFois*coeffDirection) , y); break;
        case 180:    jardin->changePosition(numeroTortue(), x , y+(_nombreDeFois*coeffDirection)); break;
        case -180:   jardin->changePosition(numeroTortue(), x , y+(_nombreDeFois*coeffDirection)); break;
        case 270:    jardin->changePosition(numeroTortue(), x-(_nombreDeFois*coeffDirection) , y); break;
        case -90:    jardin->changePosition(numeroTortue(), x-(_nombreDeFois*coeffDirection) , y); break;
    }
}

void tourner::executer() const {     
    int orientation = static_cast<int>(jardin->orientation(numeroTortue()));

    if(_sens == sens::droite) 
        jardin->changeOrientation(numeroTortue(), orientation + _nombreDeFois*90);
    else if (_sens == sens::gauche) 
        jardin->changeOrientation(numeroTortue(), orientation - _nombreDeFois*90);

}