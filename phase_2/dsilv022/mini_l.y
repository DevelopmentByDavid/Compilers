%{
 #include <stdio.h>
 #include <stdlib.h>
 #include "header.h"
 
 extern int currLine;
 extern int currPos;
 extern char* yytext;     // defined and maintained in lex.c
 extern int yylex();
 extern void yyerror(char *);
 extern void yyerror(string);
%}

%union {
    char *char_pointer;
}

//start symbol
%start program

%type <char_pointer> program
%type <char_pointer> functions
%type <char_pointer> function
%type <char_pointer> declaration
%type <char_pointer> declarations
%type <char_pointer> statement
%type <char_pointer> statements
%type <char_pointer> bool_expr
%type <char_pointer> relation_and_expr
%type <char_pointer> relation_expr
%type <char_pointer> comp
%type <char_pointer> expression
%type <char_pointer> expressions
%type <char_pointer> multiplicative_expr
%type <char_pointer> terms
%type <char_pointer> term
%type <char_pointer> var
%type <char_pointer> vars
%type <char_pointer> idents

%type <char_pointer> bool_expressions
%type <char_pointer> relation_and_expressions
%type <char_pointer> expression_loop

%token  FUNCTION
%token  BEGIN_PARAMS
%token  END_PARAMS
%token  BEGIN_LOCALS
%token  END_LOCALS
%token  BEGIN_BODY
%token  END_BODY
%token  INTEGER
%token  ARRAY
%token  OF
%token  IF
%token  THEN
%token  ENDIF
%token  ELSE
%token  WHILE
%token  DO
%token  BEGINLOOP
%token  ENDLOOP
%token  CONTINUE
%token  READ
%token  WRITE
%token  AND
%token  OR
%token  NOT
%token  TRUE
%token  FALSE
%token  RETURN
%token  IDENT
%token  COLON
%token  SEMICOLON
%token  COMMA
%token  NUMBER

// %printer {fprintf(yyoutput, "'%c'", $$); } <char_pointer>


%right      ASSIGN
%left       OR
%left       AND
%right      NOT
%left       NEQ
%left       EQ
%left       GTE
%left       GT
%left       LTE
%left       LT
%left       SUB
%left       ADD
%left       MOD
%left       DIV
%left       MULT
%right      UMINUS
%left       L_SQUARE_BRACKET
%left       R_SQUARE_BRACKET
%left       L_PAREN
%left       R_PAREN



%% 
program:            functions                {printf("program -> functions\n");} 
		        ;

functions:          /* empty */              {printf("functions -> epsilon\n");}
                |   function functions       {printf("functions -> function functions\n");}
                ;

function:           FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY  
                    {printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY\n");}
                ;

declarations:       /* empty */                         {printf("declarations -> epsilon\n");}
                |   declaration SEMICOLON declarations  {printf("declarations -> declaration SEMICOLON declarations\n");}
                ;

declaration:        IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER   {printf("statements -> IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
                |   IDENT idents COLON INTEGER                                                     {printf("statements -> IDENT idents COLON INTEGER\n");}
                ;

idents:             /* empty */         {printf("idents -> epsilon\n");}
                |   COMMA IDENT idents  {printf("idents -> COMMA IDENT idents\n");}
                ;

statements:         /* empty */                     {printf("statements -> epsilon\n");}
                |   statement SEMICOLON statements  {printf("statements -> statement SEMICOLON statements\n");}
                ;

statement:          var ASSIGN expression                                                                       {printf("statement -> var ASSIGN expression\n");}
                |   IF bool_expr THEN statement SEMICOLON statements ENDIF                                      {printf("statement -> IF bool_expr THEN statement SEMICOLON statements ENDIF\n"); }
                |   IF bool_expr THEN statement SEMICOLON statements ELSE statement SEMICOLON statements ENDIF  {printf("statement -> IF bool_expr THEN statement SEMICOLON statements ELSE statement SEMICOLON statements ENDIF\n");}
                |   WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP                            {printf("statement -> WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP\n");}
                |   DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr                         {printf("statement -> DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr\n"); }
                |   READ var vars                                                                               {printf("statement ->  READ var vars\n"); }
                |   WRITE var vars                                                                              {printf("statement -> WRITE var vars\n");}
                |   CONTINUE                                                                                    {printf("statement -> CONTINUE\n");}
                |   RETURN expression                                                                           {printf("statement -> RETURN expression\n");}
                ;

bool_expr:          relation_and_expr bool_expressions                 {printf("bool_expr -> relation_and_expr bool_expressions\n");}
                ;

bool_expressions:   /* empty */                                         {printf("bool_expressions -> epsilon\n");}
                |   OR relation_and_expr bool_expressions               {printf("bool_expressions -> OR relation_and_expr bool_expressions\n");}
                ;

relation_and_expr:      relation_expr relation_and_expressions          {printf("relation_and_expr -> relation_expr relation_and_expressions\n");}
                    ;

relation_and_expressions:   /* empty */                                 {printf("relation_and_expressions -> epsilon\n");}
                        |   AND relation_expr relation_and_expressions  {printf("relation_and_expressions -> AND relation_expr relation_and_expressions\n");}
                        ;
relation_expr:              expression comp expression      {printf("relation_expr -> expression comp expression\n");}
                        |   TRUE                            {printf("relation_expr -> TRUE\n");}
                        |   FALSE                           {printf("relation_expr -> FALSE\n");}
                        |   L_PAREN bool_expr R_PAREN       {printf("relation_expr -> L_PAREN bool_expr R_PAREN\n");}
                        |   NOT expression comp expression  {printf("relation_expr -> NOT expression comp expression\n");}
                        |   NOT TRUE                        {printf("relation_expr -> NOT TRUE\n");}
                        |   NOT FALSE                       {printf("relation_expr -> NOT FALSE\n");}
                        |   NOT L_PAREN bool_expr R_PAREN   {printf("relation_expr -> NOT L_PAREN bool_expr R_PAREN\n");}
                        ;

comp:               EQ      {printf("comp -> EQ\n");}
                |   NEQ     {printf("comp -> NEQ\n");}
                |   LT      {printf("comp -> LT\n");}
                |   GT      {printf("comp -> GT\n");}
                |   LTE     {printf("comp -> LTE\n");}
                |   GTE     {printf("comp -> GTE\n");}
                ;

expression:         multiplicative_expr expression_loop         {printf("expression -> multiplicative_expr expression_loop\n");}
                ;

expression_loop:    /* empty */                                 {printf("expression_loop -> epsilon\n");}
                |   ADD multiplicative_expr expression_loop     {printf("expression_loop -> ADD multiplicative_expr expression_loop\n");}
                |   SUB  multiplicative_expr expression_loop    {printf("expression_loop -> SUB  multiplicative_expr expression_loop\n");}
                ;


expressions:        expression COMMA expressions    {printf("expressions -> expression COMMA expressions\n");}
                |   expression                      {printf("expressions -> expression\n");}
                |   /* empty */                     {printf("expressions -> epsilon\n");}
                ;

terms:              /* empty */             {printf("terms -> epsilon\n");}
                |   MOD term terms          {printf("terms -> MOD term terms\n");}
                |   DIV term terms          {printf("terms -> DIV term terms\n");}
                |   MULT term terms         {printf("terms -> MULT term terms\n");}
                ;

multiplicative_expr:        term terms      {printf("multiplicative_expr -> term terms\n");}
                        ;

term:               IDENT L_PAREN expressions R_PAREN         {printf("term -> IDENT L_PAREN expressions R_PAREN\n");}
                |   NUMBER                                    {printf("term -> NUMBER\n");}
                |   var                                       {printf("term -> var\n");}
                |   L_PAREN expression R_PAREN                {printf("term -> L_PAREN expression R_PAREN\n");}
                |   UMINUS NUMBER                             {printf("term -> UMINUS NUMBER\n");}
                |   UMINUS var                                {printf("term -> UMINUS var\n");}
                |   UMINUS L_PAREN expression R_PAREN         {printf("term -> UMINUS L_PAREN expression R_PAREN\n");}
                |   UMINUS IDENT L_PAREN expressions R_PAREN  {printf("term -> UMINUS IDENT L_PAREN expressions R_PAREN\n");}
                ;

var:                IDENT                                                 {printf("var -> IDENT\n");}
                |   IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET    {printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
                ;

vars:               /* empty */                 {printf("vars -> epsilon\n");}
                |   COMMA var vars              {printf("vars -> COMMA var vars \n");}
                ;

%%


void yyerror( string s ) {  // error handler routine
  extern int  yylineno;    // defined and maintained in lex.c
  extern char* yytext;     // defined and maintained in lex.c
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << currLine << " column " << currPos << endl;
  exit( 1 );
}

void yyerror( char* s ) { yyerror( string(s) ); }
