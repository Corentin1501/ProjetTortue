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

#line 62 "parser.cc"


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
#line 154 "parser.cc"

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
  case 4: // $@1: %empty
#line 84 "../parser/parser.yy"
                           {
        std::string chaineNumero = yystack_[1].value.as < std::string > ().substr(1);
        int num = std::stoi(chaineNumero);
        std::cout << "num detecte : " << num << std::endl;
    }
#line 768 "parser.cc"
    break;

  case 6: // programme: END NL
#line 90 "../parser/parser.yy"
             {  
        listeglobale->executer(); 
        compteurConditionnelles = 0 ;
        YYACCEPT;   
    }
#line 778 "parser.cc"
    break;

  case 11: // deplacement: AVANCE
#line 103 "../parser/parser.yy"
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
#line 794 "parser.cc"
    break;

  case 12: // deplacement: AVANCE NUMBER
#line 114 "../parser/parser.yy"
                    {       
        auto m(std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::avant));
        if(compteurConditionnelles == 0) listeglobale->ajouterInstruction(m); 
        else ajoutInstructionDansConditionnelle(listeglobale, compteurConditionnelles, m);
    }
#line 804 "parser.cc"
    break;

  case 13: // deplacement: AVANCE expression
#line 119 "../parser/parser.yy"
                        {   listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::avant )); }
#line 810 "parser.cc"
    break;

  case 14: // deplacement: RECULE
#line 121 "../parser/parser.yy"
             {              listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, 1, direction::arriere));     }
#line 816 "parser.cc"
    break;

  case 15: // deplacement: RECULE NUMBER
#line 122 "../parser/parser.yy"
                    {       listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::arriere));    }
#line 822 "parser.cc"
    break;

  case 16: // deplacement: RECULE expression
#line 123 "../parser/parser.yy"
                        {   listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, yystack_[0].value.as < int > (), direction::arriere));    }
#line 828 "parser.cc"
    break;

  case 17: // deplacement: SAUTE
#line 125 "../parser/parser.yy"
            {            listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, 2, direction::avant));      }
#line 834 "parser.cc"
    break;

  case 18: // deplacement: SAUTE NUMBER
#line 126 "../parser/parser.yy"
                   {     listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, (2*yystack_[0].value.as < int > ()), direction::avant)); }
#line 840 "parser.cc"
    break;

  case 19: // deplacement: SAUTE expression
#line 127 "../parser/parser.yy"
                       { listeglobale->ajouterInstruction(   std::make_shared<mouvement>(driver.getJardin(), 0, (2*yystack_[0].value.as < int > ()), direction::avant)); }
#line 846 "parser.cc"
    break;

  case 20: // deplacement: TOURNED
#line 129 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, 1,  sens::droite));    }
#line 852 "parser.cc"
    break;

  case 21: // deplacement: TOURNED NUMBER
#line 130 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, yystack_[0].value.as < int > (), sens::droite));    }
#line 858 "parser.cc"
    break;

  case 22: // deplacement: TOURNEG
#line 131 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, 1,  sens::gauche));    }
#line 864 "parser.cc"
    break;

  case 23: // deplacement: TOURNEG NUMBER
#line 132 "../parser/parser.yy"
                      {   listeglobale->ajouterInstruction(   std::make_shared<tourner>(driver.getJardin(), 0, yystack_[0].value.as < int > (), sens::gauche));    }
#line 870 "parser.cc"
    break;

  case 24: // position: DEVANT
#line 137 "../parser/parser.yy"
           {    yylhs.value.as < std::string > () = "devant";   }
#line 876 "parser.cc"
    break;

  case 25: // position: DERRIERE
#line 138 "../parser/parser.yy"
               {  yylhs.value.as < std::string > () = "derrière"; }
#line 882 "parser.cc"
    break;

  case 26: // position: DROITE
#line 139 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à droite"; }
#line 888 "parser.cc"
    break;

  case 27: // position: GAUCHE
#line 140 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à gauche"; }
#line 894 "parser.cc"
    break;

  case 28: // condition: MUR position
#line 143 "../parser/parser.yy"
                 {          yylhs.value.as < bool > () = (driver.estMurIci(yystack_[0].value.as < std::string > () ,0))? true : false;   }
#line 900 "parser.cc"
    break;

  case 29: // condition: NOT MUR position
#line 144 "../parser/parser.yy"
                       {    yylhs.value.as < bool > () = (!driver.estMurIci(yystack_[0].value.as < std::string > () ,0))? true : false;  }
#line 906 "parser.cc"
    break;

  case 30: // conditionelle: SI condition THEN finDeLigne
#line 147 "../parser/parser.yy"
                                 {
        listeglobale->ajouterInstruction(   std::make_shared<conditionnelle>(driver.getJardin(), 0, ++compteurConditionnelles, yystack_[2].value.as < bool > ())   );
    }
#line 914 "parser.cc"
    break;

  case 31: // conditionelle: SINON THEN finDeLigne
#line 150 "../parser/parser.yy"
                            {
        std::shared_ptr<conditionnelle> condit = findID(listeglobale, compteurConditionnelles);
        condit->changement_then_else();
    }
#line 923 "parser.cc"
    break;

  case 32: // conditionelle: ENDIF finDeLigne
#line 154 "../parser/parser.yy"
                       {
        compteurConditionnelles--;
    }
#line 931 "parser.cc"
    break;

  case 33: // expression: operation
#line 165 "../parser/parser.yy"
              {
        try{
            yylhs.value.as < int > () = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
#line 943 "parser.cc"
    break;

  case 34: // operation: NUMBER
#line 174 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 951 "parser.cc"
    break;

  case 35: // operation: '(' operation ')'
#line 177 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 959 "parser.cc"
    break;

  case 36: // operation: operation '+' operation
#line 180 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 967 "parser.cc"
    break;

  case 37: // operation: operation '-' operation
#line 183 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 975 "parser.cc"
    break;

  case 38: // operation: operation '*' operation
#line 186 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 983 "parser.cc"
    break;

  case 39: // operation: operation '/' operation
#line 189 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 991 "parser.cc"
    break;

  case 40: // operation: '-' operation
#line 192 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 999 "parser.cc"
    break;


#line 1003 "parser.cc"

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





  const signed char  Parser ::yypact_ninf_ = -22;

  const signed char  Parser ::yytable_ninf_ = -19;

  const signed char
   Parser ::yypact_[] =
  {
       3,    -2,    -5,    14,    21,   -21,     5,    -9,    11,    59,
      59,    16,    59,     3,   -22,    63,    23,    23,   -22,    29,
      67,   -22,    71,   -22,   -22,   -22,    39,    24,    50,    59,
     -22,    19,    49,   -22,   -22,   -22,     3,   -22,   -22,   -22,
       9,    23,    23,    23,    23,   -22,   -22,   -22,   -22,   -22,
      39,    59,   -22,   -22,   -22,     3,   -22,   -22,     0,     0,
     -22,   -22,   -22,   -22,   -22
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     0,    11,    14,    17,    20,    22,     0,     0,     0,
       0,     0,     0,     0,     6,    34,     0,     0,    13,    33,
      34,    16,    34,    19,    21,    23,     0,     0,     0,     0,
       7,     0,     9,    32,     4,     1,     0,     3,    34,    40,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
       0,     0,    31,     8,    10,     0,     2,    35,    37,    36,
      38,    39,    29,    30,     5
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -22,   -13,   -22,    -8,   -22,    17,   -22,   -22,    46,   -11
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,    11,    55,    33,    12,    49,    28,    13,    18,    19
  };

  const signed char
   Parser ::yytable_[] =
  {
      37,    14,    34,    24,    36,    39,    40,     1,    26,    27,
       2,     3,     4,     5,     6,     7,    35,     8,     9,    15,
      16,    52,    53,    56,    29,    17,    10,    43,    44,    25,
      58,    59,    60,    61,    41,    42,    43,    44,    20,    16,
      57,    50,    64,    63,    17,    22,    16,    38,    16,    21,
      23,    17,    54,    17,    41,    42,    43,    44,    45,    46,
      47,    48,    30,    51,    31,    32,   -12,    62,   -12,   -12,
     -15,     0,   -15,   -15,   -18,     0,   -18,   -18
  };

  const signed char
   Parser ::yycheck_[] =
  {
      13,     3,    10,    24,    12,    16,    17,     4,    17,    18,
       7,     8,     9,    10,    11,    12,     0,    14,    15,    24,
      25,    29,     3,    36,    13,    30,    23,    27,    28,    24,
      41,    42,    43,    44,    25,    26,    27,    28,    24,    25,
      31,    17,    55,    51,    30,    24,    25,    24,    25,     3,
       4,    30,     3,    30,    25,    26,    27,    28,    19,    20,
      21,    22,     3,    13,     5,     6,     3,    50,     5,     6,
       3,    -1,     5,     6,     3,    -1,     5,     6
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     4,     7,     8,     9,    10,    11,    12,    14,    15,
      23,    33,    36,    39,     3,    24,    25,    30,    40,    41,
      24,    40,    24,    40,    24,    24,    17,    18,    38,    13,
       3,     5,     6,    35,    35,     0,    35,    33,    24,    41,
      41,    25,    26,    27,    28,    19,    20,    21,    22,    37,
      17,    13,    35,     3,     3,    34,    33,    31,    41,    41,
      41,    41,    37,    35,    33
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    32,    33,    33,    34,    33,    33,    35,    35,    35,
      35,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    37,    37,    37,    37,    38,    38,
      39,    39,    39,    40,    41,    41,    41,    41,    41,    41,
      41
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     3,     2,     0,     4,     2,     1,     2,     1,
       2,     1,     2,     2,     1,     2,     2,     1,     2,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     3,
       4,     3,     2,     1,     1,     3,     3,     3,     3,     3,
       2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END", "FOIS",
  "COMMENTAIRE", "AVANCE", "RECULE", "SAUTE", "TOURNED", "TOURNEG", "SI",
  "THEN", "SINON", "ENDIF", "WHILE", "MUR", "NOT", "DEVANT", "DERRIERE",
  "DROITE", "GAUCHE", "NUMTORTUE", "NUMBER", "'-'", "'+'", "'*'", "'/'",
  "NEG", "'('", "')'", "$accept", "programme", "$@1", "finDeLigne",
  "deplacement", "position", "condition", "conditionelle", "expression",
  "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    82,    82,    83,    84,    84,    90,    98,    98,    98,
      98,   103,   114,   119,   121,   122,   123,   125,   126,   127,
     129,   130,   131,   132,   137,   138,   139,   140,   143,   144,
     147,   150,   154,   165,   174,   177,   180,   183,   186,   189,
     192
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
      30,    31,    27,    26,     2,    25,     2,    28,     2,     2,
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
      29
    };
    // Last valid token kind.
    const int code_max = 280;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1397 "parser.cc"

#line 196 "../parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
