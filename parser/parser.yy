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
    #include <list>
    
    #include "scanner.hh"
    #include "driver.hh"
    #include "structureTortue/instruction.hh"
    #include "structureTortue/liste.hh"

    #undef  yylex
    #define yylex scanner.yylex
    
    std::list< boucleEtConditionnellePtr > file;
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
%token                  ENDWHILE

%token                  REPETE
%token                  ENDREPETE

%token                  MUR
%token                  NOT
%token                  VIDE

%token                  DEVANT
%token                  DERRIERE
%token                  DROITE
%token                  GAUCHE

%token <std::string>    NUMTORTUE

%token                  COULEUR
%token                  COULEURMOTIF
%token <std::string>    HEXCODE

%token <int>            NUMBER

%type <ExpressionPtr>   operation
%type <int>             expression
%type <int>             numeroDeTortue
%type <int>             numeroOuRien
%type <std::string>     position
%type <bool>            condition
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:

      deplacement       programme
    | conditionelle     programme
    | boucle            programme
    | finDeLigne        programme
    | color finDeLigne programme

    | END NL {  
        listeglobale->executer(); 
        listeglobale->vider();
        YYACCEPT;   
    }


numeroDeTortue:
    NUMTORTUE {  $$ = std::stoi($1.substr(1));   }

finDeLigne:
    NL | FOIS NL | COMMENTAIRE | COMMENTAIRE NL

/*####################### FONCTION DE DEPLACEMENT #######################*/

numeroOuRien:
    finDeLigne { $$ = 0; }
    | numeroDeTortue finDeLigne { $$ = $1; }


deplacement:
    avancer
    | reculer
    | sauter
    | tourner

avancer:
    AVANCE numeroOuRien{                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), $2, 1, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), $2, 1, direction::avant));
    } 
    | AVANCE expression numeroOuRien{ 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), $3, $2, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), $3, $2, direction::avant));  
    }
reculer:
    RECULE numeroOuRien{                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), $2, 1, direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), $2, 1, direction::arriere));
    } 
    | RECULE expression numeroOuRien{ 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), $3, $2, direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), $3, $2, direction::arriere));  
    }
sauter:
    SAUTE numeroOuRien{                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), $2, 2, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), $2, 2, direction::avant));
    } 
    | SAUTE expression numeroOuRien{ 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), $3, 2*$2, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), $3, 2*$2, direction::avant));  
    }
tourner:
    TOURNED numeroOuRien{
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), $2, 1,  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), $2, 1,  sens::droite));
    }
    | TOURNED expression numeroOuRien{  
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), $3, $2,  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), $3, $2,  sens::droite));
    } 
    | TOURNEG numeroOuRien{
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), $2, 1,  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), $2, 1,  sens::gauche));
    }
    | TOURNEG expression numeroOuRien{
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), $3, $2,  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), $3, $2,  sens::gauche));
    }

/*####################### INSTRUCTIONS SPECIALES #######################*/

position:
    DEVANT {    $$ = "devant";   } 
    | DERRIERE {  $$ = "derrière"; } 
    | DROITE {    $$ = "à droite"; } 
    | GAUCHE {    $$ = "à gauche"; } 

condition:
    MUR {          $$ = true;   } 
    | NOT MUR {    $$ = false;  }
    | VIDE {       $$ = false;  }
    | NOT VIDE {   $$ = true;   }

conditionelle:
    SI condition position THEN numeroOuRien {
        auto instptr = std::make_shared<conditionnelle>(driver.getJardin(), 0, $2, $3, $5);
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
    | SINON finDeLigne {    file.front()->changement_then_else();   }
    | ENDIF finDeLigne {    file.pop_front();                       }

/*####################### BOUCLES #######################*/

boucle:
    WHILE condition position THEN numeroOuRien {
        auto instptr = std::make_shared<tantque>(driver.getJardin(), 0, $2, $3, $5);
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
    | ENDWHILE finDeLigne {
        file.pop_front();
    }


    | REPETE expression THEN finDeLigne {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, $2);
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
    | REPETE expression FOIS THEN finDeLigne {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, $2);
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
    | ENDREPETE finDeLigne {
        file.pop_front();
    }

color:
    COULEUR HEXCODE {                   std::array<int, 3> n = convert($2);     driver.changeCouleurCarapace(0,  n[0], n[1], n[2]);     }
    | COULEUR HEXCODE numeroDeTortue {  std::array<int, 3> n = convert($2);     driver.changeCouleurCarapace($3, n[0], n[1], n[2]);     }
    | COULEURMOTIF HEXCODE {                   std::array<int, 3> n = convert($2);     driver.changeCouleurMotif(0,  n[0], n[1], n[2]);     }
    | COULEURMOTIF HEXCODE numeroDeTortue{     std::array<int, 3> n = convert($2);     driver.changeCouleurMotif($3, n[0], n[1], n[2]);     }



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
