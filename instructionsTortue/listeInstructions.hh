#pragma once
#include "instructions.hh"
#include <vector>


class ListeInstructions {

    private:
        std::vector<InstructionPtr> liste;

    public:
        ListeInstructions() { liste.clear(); }
        
        void executer();
        void ajouterInstruction(InstructionPtr const & instru);


};