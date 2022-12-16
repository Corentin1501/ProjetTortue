#pragma once
#include "instruction.hh"
#include <vector>
#include <memory>


class liste {
    private:
        std::vector<instruction> _instructions;
        liste() = default;

    public:
        static std::shared_ptr<liste> fabrique();
        void executer();

        bool ajouterInstruction(instruction const & instr);

};

using listePtr = std::shared_ptr<liste>;

