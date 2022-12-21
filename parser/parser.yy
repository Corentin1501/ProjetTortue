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
    unsigned int compteurConditionnelles = 0 ;
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
        compteurConditionnelles = 0 ;
        YYACCEPT;   
    }


finDeLigne:
    NL | FOIS NL | COMMENTAIRE | COMMENTAIRE NL

/*####################### FONCTION DE DEPLACEMENT #######################*/

deplacement:
    AVANCE {                
        auto m(std::make_shared<mouvement>(driver.getJardin(), 0, 1, direction::avant));
        if(compteurConditionnelles == 0) {
            std::cout << "      pas de contionnelle active : ajout dans la liste globale." << std::endl;
            listeglobale->ajouterInstruction(m); 
        }
        else {
            std::cout << "      contionnelle actives, id actif : " << std::to_string(compteurConditionnelles) << std::endl;
            ajoutInstructionDansConditionnelle(listeglobale, compteurConditionnelles, m);
        }
    } 
    | AVANCE NUMBER {       
        auto m(std::make_shared<mouvement>(driver.getJardin(), 0, $2, direction::avant));
        if(compteurConditionnelles == 0) listeglobale->ajouterInstruction(m); 
        else ajoutInstructionDansConditionnelle(listeglobale, compteurConditionnelles, m);
    } 
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
    MUR position {          $$ = (driver.estMurIci($2 ,0))? true : false;   } 
    | NOT MUR position {    $$ = (!driver.estMurIci($3 ,0))? true : false;  }

conditionelle:
    SI condition THEN finDeLigne {
        listeglobale->ajouterInstruction(   std::make_shared<conditionnelle>(driver.getJardin(), 0, ++compteurConditionnelles, $2)   );
    }
    | SINON THEN finDeLigne {
        std::shared_ptr<conditionnelle> condit = findID(listeglobale, compteurConditionnelles);
        condit->changement_then_else();
    }
    | ENDIF finDeLigne {
        compteurConditionnelles--;
    }





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
