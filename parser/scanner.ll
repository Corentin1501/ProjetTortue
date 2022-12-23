%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%

%{
    yylval = lval;
%}

fin return token::END;
"fois"      return token::FOIS;     
--(.)* return token::COMMENTAIRE;
"\n"          {
    loc->lines();
    return token::NL;
}

"avance"    return token::AVANCE;
"recule"    return token::RECULE;
"saute"     return token::SAUTE;

"tourne à droite"   return token::TOURNED;
"tourne à gauche"   return token::TOURNEG;

"si"            return token::SI;
"fin si"        return token::ENDIF;
":"             return token::THEN;
"sinon :"       return token::SINON;

"mur"           return token::MUR;
"pas de"|"pas"  return token::NOT;
"vide"          return token::VIDE;

"devant"    return token::DEVANT;
"derriere"  return token::DERRIERE;
"à droite"  return token::DROITE;
"à gauche"  return token::GAUCHE;

"tant que"      return token::WHILE;
"fin tant que"  return token::ENDWHILE;

"repete"        return token::REPETE;
"fin repete"    return token::ENDREPETE;

"couleur"|"couleur carapace" return token::COULEUR; 
"couleur motif" return token::COULEURMOTIF; 
#[a-zA-Z0-9]{6} {
    yylval->build<std::string>(yytext);
    return token::HEXCODE;
}

@[0-9]+      {
    yylval->build<std::string>(yytext);
    return token::NUMTORTUE;
}
"tortues" return token::TORTUES;

"jardin"    return token::JARDIN;
'[\S]*' {
    yylval->build<std::string>(yytext);
    return token::FILE;
}

"fonction" return token::FONCTION;
"fin fonction" return token::ENDFONCTION;

[a-zA-Z]{2,} {
    yylval->build<std::string>(yytext);
    return token::NAME;
}
([0-9]+[ ]+)+ {
    yylval->build<std::string>(yytext);
    return token::ARGUMENTS;
}
(\$[0-9]+[ ]?)+ {
    yylval->build<std::string>(yytext);
    return token::NUMBERARG;
}


"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';

[0-9]+      {
    yylval->build<int>(std::atoi(yytext));
    return token::NUMBER;
}


%%
