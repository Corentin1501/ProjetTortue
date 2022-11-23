#pragma once
#include <string>

class Instruction {
    private:
        std::string instruc;
    public:
        virtual void executer() const = 0;
};