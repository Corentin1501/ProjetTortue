#pragma once
#include "listeInstructions.hh"
#include <vector>

class Conditionelle {
    public:
        Conditionelle(bool cond, ListeInstructions th, ListeInstructions el);
        ~Conditionelle() = default;
    
        void executer() const;

    private:
        bool _condition;
        ListeInstructions _then;
        ListeInstructions _else;
};