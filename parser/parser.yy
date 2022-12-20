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
    #include "structureTortue/instruction.hh"
    #include "structureTortue/liste.hh"

    #undef  yylex
    #define yylex scanner.yylex
    
    listePtr listeglobale = liste::fabrique();
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
    | conditionelle  programme
    | NUMTORTUE finDeLigne {
        std::string chaineNumero = $1.substr(1);
        int num = std::stoi(chaineNumero);
        std::cout << "num detecte : " << num << std::endl;
    } programme
    
    | END NL {  
        listeglobale->executer(); 
        YYACCEPT;   
    }


finDeLigne:
    NL | FOIS NL | COMMENTAIRE | COMMENTAIRE NL

/*####################### FONCTION DE DEPLACEMENT #######################*/
deplacement:
    AVANCE {                listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, 1, direction::avant  )); } 
    | AVANCE NUMBER {       listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, $2, direction::avant )); } 
    | AVANCE expression {   listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, $2, direction::avant )); } 

    | RECULE {              listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, 1, direction::arriere));     } 
    | RECULE NUMBER {       listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, $2, direction::arriere));    } 
    | RECULE expression {   listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, $2, direction::arriere));    } 

    | SAUTE {            listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, 2, direction::avant));      } 
    | SAUTE NUMBER {     listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, (2*$2), direction::avant)); } 
    | SAUTE expression { listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, (2*$2), direction::avant)); } 

    | TOURNED         {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, 1,  sens::droite));    } 
    | TOURNED NUMBER  {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, $2, sens::droite));    } 
    | TOURNEG         {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, 1,  sens::gauche));    } 
    | TOURNEG NUMBER  {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, $2, sens::gauche));    } 

/*####################### CONDITIONELLE #######################*/

position:
    DEVANT {    $$ = "devant";   } 
    | DERRIERE {  $$ = "derrière"; } 
    | DROITE {    $$ = "à droite"; } 
    | GAUCHE {    $$ = "à gauche"; } 

condition:
    MUR position {   
        if(driver.estMurIci($2 ,0)) $$ = true; 
        else $$ = false;
    } 
    | NOT MUR position {   
        if(!driver.estMurIci($3 ,0)) $$ = true;
        else $$ = false;
    }

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
    // index de listeglobale actuelle pour l'id de la conditionelle then
    // 
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
