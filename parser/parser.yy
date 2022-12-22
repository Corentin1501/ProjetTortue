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
%token                  COMMENTAIRE

%token                  AVANCE
%token                  RECULE
%token                  SAUTE
%token                  TOURNED
%token                  TOURNEG


%token<std::string>     NUMTORTUE

%token <int>            NUMBER

%type <ExpressionPtr>   operation
%type <int>             expression
%type <int>             numeroDeTortue
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:

    deplacement finDeLigne      programme
    
    | END NL {  YYACCEPT;   }
    
numeroDeTortue:
    NUMTORTUE {  $$ = std::stoi($1.substr(1));   }

finDeLigne:
    NL | FOIS NL | COMMENTAIRE | COMMENTAIRE NL

/*####################### FONCTION DE DEPLACEMENT #######################*/
deplacement:
    AVANCE {                driver.avancerTortue(0,1);                              } 
    | AVANCE NUMBER {       for (int i(0) ; i<$2; i++) driver.avancerTortue(0,1);   } 
    | AVANCE expression {   for (int i(0) ; i<$2; i++) driver.avancerTortue(0,1);   } 

    | RECULE {            driver.avancerTortue( 0, (-1) );        } 
    | RECULE NUMBER {     for (int i(0) ; i<$2; i++) driver.avancerTortue( 0, -1 );   } 
    | RECULE expression { for (int i(0) ; i<$2; i++) driver.avancerTortue( 0, -1 );   } 

    | SAUTE {            driver.avancerTortue(0,2);      } 
    | SAUTE NUMBER {     for (int i(0) ; i<$2; i++) driver.avancerTortue(0,2);   } 
    | SAUTE expression { for (int i(0) ; i<$2; i++) driver.avancerTortue(0,2);   } 

    | TOURNED         {   driver.changerOrientationTortue(0, "droite");    } 
    | TOURNED NUMBER  {   for (int i(0) ; i<$2; i++) driver.changerOrientationTortue(0, "droite");   } 
    | TOURNEG         {   driver.changerOrientationTortue(0, "gauche");    } 
    | TOURNEG NUMBER  {   for (int i(0) ; i<$2; i++) driver.changerOrientationTortue(0, "gauche");   } 


/*####################### EXPRESSION ARITHMETIQUE #######################*/
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
