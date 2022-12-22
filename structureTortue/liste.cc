#include "liste.hh"


void liste::executer(){
    for(auto const & instruc : _instructions)
        instruc->executer();
    
    _instructions.clear();
}

bool liste::ajouterInstruction(instructionPtr i){
    std::cout<<"ajout...";
    _instructions.push_back(i);
    std::cout << " ajouté !" << std::endl;
    return true;
}

void conditionnelle::executer() const {
    if (_condition)
        _then->executer();
    else 
        _else->executer();
}

std::shared_ptr<conditionnelle> findID(std::shared_ptr<liste> l, unsigned int id){
    for(auto const & inst : l->instructions()){
        auto isCond = std::dynamic_pointer_cast<conditionnelle>(inst);
        if(isCond){
            if(isCond->id() == id) return isCond;
            else {
                auto foundthen(findID(isCond->listethen(), id));
                if (foundthen) return foundthen;
                auto foundelse(findID(isCond->listeelse(), id));
                if (foundelse) return foundelse;
                return nullptr;
            }
        }
    }
    return nullptr;
}

void ajoutInstructionDansConditionnelle(listePtr l, unsigned int id, instructionPtr const & i) {
    auto cond(findID(l, id));
    if (cond->mettredanselse()) {
        cond->ajouterInstructionElse(i);
        std::cout << "ajout dans le else de la conditionelle active." << std::endl;
    }
    else {
        cond->ajouterInstructionThen(i);
        std::cout << "ajout dans le then de la conditionelle active." << std::endl;
    }
}

void tantque::executer() const {
    while(_condition)
        _then->executer();
}
void repete::executer() const {
    for(unsigned int i(0); i<_nombreDeFois; i++)
        _then->executer();
}