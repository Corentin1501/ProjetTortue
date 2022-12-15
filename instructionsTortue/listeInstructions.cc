#include "listeInstructions.hh"



void ListeInstructions::executer() {
    for(auto const & inst : _liste) 
        inst.executer();
    _liste.clear();
    
}


void ListeInstructions::ajouterInstruction(Instruction const & deplace){
    _liste.push_back(deplace);
}