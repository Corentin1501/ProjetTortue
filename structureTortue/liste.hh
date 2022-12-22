#pragma once
#include "instruction.hh"
#include <vector>
#include <memory>
#include <algorithm>


class conditionnelle;
class liste {
    private:
        std::vector<instructionPtr> _instructions;
        liste() = default;

    public:
        static std::shared_ptr<liste> fabrique() { return std::shared_ptr<liste>(new liste()); }
        void executer();

        bool ajouterInstruction(instructionPtr i);
        std::vector<instructionPtr> instructions() const { return _instructions; }



};

std::shared_ptr<conditionnelle> findID(std::shared_ptr<liste> l, unsigned int id);

using listePtr = std::shared_ptr<liste>;

class conditionnelle : public instruction{
    private:
        unsigned int _id;
        bool _danselse;
        bool _condition;
        listePtr _then;
        listePtr _else;
    public:
        conditionnelle(JardinRendering * jard, int num, unsigned int id, bool cond): instruction(jard, num), _id(id), _danselse(false), _condition(cond) {}
        void ajouterInstructionThen(instructionPtr i){ _then->ajouterInstruction(i); }
        void ajouterInstructionElse(instructionPtr i){ _else->ajouterInstruction(i); }

        void executer() const override;

        unsigned int id() const { return _id; }
        bool mettredanselse() const { return _danselse; }
        void changement_then_else() { _danselse = true; }
        listePtr listethen() const { return _then; }
        listePtr listeelse() const { return _else; }
};

void ajoutInstructionDansConditionnelle(listePtr l, unsigned int id, instructionPtr const & i);