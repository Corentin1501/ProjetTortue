#pragma once
#include "../parser/driver.hh"
#include "jardinRendering.hh"

#include <string>
#include <memory>



//###################################################################
//#                         INSTRUCTION                             #
//###################################################################

    class Instruction {
        public:
            Instruction(JardinRendering * j): jardin(j) {}

            virtual void executer() const = 0;
        //private:    
            JardinRendering * jardin;
    };


//###################################################################
//#                      AVANCER ET RECULER                         #
//###################################################################

    enum class direction { avant, arriere };
    class Mouvement : public Instruction {
        public:
            Mouvement(JardinRendering * jard, int num, int nb, direction dir): Instruction(jard), numeroTortue(num), nombreDeFois(nb), _dir(dir) {}
            ~Mouvement() = default;

            void executer() const override;

        private:
            int numeroTortue;
            int nombreDeFois;
            direction _dir;
    };

//###################################################################
//#                           TOURNER                               #
//###################################################################

    enum class sens { gauche, droite };
    class Tourner : public Instruction {
        public:
            Tourner(JardinRendering * jard, sens s, int nb): Instruction(jard), _sens(s), nombreDeFois(nb) {}
            ~Tourner() = default;

            void executer() const override;

        private:
            int numeroTortue;
            sens _sens;
            int nombreDeFois;
    };
