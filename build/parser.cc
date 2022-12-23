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

    
    #include "scanner.hh"
    #include "driver.hh"
    #include "structureTortue/instruction.hh"
    #include "structureTortue/liste.hh"

    #undef  yylex
    #define yylex scanner.yylex
    
    std::list< boucleEtConditionnellePtr > file;
    listePtr listeglobale = liste::fabrique();


#line 67 "parser.cc"


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
#line 159 "parser.cc"

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
      case symbol_kind::S_FILE: // FILE
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
      case symbol_kind::S_FILE: // FILE
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
      case symbol_kind::S_FILE: // FILE
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
      case symbol_kind::S_FILE: // FILE
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
      case symbol_kind::S_FILE: // FILE
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
      case symbol_kind::S_FILE: // FILE
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
  case 9: // programme: END NL
#line 112 "../parser/parser.yy"
             {  
        listeglobale->executer(); 
        listeglobale->vider();
        YYACCEPT;   
    }
#line 801 "parser.cc"
    break;

  case 10: // tortues: TORTUES NUMBER finDeLigne
#line 118 "../parser/parser.yy"
                              {
        QSize tailleDuJardin = driver.getJardin()->tailleJardin();

        for(int i(0); i<yystack_[1].value.as < int > (); i++){
            int x = rand() % tailleDuJardin.width();
            int y = rand() % tailleDuJardin.height();
            driver.getJardin()->newTortue(x,y);
        }
    }
#line 815 "parser.cc"
    break;

  case 11: // jardin: JARDIN FILE finDeLigne
#line 129 "../parser/parser.yy"
                           {
        std::string s = yystack_[1].value.as < std::string > ().substr(1);
        std::string fichier = s.substr(0,s.size()-1);
        try {
            driver.getJardin()->construction(fichier.c_str());
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

    }
#line 830 "parser.cc"
    break;

  case 12: // numeroDeTortue: NUMTORTUE
#line 141 "../parser/parser.yy"
              {  yylhs.value.as < int > () = std::stoi(yystack_[0].value.as < std::string > ().substr(1));   }
#line 836 "parser.cc"
    break;

  case 17: // numeroOuRien: finDeLigne
#line 152 "../parser/parser.yy"
               { yylhs.value.as < int > () = 66; }
#line 842 "parser.cc"
    break;

  case 18: // numeroOuRien: numeroDeTortue finDeLigne
#line 153 "../parser/parser.yy"
                                { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 848 "parser.cc"
    break;

  case 23: // avancer: AVANCE numeroOuRien
#line 163 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::avant));
    }
#line 857 "parser.cc"
    break;

  case 24: // avancer: AVANCE expression numeroOuRien
#line 167 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::avant));  
    }
#line 866 "parser.cc"
    break;

  case 25: // reculer: RECULE numeroOuRien
#line 172 "../parser/parser.yy"
                       {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 1, direction::arriere));
    }
#line 875 "parser.cc"
    break;

  case 26: // reculer: RECULE expression numeroOuRien
#line 176 "../parser/parser.yy"
                                    { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (), direction::arriere));  
    }
#line 884 "parser.cc"
    break;

  case 27: // sauter: SAUTE numeroOuRien
#line 181 "../parser/parser.yy"
                      {                
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2, direction::avant));
    }
#line 893 "parser.cc"
    break;

  case 28: // sauter: SAUTE expression numeroOuRien
#line 185 "../parser/parser.yy"
                                   { 
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant) ); 
        else file.front()->ajouterInstruction(std::make_shared<mouvement>(driver.getJardin(), yystack_[0].value.as < int > (), 2*yystack_[1].value.as < int > (), direction::avant));  
    }
#line 902 "parser.cc"
    break;

  case 29: // tourner: TOURNED numeroOuRien
#line 190 "../parser/parser.yy"
                        {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::droite));
    }
#line 911 "parser.cc"
    break;

  case 30: // tourner: TOURNED expression numeroOuRien
#line 194 "../parser/parser.yy"
                                     {  
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::droite));
    }
#line 920 "parser.cc"
    break;

  case 31: // tourner: TOURNEG numeroOuRien
#line 198 "../parser/parser.yy"
                          {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), 1,  sens::gauche));
    }
#line 929 "parser.cc"
    break;

  case 32: // tourner: TOURNEG expression numeroOuRien
#line 202 "../parser/parser.yy"
                                     {
        if (file.empty()) listeglobale->ajouterInstruction( std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche) ); 
        else file.front()->ajouterInstruction(std::make_shared<tourner>(driver.getJardin(), yystack_[0].value.as < int > (), yystack_[1].value.as < int > (),  sens::gauche));
    }
#line 938 "parser.cc"
    break;

  case 33: // position: DEVANT
#line 210 "../parser/parser.yy"
           {    yylhs.value.as < std::string > () = "devant";   }
#line 944 "parser.cc"
    break;

  case 34: // position: DERRIERE
#line 211 "../parser/parser.yy"
               {  yylhs.value.as < std::string > () = "derrière"; }
#line 950 "parser.cc"
    break;

  case 35: // position: DROITE
#line 212 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à droite"; }
#line 956 "parser.cc"
    break;

  case 36: // position: GAUCHE
#line 213 "../parser/parser.yy"
             {    yylhs.value.as < std::string > () = "à gauche"; }
#line 962 "parser.cc"
    break;

  case 37: // condition: MUR
#line 216 "../parser/parser.yy"
        {          yylhs.value.as < bool > () = true;   }
#line 968 "parser.cc"
    break;

  case 38: // condition: NOT MUR
#line 217 "../parser/parser.yy"
              {    yylhs.value.as < bool > () = false;  }
#line 974 "parser.cc"
    break;

  case 39: // condition: VIDE
#line 218 "../parser/parser.yy"
           {       yylhs.value.as < bool > () = false;  }
#line 980 "parser.cc"
    break;

  case 40: // condition: NOT VIDE
#line 219 "../parser/parser.yy"
               {   yylhs.value.as < bool > () = true;   }
#line 986 "parser.cc"
    break;

  case 41: // conditionelle: SI condition position THEN numeroOuRien
#line 222 "../parser/parser.yy"
                                            {
        auto instptr = std::make_shared<conditionnelle>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 996 "parser.cc"
    break;

  case 42: // conditionelle: SINON finDeLigne
#line 227 "../parser/parser.yy"
                       {    file.front()->changement_then_else();   }
#line 1002 "parser.cc"
    break;

  case 43: // conditionelle: ENDIF finDeLigne
#line 228 "../parser/parser.yy"
                       {    file.pop_front();                       }
#line 1008 "parser.cc"
    break;

  case 44: // boucle: WHILE condition position THEN numeroOuRien
#line 233 "../parser/parser.yy"
                                               {
        auto instptr = std::make_shared<tantque>(driver.getJardin(), 0, yystack_[3].value.as < bool > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1018 "parser.cc"
    break;

  case 45: // boucle: ENDWHILE finDeLigne
#line 238 "../parser/parser.yy"
                          {
        file.pop_front();
    }
#line 1026 "parser.cc"
    break;

  case 46: // boucle: REPETE expression THEN finDeLigne
#line 243 "../parser/parser.yy"
                                        {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[2].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1036 "parser.cc"
    break;

  case 47: // boucle: REPETE expression FOIS THEN finDeLigne
#line 248 "../parser/parser.yy"
                                             {
        auto instptr = std::make_shared<repete>(driver.getJardin(), 0, yystack_[3].value.as < int > ());
        listeglobale->ajouterInstruction(instptr);
        file.push_front(instptr);
    }
#line 1046 "parser.cc"
    break;

  case 48: // boucle: ENDREPETE finDeLigne
#line 253 "../parser/parser.yy"
                           {
        file.pop_front();
    }
#line 1054 "parser.cc"
    break;

  case 49: // color: COULEUR HEXCODE
#line 258 "../parser/parser.yy"
                    {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurCarapace(0,  n[0], n[1], n[2]);     }
#line 1060 "parser.cc"
    break;

  case 50: // color: COULEUR HEXCODE numeroDeTortue
#line 259 "../parser/parser.yy"
                                     {  std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurCarapace(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 1066 "parser.cc"
    break;

  case 51: // color: COULEURMOTIF HEXCODE
#line 260 "../parser/parser.yy"
                           {                   std::array<int, 3> n = convert(yystack_[0].value.as < std::string > ());     driver.changeCouleurMotif(0,  n[0], n[1], n[2]);     }
#line 1072 "parser.cc"
    break;

  case 52: // color: COULEURMOTIF HEXCODE numeroDeTortue
#line 261 "../parser/parser.yy"
                                         {     std::array<int, 3> n = convert(yystack_[1].value.as < std::string > ());     driver.changeCouleurMotif(yystack_[0].value.as < int > (), n[0], n[1], n[2]);     }
#line 1078 "parser.cc"
    break;

  case 53: // expression: operation
#line 268 "../parser/parser.yy"
              {
        try{
            yylhs.value.as < int > () = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
#line 1090 "parser.cc"
    break;

  case 54: // operation: NUMBER
#line 277 "../parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 1098 "parser.cc"
    break;

  case 55: // operation: '(' operation ')'
#line 280 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 1106 "parser.cc"
    break;

  case 56: // operation: operation '+' operation
#line 283 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 1114 "parser.cc"
    break;

  case 57: // operation: operation '-' operation
#line 286 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 1122 "parser.cc"
    break;

  case 58: // operation: operation '*' operation
#line 289 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 1130 "parser.cc"
    break;

  case 59: // operation: operation '/' operation
#line 292 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 1138 "parser.cc"
    break;

  case 60: // operation: '-' operation
#line 295 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 1146 "parser.cc"
    break;


#line 1150 "parser.cc"

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
      76,   -38,     7,    30,    32,    31,    31,    31,    31,    31,
     105,   118,   118,   105,   118,    38,   118,     5,    12,    11,
      13,    56,    76,    76,    76,    76,   -38,   -38,   -38,   -38,
      76,    76,   118,   -38,   -38,   -38,   -38,   -38,    38,    38,
     118,   -38,   -38,    49,    62,   -38,    49,   -38,    49,   -38,
      49,   -38,    49,   -38,    -7,   -38,    94,   -38,   -38,    94,
     -38,     4,   -38,   118,   118,    26,    26,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,    76,   -38,    75,   -38,   -38,    38,
      38,    38,    38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,    44,    54,    64,   118,   -38,   -38,   -38,
     -38,   -38,   -38,   -32,   -32,   -38,   -38,    49,    49,   118,
     -38,   -38,   -38,   -38
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,    13,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,    21,    22,
       0,     0,     0,     9,    14,    16,    12,    54,     0,     0,
       0,    17,    23,     0,    53,    25,     0,    27,     0,    29,
       0,    31,     0,    37,     0,    39,     0,    42,    43,     0,
      45,     0,    48,     0,     0,    49,    51,     1,     7,     8,
       5,     2,     3,     4,     0,    60,     0,    18,    24,     0,
       0,     0,     0,    26,    28,    30,    32,    38,    40,    33,
      34,    35,    36,     0,     0,     0,     0,    10,    11,    50,
      52,     6,    55,    57,    56,    58,    59,     0,     0,     0,
      46,    41,    44,    47
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -38,    -4,   -38,   -38,   -37,     0,    -5,   -38,   -38,   -38,
     -38,   -38,    10,    88,   -38,   -38,   -38,    53,   -31
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,    21,    22,    23,    40,    41,    42,    25,    26,    27,
      28,    29,    93,    56,    30,    31,    32,    43,    44
  };

  const signed char
   Parser ::yytable_[] =
  {
      24,    45,    47,    49,    51,    81,    82,    75,    76,    95,
      33,    57,    58,    87,    60,    88,    62,    96,    68,    69,
      70,    71,    24,    24,    24,    24,    72,    73,    99,   100,
      24,    24,    74,    34,     1,    35,     3,     4,    78,    63,
      77,    83,    64,    84,    65,    85,    66,    86,   103,   104,
     105,   106,     1,    36,     3,     4,    67,   107,    36,    46,
      48,    50,    52,    97,    98,    37,    38,   108,    61,    94,
     101,    39,    37,    38,    24,     0,    36,   109,    39,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,    16,   110,    79,    80,    81,
      82,    59,   111,   112,    17,    18,     0,    19,    20,   113,
      79,    80,    81,    82,     0,     0,   102,    89,    90,    91,
      92,     1,     0,     3,     4,    53,    54,    55
  };

  const signed char
   Parser ::yycheck_[] =
  {
       0,     6,     7,     8,     9,    37,    38,    38,    39,     5,
       3,    11,    12,    20,    14,    22,    16,    13,    22,    23,
      24,    25,    22,    23,    24,    25,    30,    31,    65,    66,
      30,    31,    32,     3,     3,     3,     5,     6,    43,    34,
      40,    46,    30,    48,    33,    50,    33,    52,    79,    80,
      81,    82,     3,    27,     5,     6,     0,    13,    27,     6,
       7,     8,     9,    63,    64,    34,    35,    13,    15,    59,
      74,    40,    34,    35,    74,    -1,    27,    13,    40,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    96,    35,    36,    37,
      38,    13,   107,   108,    28,    29,    -1,    31,    32,   109,
      35,    36,    37,    38,    -1,    -1,    41,    23,    24,    25,
      26,     3,    -1,     5,     6,    20,    21,    22
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    28,    29,    31,
      32,    43,    44,    45,    47,    49,    50,    51,    52,    53,
      56,    57,    58,     3,     3,     3,    27,    34,    35,    40,
      46,    47,    48,    59,    60,    48,    59,    48,    59,    48,
      59,    48,    59,    20,    21,    22,    55,    47,    47,    55,
      47,    59,    47,    34,    30,    33,    33,     0,    43,    43,
      43,    43,    43,    43,    47,    60,    60,    47,    48,    35,
      36,    37,    38,    48,    48,    48,    48,    20,    22,    23,
      24,    25,    26,    54,    54,     5,    13,    47,    47,    46,
      46,    43,    41,    60,    60,    60,    60,    13,    13,    13,
      47,    48,    48,    47
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    45,    46,    47,    47,    47,    47,    48,    48,    49,
      49,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    55,
      55,    56,    56,    56,    57,    57,    57,    57,    57,    58,
      58,    58,    58,    59,    60,    60,    60,    60,    60,    60,
      60
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       3,     3,     1,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     1,     1,     1,     1,     1,     2,     1,
       2,     5,     2,     2,     5,     2,     4,     5,     2,     2,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
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
  "THEN", "SINON", "ENDIF", "WHILE", "ENDWHILE", "REPETE", "ENDREPETE",
  "MUR", "NOT", "VIDE", "DEVANT", "DERRIERE", "DROITE", "GAUCHE",
  "NUMTORTUE", "TORTUES", "JARDIN", "FILE", "COULEUR", "COULEURMOTIF",
  "HEXCODE", "NUMBER", "'-'", "'+'", "'*'", "'/'", "NEG", "'('", "')'",
  "$accept", "programme", "tortues", "jardin", "numeroDeTortue",
  "finDeLigne", "numeroOuRien", "deplacement", "avancer", "reculer",
  "sauter", "tourner", "position", "condition", "conditionelle", "boucle",
  "color", "expression", "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   104,   104,   105,   106,   107,   108,   109,   110,   112,
     118,   129,   141,   144,   144,   144,   144,   152,   153,   157,
     158,   159,   160,   163,   167,   172,   176,   181,   185,   190,
     194,   198,   202,   210,   211,   212,   213,   216,   217,   218,
     219,   222,   227,   228,   233,   238,   243,   248,   253,   258,
     259,   260,   261,   268,   277,   280,   283,   286,   289,   292,
     295
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
      40,    41,    37,    36,     2,    35,     2,    38,     2,     2,
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
      39
    };
    // Last valid token kind.
    const int code_max = 290;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1581 "parser.cc"

#line 299 "../parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
