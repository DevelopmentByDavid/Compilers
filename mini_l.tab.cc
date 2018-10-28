// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

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


// First part of user declarations.
#line 2 "mini_l.y" // lalr1.cc:407

 #include <stdio.h>
 #include <stdlib.h>
 #include <sstream>
//  void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;

#line 45 "mini_l.tab.cc" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "mini_l.tab.hh"

// User implementation prologue.

#line 59 "mini_l.tab.cc" // lalr1.cc:415


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



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 135 "mini_l.tab.cc" // lalr1.cc:491

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value (other.value)
  {
  }

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = s.value;
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state)
  {
    value = that.value;
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.value)
  {
    // that is emptied.
    that.type = empty_symbol;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

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
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 94 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) =  "program -> functions";}
#line 539 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 3:
#line 97 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "function -> functions";}
#line 545 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 4:
#line 98 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "function -> epsilon";}
#line 551 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 5:
#line 101 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "function -> long rule";}
#line 557 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 6:
#line 104 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "declarations -> declaration SEMICOLON declarations";}
#line 563 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 7:
#line 105 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "declarations -> epsilon";}
#line 569 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 8:
#line 108 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statements -> IDENT COMMA statements";}
#line 575 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 9:
#line 109 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statements -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER";}
#line 581 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 10:
#line 110 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statements -> IDENT COLON INTEGER";}
#line 587 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 11:
#line 113 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statements -> statement SEMICOLON statements";}
#line 593 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 12:
#line 114 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statements -> epsilon";}
#line 599 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 13:
#line 117 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> var ASSIGN expression";}
#line 605 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 14:
#line 118 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> IF bool_expr THEN statements ENDIF";}
#line 611 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 15:
#line 119 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> IF bool_expr THEN statements ELSE statements ENDIF";}
#line 617 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 16:
#line 120 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> WHILE bool_expr BEGINLOOP statements ENDLOOP";}
#line 623 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 17:
#line 121 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_expr";}
#line 629 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 18:
#line 122 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement ->  READ vars";}
#line 635 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 19:
#line 123 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> WRITE vars";}
#line 641 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 20:
#line 124 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> CONTINUE";}
#line 647 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 21:
#line 125 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "statement -> RETURN expression";}
#line 653 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 22:
#line 128 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "bool_expr -> relation_and_expr";}
#line 659 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 23:
#line 129 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "bool_expr -> relation_and_expr OR relation_and_expr";}
#line 665 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 24:
#line 132 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_and_expr -> relation_expr";}
#line 671 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 25:
#line 133 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_and_expr -> relation_expr AND relation_expr";}
#line 677 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 26:
#line 136 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> expression comp expression";}
#line 683 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 27:
#line 137 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> TRUE";}
#line 689 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 28:
#line 138 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> FALSE";}
#line 695 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 29:
#line 139 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> L_PAREN bool_expr R_PAREN";}
#line 701 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 30:
#line 140 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> NOT expression comp expression";}
#line 707 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 31:
#line 141 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> NOT TRUE";}
#line 713 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 32:
#line 142 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> NOT FALSE";}
#line 719 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 33:
#line 143 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "relation_expr -> NOT L_PAREN bool_expr R_PAREN";}
#line 725 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 34:
#line 146 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "comp -> EQ";}
#line 731 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 35:
#line 147 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "comp -> NEQ";}
#line 737 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 36:
#line 148 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "comp -> LT";}
#line 743 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 37:
#line 149 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "comp -> GT";}
#line 749 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 38:
#line 150 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "comp -> LTE";}
#line 755 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 39:
#line 151 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "comp -> GTE";}
#line 761 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 40:
#line 154 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "expression -> multiplicative_expr";}
#line 767 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 41:
#line 155 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "expression -> multiplicative_expr SUB multiplicative_expr";}
#line 773 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 42:
#line 156 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "expression -> multiplicative_expr ADD multiplicative_expr";}
#line 779 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 43:
#line 159 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "expressions -> expression COMMA expressions";}
#line 785 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 44:
#line 160 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "expressions -> epsilon";}
#line 791 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 45:
#line 163 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "multiplicative_expr -> term";}
#line 797 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 46:
#line 164 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "multiplicative_expr -> term MOD term";}
#line 803 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 47:
#line 165 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "multiplicative_expr -> term DIV term";}
#line 809 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 48:
#line 166 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "multiplicative_expr -> term MULT term";}
#line 815 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 49:
#line 169 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "term -> IDENT L_PAREN expression R_PAREN";}
#line 821 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 50:
#line 170 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "term -> NUMBER";}
#line 827 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 51:
#line 171 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "term -> var";}
#line 833 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 52:
#line 172 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "term -> L_PAREN expressions R_PAREN";}
#line 839 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 53:
#line 173 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "term -> SUB NUMBER";}
#line 845 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 54:
#line 174 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "term -> SUB var";}
#line 851 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 55:
#line 175 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "term -> SUB L_PAREN expressions R_PAREN";}
#line 857 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 56:
#line 178 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "var -> IDENT";}
#line 863 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 57:
#line 179 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET";}
#line 869 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 58:
#line 181 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "vars -> var COMMA vars";}
#line 875 "mini_l.tab.cc" // lalr1.cc:870
    break;

  case 59:
#line 182 "mini_l.y" // lalr1.cc:870
    {(yylhs.value.myType) = "vars -> epsilon";}
#line 881 "mini_l.tab.cc" // lalr1.cc:870
    break;


#line 885 "mini_l.tab.cc" // lalr1.cc:870
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -65;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       1,     2,   -65,     8,   -65,     1,   -65,   -19,   -65,   -65,
      36,   -16,    51,    19,    31,   -65,    27,    84,    42,   -16,
     -65,    12,   -11,   -11,    47,   -65,    -6,    -6,    15,    45,
     -65,    40,    75,   -65,   109,   -65,    87,    89,   -65,   -65,
     -28,   -65,    41,    28,   112,    97,   103,   114,    53,    43,
     -65,   111,    84,    95,   -65,   -65,   -65,    90,   -65,    15,
      84,    15,   -16,    85,   -65,   -65,    28,   114,    15,   -65,
      90,   -65,    82,   108,    86,   -65,    84,   -11,   -11,   -65,
     -65,   -65,   -65,   -65,   -65,    15,    15,    15,    15,    15,
      15,    84,   115,    -6,   105,    94,   -65,   -65,   124,   145,
     107,    15,   110,   113,   -65,    90,   -65,    83,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   139,   143,   -65,   -65,
     155,   153,   -65,   -65,   -65,   -65,   -65,   -65,    84,   -65,
     -11,   157,   -65,   151,   -65,    84,   -65,   135,   159,   -65
  };

  const unsigned char
  parser::yydefact_[] =
  {
      60,     0,    61,     0,     2,    60,     4,     0,     1,     3,
       0,    60,     0,     0,     0,     7,     0,    60,     0,    60,
      10,     0,     0,     0,     0,    20,    60,    60,     0,    56,
       8,     0,     0,    12,     0,     6,     0,     0,    27,    28,
      56,    50,     0,    60,     0,    22,    24,     0,    40,    45,
      51,     0,    60,     0,    18,    59,    19,    60,    21,     0,
      60,     0,    60,     0,    31,    32,    60,     0,     0,    53,
      60,    54,     0,     0,     0,    44,    60,     0,     0,    35,
      34,    39,    37,    38,    36,     0,     0,     0,     0,     0,
       0,    60,     0,    60,     0,     0,    11,    13,     0,     0,
       0,     0,     0,     0,    29,    60,    52,     0,    23,    25,
      26,    41,    42,    46,    47,    48,     0,     0,    58,    57,
       0,     0,    33,    30,    49,    55,    43,    14,    60,    16,
       0,     0,     9,     0,    17,    60,    15,     0,     0,     5
  };

  const short
  parser::yypgoto_[] =
  {
     -65,   -65,   164,   -65,   -14,   -65,   -49,   -65,   -22,    93,
      96,   104,    24,   -64,    17,   -60,   -17,   -25,     7
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,    13,    14,    30,    31,    44,    45,
      46,    85,    47,    74,    48,    49,    50,    54,    33
  };

  const unsigned char
  parser::yytable_[] =
  {
      32,    51,    56,    92,     1,    35,   103,     6,     8,    53,
      53,    96,     6,    10,    12,    37,    38,    39,    15,    40,
      59,    72,    68,    41,    29,    71,    15,   107,   113,   114,
     115,    42,     7,    55,    55,    32,     2,    20,    21,    43,
      11,   126,   116,    32,   100,    40,     2,    34,    98,    41,
      75,    18,    58,     2,    37,    38,    39,    42,    40,    32,
      36,    67,    41,    19,    75,    57,    52,    73,   118,    15,
      42,    29,    60,    75,    32,    69,    53,    75,    43,   133,
       2,    94,    16,    95,    17,    97,   137,    88,    89,    90,
      73,    70,   102,    59,    94,    86,    87,    22,   127,   128,
      55,    23,    24,   111,   112,    25,    26,    27,   134,   110,
      61,    32,    75,    28,    29,    62,    64,    65,    32,    40,
      40,    63,    77,    41,    41,   123,    76,    78,    93,    94,
      91,    42,    42,   104,    99,   117,     2,   106,   105,    66,
      57,   105,     2,   119,    79,    80,    81,    82,    83,    84,
      79,    80,    81,    82,    83,    84,   120,   121,   122,   129,
     130,   124,   131,   132,   125,   135,   136,   138,   139,     9,
     108,   101,     0,     0,   109
  };

  const short
  parser::yycheck_[] =
  {
      17,    23,    27,    52,     3,    19,    70,     0,     0,    26,
      27,    60,     5,    32,    30,    26,    27,    28,    11,    30,
      48,    43,    50,    34,    30,    42,    19,    76,    88,    89,
      90,    42,    30,    26,    27,    52,    52,    10,    11,    50,
       4,   105,    91,    60,    66,    30,    52,     5,    62,    34,
      43,    32,    28,    52,    26,    27,    28,    42,    30,    76,
      48,    37,    34,    32,    57,    50,    19,    43,    93,    62,
      42,    30,    32,    66,    91,    34,    93,    70,    50,   128,
      52,    57,    31,    59,    33,    61,   135,    44,    45,    46,
      66,    50,    68,    48,    70,    42,    43,    13,    15,    16,
      93,    17,    18,    86,    87,    21,    22,    23,   130,    85,
      35,   128,   105,    29,    30,     6,    27,    28,   135,    30,
      30,    34,    25,    34,    34,   101,    14,    24,    33,   105,
      19,    42,    42,    51,    49,    20,    52,    51,    33,    50,
      50,    33,    52,    49,    36,    37,    38,    39,    40,    41,
      36,    37,    38,    39,    40,    41,    32,    12,    51,    20,
      17,    51,     7,    10,    51,     8,    15,    32,     9,     5,
      77,    67,    -1,    -1,    78
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    52,    54,    55,    56,    71,    30,     0,    55,
      32,     4,    30,    57,    58,    71,    31,    33,    32,    32,
      10,    11,    13,    17,    18,    21,    22,    23,    29,    30,
      59,    60,    69,    71,     5,    57,    48,    26,    27,    28,
      30,    34,    42,    50,    61,    62,    63,    65,    67,    68,
      69,    61,    19,    69,    70,    71,    70,    50,    65,    48,
      32,    35,     6,    34,    27,    28,    50,    65,    50,    34,
      50,    69,    61,    65,    66,    71,    14,    25,    24,    36,
      37,    38,    39,    40,    41,    64,    42,    43,    44,    45,
      46,    19,    59,    33,    65,    65,    59,    65,    57,    49,
      61,    64,    65,    66,    51,    33,    51,    59,    62,    63,
      65,    67,    67,    68,    68,    68,    59,    20,    70,    49,
      32,    12,    51,    65,    51,    51,    66,    15,    16,    20,
      17,     7,    10,    59,    61,     8,    15,    59,    32,     9
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    53,    54,    55,    55,    56,    57,    57,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,    15,     3,     1,     3,     8,
       3,     3,     1,     3,     5,     7,     5,     6,     2,     2,
       1,     2,     1,     3,     1,     3,     3,     1,     1,     3,
       4,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     1,     3,     3,     3,     4,
       1,     1,     3,     2,     2,     4,     1,     4,     3,     1,
       0,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "RETURN", "IDENT", "COLON", "SEMICOLON", "COMMA", "NUMBER",
  "ASSIGN", "NEQ", "EQ", "GTE", "GT", "LTE", "LT", "SUB", "ADD", "MOD",
  "DIV", "MULT", "UMINUS", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET",
  "L_PAREN", "R_PAREN", "\";\"", "$accept", "program", "functions",
  "function", "declarations", "declaration", "statements", "statement",
  "bool_expr", "relation_and_expr", "relation_expr", "comp", "expression",
  "expressions", "multiplicative_expr", "term", "var", "vars", "epsilon", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    94,    94,    97,    98,   101,   104,   105,   108,   109,
     110,   113,   114,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   128,   129,   132,   133,   136,   137,   138,   139,
     140,   141,   142,   143,   146,   147,   148,   149,   150,   151,
     154,   155,   156,   159,   160,   163,   164,   165,   166,   169,
     170,   171,   172,   173,   174,   175,   178,   179,   181,   182,
     185,   185
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
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

  // Symbol number corresponding to token number t.
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
    };
    const unsigned user_token_number_max_ = 307;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1309 "mini_l.tab.cc" // lalr1.cc:1181
#line 187 "mini_l.y" // lalr1.cc:1182


int main(int argc, char **argv) {
    // extern char* yytext;    //defined and maintained in lex.c
    // if (argc > 1) {
    //     yyin = fopen(argv[1], "r");
    //     if (yyin == NULL){
    //         printf("syntax: %s filename\n", argv[0]);
    //     }//end if
    // }//end if
    yyparse(); // Calls yylex() for tokens.
    // //where do I get s from?
    // cerr << "ERROR:" + s + " at symbol " + yytext + " on line ";
    return 0;
}

// int yyerror(char *s) {
//     return yyerror(string(s));
// }
