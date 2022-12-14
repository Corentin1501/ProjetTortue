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
    bool cond = false;
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

%token <std::string>    NUMTORTUE
%token <int>            NUMBER
%token                  COULEUR
%token <std::string>    HEXCODE
%type <int>             numeroTortue

%type <ExpressionPtr>   operation
%type <int>             expression
%type <std::string>     position
%type <bool>            condition
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:

    deplacement finDeLigne      programme
    | color programme
    | conditionelle  programme
    | numeroTortue programme
    
    | END NL {  YYACCEPT;   }


finDeLigne:
    NL | FOIS NL | COMMENTAIRE | COMMENTAIRE NL

numeroTortue:
    NUMTORTUE finDeLigne {  $$ = std::stoi($1.substr(1));    }

/*####################### COULEUR TORTUE #######################*/

color: 
    COULEUR NUMBER NUMBER NUMBER {    driver.changerCouleurCarapace(0, $2, $3, $4);   }
    |    COULEUR NUMBER NUMBER NUMBER numeroTortue {  driver.changerCouleurCarapace($5, $2, $3, $4);  }


/*####################### FONCTION DE DEPLACEMENT #######################*/

deplacement:
    AVANCE {                 driver.avancerTortue(0,1);                              } 
    | AVANCE NUMBER {
                for (int i(0) ; i<$2; i++) driver.avancerTortue(0,1);   } 
    | AVANCE expression {    for (int i(0) ; i<$2; i++) driver.avancerTortue(0,1);   } 

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

/*####################### CONDITIONELLE #######################*/

position:
    DEVANT {    $$ = "devant";   } 
    | DERRIERE {  $$ = "derri??re"; } 
    | DROITE {    $$ = "?? droite"; } 
    | GAUCHE {    $$ = "?? gauche"; } 

condition:
    MUR position {  $$ =    driver.estMurIci($2 ,0);    }
    | NOT MUR position {   $$ =    !driver.estMurIci($2 ,0);    }

    /*

    I -> instruction
        | SI condition THEN I
        | SI condition THEN C SINON I
    C -> instruction
        | SI condition THEN C SINON C

     */
conditionelle:
    deplacement finDeLigne conditionelle
    | SI condition THEN finDeLigne conditionelle
    | SI condition THEN finDeLigne conditionelleComplete finDeLigne SINON finDeLigne conditionelle

    /* | condition {   std::cout << $1 << std::endl;   }  */

conditionelleComplete:
    deplacement finDeLigne conditionelleComplete
    | SI condition THEN finDeLigne conditionelleComplete SINON finDeLigne conditionelleComplete {}

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
