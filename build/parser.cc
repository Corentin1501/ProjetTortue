// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 26 "../parser/parser.yy"

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
    unsigned int compteurWhile = 0 ;
    unsigned int compteurRepete = 0 ;

#line 64 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 156 "parser.cc"

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_operation: // operation
        value.copy< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_position: // position
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_position: // position
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.YY_MOVE_OR_COPY< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_position: // position
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_position: // position
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.copy< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_condition: // condition
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_position: // position
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_condition: // condition
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.move< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_position: // position
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_operation: // operation
        yylhs.value.emplace< ExpressionPtr > ();
        break;

      case symbol_kind::S_condition: // condition
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_position: // position
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 5: // $@1: %empty
#line 91 "../parser/parser.yy"
                           {
        std::string chaineNumero = yystack_[1].value.as < std::string > ().substr(1);
        int num = std::stoi(chaineNumero);
        std::cout << "num detecte : " << num << std::endl;
    }
#line 770 "parser.cc"
    break;

  case 7: // programme: END NL
#line 97 "../parser/parser.yy"
             {  
        listeglobale->executer(); 
        compteurConditionnelles = 0 ;
        YYACCEPT;   
    }
#line 780 "parser.cc"
    break;

  case 12: // deplacement: AVANCE
#line 110 "../parser/parser.yy"
           {                
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
#line 796 "parser.cc"
    break;

  case 13: // deplacement: AVANCE NUMBER
#line 121 "../parser/parser.yy"
                    {       
        auto m(std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::avant));
        if(compteurConditionnelles == 0) listeglobale->ajouterInstruction(m); 
        else ajoutInstructionDansConditionnelle(listeglobale, compteurConditionnelles, m);
    }
#line 806 "parser.cc"
    break;

  case 14: // deplacement: AVANCE expression
#line 126 "../parser/parser.yy"
                        {   listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::avant )); }
#line 812 "parser.cc"
    break;

  case 15: // deplacement: RECULE
#line 128 "../parser/parser.yy"
             {              listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, 1, direction::arriere));     }
#line 818 "parser.cc"
    break;

  case 16: // deplacement: RECULE NUMBER
#line 129 "../parser/parser.yy"
                    {       listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::arriere));    }
#line 824 "parser.cc"
    break;

  case 17: // deplacement: RECULE expression
#line 130 "../parser/parser.yy"
                        {   listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::arriere));    }
#line 830 "parser.cc"
    break;

  case 18: // deplacement: SAUTE
#line 132 "../parser/parser.yy"
            {            listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, 2, direction::avant));      }
#line 836 "parser.cc"
    break;

  case 19: // deplacement: SAUTE NUMBER
#line 133 "../parser/parser.yy"
                   {     listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, (2*yystack_[0].value.as < int > ()), direction::avant)); }
#line 842 "parser.cc"
    break;

  case 20: // deplacement: SAUTE expression
#line 134 "../parser/parser.yy"
                       { listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, (2*yystack_[0].value.as < int > ()), direction::avant)); }
#line 848 "parser.cc"
    break;

  case 21: // deplacement: TOURNED
#line 136 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, 1,  sens::droite));    }
#line 854 "parser.cc"
    break;

  case 22: // deplacement: TOURNED NUMBER
#line 137 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, yystack_[0].value.as < int > (), sens::droite));    }
#line 860 "parser.cc"
    break;

  case 23: // deplacement: TOURNEG
#line 138 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, 1,  sens::gauche));    }
#line 866 "parser.cc"
    break;

  case 24: // deplacement: TOURNEG NUMBER
#line 139 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, yystack_[0].value.as < int > (), sens::gauche));    }
#line 872 "parser.cc"
    break;

  case 25: // position: DEVANT
#line 144 "../parser/parser.yy"
           {    yylhs.value.as < std::string > () = "devant";   }
#line 878 "parser.cc"
    break;

  case 26: // position: DERRIERE
#line 145 "../parser/parser.yy"
               {  yylhs.value.as < std::string > () = "derrière"; }
#line 884 "parser.cc"
    break;

  case 27: // position: DROITE
#line 146 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à droite"; }
#line 890 "parser.cc"
    break;

  case 28: // position: GAUCHE
#line 147 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à gauche"; }
#line 896 "parser.cc"
    break;

  case 29: // condition: MUR position
#line 150 "../parser/parser.yy"
                 {          yylhs.value.as < bool > () = (driver.estMurIci(yystack_[0].value.as < std::string > () ,0))? true : false;   }
#line 902 "parser.cc"
    break;

  case 30: // condition: NOT MUR position
#line 151 "../parser/parser.yy"
                       {    yylhs.value.as < bool > () = (!driver.estMurIci(yystack_[0].value.as < std::string > () ,0))? true : false;  }
#line 908 "parser.cc"
    break;

  case 31: // conditionelle: SI condition THEN finDeLigne
#line 154 "../parser/parser.yy"
                                 {
        listeglobale->ajouterInstruction(   std::make_shared<conditionnelle>(driver.getJardin(), 0, ++compteurConditionnelles, yystack_[2].value.as < bool > ())   );
    }
#line 916 "parser.cc"
    break;

  case 32: // conditionelle: SINON THEN finDeLigne
#line 157 "../parser/parser.yy"
                            {
        std::shared_ptr<conditionnelle> condit = findID(listeglobale, compteurConditionnelles);
        condit->changement_then_else();
    }
#line 925 "parser.cc"
    break;

  case 33: // conditionelle: ENDIF finDeLigne
#line 161 "../parser/parser.yy"
                       {
        compteurConditionnelles--;
    }
#line 933 "parser.cc"
    break;

  case 34: // boucle: WHILE condition THEN finDeLigne
#line 168 "../parser/parser.yy"
                                    {
        listeglobale->ajouterInstruction( std::make_shared<tantque>(driver.getJardin(), 0, ++compteurWhile, yystack_[2].value.as < bool > ()));
    }
#line 941 "parser.cc"
    break;

  case 35: // boucle: ENDWHILE finDeLigne
#line 171 "../parser/parser.yy"
                          {
        --compteurWhile;
    }
#line 949 "parser.cc"
    break;

  case 36: // boucle: REPETE NUMBER THEN finDeLigne
#line 174 "../parser/parser.yy"
                                    {
        listeglobale->ajouterInstruction( std::make_shared<repete>(driver.getJardin(), 0, ++compteurRepete, yystack_[2].value.as < int > ()));
    }
#line 957 "parser.cc"
    break;

  case 37: // boucle: ENDREPETE finDeLigne
#line 177 "../parser/parser.yy"
                           {
        --compteurRepete;
    }
#line 965 "parser.cc"
    break;

  case 38: // expression: operation
#line 186 "../parser/parser.yy"
              {
        try{
            yylhs.value.as < int > () = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
#line 977 "parser.cc"
    break;

  case 39: // operation: NUMBER
#line 195 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 985 "parser.cc"
    break;

  case 40: // operation: '(' operation ')'
#line 198 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 993 "parser.cc"
    break;

  case 41: // operation: operation '+' operation
#line 201 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 1001 "parser.cc"
    break;

  case 42: // operation: operation '-' operation
#line 204 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 1009 "parser.cc"
    break;

  case 43: // operation: operation '*' operation
#line 207 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 1017 "parser.cc"
    break;

  case 44: // operation: operation '/' operation
#line 210 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 1025 "parser.cc"
    break;

  case 45: // operation: '-' operation
#line 213 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 1033 "parser.cc"
    break;


#line 1037 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char  Parser ::yypact_ninf_ = -24;

  const signed char  Parser ::yytable_ninf_ = -20;

  const signed char
   Parser ::yypact_[] =
  {
      10,    -2,    16,    18,    20,   -23,   -21,    -9,     0,    66,
      -9,    66,    11,    66,    66,    30,    66,    10,    10,   -24,
      70,    31,    31,   -24,    32,    74,   -24,    78,   -24,   -24,
     -24,    43,    36,    39,    66,   -24,    67,    71,   -24,    65,
     -24,    69,   -24,   -24,   -24,    10,   -24,   -24,   -24,   -24,
       3,    31,    31,    31,    31,   -24,   -24,   -24,   -24,   -24,
      43,    66,   -24,   -24,   -24,    66,    66,    10,   -24,   -24,
     -15,   -15,   -24,   -24,   -24,   -24,   -24,   -24,   -24
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     0,    12,    15,    18,    21,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
      39,     0,     0,    14,    38,    39,    17,    39,    20,    22,
      24,     0,     0,     0,     0,     8,     0,    10,    33,     0,
      35,     0,    37,     5,     1,     0,     3,     4,    39,    45,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
       0,     0,    32,     9,    11,     0,     0,     0,     2,    40,
      42,    41,    43,    44,    30,    31,    34,    36,     6
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -24,   -10,   -24,   -11,   -24,    27,    79,   -24,   -24,    82,
     -12
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,    15,    67,    38,    16,    59,    33,    17,    18,    23,
      24
  };

  const signed char
   Parser ::yytable_[] =
  {
      40,    19,    42,    43,    29,    45,    30,    46,    47,    49,
      50,    31,    32,    34,     1,    53,    54,     2,     3,     4,
       5,     6,     7,    62,     8,     9,    10,    11,    12,    13,
      44,    51,    52,    53,    54,    68,    14,    69,    41,    70,
      71,    72,    73,    20,    21,    25,    21,    27,    21,    22,
      75,    22,    61,    22,    76,    77,    60,    78,    48,    21,
      51,    52,    53,    54,    22,    55,    56,    57,    58,    35,
      63,    36,    37,   -13,    64,   -13,   -13,   -16,    65,   -16,
     -16,   -19,    66,   -19,   -19,    26,    28,    74,     0,    39
  };

  const signed char
   Parser ::yycheck_[] =
  {
      11,     3,    13,    14,    27,    16,    27,    17,    18,    21,
      22,    20,    21,    13,     4,    30,    31,     7,     8,     9,
      10,    11,    12,    34,    14,    15,    16,    17,    18,    19,
       0,    28,    29,    30,    31,    45,    26,    34,    27,    51,
      52,    53,    54,    27,    28,    27,    28,    27,    28,    33,
      61,    33,    13,    33,    65,    66,    20,    67,    27,    28,
      28,    29,    30,    31,    33,    22,    23,    24,    25,     3,
       3,     5,     6,     3,     3,     5,     6,     3,    13,     5,
       6,     3,    13,     5,     6,     3,     4,    60,    -1,    10
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     4,     7,     8,     9,    10,    11,    12,    14,    15,
      16,    17,    18,    19,    26,    36,    39,    42,    43,     3,
      27,    28,    33,    44,    45,    27,    44,    27,    44,    27,
      27,    20,    21,    41,    13,     3,     5,     6,    38,    41,
      38,    27,    38,    38,     0,    38,    36,    36,    27,    45,
      45,    28,    29,    30,    31,    22,    23,    24,    25,    40,
      20,    13,    38,     3,     3,    13,    13,    37,    36,    34,
      45,    45,    45,    45,    40,    38,    38,    38,    36
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    35,    36,    36,    36,    37,    36,    36,    38,    38,
      38,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    42,    43,    43,    43,    43,    44,    45,
      45,    45,    45,    45,    45,    45
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     3,     2,     2,     0,     4,     2,     1,     2,
       1,     2,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     2,
       3,     4,     3,     2,     4,     2,     4,     2,     1,     1,
       3,     3,     3,     3,     3,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END", "FOIS",
  "COMMENTAIRE", "AVANCE", "RECULE", "SAUTE", "TOURNED", "TOURNEG", "SI",
  "THEN", "SINON", "ENDIF", "WHILE", "ENDWHILE", "REPETE", "ENDREPETE",
  "MUR", "NOT", "DEVANT", "DERRIERE", "DROITE", "GAUCHE", "NUMTORTUE",
  "NUMBER", "'-'", "'+'", "'*'", "'/'", "NEG", "'('", "')'", "$accept",
  "programme", "$@1", "finDeLigne", "deplacement", "position", "condition",
  "conditionelle", "boucle", "expression", "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    88,    88,    89,    90,    91,    91,    97,   105,   105,
     105,   105,   110,   121,   126,   128,   129,   130,   132,   133,
     134,   136,   137,   138,   139,   144,   145,   146,   147,   150,
     151,   154,   157,   161,   168,   171,   174,   177,   186,   195,
     198,   201,   204,   207,   210,   213
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    30,    29,     2,    28,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    32
    };
    // Last valid token kind.
    const int code_max = 283;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1438 "parser.cc"

#line 217 "../parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
