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


#line 69 "parser.cc"


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
#line 161 "parser.cc"

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
      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ARGUMENTS: // ARGUMENTS
      case symbol_kind::S_NUMBERARG: // NUMBERARG
      case symbol_kind::S_HEXCODE: // HEXCODE
      case symbol_kind::S_position: // position
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argumentsOuRien: // argumentsOuRien
        value.copy< std::vector<int> > (YY_MOVE (that.value));
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
      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ARGUMENTS: // ARGUMENTS
      case symbol_kind::S_NUMBERARG: // NUMBERARG
      case symbol_kind::S_HEXCODE: // HEXCODE
      case symbol_kind::S_position: // position
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_argumentsOuRien: // argumentsOuRien
        value.move< std::vector<int> > (YY_MOVE (s.value));
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
      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ARGUMENTS: // ARGUMENTS
      case symbol_kind::S_NUMBERARG: // NUMBERARG
      case symbol_kind::S_HEXCODE: // HEXCODE
      case symbol_kind::S_position: // position
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argumentsOuRien: // argumentsOuRien
        value.YY_MOVE_OR_COPY< std::vector<int> > (YY_MOVE (that.value));
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
      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ARGUMENTS: // ARGUMENTS
      case symbol_kind::S_NUMBERARG: // NUMBERARG
      case symbol_kind::S_HEXCODE: // HEXCODE
      case symbol_kind::S_position: // position
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argumentsOuRien: // argumentsOuRien
        value.move< std::vector<int> > (YY_MOVE (that.value));
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
      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ARGUMENTS: // ARGUMENTS
      case symbol_kind::S_NUMBERARG: // NUMBERARG
      case symbol_kind::S_HEXCODE: // HEXCODE
      case symbol_kind::S_position: // position
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_argumentsOuRien: // argumentsOuRien
        value.copy< std::vector<int> > (that.value);
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
      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ARGUMENTS: // ARGUMENTS
      case symbol_kind::S_NUMBERARG: // NUMBERARG
      case symbol_kind::S_HEXCODE: // HEXCODE
      case symbol_kind::S_position: // position
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_argumentsOuRien: // argumentsOuRien
        value.move< std::vector<int> > (that.value);
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
      case symbol_kind::S_FILE: // FILE
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ARGUMENTS: // ARGUMENTS
      case symbol_kind::S_NUMBERARG: // NUMBERARG
      case symbol_kind::S_HEXCODE: // HEXCODE
      case symbol_kind::S_position: // position
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_argumentsOuRien: // argumentsOuRien
        yylhs.value.emplace< std::vector<int> > ();
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
  case 10: // programme: END NL
#line 126 "../parser/parser.yy"
             {  
        listeglobale->executer(); 
        listeglobale->vider();
        YYACCEPT;   
    }
#line 852 "parser.cc"
    break;

  case 11: // tortues: TORTUES NUMBER finDeLigne
#line 132 "../parser/parser.yy"
                              {
        QSize tailleDuJardin = driver.getJardin()->tailleJardin();

        for(int i(0); i<yystack_[1].value.as < int > (); i++){
            int x = rand() % tailleDuJardin.width();
            int y = rand() % tailleDuJardin.height();
            driver.getJardin()->newTortue(x,y);
        }
    }
#line 866 "parser.cc"
    break;

  case 12: // jardin: JARDIN FILE finDeLigne
#line 143 "../parser/parser.yy"
                           {
        std::string s = yystack_[1].value.as < std::string > ().substr(1);
        std::string fichier = s.substr(0,s.size()-1);
        try {
            driver.getJardin()->construction(fichier.c_str());
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

    }
#line 881 "parser.cc"
    break;

  case 13: // numeroDeTortue: NUMTORTUE
#line 155 "../parser/parser.yy"
              {  yylhs.value.as < int > () = std::stoi(yystack_[0].value.as < std::string > ().substr(1));   }
#line 887 "parser.cc"
    break;

  case 18: // numeroOuRien: finDeLigne
#line 166 "../parser/parser.yy"
               { yylhs.value.as < int > () = 66; }
#line 893 "parser.cc"
    break;

  case 19: // numeroOuRien: numeroDeTortue finDeLigne
#line 167 "../parser/parser.yy"
                                { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 899 "parser.cc"
    break;

  case 24: // avancer: AVANCE numeroOuRien
#line 177 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant));
    }
#line 908 "parser.cc"
    break;

  case 25: // avancer: AVANCE expression numeroOuRien
#line 181 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant));  
    }
#line 917 "parser.cc"
    break;

  case 26: // reculer: RECULE numeroOuRien
#line 186 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere));
    }
#line 926 "parser.cc"
    break;

  case 27: // reculer: RECULE expression numeroOuRien
#line 190 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere));  
    }
#line 935 "parser.cc"
    break;

  case 28: // sauter: SAUTE numeroOuRien
#line 195 "../parser/parser.yy"
                      {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant));
    }
#line 944 "parser.cc"
    break;

  case 29: // sauter: SAUTE expression numeroOuRien
#line 199 "../parser/parser.yy"
                                   { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant));  
    }
#line 953 "parser.cc"
    break;

  case 30: // tourner: TOURNED numeroOuRien
#line 204 "../parser/parser.yy"
                        {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite));
    }
#line 962 "parser.cc"
    break;

  case 31: // tourner: TOURNED expression numeroOuRien
#line 208 "../parser/parser.yy"
                                     {  
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite));
    }
#line 971 "parser.cc"
    break;

  case 32: // tourner: TOURNEG numeroOuRien
#line 212 "../parser/parser.yy"
                          {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche));
    }
#line 980 "parser.cc"
    break;

  case 33: // tourner: TOURNEG expression numeroOuRien
#line 216 "../parser/parser.yy"
                                     {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche));
    }
#line 989 "parser.cc"
    break;

  case 34: // position: DEVANT
#line 224 "../parser/parser.yy"
           {    yylhs.value.as < std::string > () = "devant";   }
#line 995 "parser.cc"
    break;

  case 35: // position: DERRIERE
#line 225 "../parser/parser.yy"
               {  yylhs.value.as < std::string > () = "derrière"; }
#line 1001 "parser.cc"
    break;

  case 36: // position: DROITE
#line 226 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à droite"; }
#line 1007 "parser.cc"
    break;

  case 37: // position: GAUCHE
#line 227 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à gauche"; }
#line 1013 "parser.cc"
    break;

  case 38: // condition: MUR
#line 230 "../parser/parser.yy"
        {          yylhs.value.as < bool > () = true;   }
#line 1019 "parser.cc"
    break;

  case 39: // condition: NOT MUR
#line 231 "../parser/parser.yy"
              {    yylhs.value.as < bool > () = false;  }
#line 1025 "parser.cc"
    break;

  case 40: // condition: VIDE
#line 232 "../parser/parser.yy"
           {       yylhs.value.as < bool > () = false;  }
#line 1031 "parser.cc"
    break;

  case 41: // condition: NOT VIDE
#line 233 "../parser/parser.yy"
               {   yylhs.value.as < bool > () = true;   }
#line 1037 "parser.cc"
    break;

  case 42: // conditionelle: SI condition position THEN numeroOuRien
#line 236 "../parser/parser.yy"
                                            {
        auto instptr = std::make_shared<conditionnelle>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1047 "parser.cc"
    break;

  case 43: // conditionelle: SINON finDeLigne
#line 241 "../parser/parser.yy"
                       {    file.front()->changement_then_else();   }
#line 1053 "parser.cc"
    break;

  case 44: // conditionelle: ENDIF finDeLigne
#line 242 "../parser/parser.yy"
                       {    file.pop_front();                       }
#line 1059 "parser.cc"
    break;

  case 45: // boucle: WHILE condition position THEN numeroOuRien
#line 247 "../parser/parser.yy"
                                               {
        auto instptr = std::make_shared<tantque>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1069 "parser.cc"
    break;

  case 46: // boucle: ENDWHILE finDeLigne
#line 252 "../parser/parser.yy"
                          {
        file.pop_front();
    }
#line 1077 "parser.cc"
    break;

  case 47: // boucle: REPETE expression THEN finDeLigne
#line 257 "../parser/parser.yy"
                                        {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[2].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1087 "parser.cc"
    break;

  case 48: // boucle: REPETE expression FOIS THEN finDeLigne
#line 262 "../parser/parser.yy"
                                             {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[3].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1097 "parser.cc"
    break;

  case 49: // boucle: ENDREPETE finDeLigne
#line 267 "../parser/parser.yy"
                           {
        file.pop_front();
    }
#line 1105 "parser.cc"
    break;

  case 50: // color: COULEUR HEXCODE
#line 272 "../parser/parser.yy"
                    {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurCarapace(0,  n[0], n[1], n[2]);     }
#line 1111 "parser.cc"
    break;

  case 51: // color: COULEUR HEXCODE numeroDeTortue
#line 273 "../parser/parser.yy"
                                     {  std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurCarapace(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 1117 "parser.cc"
    break;

  case 52: // color: COULEURMOTIF HEXCODE
#line 274 "../parser/parser.yy"
                           {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurMotif(0,  n[0], n[1], n[2]);     }
#line 1123 "parser.cc"
    break;

  case 53: // color: COULEURMOTIF HEXCODE numeroDeTortue
#line 275 "../parser/parser.yy"
                                         {     std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurMotif(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 1129 "parser.cc"
    break;

  case 54: // argumentsOuRien: ARGUMENTS
#line 281 "../parser/parser.yy"
              {
        std::vector<std::string> chainearguments = split(yystack_[0].value.as < std::string > ()," ");
        std::vector<int> arguments;
        for(auto chaine : chainearguments) arguments.push_back( std::stoi(chaine) );
        yylhs.value.as < std::vector<int> > () = arguments;
    }
#line 1140 "parser.cc"
    break;

  case 55: // argumentsOuRien: finDeLigne
#line 287 "../parser/parser.yy"
                 { yylhs.value.as < std::vector<int> > () = {0};}
#line 1146 "parser.cc"
    break;

  case 56: // fonction: FONCTION NAME THEN finDeLigne
#line 290 "../parser/parser.yy"
                                  {
        std::string nom = yystack_[2].value.as < std::string > ();
        auto found = std::find_if(listefonction.begin(), listefonction.end(), [nom](auto i){ return i->nom() == nom; });

        // s'il n'y a pas déjà de fonction avec le même nom, on ajoute
        if (found == listefonction.end()) listefonction.push_front( std::make_shared<fonction>(yystack_[2].value.as < std::string > ()) ); 
        else std::cout << "fonction déjà déclarée" << std::endl;
    }
#line 1159 "parser.cc"
    break;

  case 57: // fonction: NAME argumentsOuRien
#line 298 "../parser/parser.yy"
                           {
        auto it (listefonction.begin());
        while (it != listefonction.end() || (*it)->nom() != yystack_[1].value.as < std::string > ()) it++;
        if (it != listefonction.end()){
            for(auto i : yystack_[0].value.as < std::vector<int> > ()) std::cout << i << std::endl;

            (*it)->setArguments(yystack_[0].value.as < std::vector<int> > ());
            (*it)->executer();
        }
    }
#line 1174 "parser.cc"
    break;

  case 58: // fonction: ENDFONCTION finDeLigne
#line 308 "../parser/parser.yy"
                             {
        listefonction.front()->completer();
    }
#line 1182 "parser.cc"
    break;

  case 59: // expression: operation
#line 316 "../parser/parser.yy"
              {
        try{
            yylhs.value.as < int > () = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
#line 1194 "parser.cc"
    break;

  case 60: // operation: NUMBER
#line 325 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 1202 "parser.cc"
    break;

  case 61: // operation: '(' operation ')'
#line 328 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 1210 "parser.cc"
    break;

  case 62: // operation: operation '+' operation
#line 331 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 1218 "parser.cc"
    break;

  case 63: // operation: operation '-' operation
#line 334 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 1226 "parser.cc"
    break;

  case 64: // operation: operation '*' operation
#line 337 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 1234 "parser.cc"
    break;

  case 65: // operation: operation '/' operation
#line 340 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 1242 "parser.cc"
    break;

  case 66: // operation: '-' operation
#line 343 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 1250 "parser.cc"
    break;


#line 1254 "parser.cc"

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





  const signed char  Parser ::yypact_ninf_ = -38;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
     118,   -38,    16,    40,    45,    53,    53,    53,    53,    53,
       2,    96,    96,     2,    96,    34,    96,    11,    31,    44,
      96,    12,    26,    28,    85,   118,   118,   118,   118,   -38,
     -38,   -38,   -38,   118,   118,    96,   118,   -38,   -38,   -38,
     -38,   -38,    34,    34,    96,   -38,   -38,    57,    48,   -38,
      57,   -38,    57,   -38,    57,   -38,    57,   -38,    19,   -38,
      71,   -38,   -38,    71,   -38,    52,   -38,    96,    96,    73,
     -38,   -38,   -38,   -38,    76,    76,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   118,   -38,   -38,   -33,   -38,   -38,    34,
      34,    34,    34,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,    87,    91,    92,    96,   -38,   -38,    96,
     -38,   -38,   -38,   -38,    33,    33,   -38,   -38,    57,    57,
      96,   -38,   -38,   -38,   -38,   -38
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,    14,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,    22,    23,     0,     0,     0,     0,    10,    15,    17,
      13,    60,     0,     0,     0,    18,    24,     0,    59,    26,
       0,    28,     0,    30,     0,    32,     0,    38,     0,    40,
       0,    43,    44,     0,    46,     0,    49,     0,     0,     0,
      58,    54,    55,    57,    50,    52,     1,     7,     8,     5,
       2,     3,     4,     0,     9,    66,     0,    19,    25,     0,
       0,     0,     0,    27,    29,    31,    33,    39,    41,    34,
      35,    36,    37,     0,     0,     0,     0,    11,    12,     0,
      51,    53,     6,    61,    63,    62,    64,    65,     0,     0,
       0,    47,    56,    42,    45,    48
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -38,     4,   -38,   -38,     7,     0,    -5,   -38,   -38,   -38,
     -38,   -38,    47,    94,   -38,   -38,   -38,   -38,   -38,    63,
     -37
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,    24,    25,    26,    44,    45,    46,    28,    29,    30,
      31,    32,   103,    60,    33,    34,    35,    73,    36,    47,
      48
  };

  const signed char
   Parser ::yytable_[] =
  {
      27,    49,    51,    53,    55,    85,    86,    89,    90,    91,
      92,    61,    62,   113,    64,     1,    66,     3,     4,    37,
      70,    72,    57,    58,    59,    27,    27,    27,    27,    77,
      78,    79,    80,    27,    27,    83,    27,    81,    82,    97,
      84,    98,    88,    38,    87,    93,    71,    94,    39,    95,
      67,    96,   114,   115,   116,   117,     1,   105,     3,     4,
       1,    68,     3,     4,    74,   106,    75,   107,   108,    50,
      52,    54,    56,    41,    42,    91,    92,    69,    65,    43,
      40,   110,   111,    27,    40,    76,   109,   112,    89,    90,
      91,    92,    41,    42,    99,   100,   101,   102,    43,     1,
     118,     3,     4,    40,   119,   120,   121,    63,     0,   122,
     104,     0,     0,   123,   124,     0,     0,     0,     0,     0,
     125,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,     0,    19,
      20,    21,     0,     0,    22,    23
  };

  const signed char
   Parser ::yycheck_[] =
  {
       0,     6,     7,     8,     9,    42,    43,    40,    41,    42,
      43,    11,    12,    46,    14,     3,    16,     5,     6,     3,
      20,    21,    20,    21,    22,    25,    26,    27,    28,    25,
      26,    27,    28,    33,    34,    35,    36,    33,    34,    20,
      36,    22,    47,     3,    44,    50,    34,    52,     3,    54,
      39,    56,    89,    90,    91,    92,     3,     5,     5,     6,
       3,    30,     5,     6,    38,    13,    38,    67,    68,     6,
       7,     8,     9,    39,    40,    42,    43,    33,    15,    45,
      27,    74,    75,    83,    27,     0,    13,    83,    40,    41,
      42,    43,    39,    40,    23,    24,    25,    26,    45,     3,
      13,     5,     6,    27,    13,    13,   106,    13,    -1,   109,
      63,    -1,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,
     120,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    -1,    -1,    36,    37
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    28,    29,    31,
      32,    33,    36,    37,    48,    49,    50,    52,    54,    55,
      56,    57,    58,    61,    62,    63,    65,     3,     3,     3,
      27,    39,    40,    45,    51,    52,    53,    66,    67,    53,
      66,    53,    66,    53,    66,    53,    66,    20,    21,    22,
      60,    52,    52,    60,    52,    66,    52,    39,    30,    33,
      52,    34,    52,    64,    38,    38,     0,    48,    48,    48,
      48,    48,    48,    52,    48,    67,    67,    52,    53,    40,
      41,    42,    43,    53,    53,    53,    53,    20,    22,    23,
      24,    25,    26,    59,    59,     5,    13,    52,    52,    13,
      51,    51,    48,    46,    67,    67,    67,    67,    13,    13,
      13,    52,    52,    53,    53,    52
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    50,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    65,    66,
      67,    67,    67,    67,    67,    67,    67
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       2,     3,     3,     1,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     1,     1,     1,     1,     1,     2,
       1,     2,     5,     2,     2,     5,     2,     4,     5,     2,
       2,     3,     2,     3,     1,     1,     4,     2,     2,     1,
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
  "NUMTORTUE", "TORTUES", "JARDIN", "FILE", "FONCTION", "ENDFONCTION",
  "NAME", "ARGUMENTS", "NUMBERARG", "COULEUR", "COULEURMOTIF", "HEXCODE",
  "NUMBER", "'-'", "'+'", "'*'", "'/'", "NEG", "'('", "')'", "$accept",
  "programme", "tortues", "jardin", "numeroDeTortue", "finDeLigne",
  "numeroOuRien", "deplacement", "avancer", "reculer", "sauter", "tourner",
  "position", "condition", "conditionelle", "boucle", "color",
  "argumentsOuRien", "fonction", "expression", "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   117,   117,   118,   119,   120,   121,   122,   123,   124,
     126,   132,   143,   155,   158,   158,   158,   158,   166,   167,
     171,   172,   173,   174,   177,   181,   186,   190,   195,   199,
     204,   208,   212,   216,   224,   225,   226,   227,   230,   231,
     232,   233,   236,   241,   242,   247,   252,   257,   262,   267,
     272,   273,   274,   275,   281,   287,   290,   298,   308,   316,
     325,   328,   331,   334,   337,   340,   343
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
      45,    46,    42,    41,     2,    40,     2,    43,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    44
    };
    // Last valid token kind.
    const int code_max = 295;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1697 "parser.cc"

#line 347 "../parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
