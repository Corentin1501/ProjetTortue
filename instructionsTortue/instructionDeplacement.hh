#pragma once
#include "instruction.hh"


class ExpressionUnaire : public Instruction {
public:
    Instruction();
    ~Instruction() = default;

    void executer() const override;

private:
    
};
