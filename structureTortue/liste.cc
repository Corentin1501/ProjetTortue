#include "liste.hh"


void liste::executer(){
    for(auto const & instruc : _instructions)
        instruc->executer();
    
    _instructions.clear();
}

bool liste::ajouterInstruction(instructionPtr i){
    _instructions.push_back(i);
    return true;
}

void conditionnelle::executer() const {
    if (_condition)
        _then->executer();
    else 
        _else->executer();
}

std::shared_ptr<conditionnelle> findID(std::shared_ptr<liste> l, unsigned int id){
    for(auto const & inst : l->instructions()){
        auto isCond = std::dynamic_pointer_cast<conditionnelle>(inst);
        if(isCond){
            if(isCond->id() == id) return isCond;
            else {
                auto foundthen(findID(isCond->listethen(), id));
                if (foundthen) return foundthen;
                auto foundelse(findID(isCond->listeelse(), id));
                if (foundelse) return foundelse;
                return nullptr;
            }
        }
    }
    return nullptr;
}