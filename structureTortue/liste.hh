#pragma once
#include "instruction.hh"
#include <vector>
#include <memory>
#include <algorithm>

//###################################################################
//#                            LISTE                                #
//###################################################################

class conditionnelle;
class liste {
    private:
        std::vector<instructionPtr> _instructions;
        liste() = default;

    public:
        static std::shared_ptr<liste> fabrique() { return std::shared_ptr<liste>(new liste()); }
        void executer() const;

        bool ajouterInstruction(instructionPtr i);
        std::vector<instructionPtr> instructions() const { return _instructions; }

        void vider() { _instructions.clear(); }



};

using listePtr = std::shared_ptr<liste>;

//###################################################################
//#                  BOUCLES ET CONDITIONNELLES                     #
//###################################################################

class boucleEtConditionnelle : public instruction {
    public:
        boucleEtConditionnelle(JardinRendering * jard, int num): instruction(jard, num) {}
        virtual void ajouterInstruction(instructionPtr i) =0;
        void executer() const override {}

        virtual void changement_then_else() {}
        bool estMurIci(std::string direction, unsigned int tortue) const ;

        virtual std::string tostring() const =0;
};

using boucleEtConditionnellePtr = std::shared_ptr<boucleEtConditionnelle>;

//###################################################################
//#                        CONDITIONNELLE                           #
//###################################################################

class conditionnelle : public boucleEtConditionnelle{
    private:
        bool _danselse;
        bool _condition;
        std::string _position;
        unsigned int _emplacement;
        listePtr _then;
        listePtr _else;
    public:
        conditionnelle(JardinRendering * jard, int num, bool cond, std::string pos, unsigned int emp): 
            boucleEtConditionnelle(jard, num), 
            _danselse(false), 
            _condition(cond), 
            _position(pos), 
            _emplacement(emp), 
            _then(liste::fabrique()), 
            _else(liste::fabrique()) {}

        void ajouterInstructionThen(instructionPtr i){ _then->ajouterInstruction(i); }
        void ajouterInstructionElse(instructionPtr i){ _else->ajouterInstruction(i); }
        void ajouterInstruction(instructionPtr i) override;

        void executer() const override;

        std::string tostring() const override { return "Conditionnelle :\n\tcond : " + std::to_string(_condition) + "\telse : " + std::to_string(_danselse); }
        bool mettredanselse() const { return _danselse; }
        void changement_then_else() override { _danselse = true; }
        listePtr listethen() const { return _then; }
        listePtr listeelse() const { return _else; }
};




//###################################################################
//#                            WHILE                                #
//###################################################################

class tantque : public boucleEtConditionnelle {
    private:
        bool _condition;
        std::string _position;
        unsigned int _emplacement;
        listePtr _then;
    public:
        tantque(JardinRendering * jard, int num, bool cond, std::string pos, unsigned int emp):
            boucleEtConditionnelle(jard, num), 
            _condition(cond), 
            _position(pos), 
            _emplacement(emp), 
            _then(liste::fabrique()){}

        void ajouterInstruction(instructionPtr i){ _then->ajouterInstruction(i); }
        void executer() const override;
        std::string tostring() const override { return "While :\n\tcond : " + std::to_string(_condition); }
};

//###################################################################
//#                            REPETE                               #
//###################################################################

class repete : public boucleEtConditionnelle {
    private:
        unsigned int _nombreDeFois;
        listePtr _then;
    public:
        repete(JardinRendering * jard, int num, unsigned int nb):
            boucleEtConditionnelle(jard, num), _nombreDeFois(nb), _then(liste::fabrique()) {}

        void ajouterInstruction(instructionPtr i){ _then->ajouterInstruction(i); }
        void executer() const override;
        std::string tostring() const override { return "Repete :\n\tnombre de fois : " + std::to_string(_nombreDeFois); }
};

//###################################################################
//#                           FONCTION                              #
//###################################################################

class fonction {
    private:
        std::string _nomFonction;
        std::vector<int> _arguments;
        listePtr _contenu;
        bool _complete;

    public:
        fonction(std::string name): _nomFonction(name), _contenu(liste::fabrique()), _complete(false) {}

        void ajouterInstruction(instructionPtr i){ _contenu->ajouterInstruction(i); }
        void executer() const ; 


        std::string nom() const { return _nomFonction; }
        void setArguments(std::vector<int> args) { _arguments = args; }
        void completer() { _complete = true; }
};

using fonctionPtr = std::shared_ptr<fonction>;

std::vector<std::string> split(std::string s, std::string delimiter);







