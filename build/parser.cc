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
    #include <list>
    
    #include "scanner.hh"
    #include "driver.hh"
    #include "structureTortue/instruction.hh"
    #include "structureTortue/liste.hh"

    #undef  yylex
    #define yylex scanner.yylex
    
    std::list< boucleEtConditionnellePtr > file;
    listePtr listeglobale = liste::fabrique();


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
      case symbol_kind::S_numeroDeTortue: // numeroDeTortue
      case symbol_kind::S_numeroOuRien: // numeroOuRien
      case symbol_kind::S_expression: // expression
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_HEXCODE: // HEXCODE
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
      case symbol_kind::S_numeroDeTortue: // numeroDeTortue
      case symbol_kind::S_numeroOuRien: // numeroOuRien
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_HEXCODE: // HEXCODE
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
      case symbol_kind::S_numeroDeTortue: // numeroDeTortue
      case symbol_kind::S_numeroOuRien: // numeroOuRien
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_HEXCODE: // HEXCODE
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
      case symbol_kind::S_numeroDeTortue: // numeroDeTortue
      case symbol_kind::S_numeroOuRien: // numeroOuRien
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_HEXCODE: // HEXCODE
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
      case symbol_kind::S_numeroDeTortue: // numeroDeTortue
      case symbol_kind::S_numeroOuRien: // numeroOuRien
      case symbol_kind::S_expression: // expression
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_HEXCODE: // HEXCODE
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
      case symbol_kind::S_numeroDeTortue: // numeroDeTortue
      case symbol_kind::S_numeroOuRien: // numeroOuRien
      case symbol_kind::S_expression: // expression
        value.move< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_HEXCODE: // HEXCODE
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
      case symbol_kind::S_numeroDeTortue: // numeroDeTortue
      case symbol_kind::S_numeroOuRien: // numeroOuRien
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
      case symbol_kind::S_HEXCODE: // HEXCODE
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
  case 7: // programme: END NL
#line 103 "../parser/parser.yy"
             {  
        listeglobale->executer(); 
        listeglobale->vider();
        YYACCEPT;   
    }
#line 791 "parser.cc"
    break;

  case 8: // numeroDeTortue: NUMTORTUE
#line 111 "../parser/parser.yy"
              {  yylhs.value.as < int > () = std::stoi(yystack_[0].value.as < std::string > ().substr(1));   }
#line 797 "parser.cc"
    break;

  case 13: // numeroOuRien: finDeLigne
#line 122 "../parser/parser.yy"
               { yylhs.value.as < int > () = 66; }
#line 803 "parser.cc"
    break;

  case 14: // numeroOuRien: numeroDeTortue finDeLigne
#line 123 "../parser/parser.yy"
                                { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 809 "parser.cc"
    break;

  case 19: // avancer: AVANCE numeroOuRien
#line 133 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant));
    }
#line 818 "parser.cc"
    break;

  case 20: // avancer: AVANCE expression numeroOuRien
#line 137 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant));  
    }
#line 827 "parser.cc"
    break;

  case 21: // reculer: RECULE numeroOuRien
#line 142 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere));
    }
#line 836 "parser.cc"
    break;

  case 22: // reculer: RECULE expression numeroOuRien
#line 146 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere));  
    }
#line 845 "parser.cc"
    break;

  case 23: // sauter: SAUTE numeroOuRien
#line 151 "../parser/parser.yy"
                      {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant));
    }
#line 854 "parser.cc"
    break;

  case 24: // sauter: SAUTE expression numeroOuRien
#line 155 "../parser/parser.yy"
                                   { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant));  
    }
#line 863 "parser.cc"
    break;

  case 25: // tourner: TOURNED numeroOuRien
#line 160 "../parser/parser.yy"
                        {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite));
    }
#line 872 "parser.cc"
    break;

  case 26: // tourner: TOURNED expression numeroOuRien
#line 164 "../parser/parser.yy"
                                     {  
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite));
    }
#line 881 "parser.cc"
    break;

  case 27: // tourner: TOURNEG numeroOuRien
#line 168 "../parser/parser.yy"
                          {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche));
    }
#line 890 "parser.cc"
    break;

  case 28: // tourner: TOURNEG expression numeroOuRien
#line 172 "../parser/parser.yy"
                                     {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche));
    }
#line 899 "parser.cc"
    break;

  case 29: // position: DEVANT
#line 180 "../parser/parser.yy"
           {    yylhs.value.as < std::string > () = "devant";   }
#line 905 "parser.cc"
    break;

  case 30: // position: DERRIERE
#line 181 "../parser/parser.yy"
               {  yylhs.value.as < std::string > () = "derrière"; }
#line 911 "parser.cc"
    break;

  case 31: // position: DROITE
#line 182 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à droite"; }
#line 917 "parser.cc"
    break;

  case 32: // position: GAUCHE
#line 183 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à gauche"; }
#line 923 "parser.cc"
    break;

  case 33: // condition: MUR
#line 186 "../parser/parser.yy"
        {          yylhs.value.as < bool > () = true;   }
#line 929 "parser.cc"
    break;

  case 34: // condition: NOT MUR
#line 187 "../parser/parser.yy"
              {    yylhs.value.as < bool > () = false;  }
#line 935 "parser.cc"
    break;

  case 35: // condition: VIDE
#line 188 "../parser/parser.yy"
           {       yylhs.value.as < bool > () = false;  }
#line 941 "parser.cc"
    break;

  case 36: // condition: NOT VIDE
#line 189 "../parser/parser.yy"
               {   yylhs.value.as < bool > () = true;   }
#line 947 "parser.cc"
    break;

  case 37: // conditionelle: SI condition position THEN numeroOuRien
#line 192 "../parser/parser.yy"
                                            {
        auto instptr = std::make_shared<conditionnelle>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 957 "parser.cc"
    break;

  case 38: // conditionelle: SINON finDeLigne
#line 197 "../parser/parser.yy"
                       {    file.front()->changement_then_else();   }
#line 963 "parser.cc"
    break;

  case 39: // conditionelle: ENDIF finDeLigne
#line 198 "../parser/parser.yy"
                       {    file.pop_front();                       }
#line 969 "parser.cc"
    break;

  case 40: // boucle: WHILE condition position THEN numeroOuRien
#line 203 "../parser/parser.yy"
                                               {
        auto instptr = std::make_shared<tantque>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 979 "parser.cc"
    break;

  case 41: // boucle: ENDWHILE finDeLigne
#line 208 "../parser/parser.yy"
                          {
        file.pop_front();
    }
#line 987 "parser.cc"
    break;

  case 42: // boucle: REPETE expression THEN finDeLigne
#line 213 "../parser/parser.yy"
                                        {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[2].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 997 "parser.cc"
    break;

  case 43: // boucle: REPETE expression FOIS THEN finDeLigne
#line 218 "../parser/parser.yy"
                                             {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[3].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1007 "parser.cc"
    break;

  case 44: // boucle: ENDREPETE finDeLigne
#line 223 "../parser/parser.yy"
                           {
        file.pop_front();
    }
#line 1015 "parser.cc"
    break;

  case 45: // color: COULEUR HEXCODE
#line 228 "../parser/parser.yy"
                    {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurCarapace(0,  n[0], n[1], n[2]);     }
#line 1021 "parser.cc"
    break;

  case 46: // color: COULEUR HEXCODE numeroDeTortue
#line 229 "../parser/parser.yy"
                                     {  std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurCarapace(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 1027 "parser.cc"
    break;

  case 47: // color: COULEURMOTIF HEXCODE
#line 230 "../parser/parser.yy"
                           {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurMotif(0,  n[0], n[1], n[2]);     }
#line 1033 "parser.cc"
    break;

  case 48: // color: COULEURMOTIF HEXCODE numeroDeTortue
#line 231 "../parser/parser.yy"
                                         {     std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurMotif(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 1039 "parser.cc"
    break;

  case 49: // expression: operation
#line 238 "../parser/parser.yy"
              {
        try{
            yylhs.value.as < int > () = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
#line 1051 "parser.cc"
    break;

  case 50: // operation: NUMBER
#line 247 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 1059 "parser.cc"
    break;

  case 51: // operation: '(' operation ')'
#line 250 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 1067 "parser.cc"
    break;

  case 52: // operation: operation '+' operation
#line 253 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 1075 "parser.cc"
    break;

  case 53: // operation: operation '-' operation
#line 256 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 1083 "parser.cc"
    break;

  case 54: // operation: operation '*' operation
#line 259 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 1091 "parser.cc"
    break;

  case 55: // operation: operation '/' operation
#line 262 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 1099 "parser.cc"
    break;

  case 56: // operation: '-' operation
#line 265 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 1107 "parser.cc"
    break;


#line 1111 "parser.cc"

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





  const signed char  Parser ::yypact_ninf_ = -30;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
      66,   -30,    10,    16,    19,    27,    27,    27,    27,    27,
      76,    50,    50,    76,    50,   -22,    50,     5,     8,    25,
      66,    66,   -30,   -30,   -30,   -30,    66,    66,    50,   -30,
     -30,   -30,   -30,   -30,   -22,   -22,    50,   -30,   -30,    62,
      75,   -30,    62,   -30,    62,   -30,    62,   -30,    62,   -30,
       9,   -30,    88,   -30,   -30,    88,   -30,    47,   -30,    13,
      13,   -30,   -30,   -30,   -30,   -30,    66,   -30,    68,   -30,
     -30,   -22,   -22,   -22,   -22,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,    29,    73,    74,    50,   -30,
     -30,   -30,   -30,   -29,   -29,   -30,   -30,    62,    62,    50,
     -30,   -30,   -30,   -30
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     9,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,     0,     0,     0,     7,
      10,    12,     8,    50,     0,     0,     0,    13,    19,     0,
      49,    21,     0,    23,     0,    25,     0,    27,     0,    33,
       0,    35,     0,    38,    39,     0,    41,     0,    44,    45,
      47,     1,     5,     2,     3,     4,     0,    56,     0,    14,
      20,     0,     0,     0,     0,    22,    24,    26,    28,    34,
      36,    29,    30,    31,    32,     0,     0,     0,     0,    46,
      48,     6,    51,    53,    52,    54,    55,     0,     0,     0,
      42,    37,    40,    43
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -30,    -3,     2,     0,    -5,   -30,   -30,   -30,   -30,   -30,
      24,    77,   -30,   -30,   -30,    42,   -27
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,    19,    36,    37,    38,    21,    22,    23,    24,    25,
      85,    52,    26,    27,    28,    39,    40
  };

  const signed char
   Parser ::yytable_[] =
  {
      20,    41,    43,    45,    47,    73,    74,    67,    68,    33,
      34,    53,    54,    29,    56,    35,    58,    62,    63,    30,
      20,    20,    31,    64,    65,    61,    20,    20,    66,    79,
       1,    80,     3,     4,    70,    59,    69,    75,    60,    76,
      32,    77,    97,    78,    93,    94,    95,    96,    42,    44,
      46,    48,    87,     1,    32,     3,     4,    57,    33,    34,
      88,    89,    90,    91,    35,     1,    20,     3,     4,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    86,
      11,    12,    13,    14,    15,    16,    98,    99,   100,    32,
      55,     0,   101,   102,    17,    18,    49,    50,    51,   103,
      71,    72,    73,    74,     0,     0,    92,    71,    72,    73,
      74,    81,    82,    83,    84
  };

  const signed char
   Parser ::yycheck_[] =
  {
       0,     6,     7,     8,     9,    34,    35,    34,    35,    31,
      32,    11,    12,     3,    14,    37,    16,    20,    21,     3,
      20,    21,     3,    26,    27,     0,    26,    27,    28,    20,
       3,    22,     5,     6,    39,    30,    36,    42,    30,    44,
      27,    46,    13,    48,    71,    72,    73,    74,     6,     7,
       8,     9,     5,     3,    27,     5,     6,    15,    31,    32,
      13,    59,    60,    66,    37,     3,    66,     5,     6,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    55,
      14,    15,    16,    17,    18,    19,    13,    13,    88,    27,
      13,    -1,    97,    98,    28,    29,    20,    21,    22,    99,
      32,    33,    34,    35,    -1,    -1,    38,    32,    33,    34,
      35,    23,    24,    25,    26
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    28,    29,    40,
      42,    44,    45,    46,    47,    48,    51,    52,    53,     3,
       3,     3,    27,    31,    32,    37,    41,    42,    43,    54,
      55,    43,    54,    43,    54,    43,    54,    43,    54,    20,
      21,    22,    50,    42,    42,    50,    42,    54,    42,    30,
      30,     0,    40,    40,    40,    40,    42,    55,    55,    42,
      43,    32,    33,    34,    35,    43,    43,    43,    43,    20,
      22,    23,    24,    25,    26,    49,    49,     5,    13,    41,
      41,    40,    38,    55,    55,    55,    55,    13,    13,    13,
      42,    43,    43,    42
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    39,    40,    40,    40,    40,    40,    40,    41,    42,
      42,    42,    42,    43,    43,    44,    44,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    48,    48,    49,
      49,    49,    49,    50,    50,    50,    50,    51,    51,    51,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      55,    55,    55,    55,    55,    55,    55
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     2,     2,     2,     3,     2,     1,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     1,
       1,     1,     1,     1,     2,     1,     2,     5,     2,     2,
       5,     2,     4,     5,     2,     2,     3,     2,     3,     1,
       1,     3,     3,     3,     3,     3,     2
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
  "MUR", "NOT", "VIDE", "DEVANT", "DERRIERE", "DROITE", "GAUCHE",
  "NUMTORTUE", "COULEUR", "COULEURMOTIF", "HEXCODE", "NUMBER", "'-'",
  "'+'", "'*'", "'/'", "NEG", "'('", "')'", "$accept", "programme",
  "numeroDeTortue", "finDeLigne", "numeroOuRien", "deplacement", "avancer",
  "reculer", "sauter", "tourner", "position", "condition", "conditionelle",
  "boucle", "color", "expression", "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,    97,    97,    98,    99,   100,   101,   103,   111,   114,
     114,   114,   114,   122,   123,   127,   128,   129,   130,   133,
     137,   142,   146,   151,   155,   160,   164,   168,   172,   180,
     181,   182,   183,   186,   187,   188,   189,   192,   197,   198,
     203,   208,   213,   218,   223,   228,   229,   230,   231,   238,
     247,   250,   253,   256,   259,   262,   265
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
      37,    38,    34,    33,     2,    32,     2,    35,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    36
    };
    // Last valid token kind.
    const int code_max = 287;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1532 "parser.cc"

#line 269 "../parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
