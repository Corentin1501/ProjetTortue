#include "liste.hh"


std::shared_ptr<liste> liste::fabrique(){
    return listePtr(new liste());
}

void liste::executer(){
    for(auto const & instruc : _instructions)
        instruc->executer();
    
    _instructions.clear();
}

bool liste::ajouterInstruction(instructionPtr i){
    _instructions.push_back(i);
    return true;
}
