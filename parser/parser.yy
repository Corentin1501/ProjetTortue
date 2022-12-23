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
    #include <exception>
    #include <cstdlib>
    #include <algorithm>

    
    #include "scanner.hh"
    #include "driver.hh"
    #include "structureTortue/instruction.hh"
    #include "structureTortue/liste.hh"

    #undef  yylex
    #define yylex scanner.yylex
    
    std::list< boucleEtConditionnellePtr > file;
    listePtr listeglobale = liste::fabrique();
    std::list<fonctionPtr> listefonction;

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
%token                  TORTUES

%token                  JARDIN
%token <std::string>    FILE

%token                  FONCTION
%token                  ENDFONCTION
%token <std::string>    NAME
%token <std::string>    ARGUMENTS
%token <std::string>    NUMBERARG

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

%type <std::vector<int>> argumentsOuRien

%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:

      deplacement       programme
    | conditionelle     programme
    | boucle            programme
    | finDeLigne        programme
    | color finDeLigne  programme
    | tortues           programme
    | jardin            programme
    | fonction          programme

    | END NL {  
        listeglobale->executer(); 
        listeglobale->vider();
        YYACCEPT;   
    }
tortues:
    TORTUES NUMBER finDeLigne {
        QSize tailleDuJardin = driver.getJardin()->tailleJardin();

        for(int i(0); i<$2; i++){
            int x = rand() % tailleDuJardin.width();
            int y = rand() % tailleDuJardin.height();
            driver.getJardin()->newTortue(x,y);
        }
    }

jardin:
    JARDIN FILE finDeLigne {
        std::string s = $2.substr(1);
        std::string fichier = s.substr(0,s.size()-1);
        try {
            driver.getJardin()->construction(fichier.c_str());
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

    }

numeroDeTortue:
    NUMTORTUE {  $$ = std::stoi($1.substr(1));   }

finDeLigne:
    NL | FOIS NL | COMMENTAIRE | COMMENTAIRE NL

/*####################### FONCTION DE DEPLACEMENT #######################*/

numeroOuRien:
    // Si on ne précise pas de numéro : 
    // appliquer à toutes les tortues (grace au nuémro 66) 
    // (je suppose qu'il n'y aura pas 66 tortues en meme temps)
    finDeLigne { $$ = 66; }
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

/*####################### FONCTIONS #######################*/


argumentsOuRien:
    ARGUMENTS {
        std::vector<std::string> chainearguments = split($1," ");
        std::vector<int> arguments;
        for(auto chaine : chainearguments) arguments.push_back( std::stoi(chaine) );
        $$ = arguments;
    }
    | finDeLigne { $$ = {0};}

fonction:
    FONCTION NAME THEN finDeLigne {
        std::string nom = $2;
        auto found = std::find_if(listefonction.begin(), listefonction.end(), [nom](auto i){ return i->nom() == nom; });

        // s'il n'y a pas déjà de fonction avec le même nom, on ajoute
        if (found == listefonction.end()) listefonction.push_front( std::make_shared<fonction>($2) ); 
        else std::cout << "fonction déjà déclarée" << std::endl;
    }
    | NAME argumentsOuRien {
        auto it (listefonction.begin());
        while (it != listefonction.end() || (*it)->nom() != $1) it++;
        if (it != listefonction.end()){
            for(auto i : $2) std::cout << i << std::endl;

            (*it)->setArguments($2);
            (*it)->executer();
        }
    }
    | ENDFONCTION finDeLigne {
        listefonction.front()->completer();
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
