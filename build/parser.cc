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

    #undef  yylex
    #define yylex scanner.yylex
    
    bool dansBlocIF = false;
    bool cond = false;

#line 60 "parser.cc"


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
#line 152 "parser.cc"

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

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
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

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
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

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
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

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
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

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
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

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        value.move< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
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

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
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
<<<<<<< HEAD
<<<<<<< HEAD
  case 2: // $@1: %empty
#line 69 "../parser/parser.yy"
              {             driver.avancerTortue(0,1);      }
#line 724 "parser.cc"
    break;

  case 4: // $@2: %empty
#line 70 "../parser/parser.yy"
                       {    
        for (int i(0) ; i<yystack_[1].value.as < int > (); i++)
            driver.avancerTortue(0,1); 
            
    }
#line 734 "parser.cc"
    break;

  case 6: // $@3: %empty
#line 75 "../parser/parser.yy"
                          { 
        int calcul = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.avancerTortue(0,calcul);
    }
#line 743 "parser.cc"
    break;

  case 8: // $@4: %empty
#line 80 "../parser/parser.yy"
                {           driver.avancerTortue( 0, (-1) );        }
#line 749 "parser.cc"
    break;

  case 10: // $@5: %empty
#line 81 "../parser/parser.yy"
                       {    driver.avancerTortue( 0, (yystack_[1].value.as < int > ()*(-1)) );   }
#line 755 "parser.cc"
    break;

  case 12: // $@6: %empty
#line 82 "../parser/parser.yy"
                          {
        int calcul = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.avancerTortue( 0, (calcul*(-1)) );
    }
#line 764 "parser.cc"
    break;

  case 14: // $@7: %empty
#line 87 "../parser/parser.yy"
               {             driver.avancerTortue(0,2);      }
#line 770 "parser.cc"
    break;

  case 16: // $@8: %empty
#line 88 "../parser/parser.yy"
                      {    driver.avancerTortue(0,2*yystack_[1].value.as < int > ());     }
#line 776 "parser.cc"
    break;

  case 18: // $@9: %empty
#line 89 "../parser/parser.yy"
                         { 
        int calcul = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.avancerTortue(0,2*calcul);
    }
#line 785 "parser.cc"
    break;

  case 20: // $@10: %empty
#line 96 "../parser/parser.yy"
                        {   driver.changerOrientationTortue(0, "droite", 1);    }
#line 791 "parser.cc"
    break;

  case 22: // $@11: %empty
#line 97 "../parser/parser.yy"
                        {   driver.changerOrientationTortue(0, "droite", yystack_[1].value.as < int > ());   }
#line 797 "parser.cc"
    break;

  case 24: // $@12: %empty
#line 98 "../parser/parser.yy"
                        {   driver.changerOrientationTortue(0, "gauche", 1);    }
#line 803 "parser.cc"
    break;

  case 26: // $@13: %empty
#line 99 "../parser/parser.yy"
                        {   driver.changerOrientationTortue(0, "gauche", yystack_[1].value.as < int > ());   }
#line 809 "parser.cc"
    break;

  case 28: // $@14: %empty
#line 101 "../parser/parser.yy"
                              {

    }
#line 817 "parser.cc"
    break;

  case 31: // $@15: %empty
#line 108 "../parser/parser.yy"
                   {    std::cout << "numéro de tortue reconnu : " + yystack_[1].value.as < int > () << std::endl    }
#line 823 "parser.cc"
    break;

  case 33: // programme: END NL
#line 110 "../parser/parser.yy"
             {
        YYACCEPT;
    }
#line 831 "parser.cc"
    break;

  case 34: // instruction: expression
#line 115 "../parser/parser.yy"
                {
    }
#line 838 "parser.cc"
    break;

  case 35: // instruction: affectation
#line 117 "../parser/parser.yy"
                  {
    }
#line 845 "parser.cc"
    break;

  case 36: // expression: operation
#line 121 "../parser/parser.yy"
=======
  case 3: // programme: END NL
=======
  case 3: // $@1: %empty
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
#line 82 "../parser/parser.yy"
                           {
        std::string chaineNumero = yystack_[1].value.as < std::string > ().substr(1);
        int num = std::stoi(chaineNumero);
        std::cout << "num detecte : " << num << std::endl;
    }
#line 731 "parser.cc"
    break;

  case 5: // programme: END NL
#line 88 "../parser/parser.yy"
             {  YYACCEPT;   }
#line 737 "parser.cc"
    break;

  case 10: // deplacement: AVANCE
#line 96 "../parser/parser.yy"
           {                 driver.avancerTortue(0,1);                              }
#line 743 "parser.cc"
    break;

  case 11: // deplacement: AVANCE NUMBER
#line 97 "../parser/parser.yy"
                    {
                for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue(0,1);   }
#line 750 "parser.cc"
    break;

  case 12: // deplacement: AVANCE expression
#line 99 "../parser/parser.yy"
                        {    for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue(0,1);   }
#line 756 "parser.cc"
    break;

  case 13: // deplacement: RECULE
#line 101 "../parser/parser.yy"
             {            driver.avancerTortue( 0, (-1) );        }
#line 762 "parser.cc"
    break;

  case 14: // deplacement: RECULE NUMBER
#line 102 "../parser/parser.yy"
                    {     for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue( 0, -1 );   }
#line 768 "parser.cc"
    break;

  case 15: // deplacement: RECULE expression
#line 103 "../parser/parser.yy"
                        { for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue( 0, -1 );   }
#line 774 "parser.cc"
    break;

  case 16: // deplacement: SAUTE
#line 105 "../parser/parser.yy"
            {            driver.avancerTortue(0,2);      }
#line 780 "parser.cc"
    break;

  case 17: // deplacement: SAUTE NUMBER
#line 106 "../parser/parser.yy"
                   {     for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue(0,2);   }
#line 786 "parser.cc"
    break;

  case 18: // deplacement: SAUTE expression
#line 107 "../parser/parser.yy"
                       { for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue(0,2);   }
#line 792 "parser.cc"
    break;

  case 19: // deplacement: TOURNED
#line 109 "../parser/parser.yy"
                      {   driver.changerOrientationTortue(0, "droite");    }
#line 798 "parser.cc"
    break;

  case 20: // deplacement: TOURNED NUMBER
#line 110 "../parser/parser.yy"
                      {   for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.changerOrientationTortue(0, "droite");   }
#line 804 "parser.cc"
    break;

  case 21: // deplacement: TOURNEG
#line 111 "../parser/parser.yy"
                      {   driver.changerOrientationTortue(0, "gauche");    }
#line 810 "parser.cc"
    break;

  case 22: // deplacement: TOURNEG NUMBER
#line 112 "../parser/parser.yy"
                      {   for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.changerOrientationTortue(0, "gauche");   }
#line 816 "parser.cc"
    break;

<<<<<<< HEAD
  case 21: // expression: operation
#line 147 "../parser/parser.yy"
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
  case 23: // expression: operation
#line 154 "../parser/parser.yy"
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
              {
        try{
            yylhs.value.as < int > () = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
#line 858 "parser.cc"
    break;

  case 37: // affectation: IDENT '=' operation
#line 131 "../parser/parser.yy"
                        { 
        double val = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.setVariable(yystack_[2].value.as < std::string > (),val);
    }
#line 867 "parser.cc"
    break;

  case 38: // operation: NUMBER
#line 137 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 875 "parser.cc"
    break;

  case 39: // operation: IDENT
#line 140 "../parser/parser.yy"
            {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ());
    }
#line 883 "parser.cc"
    break;

  case 40: // operation: '(' operation ')'
#line 143 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 891 "parser.cc"
    break;

  case 41: // operation: operation '+' operation
#line 146 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 899 "parser.cc"
    break;

  case 42: // operation: operation '-' operation
#line 149 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 907 "parser.cc"
    break;

  case 43: // operation: operation '*' operation
#line 152 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 915 "parser.cc"
    break;

  case 44: // operation: operation '/' operation
#line 155 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 923 "parser.cc"
    break;

  case 45: // operation: '-' operation
#line 158 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 931 "parser.cc"
    break;


#line 935 "parser.cc"
=======
#line 789 "parser.cc"
=======
#line 828 "parser.cc"
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
    break;

  case 24: // operation: NUMBER
#line 163 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 836 "parser.cc"
    break;

  case 25: // operation: '(' operation ')'
#line 166 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 844 "parser.cc"
    break;

  case 26: // operation: operation '+' operation
#line 169 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 852 "parser.cc"
    break;

  case 27: // operation: operation '-' operation
#line 172 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 860 "parser.cc"
    break;

  case 28: // operation: operation '*' operation
#line 175 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 868 "parser.cc"
    break;

  case 29: // operation: operation '/' operation
#line 178 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 876 "parser.cc"
    break;

  case 30: // operation: '-' operation
#line 181 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 884 "parser.cc"
    break;


<<<<<<< HEAD
#line 849 "parser.cc"
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
#line 888 "parser.cc"
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885

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





<<<<<<< HEAD
<<<<<<< HEAD
  const signed char  Parser ::yypact_ninf_ = -40;
=======
  const signed char  Parser ::yypact_ninf_ = -24;
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
  const signed char  Parser ::yypact_ninf_ = -26;
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885

  const signed char  Parser ::yytable_ninf_ = -18;

  const signed char
   Parser ::yypact_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
      78,    -2,     4,     7,    35,    -1,     0,    -8,     1,   -40,
     -16,    40,    40,    15,    17,   -40,   -40,    70,   -40,   -40,
      18,   -40,    42,   -40,    33,    49,   -40,    41,    54,   -40,
      43,   -40,    44,    27,   -40,    40,   -40,    79,   -40,    78,
      40,    40,    40,    40,    78,   -40,   -40,    78,   -40,   -40,
      78,   -40,   -40,    78,   -40,    78,   -40,    36,    78,    70,
     -40,   -40,   -10,   -10,   -40,   -40,   -40,    78,    78,   -40,
      78,    78,   -40,    78,    78,   -40,    78,   -40,    78,    53,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
      78,   -40
=======
      -2,    12,    -1,     1,     3,    -9,    -6,    29,    37,   -24,
      41,    10,    10,   -24,    11,    45,   -24,    49,   -24,   -24,
     -24,   -24,   -24,    28,    38,    -2,   -24,   -24,   -14,    10,
      10,    10,    10,   -24,   -24,   -24,   -24,   -23,   -23,   -24,
     -24
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
       0,    10,     4,     7,    11,   -21,    -6,    37,    33,    37,
     -26,    42,    14,    14,   -26,   -11,    46,   -26,    50,   -26,
     -26,   -26,   -26,    43,    47,   -26,   -26,     0,   -26,   -26,
      -1,    14,    14,    14,    14,   -26,   -26,     0,   -26,   -26,
     -22,   -22,   -26,   -26,   -26
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yydefact_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,     0,     0,     0,     0,    34,    35,    36,    33,     2,
      38,    39,     0,     8,    38,     0,    14,    38,     0,    20,
       0,    24,     0,     0,    31,     0,    45,     0,     1,     0,
       0,     0,     0,     0,     0,     4,     6,     0,    10,    12,
       0,    16,    18,     0,    22,     0,    26,     0,     0,    37,
      40,    30,    42,    41,    43,    44,     3,     0,     0,     9,
       0,     0,    15,     0,     0,    21,     0,    25,     0,     0,
      32,     5,     7,    11,    13,    17,    19,    23,    27,    28,
       0,    29
=======
       0,     0,     8,    11,    14,    17,    19,     0,     0,     3,
      22,     0,     0,    10,    21,    22,    13,    22,    16,    18,
      20,     1,     4,     0,     6,     0,    22,    28,     0,     0,
       0,     0,     0,     5,     7,     2,    23,    25,    24,    26,
      27
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
       0,     0,    10,    13,    16,    19,    21,     0,     0,     0,
       5,    24,     0,     0,    12,    23,    24,    15,    24,    18,
      20,    22,     6,     0,     8,     3,     1,     0,    24,    30,
       0,     0,     0,     0,     0,     7,     9,     0,     2,    25,
      27,    26,    28,    29,     4
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yypgoto_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
     -40,   -39,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
      38
=======
     -24,    20,   -24,   -24,    53,   -11
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
     -26,   -25,   -26,    45,   -26,    54,   -12
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
       0,    13,    44,    67,    68,    47,    70,    71,    50,    73,
      74,    53,    76,    55,    78,    90,    58,    14,    15,    16,
      17
=======
       0,     7,    25,     8,    13,    14
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
       0,     8,    37,    25,     9,    14,    15
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yytable_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
      61,    18,    29,    31,    34,    66,    33,    19,    69,    35,
      23,    72,    42,    43,    75,    38,    77,    30,    32,    80,
      39,    45,    20,    21,    11,    24,    21,    11,    81,    82,
      12,    83,    84,    12,    85,    86,    48,    87,    26,    88,
      22,    25,    28,    57,    51,    46,    54,    56,    79,    36,
      37,    91,    49,    27,    21,    11,    89,    52,     9,    21,
      11,    12,    40,    41,    42,    43,    12,     0,     0,    40,
      41,    42,    43,    59,    40,    41,    42,    43,    62,    63,
      64,    65,     1,     0,     2,     3,     4,     5,     6,     7,
      40,    41,    42,    43,     0,     8,     9,    10,    11,    40,
      41,    42,    43,     0,    12,     0,    60
=======
      27,    28,     1,    31,    32,     2,     3,     4,     5,     6,
      29,    30,    31,    32,    19,     9,    36,    20,    37,    38,
      39,    40,    10,    11,    15,    11,    17,    11,    12,    21,
      12,    33,    12,    26,    11,    29,    30,    31,    32,    12,
      22,    34,    23,    24,    -9,    35,    -9,    -9,   -12,     0,
     -12,   -12,   -15,     0,   -15,   -15,    16,    18
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
      29,    30,    38,    20,     1,    33,    34,     2,     3,     4,
       5,     6,    44,    10,    31,    32,    33,    34,    21,    40,
      41,    42,    43,     7,    31,    32,    33,    34,    11,    12,
      39,    16,    12,    26,    13,    18,    12,    13,    28,    12,
      22,    13,    23,    24,    13,   -11,    35,   -11,   -11,   -14,
      36,   -14,   -14,   -17,    27,   -17,   -17,    17,    19
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yycheck_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
      39,     3,     3,     3,     3,    44,    14,     3,    47,    25,
       3,    50,    22,    23,    53,     0,    55,    18,    18,    58,
       3,     3,    18,    19,    20,    18,    19,    20,    67,    68,
      26,    70,    71,    26,    73,    74,     3,    76,     3,    78,
       2,     3,     4,    16,     3,     3,     3,     3,    12,    11,
      12,    90,     3,    18,    19,    20,     3,     3,    18,    19,
      20,    26,    20,    21,    22,    23,    26,    -1,    -1,    20,
      21,    22,    23,    35,    20,    21,    22,    23,    40,    41,
      42,    43,     4,    -1,     6,     7,     8,     9,    10,    11,
      20,    21,    22,    23,    -1,    17,    18,    19,    20,    20,
      21,    22,    23,    -1,    26,    -1,    27
=======
      11,    12,     4,    26,    27,     7,     8,     9,    10,    11,
      24,    25,    26,    27,    23,     3,    30,    23,    29,    30,
      31,    32,    23,    24,    23,    24,    23,    24,    29,     0,
      29,     3,    29,    23,    24,    24,    25,    26,    27,    29,
       3,     3,     5,     6,     3,    25,     5,     6,     3,    -1,
       5,     6,     3,    -1,     5,     6,     3,     4
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
      12,    13,    27,    24,     4,    27,    28,     7,     8,     9,
      10,    11,    37,     3,    25,    26,    27,    28,    24,    31,
      32,    33,    34,    23,    25,    26,    27,    28,    24,    25,
      31,    24,    25,     0,    30,    24,    25,    30,    24,    25,
       3,    30,     5,     6,    30,     3,     3,     5,     6,     3,
       3,     5,     6,     3,     9,     5,     6,     3,     4
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yystos_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
       0,     4,     6,     7,     8,     9,    10,    11,    17,    18,
      19,    20,    26,    29,    45,    46,    47,    48,     3,     3,
      18,    19,    48,     3,    18,    48,     3,    18,    48,     3,
      18,     3,    18,    14,     3,    25,    48,    48,     0,     3,
      20,    21,    22,    23,    30,     3,     3,    33,     3,     3,
      36,     3,     3,    39,     3,    41,     3,    16,    44,    48,
      27,    29,    48,    48,    48,    48,    29,    31,    32,    29,
      34,    35,    29,    37,    38,    29,    40,    29,    42,    12,
      29,    29,    29,    29,    29,    29,    29,    29,    29,     3,
      43,    29
=======
       0,     4,     7,     8,     9,    10,    11,    32,    34,     3,
      23,    24,    29,    35,    36,    23,    35,    23,    35,    23,
      23,     0,     3,     5,     6,    33,    23,    36,    36,    24,
      25,    26,    27,     3,     3,    32,    30,    36,    36,    36,
      36
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
       0,     4,     7,     8,     9,    10,    11,    23,    33,    36,
       3,    24,    25,    30,    37,    38,    24,    37,    24,    37,
      24,    24,     3,     5,     6,    35,     0,    35,    24,    38,
      38,    25,    26,    27,    28,     3,     3,    34,    33,    31,
      38,    38,    38,    38,    33
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yyr1_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
       0,    28,    30,    29,    31,    29,    32,    29,    33,    29,
      34,    29,    35,    29,    36,    29,    37,    29,    38,    29,
      39,    29,    40,    29,    41,    29,    42,    29,    43,    29,
      29,    44,    29,    29,    45,    45,    46,    47,    48,    48,
      48,    48,    48,    48,    48,    48
=======
       0,    31,    32,    32,    33,    33,    33,    33,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    35,    36,    36,    36,    36,    36,    36,    36
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
       0,    32,    33,    34,    33,    33,    35,    35,    35,    35,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    37,    38,    38,    38,    38,    38,    38,
      38
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };

  const signed char
   Parser ::yyr2_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
       0,     2,     0,     4,     0,     5,     0,     5,     0,     4,
       0,     5,     0,     5,     0,     4,     0,     5,     0,     5,
       0,     4,     0,     5,     0,     4,     0,     5,     0,     7,
       3,     0,     4,     2,     1,     1,     1,     3,     1,     1,
       3,     3,     3,     3,     3,     2
=======
       0,     2,     3,     2,     1,     2,     1,     2,     1,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     2,     1,
       2,     1,     1,     3,     3,     3,     3,     3,     2
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
       0,     2,     3,     0,     4,     2,     1,     2,     1,     2,
       1,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     3,     3,     3,
       2
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END", "FOIS",
<<<<<<< HEAD
  "AVANCE", "RECULE", "SAUTE", "TOURNED", "TOURNEG", "SI", "THEN", "SINON",
  "MUR", "NOT", "POSITION", "NUMTORTUE", "NUMBER", "IDENT", "'-'", "'+'",
  "'*'", "'/'", "NEG", "'='", "'('", "')'", "$accept", "programme", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "instruction", "expression",
  "affectation", "operation", YY_NULLPTR
=======
  "COMMENTAIRE", "AVANCE", "RECULE", "SAUTE", "TOURNED", "TOURNEG", "SI",
  "THEN", "SINON", "ENDIF", "WHILE", "MUR", "NOT", "DEVANT", "DERRIERE",
<<<<<<< HEAD
  "DROITE", "GAUCHE", "NUMBER", "'-'", "'+'", "'*'", "'/'", "NEG", "'('",
  "')'", "$accept", "programme", "finDeLigne", "deplacement", "expression",
  "operation", YY_NULLPTR
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
  "DROITE", "GAUCHE", "NUMTORTUE", "NUMBER", "'-'", "'+'", "'*'", "'/'",
  "NEG", "'('", "')'", "$accept", "programme", "$@1", "finDeLigne",
  "deplacement", "expression", "operation", YY_NULLPTR
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
<<<<<<< HEAD
<<<<<<< HEAD
       0,    69,    69,    69,    70,    70,    75,    75,    80,    80,
      81,    81,    82,    82,    87,    87,    88,    88,    89,    89,
      96,    96,    97,    97,    98,    98,    99,    99,   101,   101,
     106,   108,   108,   110,   115,   117,   121,   131,   137,   140,
     143,   146,   149,   152,   155,   158
=======
       0,    79,    79,    82,    86,    86,    86,    86,    90,    91,
      92,    94,    95,    96,    98,    99,   100,   102,   103,   104,
     105,   147,   156,   159,   162,   165,   168,   171,   174
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
       0,    80,    80,    82,    82,    88,    92,    92,    92,    92,
      96,    97,    99,   101,   102,   103,   105,   106,   107,   109,
     110,   111,   112,   154,   163,   166,   169,   172,   175,   178,
     181
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
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
<<<<<<< HEAD
<<<<<<< HEAD
      26,    27,    22,    21,     2,    20,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,     2,     2,     2,     2,     2,     2,     2,
=======
      29,    30,    26,    25,     2,    24,     2,    27,     2,     2,
=======
      30,    31,    27,    26,     2,    25,     2,    28,     2,     2,
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
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
<<<<<<< HEAD
<<<<<<< HEAD
      15,    16,    17,    18,    19,    24
    };
    // Last valid token kind.
    const int code_max = 275;
=======
      15,    16,    17,    18,    19,    20,    21,    22,    23,    28
    };
    // Last valid token kind.
    const int code_max = 279;
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      29
    };
    // Last valid token kind.
    const int code_max = 280;
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
<<<<<<< HEAD
<<<<<<< HEAD
#line 1347 "parser.cc"

#line 162 "../parser/parser.yy"
=======
#line 1225 "parser.cc"

#line 178 "../parser/parser.yy"
>>>>>>> 97552c54239cfb393f51b6321c32eeb3321fea5c
=======
#line 1268 "parser.cc"

#line 185 "../parser/parser.yy"
>>>>>>> 357879fd401bab50e0d5b8eba7facc6d2a8d4885


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
