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
<<<<<<< HEAD
    
    std::list< boucleEtConditionnellePtr > file;
    listePtr listeglobale = liste::fabrique();


#line 64 "parser.cc"
=======

#line 57 "parser.cc"
>>>>>>> couleur


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
<<<<<<< HEAD
#line 156 "parser.cc"
=======
#line 149 "parser.cc"
>>>>>>> couleur

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
<<<<<<< HEAD
      case symbol_kind::S_numeroOuRien: // numeroOuRien
=======
>>>>>>> couleur
      case symbol_kind::S_expression: // expression
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
<<<<<<< HEAD
      case symbol_kind::S_position: // position
=======
      case symbol_kind::S_HEXCODE: // HEXCODE
>>>>>>> couleur
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
<<<<<<< HEAD
      case symbol_kind::S_numeroOuRien: // numeroOuRien
=======
>>>>>>> couleur
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
<<<<<<< HEAD
      case symbol_kind::S_position: // position
=======
      case symbol_kind::S_HEXCODE: // HEXCODE
>>>>>>> couleur
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
<<<<<<< HEAD
      case symbol_kind::S_numeroOuRien: // numeroOuRien
=======
>>>>>>> couleur
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
<<<<<<< HEAD
      case symbol_kind::S_position: // position
=======
      case symbol_kind::S_HEXCODE: // HEXCODE
>>>>>>> couleur
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
<<<<<<< HEAD
      case symbol_kind::S_numeroOuRien: // numeroOuRien
=======
>>>>>>> couleur
      case symbol_kind::S_expression: // expression
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
<<<<<<< HEAD
      case symbol_kind::S_position: // position
=======
      case symbol_kind::S_HEXCODE: // HEXCODE
>>>>>>> couleur
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
<<<<<<< HEAD
      case symbol_kind::S_numeroOuRien: // numeroOuRien
=======
>>>>>>> couleur
      case symbol_kind::S_expression: // expression
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
<<<<<<< HEAD
      case symbol_kind::S_position: // position
=======
      case symbol_kind::S_HEXCODE: // HEXCODE
>>>>>>> couleur
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
<<<<<<< HEAD
      case symbol_kind::S_numeroOuRien: // numeroOuRien
=======
>>>>>>> couleur
      case symbol_kind::S_expression: // expression
        value.move< int > (that.value);
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
<<<<<<< HEAD
      case symbol_kind::S_position: // position
=======
      case symbol_kind::S_HEXCODE: // HEXCODE
>>>>>>> couleur
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
<<<<<<< HEAD
      case symbol_kind::S_numeroOuRien: // numeroOuRien
=======
>>>>>>> couleur
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_NUMTORTUE: // NUMTORTUE
<<<<<<< HEAD
      case symbol_kind::S_position: // position
=======
      case symbol_kind::S_HEXCODE: // HEXCODE
>>>>>>> couleur
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
  case 6: // programme: END NL
#line 96 "../parser/parser.yy"
             {  
        listeglobale->executer(); 
        listeglobale->vider();
        YYACCEPT;   
    }
#line 784 "parser.cc"
    break;

  case 7: // numeroDeTortue: NUMTORTUE
#line 103 "../parser/parser.yy"
              {  yylhs.value.as < int > () = std::stoi(yystack_[0].value.as < std::string > ().substr(1));   }
#line 790 "parser.cc"
    break;

  case 12: // numeroOuRien: finDeLigne
#line 111 "../parser/parser.yy"
               { yylhs.value.as < int > () = 0; }
#line 796 "parser.cc"
    break;

  case 13: // numeroOuRien: numeroDeTortue finDeLigne
#line 112 "../parser/parser.yy"
                                { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 802 "parser.cc"
    break;

  case 18: // avancer: AVANCE numeroOuRien
#line 122 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant));
    }
#line 811 "parser.cc"
    break;

  case 19: // avancer: AVANCE expression numeroOuRien
#line 126 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant));  
    }
#line 820 "parser.cc"
    break;

  case 20: // reculer: RECULE numeroOuRien
#line 131 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere));
    }
#line 829 "parser.cc"
    break;

  case 21: // reculer: RECULE expression numeroOuRien
#line 135 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere));  
    }
#line 838 "parser.cc"
    break;

  case 22: // sauter: SAUTE numeroOuRien
#line 140 "../parser/parser.yy"
                      {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant));
    }
#line 847 "parser.cc"
    break;

  case 23: // sauter: SAUTE expression numeroOuRien
#line 144 "../parser/parser.yy"
                                   { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant));  
    }
#line 856 "parser.cc"
    break;

  case 24: // tourner: TOURNED numeroOuRien
#line 149 "../parser/parser.yy"
                        {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite));
    }
#line 865 "parser.cc"
    break;

  case 25: // tourner: TOURNED expression numeroOuRien
#line 153 "../parser/parser.yy"
                                     {  
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite));
    }
#line 874 "parser.cc"
    break;

  case 26: // tourner: TOURNEG numeroOuRien
#line 157 "../parser/parser.yy"
                          {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche));
    }
#line 883 "parser.cc"
    break;

  case 27: // tourner: TOURNEG expression numeroOuRien
#line 161 "../parser/parser.yy"
                                     {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche));
    }
#line 892 "parser.cc"
    break;

  case 28: // position: DEVANT
#line 169 "../parser/parser.yy"
           {    yylhs.value.as < std::string > () = "devant";   }
#line 898 "parser.cc"
    break;

  case 29: // position: DERRIERE
#line 170 "../parser/parser.yy"
               {  yylhs.value.as < std::string > () = "derrière"; }
#line 904 "parser.cc"
    break;

  case 30: // position: DROITE
#line 171 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à droite"; }
#line 910 "parser.cc"
    break;

  case 31: // position: GAUCHE
#line 172 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à gauche"; }
#line 916 "parser.cc"
    break;

  case 32: // condition: MUR
#line 175 "../parser/parser.yy"
        {          yylhs.value.as < bool > () = true;   }
#line 922 "parser.cc"
    break;

  case 33: // condition: NOT MUR
#line 176 "../parser/parser.yy"
              {    yylhs.value.as < bool > () = false;  }
#line 928 "parser.cc"
    break;

  case 34: // condition: VIDE
#line 177 "../parser/parser.yy"
           {       yylhs.value.as < bool > () = false;  }
#line 934 "parser.cc"
    break;

  case 35: // condition: NOT VIDE
#line 178 "../parser/parser.yy"
               {   yylhs.value.as < bool > () = true;   }
#line 940 "parser.cc"
    break;

  case 36: // conditionelle: SI condition position THEN numeroOuRien
#line 181 "../parser/parser.yy"
                                            {
        auto instptr = std::make_shared<conditionnelle>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 950 "parser.cc"
    break;

  case 37: // conditionelle: SINON finDeLigne
#line 186 "../parser/parser.yy"
                       {    file.front()->changement_then_else();   }
#line 956 "parser.cc"
    break;

  case 38: // conditionelle: ENDIF finDeLigne
#line 187 "../parser/parser.yy"
                       {    file.pop_front();                       }
#line 962 "parser.cc"
    break;

  case 39: // boucle: WHILE condition position THEN numeroOuRien
#line 192 "../parser/parser.yy"
                                               {
        auto instptr = std::make_shared<tantque>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 972 "parser.cc"
    break;

  case 40: // boucle: ENDWHILE finDeLigne
#line 197 "../parser/parser.yy"
                          {
        file.pop_front();
    }
#line 980 "parser.cc"
    break;

  case 41: // boucle: REPETE expression THEN finDeLigne
#line 202 "../parser/parser.yy"
                                        {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[2].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 990 "parser.cc"
    break;

  case 42: // boucle: REPETE expression FOIS THEN finDeLigne
#line 207 "../parser/parser.yy"
                                             {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[3].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1000 "parser.cc"
    break;

  case 43: // boucle: ENDREPETE finDeLigne
#line 212 "../parser/parser.yy"
                           {
        file.pop_front();
    }
#line 1008 "parser.cc"
    break;

  case 44: // expression: operation
#line 221 "../parser/parser.yy"
=======
  case 5: // programme: END NL
#line 72 "../parser/parser.yy"
             {  YYACCEPT;   }
#line 738 "parser.cc"
    break;

  case 6: // numeroDeTortue: NUMTORTUE
#line 75 "../parser/parser.yy"
              {  yylhs.value.as < int > () = std::stoi(yystack_[0].value.as < std::string > ().substr(1));   }
#line 744 "parser.cc"
    break;

  case 11: // deplacement: AVANCE
#line 82 "../parser/parser.yy"
           {                driver.avancerTortue(0,1);                              }
#line 750 "parser.cc"
    break;

  case 12: // deplacement: AVANCE expression
#line 83 "../parser/parser.yy"
                        {   for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue(0,1);   }
#line 756 "parser.cc"
    break;

  case 13: // deplacement: RECULE
#line 85 "../parser/parser.yy"
             {            driver.avancerTortue( 0, (-1) );        }
#line 762 "parser.cc"
    break;

  case 14: // deplacement: RECULE expression
#line 86 "../parser/parser.yy"
                        { for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue( 0, -1 );   }
#line 768 "parser.cc"
    break;

  case 15: // deplacement: SAUTE
#line 88 "../parser/parser.yy"
            {            driver.avancerTortue(0,2);      }
#line 774 "parser.cc"
    break;

  case 16: // deplacement: SAUTE expression
#line 89 "../parser/parser.yy"
                       { for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.avancerTortue(0,2);   }
#line 780 "parser.cc"
    break;

  case 17: // deplacement: TOURNED
#line 91 "../parser/parser.yy"
                      {   driver.changerOrientationTortue(0, "droite");    }
#line 786 "parser.cc"
    break;

  case 18: // deplacement: TOURNED NUMBER
#line 92 "../parser/parser.yy"
                      {   for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.changerOrientationTortue(0, "droite");   }
#line 792 "parser.cc"
    break;

  case 19: // deplacement: TOURNEG
#line 93 "../parser/parser.yy"
                      {   driver.changerOrientationTortue(0, "gauche");    }
#line 798 "parser.cc"
    break;

  case 20: // deplacement: TOURNEG NUMBER
#line 94 "../parser/parser.yy"
                      {   for (int i(0) ; i<yystack_[0].value.as < int > (); i++) driver.changerOrientationTortue(0, "gauche");   }
#line 804 "parser.cc"
    break;

  case 21: // color: COULEUR HEXCODE
#line 100 "../parser/parser.yy"
                    {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurCarapace(0,  n[0], n[1], n[2]);     }
#line 810 "parser.cc"
    break;

  case 22: // color: COULEUR HEXCODE numeroDeTortue
#line 101 "../parser/parser.yy"
                                     {  std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurCarapace(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 816 "parser.cc"
    break;

  case 23: // color: COULEURMOTIF HEXCODE
#line 102 "../parser/parser.yy"
                           {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurMotif(0,  n[0], n[1], n[2]);     }
#line 822 "parser.cc"
    break;

  case 24: // color: COULEURMOTIF HEXCODE numeroDeTortue
#line 103 "../parser/parser.yy"
                                         {     std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurMotif(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 828 "parser.cc"
    break;

  case 25: // expression: operation
#line 108 "../parser/parser.yy"
>>>>>>> couleur
              {
        try{
            yylhs.value.as < int > () = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
<<<<<<< HEAD
#line 1020 "parser.cc"
    break;

  case 45: // operation: NUMBER
#line 230 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 1028 "parser.cc"
    break;

  case 46: // operation: '(' operation ')'
#line 233 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 1036 "parser.cc"
    break;

  case 47: // operation: operation '+' operation
#line 236 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 1044 "parser.cc"
    break;

  case 48: // operation: operation '-' operation
#line 239 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 1052 "parser.cc"
    break;

  case 49: // operation: operation '*' operation
#line 242 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 1060 "parser.cc"
    break;

  case 50: // operation: operation '/' operation
#line 245 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 1068 "parser.cc"
    break;

  case 51: // operation: '-' operation
#line 248 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 1076 "parser.cc"
    break;


#line 1080 "parser.cc"
=======
#line 840 "parser.cc"
    break;

  case 26: // operation: NUMBER
#line 117 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 848 "parser.cc"
    break;

  case 27: // operation: '(' operation ')'
#line 120 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 856 "parser.cc"
    break;

  case 28: // operation: operation '+' operation
#line 123 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 864 "parser.cc"
    break;

  case 29: // operation: operation '-' operation
#line 126 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 872 "parser.cc"
    break;

  case 30: // operation: operation '*' operation
#line 129 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 880 "parser.cc"
    break;

  case 31: // operation: operation '/' operation
#line 132 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 888 "parser.cc"
    break;

  case 32: // operation: '-' operation
#line 135 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 896 "parser.cc"
    break;


#line 900 "parser.cc"
>>>>>>> couleur

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
  const signed char  Parser ::yypact_ninf_ = -30;
=======
  const signed char  Parser ::yypact_ninf_ = -17;
>>>>>>> couleur

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
<<<<<<< HEAD
      56,   -30,     7,    12,    17,    23,    23,    23,    23,    23,
      87,   100,   100,    87,   100,    -7,   100,    13,    56,    56,
     -30,   -30,   -30,   -30,    56,    56,   -30,   -30,   -30,   -30,
     -30,    -7,    -7,   100,   -30,   -30,    42,    24,   -30,    42,
     -30,    42,   -30,    42,   -30,    42,   -30,    10,   -30,    76,
     -30,   -30,    76,   -30,     4,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,    63,   -30,   -30,    -7,    -7,    -7,    -7,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,    22,
      26,    33,   100,   -30,   -26,   -26,   -30,   -30,    42,    42,
     100,   -30,   -30,   -30,   -30
=======
       4,   -17,    15,    39,    40,    13,    13,    13,    28,    29,
      32,    33,    46,     4,    31,    31,   -17,   -17,   -17,   -17,
      13,    13,   -17,   -16,   -17,   -17,   -17,   -17,    35,    35,
     -17,   -17,     4,     4,   -17,     8,    13,    13,    13,    13,
     -17,   -17,   -17,   -17,   -17,   -17,    19,    19,   -17,   -17
>>>>>>> couleur
  };

  const signed char
   Parser ::yydefact_[] =
  {
<<<<<<< HEAD
       0,     8,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    16,    17,     0,     0,     6,     9,    11,     7,
      45,     0,     0,     0,    12,    18,     0,    44,    20,     0,
      22,     0,    24,     0,    26,     0,    32,     0,    34,     0,
      37,    38,     0,    40,     0,    43,     1,     5,     2,     3,
       4,    51,     0,    13,    19,     0,     0,     0,     0,    21,
      23,    25,    27,    33,    35,    28,    29,    30,    31,     0,
       0,     0,     0,    46,    48,    47,    49,    50,     0,     0,
       0,    41,    36,    39,    42
=======
       0,     7,     0,     0,     9,    11,    13,    15,    17,    19,
       0,     0,     0,     0,     0,     0,     5,     8,    10,    26,
       0,     0,    12,    25,    14,    16,    18,    20,    21,    23,
       1,     4,     0,     0,    32,     0,     0,     0,     0,     0,
       6,    22,    24,     2,     3,    27,    29,    28,    30,    31
>>>>>>> couleur
  };

  const signed char
   Parser ::yypgoto_[] =
  {
<<<<<<< HEAD
     -30,    62,   -30,     0,    -5,   -30,   -30,   -30,   -30,   -30,
     -29,    36,   -30,   -30,    70,   -24
=======
     -17,   -13,    21,    18,   -17,   -17,    34,   -15
>>>>>>> couleur
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
<<<<<<< HEAD
       0,    17,    33,    34,    35,    19,    20,    21,    22,    23,
      79,    49,    24,    25,    36,    37
=======
       0,    12,    41,    13,    14,    15,    22,    23
>>>>>>> couleur
  };

  const signed char
   Parser ::yytable_[] =
  {
<<<<<<< HEAD
      18,    38,    40,    42,    44,    67,    68,    61,    62,    81,
      26,    50,    51,    56,    53,    27,    55,    82,    18,    18,
      28,    30,    31,    80,    18,    18,     1,    32,     3,     4,
      73,    64,    74,    63,    69,    88,    70,     0,    71,    89,
      72,    84,    85,    86,    87,     1,    90,     3,     4,    52,
      29,    30,    31,    65,    66,    67,    68,    32,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    29,
      11,    12,    13,    14,    15,    16,    39,    41,    43,    45,
      57,    58,    91,    92,    93,    54,    59,    60,     0,     0,
      94,     0,    65,    66,    67,    68,     0,     0,    83,    75,
      76,    77,    78,     1,     0,     3,     4,    46,    47,    48
=======
      31,    36,    37,    38,    39,    34,    35,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    16,    43,
      44,    46,    47,    48,    49,    36,    37,    38,    39,    19,
      20,    45,    32,    33,     1,    21,     3,     4,    38,    39,
      24,    25,    17,    18,    26,    27,    30,    28,    29,    40,
      42
>>>>>>> couleur
  };

  const signed char
   Parser ::yycheck_[] =
  {
<<<<<<< HEAD
       0,     6,     7,     8,     9,    31,    32,    31,    32,     5,
       3,    11,    12,     0,    14,     3,    16,    13,    18,    19,
       3,    28,    29,    52,    24,    25,     3,    34,     5,     6,
      20,    36,    22,    33,    39,    13,    41,    -1,    43,    13,
      45,    65,    66,    67,    68,     3,    13,     5,     6,    13,
      27,    28,    29,    29,    30,    31,    32,    34,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    27,
      14,    15,    16,    17,    18,    19,     6,     7,     8,     9,
      18,    19,    82,    88,    89,    15,    24,    25,    -1,    -1,
      90,    -1,    29,    30,    31,    32,    -1,    -1,    35,    23,
      24,    25,    26,     3,    -1,     5,     6,    20,    21,    22
=======
      13,    17,    18,    19,    20,    20,    21,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,    32,
      33,    36,    37,    38,    39,    17,    18,    19,    20,    16,
      17,    23,    14,    15,     3,    22,     5,     6,    19,    20,
       6,     7,     3,     3,    16,    16,     0,    15,    15,    14,
      29
>>>>>>> couleur
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
<<<<<<< HEAD
      12,    14,    15,    16,    17,    18,    19,    37,    39,    41,
      42,    43,    44,    45,    48,    49,     3,     3,     3,    27,
      28,    29,    34,    38,    39,    40,    50,    51,    40,    50,
      40,    50,    40,    50,    40,    50,    20,    21,    22,    47,
      39,    39,    47,    39,    50,    39,     0,    37,    37,    37,
      37,    51,    51,    39,    40,    29,    30,    31,    32,    40,
      40,    40,    40,    20,    22,    23,    24,    25,    26,    46,
      46,     5,    13,    35,    51,    51,    51,    51,    13,    13,
      13,    39,    40,    40,    39
=======
      12,    13,    25,    27,    28,    29,     3,     3,     3,    16,
      17,    22,    30,    31,    30,    30,    16,    16,    15,    15,
       0,    25,    27,    27,    31,    31,    17,    18,    19,    20,
      14,    26,    26,    25,    25,    23,    31,    31,    31,    31
>>>>>>> couleur
  };

  const signed char
   Parser ::yyr1_[] =
  {
<<<<<<< HEAD
       0,    36,    37,    37,    37,    37,    37,    38,    39,    39,
      39,    39,    40,    40,    41,    41,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    45,    45,    46,    46,
      46,    46,    47,    47,    47,    47,    48,    48,    48,    49,
      49,    49,    49,    49,    50,    51,    51,    51,    51,    51,
      51,    51
=======
       0,    24,    25,    25,    25,    25,    26,    27,    27,    27,
      27,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    29,    29,    29,    29,    30,    31,    31,    31,    31,
      31,    31,    31
>>>>>>> couleur
  };

  const signed char
   Parser ::yyr2_[] =
  {
<<<<<<< HEAD
       0,     2,     2,     2,     2,     2,     2,     1,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     2,     1,     2,     5,     2,     2,     5,
       2,     4,     5,     2,     1,     1,     3,     3,     3,     3,
       3,     2
=======
       0,     2,     3,     3,     2,     2,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     2,     3,     2,     3,     1,     1,     3,     3,     3,
       3,     3,     2
>>>>>>> couleur
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END", "FOIS",
<<<<<<< HEAD
  "COMMENTAIRE", "AVANCE", "RECULE", "SAUTE", "TOURNED", "TOURNEG", "SI",
  "THEN", "SINON", "ENDIF", "WHILE", "ENDWHILE", "REPETE", "ENDREPETE",
  "MUR", "NOT", "VIDE", "DEVANT", "DERRIERE", "DROITE", "GAUCHE",
  "NUMTORTUE", "NUMBER", "'-'", "'+'", "'*'", "'/'", "NEG", "'('", "')'",
  "$accept", "programme", "numeroDeTortue", "finDeLigne", "numeroOuRien",
  "deplacement", "avancer", "reculer", "sauter", "tourner", "position",
  "condition", "conditionelle", "boucle", "expression", "operation", YY_NULLPTR
=======
  "COMMENTAIRE", "AVANCE", "RECULE", "SAUTE", "TOURNED", "TOURNEG",
  "COULEUR", "COULEURMOTIF", "NUMTORTUE", "HEXCODE", "NUMBER", "'-'",
  "'+'", "'*'", "'/'", "NEG", "'('", "')'", "$accept", "programme",
  "numeroDeTortue", "finDeLigne", "deplacement", "color", "expression",
  "operation", YY_NULLPTR
>>>>>>> couleur
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
<<<<<<< HEAD
       0,    91,    91,    92,    93,    94,    96,   103,   106,   106,
     106,   106,   111,   112,   116,   117,   118,   119,   122,   126,
     131,   135,   140,   144,   149,   153,   157,   161,   169,   170,
     171,   172,   175,   176,   177,   178,   181,   186,   187,   192,
     197,   202,   207,   212,   221,   230,   233,   236,   239,   242,
     245,   248
=======
       0,    68,    68,    69,    70,    72,    75,    78,    78,    78,
      78,    82,    83,    85,    86,    88,    89,    91,    92,    93,
      94,   100,   101,   102,   103,   108,   117,   120,   123,   126,
     129,   132,   135
>>>>>>> couleur
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
      34,    35,    31,    30,     2,    29,     2,    32,     2,     2,
=======
      22,    23,    19,    18,     2,    17,     2,    20,     2,     2,
>>>>>>> couleur
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
<<<<<<< HEAD
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    33
    };
    // Last valid token kind.
    const int code_max = 284;
=======
      15,    16,    21
    };
    // Last valid token kind.
    const int code_max = 272;
>>>>>>> couleur

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
<<<<<<< HEAD
#line 1495 "parser.cc"

#line 252 "../parser/parser.yy"
=======
#line 1279 "parser.cc"

#line 139 "../parser/parser.yy"
>>>>>>> couleur


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
