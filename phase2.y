/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
%}

%union {
    String string;
}

//start symbol
%start      program

%type <string> function
%type <string> functions
%type <string> declaration
%type <string> declarations
%type <string> statement
%type <string> bool_expr
%type <string> relation_and_expr
%type <string> relation_expr
%type <string> comp
%type <string> expression
%type <string> expressions
%type <string> multiplicative_expr
%type <string> term
%type <string> var
%type <string> epsilon

%% 
program     :   Functions           {$$ =  "program -> functions"} 
            |
		    ;

functions   :   function functions  {$$ = "function -> functions"}
            :   epsilon             {$$ = "function -> epsilon"}
            ;

function    :   FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations SEMICOLON END_PARAMS BEGIN_LOCALS declarations SEMICOLON END_LOCALS BEGIN_BODY statements SEMICOLON END_BODY {$$ = "function -> long rule"}
            ;

declarations    :   declaration SEMICOLON declarations  {$$ = "declarations -> declaration SEMICOLON declarations"}
                |   epsilon                             {$$ = "declarations -> epsilon"}
                ;

declaration     :   IDENT COMMA statements  {$$ = "statements -> IDENT COMMA statements"}
                |   IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {$$ = "statements -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER"}
                |   IDENT COLON INTEGER {$$ = "statements -> IDENT COLON INTEGER"}
                ;

statements      :   statement SEMICOLON statements  {$$ = "statements -> statement SEMICOLON statements"}
                |   epsilon                         {$$ = "statements -> epsilon"}
                ;

statement       :   var ASSIGN expression                               {$$ = "statement -> var ASSIGN expression"}
                |   IF bool_expr THEN statements ENDIF                  {$$ = "statement -> IF bool_expr THEN statements ENDIF"}
                |   IF bool_expr THEN statements ELSE statements ENDIF  {$$ = "statement -> IF bool_expr THEN statements ELSE statements ENDIF"}
                |   WHILE bool_expr BEGINLOOP statements ENDLOOP        {$$ = "statement -> WHILE bool_expr BEGINLOOP statements ENDLOOP"}
                |   DO BEGINLOOP statements ENDLOOP WHILE bool_expr     {$$ = "statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_expr"}
                |   READ vars                                           {$$ = "statement ->  READ vars"}
                |   WRITE vars                                          {$$ = "statement -> WRITE vars"}
                |   CONTINUE                                            {$$ = "statement -> CONTINUE"}
                |   RETURN expression                                   {$$ = "statement -> RETURN expression"}
                ;

bool_expr       :   relation_and_expr                       {$$ = "bool_expr -> relation_and_expr"}
                |   relation_and_expr OR relation_and_expr  {$$ = "bool_expr -> relation_and_expr OR relation_and_expr"}
                ;

relation_and_expr       :   relation_expr                   {$$ = "relation_and_expr -> relation_expr"}
                        |   relation_expr AND relation_expr {$$ = "relation_and_expr -> relation_expr AND relation_expr"}
                        ;

relation_expr           :   expression comp expression      {$$ = "relation_expr -> expression comp expression"}
                        |   TRUE                            {$$ = "relation_expr -> TRUE"}
                        |   FALSE                           {$$ = "relation_expr -> FALSE"}
                        |   L_PAREN bool_expr R_PAREN       {$$ = "relation_expr -> L_PAREN bool_expr R_PAREN"}
                        |   NOT expression comp expression  {$$ = "relation_expr -> NOT expression comp expression"}
                        |   NOT TRUE                        {$$ = "relation_expr -> NOT TRUE"}
                        |   NOT FALSE                       {$$ = "relation_expr -> NOT FALSE"}
                        |   NOT L_PAREN bool_expr R_PAREN   {$$ = "relation_expr -> NOT L_PAREN bool_expr R_PAREN"}
                        ;

comp    :   EQ      {$$ = "comp -> EQ"}
        |   NEQ     {$$ = "comp -> NEQ"}
        |   LT      {$$ = "comp -> LT"}
        |   GT      {$$ = "comp -> GT"}
        |   LTE     {$$ = "comp -> LTE"}
        |   GTE     {$$ = "comp -> GTE"}
        ;

expression  :   multiplicative_expr                             {$$ = "expression -> multiplicative_expr"}
            |   multiplicative_expr SUB multiplicative_expr     {$$ = "expression -> multiplicative_expr SUB multiplicative_expr"}
            |   multiplicative_expr ADD multiplicative_expr     {$$ = "expression -> multiplicative_expr ADD multiplicative_expr"}
            ;

expressions :   expression COMMA expressions    {$$ = "expressions -> expression COMMA expressions"}
            |   epsilon                         {$$ = "expressions -> epsilon"}
            ;

multiplicative_expr     :   term            {$$ = "multiplicative_expr -> term"}
                        |   term MOD term   {$$ = "multiplicative_expr -> term MOD term"}
                        |   term DIV term   {$$ = "multiplicative_expr -> term DIV term"}
                        |   term MULT term  {$$ = "multiplicative_expr -> term MULT term"}
                        ;

term    :   IDENT L_PAREN expression R_PAREN    {$$ = "term -> IDENT L_PAREN expression R_PAREN"}
        |   NUMBER                              {$$ = "term -> NUMBER"}
        |   var                                 {$$ = "term -> var"}
        |   L_PAREN expressions R_PAREN         {$$ = "term -> L_PAREN expressions R_PAREN"}
        |   SUB NUMBER                          {$$ = "term -> SUB NUMBER"}
        |   SUB var                             {$$ = "term -> SUB var"}
        |   SUB L_PAREN expressions R_PAREN     {$$ = "term -> SUB L_PAREN expressions R_PAREN"}
        ;

var     :   IDENT
        |   IDENT   L_SQUARE_BRACKET expression R_SQUARE_BRACKET
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
