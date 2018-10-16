/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 FILE * yyin;
%}

%union{
  double dval;
  int ival;

  Program*              program;
  Function*             function;
  Functions*            functions;
  Declaration*          declaration;
  Statement*            statement;
  Statements*           statements;
  Bool_Expr*            bool_expr;
  Relation_And_Expr*    relation_and_expr;
  Relation_Expr*        relation_expr;
  Comp*                 comp;
  Expression*           expression;
  Multiplicative_Expr*  multiplicative_expr;
  Term*                 term;
  Var*                  var;
  Vars*                 vars;
  Epsilon*              epsilon;
}

%error-verbose

%start input
%token MULT DIV PLUS MINUS EQUAL L_PAREN R_PAREN END
%token <dval> NUMBER
%type <dval> exp

%type <program> Program
%type <function> Function
%type <functions> Functions
%type <declaration> Declaration
%type <statement> Statement
%type <bool_expr> Bool_Expr
%type <relation_and_expr> Relation_And_Expr
%type <relation_expr> Relation_Expr
%type <comp> Comp
%type <expression> Expression
%type <multiplicative_expr> Multiplicative_Expr
%type <term> Term
%type <var> Var
%type <epsilon> Epsilon
%type <ident> Ident

%left PLUS MINUS
%left MULT DIV

%right  ASSIGN
%left   OR
%left   AND
%right  NOT
%left   NEQ
%left   GTE
%left   GT
%left   LTE
%left   LT
%left   SUB
%left   ADD
%left   MOD
%left   DIV
%left   MULT
%right  SUB
%left   L_SQUARE_BRACKET R_SQUARE_BRACKET
%left   L_PAREN R_PAREN


%nonassoc UMINUS


%% 
Program:	Functions    { $$ =  $1 /*default behavior but including anyways*/} 
			  ;
Functions:  Function Functions
          : Epsilon
          ;
Function:   Function          { $$ = $1 /*default behavior but including anyways*/}
          | FUNCTION IDENT SEMICOLON BEGIN_PARAMS Declarations SEMICOLON END_PARAMS BEGIN_LOCALS Declarations SEMICOLON END_LOCALS BEGIN_BODY Statements SEMICOLON END_BODY
          | Epsilon
          | Declaration SEMICOLON
          | 
			    ;
Statements:   statement SEMICOLON statements
            | Epsilon
            ;
Statement:  IF Bool_Expr then STATEMENTS ENDIF
          |  WRITE Vars
          |  
          ;
Vars:       var
          ;
Var:        Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET
          | Ident
          ;
Expression: Multiplicative_Expr
          | 
          ;
Multiplicative_Expr:    Term
                      |
                      ;
Term: Var
    ;
Ident:    IDENT
        ;

exp:		NUMBER                { $$ = $1; }
			| exp PLUS exp        { $$ = $1 + $3; }
			| exp MINUS exp       { $$ = $1 - $3; }
			| exp MULT exp        { $$ = $1 * $3; }
			| exp DIV exp         { if ($3==0) yyerror("divide by zero"); else $$ = $1 / $3; }
			| MINUS exp %prec UMINUS { $$ = -$2; }
			| L_PAREN exp R_PAREN { $$ = $2; }
			;
%%

int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
