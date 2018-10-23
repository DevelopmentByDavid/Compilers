/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
//  void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
%}

%union {
    char *str;
}

//start symbol
%start program

%type <str> program
%type <str> function
%type <str> functions
%type <str> declaration
%type <str> declarations
%type <str> statement
%type <str> statements
%type <str> bool_expr
%type <str> relation_and_expr
%type <str> relation_expr
%type <str> comp
%type <str> expression
%type <str> expressions
%type <str> multiplicative_expr
%type <str> term
%type <str> var
%type <str> vars

%token <str> FUNCTION
%token <str> BEGIN_PARAMS
%token <str> END_PARAMS
%token <str> BEGIN_LOCALS
%token <str> END_LOCALS
%token <str> BEGIN_BODY
%token <str> END_BODY
%token <str> INTEGER
%token <str> ARRAY
%token <str> OF
%token <str> IF
%token <str> THEN
%token <str> ENDIF
%token <str> ELSE
%token <str> WHILE
%token <str> DO
%token <str> BEGINLOOP
%token <str> ENDLOOP
%token <str> CONTINUE
%token <str> READ
%token <str> WRITE
%token <str> AND
%token <str> OR
%token <str> NOT
%token <str> TRUE
%token <str> FALSE
%token <str> RETURN
%token <str> IDENT
%token <str> COLON
%token <str> SEMICOLON
%token <str> COMMA
%token <str> NUMBER


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
%nonassoc   UMINUS
%left       L_SQUARE_BRACKET
%left       R_SQUARE_BRACKET
%left       L_PAREN
%left       R_PAREN



%% 
program     :   functions           {$$ =  "program -> functions"} 
		    ;

functions   :   function functions  {$$ = "function -> functions"}
            |   epsilon             {$$ = "function -> epsilon"}
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

var     :   IDENT                                                   {$$ = "var -> IDENT"}
        |   IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET    {$$ = "var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET"}
        ;
vars    :   var COMMA vars      {$$ = "vars -> var COMMA vars"}
        |   epsilon             {$$ = "vars -> epsilon"}
        ;

epsilon :   |   ";"; 

%%

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
