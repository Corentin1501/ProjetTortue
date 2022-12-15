#include "conditionnelle.hh"


Conditionelle::Conditionelle(bool cond, ListePtr th, ListePtr el)
    : _condition(cond), _then(th), _else(el)   {}


void Conditionelle::executer(){
    if (_condition)_then.executer();
    else _else.executer();
}