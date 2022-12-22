#include "liste.hh"


void liste::executer() const {
    for(auto const & instruc : _instructions)
        instruc->executer();
}

bool liste::ajouterInstruction(instructionPtr i){
    // std::cout<<"ajout...";
    _instructions.push_back(i);
    // std::cout << " ajouté !" << std::endl;
    return true;
}

void conditionnelle::executer() const {
    if (_condition == estMurIci(_position, _emplacement))
        _then->executer();
    else 
        _else->executer();
}

bool boucleEtConditionnelle::estMurIci(std::string direction, unsigned int tortue) const {
    QPoint pos = jardin->position(tortue);
    int x = pos.x();
    int y = pos.y();
    int orientation = static_cast<int>(jardin->orientation(tortue));

    if(direction == "devant") {
        switch(orientation%360){
            case 0:     return jardin->estMur(x , y-1); break;
            case 90:    return jardin->estMur(x+1 , y); break;
            case 180:   return jardin->estMur(x , y+1); break;
            case 270:   return jardin->estMur(x-1 , y); break;
        }
    }
    else if(direction == "derrière") {
        switch(orientation%360){
            case 0:     return jardin->estMur(x , y+1); break;
            case 90:    return jardin->estMur(x-1 , y); break;
            case 180:   return jardin->estMur(x , y-1); break;
            case 270:   return jardin->estMur(x+1 , y); break;
        }
    }
    else if(direction == "à droite") {
        switch(orientation%360){
            case 0:     return jardin->estMur(x+1 , y); break;
            case 90:    return jardin->estMur(x , y+1); break;
            case 180:   return jardin->estMur(x-1 , y); break;
            case 270:   return jardin->estMur(x , y-1); break;
        }
    }
    else if(direction == "à gauche") {
        switch(orientation%360){
            case 0:     return jardin->estMur(x-1 , y); break;
            case 90:    return jardin->estMur(x , y-1); break;
            case 180:   return jardin->estMur(x+1 , y); break;
            case 270:   return jardin->estMur(x , y+1); break;
        }
    }
    return false;

}

void conditionnelle::ajouterInstruction(instructionPtr i){
    if (_danselse) ajouterInstructionElse(i);
    else ajouterInstructionThen(i);
}

void tantque::executer() const {
    while(_condition == estMurIci(_position, _emplacement))
        _then->executer();
}
void repete::executer() const {
    for(unsigned int i(0); i<_nombreDeFois; i++)
        _then->executer();
}