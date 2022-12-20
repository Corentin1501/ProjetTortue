#pragma once
#include "instruction.hh"
#include <vector>
#include <memory>


class liste {
    private:
        std::vector<instructionPtr> _instructions;
        liste() = default;

    public:
        static std::shared_ptr<liste> fabrique();
        void executer();

        bool ajouterInstruction(instructionPtr i);

};

using listePtr = std::shared_ptr<liste>;

