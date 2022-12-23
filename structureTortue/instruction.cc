#include "instruction.hh"

void bouger(JardinRendering * jardin, unsigned int numero, int _nombreDeFois, direction _dir){
    QPoint pos = jardin->position(numero);
    int x = pos.x();
    int y = pos.y();
    int orientation = static_cast<int>(jardin->orientation(numero));
    int coeffDirection = (_dir==direction::avant) ? 1 : -1;
    /*
    *         0                   0
    *    270      90        -90      -270
    *        180                -180
    */

    switch(orientation%360){
        case 0:      
            for(int i(0); i<_nombreDeFois;i++) {
                jardin->changePosition(numero, x , y-(1*coeffDirection)); 
                pos = jardin->position(numero); x = pos.x(); y = pos.y();
            } break;
        case 90:     
            for(int i(0); i<_nombreDeFois;i++) {
                jardin->changePosition(numero, x+(1*coeffDirection) , y);
                pos = jardin->position(numero); x = pos.x(); y = pos.y();
            } break;
        case -270:   
            for(int i(0); i<_nombreDeFois;i++) {
                jardin->changePosition(numero, x+(1*coeffDirection) , y);
                pos = jardin->position(numero); x = pos.x(); y = pos.y();
            } break;
        case 180:    
            for(int i(0); i<_nombreDeFois;i++) {
                jardin->changePosition(numero, x , y+(1*coeffDirection)); 
                pos = jardin->position(numero); x = pos.x(); y = pos.y();
            } break;
        case -180:   
            for(int i(0); i<_nombreDeFois;i++) {
                jardin->changePosition(numero, x , y+(1*coeffDirection));
                pos = jardin->position(numero); x = pos.x(); y = pos.y();
            } break;
        case 270:    
            for(int i(0); i<_nombreDeFois;i++) {
                jardin->changePosition(numero, x-(1*coeffDirection) , y);
                pos = jardin->position(numero); x = pos.x(); y = pos.y();
            } break;
        case -90:    
            for(int i(0); i<_nombreDeFois;i++) {
                jardin->changePosition(numero, x-(1*coeffDirection) , y);
                pos = jardin->position(numero); x = pos.x(); y = pos.y();
            } break;
    }
}

void mouvement::executer() const {
    if (numeroTortue() == 66) {
        int nombreDeTortues = jardin->getTortues().size();
        for(int num(0) ; num<nombreDeTortues; num++) 
            bouger(jardin, num, _nombreDeFois, _dir);
    }
    else bouger(jardin, numeroTortue(), _nombreDeFois, _dir);
}

void tourner::executer() const {    
    if (numeroTortue() == 66) {
        int nombreDeTortues = jardin->getTortues().size();
        for(int num(0) ; num<nombreDeTortues; num++) {
            int orientation = static_cast<int>(jardin->orientation(num));
            if(_sens == sens::droite) 
                jardin->changeOrientation(num, orientation + _nombreDeFois*90);
            else if (_sens == sens::gauche) 
                jardin->changeOrientation(num, orientation - _nombreDeFois*90);
        }
    }
    else {
    int orientation = static_cast<int>(jardin->orientation(numeroTortue()));

    if(_sens == sens::droite) 
        jardin->changeOrientation(numeroTortue(), orientation + _nombreDeFois*90);
    else if (_sens == sens::gauche) 
        jardin->changeOrientation(numeroTortue(), orientation - _nombreDeFois*90);
    }
}