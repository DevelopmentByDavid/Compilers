%{
 #include "header.h"
 #include "classes.h"
 
 extern int currLine;
 extern int currPos;
 extern char* yytext;     // defined and maintained in lex.c
 extern int yylex();
 extern void yyerror(char *);
 extern void yyerror(string);
%}

%union {
    string *myString;
    int myInt;
    arr_struct *my_arr_struct;
}

//start symbol
%start program

%type <myString> program
%type <myString> functions
%type <myString> function
%type <myString> declaration
%type <myString> declarations
%type <myString> statement
%type <myString> statements
%type <myString> bool_expr
%type <myString> relation_and_expr
%type <myString> relation_expr
%type <myInt> comp
%type <myString> expression
%type <myString> expressions
%type <myString> multiplicative_expr
%type <myString> terms
%type <myString> term
%type <myString> var
%type <myString> vars
%type <myString> idents

%type <myString> bool_expressions
%type <myString> relation_and_expressions
%type <myString> expression_loop

%token <myString> FUNCTION
%token <myString> BEGIN_PARAMS
%token <myString> END_PARAMS
%token <myString> BEGIN_LOCALS
%token <myString> END_LOCALS
%token <myString> BEGIN_BODY
%token <myString> END_BODY
%token <myString> INTEGER
%token <myString> ARRAY
%token <myString> OF
%token <myString> IF
%token <myString> THEN
%token <myString> ENDIF
%token <myString> ELSE
%token <myString> WHILE
%token <myString> DO
%token <myString> BEGINLOOP
%token <myString> ENDLOOP
%token <myString> CONTINUE
%token <myString> READ
%token <myString> WRITE
%token <myString> AND
%token <myString> OR
%token <myString> NOT
%token <myString> TRUE
%token <myString> FALSE
%token <myString> RETURN
%token <myString> IDENT
%token <myString> COLON
%token <myString> SEMICOLON
%token <myString> COMMA
%token <myString> NUMBER

// %printer {f/*printf(yyoutput, "'%c'", $$); } <myString>


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
program:            functions                
                        {
                            /*printf("program -> functions\n");*/
                            print();
                        } 
		        ;

functions:          /* empty */              {/*printf("functions -> epsilon\n");*/}
                |   function functions       
                        {
                        // /*printf("functions -> function functions\n");*/
                        }
                ;

function:           FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS
                    BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY  
                        {
                            /*printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS
                            BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY\n");*/
                            // funcName($2);
                            if (addTable(*($2))) {
                                // genCode( "func " + *($2));
                                func(*($2));
                            };
                        }
                ;

declarations:       /* empty */                         {/*printf("declarations -> epsilon\n");*/}
                |   declaration SEMICOLON declarations  {/*printf("declarations -> declaration SEMICOLON declarations\n");*/}
                ;

declaration:        IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER   
                        {
                            /*printf("delcaration -> IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");*/
                            if (addTable(*($1))) {
                                genCode(". [] " + *($1) + ", " + *($6));
                            };
                        }
                |   IDENT idents COLON INTEGER                                                     
                        {
                            /*printf("declaration -> IDENT idents COLON INTEGER\n");*/
                            if (addTable(*($1))) {
                                genCode(". " + *($1));
                            };
                        }
                ;

idents:             /* empty */         {/*printf("idents -> epsilon\n");*/}
                |   COMMA IDENT idents  
                        {
                            /*printf("idents -> COMMA IDENT idents\n");*/
                            if (addTable(*($2))) {
                                genCode(". " + *($2));
                            };
                        }
                ;

statements:         /* empty */                     {/*printf("statements -> epsilon\n");*/}
                |   statement SEMICOLON statements  {/*printf("statements -> statement SEMICOLON statements\n");*/}
                ;

statement:          var ASSIGN expression                                                                       
                        {
                            /*printf("statement -> var ASSIGN expression\n");*/
                            if (exist(*($1)) && exist(*($3))) {             //if both variables exist, then simple assign statement
                                genCode("= " + *($1) + ", " + *($3));
                            }
                            //  else if (!exist(*($1))) {
                            //     string code = *($1);
                            //     code.insert(0, "[]= ");
                            //     genCode(code);
                            // } else {
                            //     genCode("$1: " + *($1) + "\n" + "$3" + *($3) + "\n");

                            // }
                            //  else if (!exist(*($3))) {                     //if $3 !exist, then it's a piece of code & $1 is dest
                            //     string code = *($3);
                            //     genCode(code.insert(1, " " + *($1)));
                            // }
                        }
                |   IF bool_expr THEN statement SEMICOLON statements ENDIF                                      
                        {
                            /*printf("statement -> IF bool_expr THEN statement SEMICOLON statements ENDIF\n");*/ 
                        }
                |   IF bool_expr THEN statement SEMICOLON statements ELSE statement SEMICOLON statements ENDIF  
                        {
                            /*
                                printf("statement -> IF bool_expr THEN statement 
                                SEMICOLON statements ELSE statement SEMICOLON statements ENDIF\n");
                            */
                        }
                |   WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP                            
                        {
                            /*printf("statement -> WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP\n");*/
                        }
                |   DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr                         
                        {
                            /*printf("statement -> DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr\n");*/ 
                        }
                |   READ var vars                                                                               
                        {
                            /*printf("statement ->  READ var vars\n");*/
                        }
                |   WRITE var vars                                                                              
                        {
                            /*printf("statement -> WRITE var vars\n");*/
                        }
                |   CONTINUE                                                                                    
                        {
                            /*printf("statement -> CONTINUE\n");*/
                        }
                |   RETURN expression                                                                           
                        {
                            /*printf("statement -> RETURN expression\n");*/
                        }
                ;

bool_expr:          relation_and_expr bool_expressions                 
                        {
                            /*printf("bool_expr -> relation_and_expr bool_expressions\n");*/
                        }
                ;

bool_expressions:   /* empty */                                         
                        {
                            /*printf("bool_expressions -> epsilon\n");*/
                        }
                |   OR relation_and_expr bool_expressions               
                        {
                            /*printf("bool_expressions -> OR relation_and_expr bool_expressions\n");*/
                        }
                ;

relation_and_expr:      relation_expr relation_and_expressions          
                            {
                                /*printf("relation_and_expr -> relation_expr relation_and_expressions\n");*/
                            }
                    ;

relation_and_expressions:   /* empty */                                 
                                {
                                    /*printf("relation_and_expressions -> epsilon\n");*/
                                }
                        |   AND relation_expr relation_and_expressions  
                                {
                                    /*printf("relation_and_expressions -> AND relation_expr relation_and_expressions\n");*/
                                }
                        ;
relation_expr:              expression comp expression      
                                {
                                    /*printf("relation_expr -> expression comp expression\n");*/
                                    //MISTAKE _EQ IS == NOT AN ASSIGNMENT!!!!!!!!!!!
                                    // switch ($2) {
                                    //     case _EQ: 
                                    //         if (exist(*($1)) && exist(*($3))) {
                                    //             genCode("=" + *($1) + ", " + *($3));
                                    //         } else {
                                    //             cerr << "Variable does not exist" << endl;
                                    //         }
                                    //         break;
                                    //     default: 
                                    //     //do nothing
                                    //         break;
                                    // }
                                        
                                }
                        |   TRUE                            {/*printf("relation_expr -> TRUE\n");*/}
                        |   FALSE                           {/*printf("relation_expr -> FALSE\n");*/}
                        |   L_PAREN bool_expr R_PAREN       {/*printf("relation_expr -> L_PAREN bool_expr R_PAREN\n");*/}
                        |   NOT expression comp expression  {/*printf("relation_expr -> NOT expression comp expression\n");*/}
                        |   NOT TRUE                        {/*printf("relation_expr -> NOT TRUE\n");*/}
                        |   NOT FALSE                       {/*printf("relation_expr -> NOT FALSE\n");*/}
                        |   NOT L_PAREN bool_expr R_PAREN   {/*printf("relation_expr -> NOT L_PAREN bool_expr R_PAREN\n");*/}
                        ;

comp:               EQ      {/*printf("comp -> EQ\n");*/ $$ = _EQ;}
                |   NEQ     {/*printf("comp -> NEQ\n");*/ $$ =_NEQ;}
                |   LT      {/*printf("comp -> LT\n");*/ $$ = _LT;}
                |   GT      {/*printf("comp -> GT\n");*/ $$ = _GT;}
                |   LTE     {/*printf("comp -> LTE\n");*/ $$ = _LTE;}
                |   GTE     {/*printf("comp -> GTE\n");*/ $$ = _GTE;}
                ;

expression:         multiplicative_expr expression_loop         
                        {
                            /*printf("expression -> multiplicative_expr expression_loop\n");*/

                            if (($2)->compare("") != 0) {   //if an expression loop exists
                                //local vars
                                string code = *($2);

                                //only applies to local code
                                code.insert(1, ", " + *($1));

                                //"return" code
                                $$ = new string(code);
                            } else {                        //if expression loop does not exist; i.e. just a number
                                $$ = $1;
                            }
                        }
                ;

expression_loop:    /* empty */                                 
                        {
                            /*printf("expression_loop -> epsilon\n");*/
                            $$ = new string("");
                        }
                |   ADD multiplicative_expr expression_loop     
                        {
                            /*printf("expression_loop -> ADD multiplicative_expr expression_loop\n");*/

                            //declare base string to "return"
                            string base = (string) "+" +  (string) ", ";

                            if (($3)->compare("") != 0) {   //expression loop is not epsilon
                                //store addition result into generated temp
                                string temp = newTemp();
                                //code returned by the loop that is NOT empty
                                string code = *($3);
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(1, " " + temp + ", " + *($2));
                                //generate code
                                genCode(code);
                                //now "return" the base + temp
                                //value of expression generated above is in the generated temp
                                $$ = new string(base + temp);
                            } else {                        //expression loop is epsilon
                                //"return" base + $2
                                $$ = new string(base + *($2));
                            }
                        }
                |   SUB  multiplicative_expr expression_loop    
                        {
                            /*printf("expression_loop -> SUB  multiplicative_expr expression_loop\n");*/

                            //declare base string to "return"
                            string base = (string) "-" +  (string) ", ";

                            if (($3)->compare("") != 0) {   //expression loop is not epsilon
                                //store addition result into generated temp
                                string temp = newTemp();
                                //code returned by the loop that is NOT empty
                                string code = *($3);
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(1, " " + temp + ", " + *($2));
                                //generate code
                                genCode(code);
                                //now "return" the base + temp
                                //value of expression generated above is in the generated temp
                                $$ = new string(base + temp);
                            } else {                        //expression loop is epsilon
                                //"return" base + $2
                                $$ = new string(base + *($2));
                            }
                        }
                ;


expressions:        expression COMMA expressions    
                        {
                            /*printf("expressions -> expression COMMA expressions\n");*/

                            //not sure if this is right
                            $$ = $1;
                        }
                |   expression                      
                        {
                            /*printf("expressions -> expression\n");*/
                            $$ = $1;
                        }
                |   /* empty */                     
                        {
                            /*printf("expressions -> epsilon\n");*/
                        }
                ;

terms:              /* empty */             
                        {
                            /*printf("terms -> epsilon\n");*/
                            $$ = new string("");
                        }
                |   MOD term terms          
                        {
                            /*printf("terms -> MOD term terms\n");*/
                            string temp = (string) "%" + (string) ", " + *($2);
                            $$ = new string(temp);
                        }
                |   DIV term terms          
                        {
                            /*printf("terms -> DIV term terms\n");*/
                            string temp = (string) "/" + (string) ", " + *($2);
                            $$ = new string(temp);
                        }
                |   MULT term terms         
                        {
                            /*printf("terms -> MULT term terms\n");*/
                            string temp = (string) "*" + (string) ", " + *($2);
                            $$ = new string(temp);
                        }
                ;

multiplicative_expr:        term terms      
                                {
                                    /*printf("multiplicative_expr -> term terms\n");*/

                                    if (($2)->compare("") != 0) {
                                        //local var
                                        string code = *($2);

                                        //inserting code
                                        code.insert(1, ", " + *($1));

                                        //"return" statement
                                        $$ = new string(code);
                                    } else {
                                        $$ = $1;
                                    }
                                }
                        ;

term:               IDENT L_PAREN expressions R_PAREN   
                        {
                            /*printf("term -> IDENT L_PAREN expressions R_PAREN\n");*/

                            /*
                                []= dst, index, src	
                            */

                            //temp is dest
                            // string temp = newTemp();
                            // //base string setup; source is $1; index is $3
                            // string base = "=[] " + temp + ", " + *($3) + ", " + *($1);
                            // //generate code
                            // genCode(base);
                            // //"return" temp b/c it now stores the array value
                            // $$ = new string(temp);

                            // undeclared(*($1));    
                        }
                |   NUMBER                              
                        {
                            /*printf("term -> NUMBER\n");*/

                            //generate temp
                            string temp = newTemp();
                            //generate the code to store $1 into temp
                            genCode("= " + temp + ", " + *($1));
                            //"return" temp b/c it now stores the number
                            $$ = new string(temp);
                        }
                |   var                                 
                        {
                            /*printf("term -> var\n");*/
                            if (!exist(*($1))) {        //if $1 isn't just an identifier
                                string code = *($1);
                                code.insert(0, "=[] ");
                                genCode(code);
                                $$ = new string(code);
                            } else {
                                $$ = $1;
                            }
                        }
                |   L_PAREN expression R_PAREN          
                        {
                            /*printf("term -> L_PAREN expression R_PAREN\n");*/
                            $$ = $2;
                        }
                |   SUB NUMBER                          
                        {
                            /*printf("term -> SUB NUMBER\n");*/

                            //have to static cast cause compiler optimizes to char* or something
                            $$ = new string( (string) "-" + *($2) );
                        }
                |   SUB var                             
                        {
                            /*printf("term -> SUB var\n");*/

                             $$ = new string( (string) "-" + *($2) );
                        }
                |   SUB L_PAREN expression R_PAREN      
                        {
                            /*printf("term -> SUB L_PAREN expression R_PAREN\n");*/

                             $$ = new string( (string) "-" + *($3) );
                        }
                ;

var:                IDENT                                                 
                        {
                            /*printf("var -> IDENT\n");*/
                            $$ = $1;
                            undeclared(*($1));
                        }
                |   IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET    
                        {
                            /*printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");*/ 
                            //base string setup; source is $1; index is $3
                            string base = "=[] " + temp + ", " + *($1) + ", " + *($3);
                            //"return" temp b/c it now stores the array value
                            $$ = new string(temp);

                            undeclared(*($1));
                        }
                ;

vars:               /* empty */                 {/*printf("vars -> epsilon\n");*/}
                |   COMMA var vars              
                    {
                        /*printf("vars -> COMMA var vars \n");*/
                        $$ = $2;
                    }
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
