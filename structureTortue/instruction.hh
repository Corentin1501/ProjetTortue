#pragma once
#include "../parser/driver.hh"
#include "jardinRendering.hh"


//###################################################################
//#                         INSTRUCTION                             #
//###################################################################

    class instruction {
        private:
            int _numTortue;

        public:
            JardinRendering * jardin;
            int numeroTortue() const { return _numTortue; }
            instruction(JardinRendering * jard, int num): _numTortue(num), jardin(jard)  {}
            virtual void executer() const = 0;

    };

//###################################################################
//#                          MOUVEMENT                              #
//###################################################################

    enum class direction { avant, arriere };

    class mouvement : public instruction {
        private:
            int _nombreDeFois;
            direction _dir;

        public:
            /**
             * @brief 
             * arguments :
             * Jardin, numero de Tortue, nombre de fois, direction
            */
            mouvement(JardinRendering * jard, int num, int nombre, direction direc): instruction(jard, num), _nombreDeFois(nombre), _dir(direc) {}
            void executer() const override;
    };

//###################################################################
//#                           TOURNER                               #
//###################################################################

    enum class sens { gauche, droite };

    class tourner : public instruction {
        private:
            int _nombreDeFois;
            sens _sens;

        public:
            /**
             * @brief 
             * arguments :
             * Jardin, numero de Tortue, nombre de fois, sens
            */
            tourner(JardinRendering * jard, int num, int nombre, sens se): instruction(jard, num), _nombreDeFois(nombre), _sens(se) {}
            void executer() const override;
    };


using instructionPtr = std::shared_ptr<instruction>;
    
