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

[--][.]* return token::COMMENTAIRE;

"avance"    return token::AVANCE;
"recule"    return token::RECULE;
"saute"     return token::SAUTE;

"tourne à droite"   return token::TOURNED;
"tourne à gauche"   return token::TOURNEG;

"si"        return token::SI;
"fin si"    return token::ENDIF;
":"         return token::THEN;
"sinon :"     return token::SINON;

"mur"       return token::MUR;
"pas de"    return token::NOT;

"tant que"  return token::WHILE;

"devant"    return token::DEVANT;
"derriere"  return token::DERRIERE;
"à droite"  return token::DROITE;
"à gauche"  return token::GAUCHE;

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

"\n"          {
    loc->lines();
    return token::NL;
}

%%
