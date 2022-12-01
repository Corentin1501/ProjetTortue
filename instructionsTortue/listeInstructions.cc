#include "listeInstructions.hh"



void listeInstructions::executer() {
    for(auto const & inst : _liste) 
        inst.executer();
    liste.clear();
    
}


void listeInstructions::ajouterInstruction(InstructionPtr const & deplace){
    liste.push_back(deplace);
}