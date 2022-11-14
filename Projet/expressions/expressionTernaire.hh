#pragma once
#include "expression.hh"

enum class OperateurTernaire {
    ifthenelse
};

class ExpressionTernaire : public Expression {
public:
    ExpressionTernaire(const ExpressionTernaire &) = default;
    ExpressionTernaire(ExpressionPtr condition, ExpressionPtr exp1, ExpressionPtr exp2, OperateurTernaire op);
    ~ExpressionTernaire() = default;

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _condition;
    ExpressionPtr _exp1;
    ExpressionPtr _exp2;
    OperateurTernaire _op;
};
