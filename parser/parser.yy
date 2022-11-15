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
    
    bool dansBlocIF = false;
    bool condition = false;
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
%token                  ENDIF

%token                  WHILE

%token                  MUR
%token                  NOT
%token                  DEVANT
%token                  DERRIERE
%token                  DROITE
%token                  GAUCHE

%token <int>            NUMBER

%type <ExpressionPtr>   operation
%type <int>             expression
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:

    AVANCE NL {             if((!dansBlocIF)||(dansBlocIF && condition)) driver.avancerTortue(0,1);      } programme
    | AVANCE NUMBER NL { 
        if((!dansBlocIF)||(dansBlocIF && condition)) {
            for (int i(0) ; i<$2; i++)
                driver.avancerTortue(0,1); 
        }   
            
    }programme
    | AVANCE expression NL { driver.avancerTortue(0,$2);    } programme

    | RECULE NL {            driver.avancerTortue( 0, (-1) );        } programme
    | RECULE NUMBER NL {     driver.avancerTortue( 0, ($2*(-1)) );   } programme
    | RECULE expression NL { driver.avancerTortue( 0, ($2*(-1)) );   } programme

    | SAUTE NL {            driver.avancerTortue(0,2);      } programme
    | SAUTE NUMBER NL {     driver.avancerTortue(0,2*$2);   } programme
    | SAUTE expression NL { driver.avancerTortue(0,2*$2);   } programme

    | TOURNED NL        {   driver.changerOrientationTortue(0, "droite", 1);    } programme
    | TOURNED NUMBER NL {   driver.changerOrientationTortue(0, "droite", $2);   } programme
    | TOURNEG NL        {   driver.changerOrientationTortue(0, "gauche", 1);    } programme
    | TOURNEG NUMBER NL {   driver.changerOrientationTortue(0, "gauche", $2);   } programme

    | MUR DEVANT NL {
        if(driver.estMurIci("devant",0)) 
            std::cout << "mur detecte" << std::endl;
        else 
            std::cout << "mur non detecte" << std::endl;
    } programme
    | SINON THEN NL {

    } programme
    | ENDIF NL {
        condition = false;
        dansBlocIF = false;
    } programme
    
    | END NL {
        YYACCEPT;
    }



expression:
    operation {
        try{
            $$ = $1->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }



operation:
    NUMBER {
        $$ = std::make_shared<Constante>($1);
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
