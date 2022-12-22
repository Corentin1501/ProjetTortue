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

    deplacement programme

    | numeroDeTortue {
        std::cout << "num : " << $1 << std::endl;
    } programme
    
    | END NL {  YYACCEPT;   }
    
numeroDeTortue:
    NUMTORTUE finDeLigne {  $$ = std::stoi($1.substr(1));   }
    | finDeLigne {  $$ = 0;   }

finDeLigne:
    NL | FOIS NL | COMMENTAIRE | COMMENTAIRE NL

/*####################### FONCTION DE DEPLACEMENT #######################*/
deplacement:
    avance
    
    | RECULE numeroDeTortue{            driver.avancerTortue( $2, (-1) );        } 
    | RECULE NUMBER numeroDeTortue{     for (int i(0) ; i<$2; i++) driver.avancerTortue( $3, -1 );   } 
    | RECULE expression numeroDeTortue{ for (int i(0) ; i<$2; i++) driver.avancerTortue( $3, -1 );   } 

    | SAUTE numeroDeTortue{            driver.avancerTortue($2,2);      } 
    | SAUTE NUMBER numeroDeTortue{     for (int i(0) ; i<$2; i++) driver.avancerTortue($3,2);   } 
    | SAUTE expression numeroDeTortue{ for (int i(0) ; i<$2; i++) driver.avancerTortue($3,2);   } 

    | TOURNED         numeroDeTortue{   driver.changerOrientationTortue($2, "droite");    } 
    | TOURNED NUMBER  numeroDeTortue{   for (int i(0) ; i<$2; i++) driver.changerOrientationTortue($3, "droite");   } 
    | TOURNEG         numeroDeTortue{   driver.changerOrientationTortue($2, "gauche");    } 
    | TOURNEG NUMBER  numeroDeTortue{   for (int i(0) ; i<$2; i++) driver.changerOrientationTortue($3, "gauche");   } 

avance:
    AVANCE numeroDeTortue{                driver.avancerTortue($2,1);                              } 
    | AVANCE NUMBER numeroDeTortue{       for (int i(0) ; i<$2; i++) driver.avancerTortue($3,1);   } 
    | AVANCE expression numeroDeTortue{   for (int i(0) ; i<$2; i++) driver.avancerTortue($3,1);   } 


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
