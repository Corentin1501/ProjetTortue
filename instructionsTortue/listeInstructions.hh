#pragma once
#include "instructions.hh"
#include <vector>


class ListeInstructions {

    private:
        std::vector<Instruction> _liste;

    public:
        ListeInstructions() { liste.clear(); }
        
        void executer();
        void ajouterInstruction(Instruction const & instru);

};

using ListePtr = std::shared_ptr<ListeInstructions>;
