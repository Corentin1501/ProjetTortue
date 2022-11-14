%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    
    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token                  FOIS

%token                  AVANCE
%token                  RECULE
%token                  SAUTE
%token                  TOURNED
%token                  TOURNEG

%token                  SI
%token                  THEN
%token                  SINON

%token                  MUR
%token                  NOT
%token                  POSITION

%token <int>            NUMBER

%token <std::string>    IDENT

%type <ExpressionPtr>             operation
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:

    AVANCE NL {             driver.avancerTortue(0,1);      } programme
    | AVANCE NUMBER NL {    
        for (int i(0) ; i<$2; i++)
            driver.avancerTortue(0,1); 
            
    }programme
    | AVANCE operation NL { 
        int calcul = $2->calculer(driver.getContexte());
        driver.avancerTortue(0,calcul);
    } programme

    | RECULE NL {           driver.avancerTortue( 0, (-1) );        } programme
    | RECULE NUMBER NL {    driver.avancerTortue( 0, ($2*(-1)) );   } programme
    | RECULE operation NL {
        int calcul = $2->calculer(driver.getContexte());
        driver.avancerTortue( 0, (calcul*(-1)) );
    } programme

    | SAUTE NL {             driver.avancerTortue(0,2);      } programme
    | SAUTE NUMBER NL {    driver.avancerTortue(0,2*$2);     }programme
    | SAUTE operation NL { 
        int calcul = $2->calculer(driver.getContexte());
        driver.avancerTortue(0,2*calcul);
    } programme



    | TOURNED NL        {   driver.changerOrientationTortue(0, "droite", 1);    } programme
    | TOURNED NUMBER NL {   driver.changerOrientationTortue(0, "droite", $2);   } programme
    | TOURNEG NL        {   driver.changerOrientationTortue(0, "gauche", 1);    } programme
    | TOURNEG NUMBER NL {   driver.changerOrientationTortue(0, "gauche", $2);   } programme

    | SI MUR POSITION THEN NL {

    } programme


    | instruction NL programme

    | END NL {
        YYACCEPT;
    }

instruction:
    expression  {
    }
    | affectation {
    }

expression:
    operation {
        //Modifier cette partie pour prendre en compte la structure avec expressions
        try{
        std::cout << "#-> " << $1->calculer(driver.getContexte()) << std::endl;
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }

affectation:
    IDENT '=' operation { 
        double val = $3->calculer(driver.getContexte());
        driver.setVariable($1,val);
    }

operation:
    NUMBER {
        $$ = std::make_shared<Constante>($1);
    }
    | IDENT {
        $$ = std::make_shared<Variable>($1);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::plus);
    }
    | operation '-' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::divise);
    }
    | '-' operation %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2,OperateurUnaire::neg);
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
