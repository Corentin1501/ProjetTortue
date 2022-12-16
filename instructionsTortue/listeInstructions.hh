#pragma once
#include "instructions.hh"
#include <vector>


class ListeInstructions {

    private:
        std::vector<Instruction> _liste;
        ListeInstructions() = default;
        
    public:
        static std::shared_ptr<ListeInstructions> fabrique();
        
        void executer();
        void ajouterInstruction(Instruction const & instru);

};

using ListePtr = std::shared_ptr<ListeInstructions>;
