#pragma once
#include "../parser/driver.hh"

#include <string>
#include <memory>


//###################################################################
//#                         INSTRUCTION                             #
//###################################################################

    class Instruction {
        public:
            virtual void executer() const = 0;
    };


//###################################################################
//#                           AVANCER                               #
//###################################################################

    class Avancer : public Instruction {
        public:
            Avancer(int num, int nb){
                std::make_shared<Avancer>(num,nb);
            } 
            ~Avancer() = default;

            void executer() const override;

        private:
            int numeroTortue;
            int nombreDeFois;
    };
    using AvancerPtr = std::shared_ptr<Avancer>;

//###################################################################
//#                           RECULER                               #
//###################################################################

    class Reculer : public Avancer {
        public:
            void executer() const override;
    };

//###################################################################
//#                           TOURNER                               #
//###################################################################

    enum class sens { gauche, droite };
    class Tourner : public Instruction {
        public:
            Tourner(sens s, int nb): _sens(s), nombreDeFois(nb) {}
            ~Tourner() = default;

            void executer() const override;

        private:
            int numeroTortue;
            sens _sens;
            int nombreDeFois;
    };
