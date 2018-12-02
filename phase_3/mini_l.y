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
    CodeBlock *myBlock;
}

//start symbol
%start program

%type <myString> program
%type <myString> functions
%type <myString> function
%type <myBlock> declaration
%type <myBlock> declarations
%type <myBlock> statement
%type <myBlock> statements
%type <myString> bool_expr
%type <myString> relation_and_expr
%type <myString> relation_expr
%type <myString> comp
%type <myString> expression
%type <myString> expressions
%type <myString> multiplicative_expr
%type <myString> terms
%type <myString> term
%type <myString> var
%type <myString> vars
%type <myBlock> idents
%type <myBlock> params

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

function:           FUNCTION IDENT SEMICOLON params
                    BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY  
                        {
                            /*printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS
                            BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY\n");*/
                            // funcName($2);
                            // CodeBlock block = *($3);
                            CodeBlock
                            ($4)->push_front("func " + *($2));
                            ($4)->shipCode();
                            // cerr << "block " << block.isNull() << endl;
                            genCode("endfunc\n");
                            func();
                        }
                ;
params:             BEGIN_PARAMS declarations END_PARAMS
                        {
                            if (!($2)->isNull()) {
                                static int i = 0;
                                CodeBlock tempBlock = *($2);
                                stringstream temp;
                                temp << "= " << ($2)->getVal() << ", $" << i;
                                i++;
                                tempBlock.push_back(temp.str());
                                $$ = new CodeBlock(tempBlock);
                            } else {
                                $$ = new CodeBlock();
                            }
                        }
                ;

declarations:       /* empty */                         
                        {
                            /*printf("declarations -> epsilon\n");*/
                            $$ = new CodeBlock();
                        }
                |   declaration SEMICOLON declarations  
                        {
                            /*printf("declarations -> declaration SEMICOLON declarations\n");*/
                            // ($1)->shipCode();
                            $$ = $1;
                        }
                ;

declaration:        IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER   
                        {
                            /*printf("delcaration -> IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");*/
                            CodeBlock temp;
                            if (addTable(*($1))) {
                                temp.push_back(". [] " + *($1) + ", " + *($6));
                                temp.setVal(*($1));
                            };
                            $$ = new CodeBlock(temp);
                        }
                |   IDENT idents COLON INTEGER                                                     
                        {
                            /*printf("declaration -> IDENT idents COLON INTEGER\n");*/
                            CodeBlock temp;
                            if (addTable(*($1))) {
                                temp.push_back(". " + *($1));
                                temp.setVal(*($1));
                            };
                            $$ = new CodeBlock(temp);
                        }
                ;

idents:             /* empty */         
                        {
                            /*printf("idents -> epsilon\n");*/
                            $$ = new CodeBlock()
                        }
                |   COMMA IDENT idents  
                        {
                            /*printf("idents -> COMMA IDENT idents\n");*/
                            CodeBlock temp;
                            if (addTable(*($2))) {
                                temp.push_back(". " + *($2));
                            };
                            $$ = new CodeBlock(temp);
                        }
                ;

statements:         /* empty */                     
                        {
                            /*printf("statements -> epsilon\n");*/
                            $$ = new CodeBlock();
                        }
                |   statement SEMICOLON statements  
                        {
                            /*printf("statements -> statement SEMICOLON statements\n");*/
                            $$ = $1;
                        }
                ;

statement:          var ASSIGN expression                                                                       
                        {
                            /*printf("statement -> var ASSIGN expression\n");*/
                            CodeBlock tempBlock;
                            if (exist(*($1)) && exist(*($3))) {             //if both variables exist, then simple assign statement
                                tempBlock.push_back("= " + *($1) + ", " + *($3));
                            } else if (!exist(*($1)) && exist(*($3))) {     //if left side is an array var and right side is not
                                string code = *($1);
                                string toAppend = *($3);
                                code.insert(0, "[] = ");
                                code.append(", " + toAppend);
                                tempBlock.push_back(code);
                            } 
                            $$ = new CodeBlock(tempBlock);
                        }
                |   IF bool_expr THEN statement SEMICOLON statements ENDIF                                      
                        {
                            /*printf("statement -> IF bool_expr THEN statement SEMICOLON statements ENDIF\n");*/                            
                            CodeBlock tempBlock;
                            string execLabel = newLabel();
                            string skiplabel = newLabel();
                            ($2)->push_back("?:= " + execLabel + ", " + ($2)->getVal());
                            ($2)->push_back(":= " + skipLabel);
                            ($2)->push_back(": " + execLabel);
                            tempBlock = *($2) + *($4) + *(6);
                            tempBlock.push_back(": " + skipLabel);
                            $$ = new CodeBlock(tempBlock);
                        }
                |   IF bool_expr THEN statement SEMICOLON statements ELSE statement SEMICOLON statements ENDIF  
                        {
                            /*
                                printf("statement -> IF bool_expr THEN statement 
                                SEMICOLON statements ELSE statement SEMICOLON statements ENDIF\n");
                            */
                            CodeBlock tempBlock;
                            string execLabel = newLabel();
                            string skiplabel = newLabel();
                            ($2)->push_back("?:= " + execLabel + ", " + ($2)->getVal());
                            ($2)->push_back(":= " + skipLabel);
                            ($2)->push_back(": " + execLabel);
                            ($8)->push_front(": " + skipLabel);
                            tempBlock = *($2) + *($4) + *(6) + *($8) + *($10);
                            $$ = new CodeBlock(tempBlock);
                        }
                |   WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP                            
                        {
                            /*printf("statement -> WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP\n");*/
                            CodeBlock tempBlock;
                            string execLabel = newLabel();
                            string skiplabel = newLabel();
                            string loopLabel = newLabel();
                            ($2)->push_front(": " + loopLabel);
                            ($2)->push_back("?:= " + execLabel + ", " + ($2)->getVal());
                            ($2)->push_back(":= " + skipLabel);
                            ($2)->push_back(": " + execLabel);
                            ($6)->push_back(":= " + loopLabel);
                            ($6)->push_back(": " + skipLabel);
                            tempBlock = *($2) + *($4) + *(6);
                            $$ = new CodeBlock(tempBlock);
                        }
                |   DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr
                        {
                            /*printf("statement -> DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr\n");*/ 
                            CodeBlock tempBlock;
                            string execLabel = newLabel();
                            // string loopLabel = newLabel();
                            ($3)->push_front(": " + execLabel);
                            ($8)->push_back("?:= " + execLabel + ", " + ($8)->getVal());
                            tempBlock = *($3) + *($5) + *(8);
                            $$ = new CodeBlock(tempBlock);
                        }
                |   READ var vars                                                                               
                        {
                            /*printf("statement ->  READ var vars\n");*/
                            CodeBlock tempBlock;
                            if (!exist(*($2))) {
                                tempBlock.push_back(".[]< " + *($2));
                            } else {
                                tempBlock.push_back(".< " + *($2));
                            }

                            if (($3)->compare("") != 0) {
                                if (!exist(*($3))) {
                                    tempBlock.push_back(".[]< " + *($3));
                                } else {
                                    tempBlock.push_back(".< " + *($3));
                                }
                            }
                            $$ = new CodeBlock(tempBlock);
                        }
                |   WRITE var vars                                                                              
                        {
                            /*printf("statement -> WRITE var vars\n");*/
                            CodeBlock tempBlock;
                            if (!exist(*($2))) {
                                tempBlock.push_back(".[]> " + *($2));
                            } else {
                                tempBlock.push_back(".> " + *($2));
                            }

                            if (($3)->compare("") != 0) {
                                if (!exist(*($3))) {
                                    tempBlock.push_back(".[]> " + *($3));
                                } else {
                                    tempBlock.push_back(".> " + *($3));
                                }
                            }
                            $$ = new CodeBlock(tempBlock);
                        }
                |   CONTINUE                                                                                    
                        {
                            /*printf("statement -> CONTINUE\n");*/
                            //THIS WOULD BE A GOTO STATEMENT
                            // genCode(":= " + soft_pop());

                        }
                |   RETURN expression                                                                           
                        {
                            /*printf("statement -> RETURN expression\n");*/
                            genCode("ret " + *($2));
                            // $$ = new string();
                        }
                ;

bool_expr:          relation_and_expr bool_expressions                 
                        {
                            /*printf("bool_expr -> relation_and_expr bool_expressions\n");*/
                            if (($2)->compare("") != 0) {           //if an bool_expression loop exists
                                //local vars
                                string code = *($2);
                                string temp = newTemp();

                                //only applies to local code
                                code.insert(1, " " + temp + ", " + *($1));
                                genCode(code);

                                // string execLabel = newLabel();
                                // string skipLabel = newLabel();
                                // genCode("?:= " + execLabel + ", " + temp);
                                // genCode("************");
                                // genCode(":= " + skipLabel);
                                // genCode(": " + execLabel);
                                //"return" code
                                $$ = new string(temp);
                            } else {                        //if expression loop does not exist; i.e. just a number
                                // string execLabel = newLabel();
                                // string skipLabel = newLabel();
                                // genCode("?:= " + execLabel + ", " + *($1));
                                // genCode("^^^^^^^^^^^^^");
                                // genCode(":= " + skipLabel);
                                // genCode(": " + execLabel);
                                // genCode("why am I getting a k? " + *($1));
                                //"return" code
                                $$ = $1;
                            }
                            // $$ = $1;

                            // string execLabel = newLabel();
                            // string skipLabel = newLabel();
                            // string checkLabel = pop_goto();
                            // if (checkLabel.compare("") != 0) {
                            //     execLabel = checkLabel;
                            //     genCode("?:= " + execLabel + ", " + temp);
                            // } else {
                            //     genCode("?:= " + execLabel + ", " + temp);
                            //     genCode(":= " + skipLabel);
                            //     genCode(": " + execLabel);
                            //     push_goto(skipLabel);
                            //     $$  = new string(skipLabel);
                            // }

                            // if (($2)->compare("") != 0) {
                            //     string temp = newTemp();
                            //     string code = *($2);
                            //     code.insert(2, " " + temp + ", " + *($1));
                            //     genCode(code);
                            //     $$ = new string(temp);
                            // } else {
                            //     $$ = $1;
                            // }
                        }
                ;

bool_expressions:   /* empty */                                         
                        {
                            /*printf("bool_expressions -> epsilon\n");*/
                            //MAY NOT NEED BELOW
                            $$ = new string("");
                        }
                |   OR relation_and_expr bool_expressions               
                        {
                            /*printf("bool_expressions -> OR relation_and_expr bool_expressions\n");*/

                            //declare base string to "return"
                            string base = (string) "||" +  (string) ", ";

                            if (($3)->compare("") != 0) {   //expression loop is not epsilon
                                //store addition result into generated temp
                                string temp = newTemp();
                                //code returned by the loop that is NOT empty
                                string code = *($3);
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(2, " " + temp + ", " + *($2));
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

relation_and_expr:      relation_expr relation_and_expressions          
                            {
                                /*printf("relation_and_expr -> relation_expr relation_and_expressions\n");*/
                                if (($2)->compare("") != 0) {
                                    //local vars
                                    string temp = newTemp();
                                    string code = *($2);
                                    //insert code 
                                    code.insert(2, temp + ", " + *($1));
                                    genCode(code);
                                    $$ = new string(temp);
                                } else {
                                    $$ = $1;
                                }
                            }
                    ;

relation_and_expressions:   /* empty */                                 
                                {
                                    /*printf("relation_and_expressions -> epsilon\n");*/
                                    $$ = new string("");
                                }
                        |   AND relation_expr relation_and_expressions  
                                {
                                    /*printf("relation_and_expressions -> AND relation_expr relation_and_expressions\n");*/
                                    //declare base string to "return"
                                    string base = (string) "&&" +  (string) ", ";

                                    if (($3)->compare("") != 0) {   //expression loop is not epsilon
                                        //store addition result into generated temp
                                        string temp = newTemp();
                                        //code returned by the loop that is NOT empty
                                        string code = *($3);
                                        //need to add current $2 and $3 together and store in generated temp
                                        code.insert(2, " " + temp + ", " + *($2));
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
relation_expr:              expression comp expression      
                                {
                                    /*printf("relation_expr -> expression comp expression\n");*/
                                    if (exist(*($1)) && exist(*($3))) {
                                        string temp = newTemp();
                                        genCode(*($2) + temp + ", " + *($1) + ", " + *($3));
                                        $$ = new string(temp);

                                        // string execLabel = newLabel();
                                        // string skipLabel = newLabel();
                                        // string checkLabel = pop_goto();
                                        // if (checkLabel.compare("") != 0) {
                                        //     execLabel = checkLabel;
                                        //     genCode("?:= " + execLabel + ", " + temp);
                                        // } else {
                                        //     genCode("?:= " + execLabel + ", " + temp);
                                        //     genCode(":= " + skipLabel);
                                        //     genCode(": " + execLabel);
                                        //     push_goto(skipLabel);
                                        //     $$  = new string(skipLabel);
                                        // }
                                                                                
                                    } else {
                                        cerr << "Variable does not exist" << endl;
                                    }
                                    
                                }
                        |   TRUE                            {/*printf("relation_expr -> TRUE\n");*/ $$ = new string("1");}
                        |   FALSE                           {/*printf("relation_expr -> FALSE\n");*/ $$ = new string("0");}
                        |   L_PAREN bool_expr R_PAREN       
                                {
                                    /*printf("relation_expr -> L_PAREN bool_expr R_PAREN\n");*/
                                    $$ = $2;
                                }
                        |   NOT expression comp expression  
                                {
                                    /*printf("relation_expr -> NOT expression comp expression\n");*/

                                    // if (exist(*($1)) && exist(*($3))) {
                                    //     string temp = newTemp();
                                    //     string notTemp = newTemp();
                                    //     genCode(*($2) + temp + ", " + *($1) + ", " + *($3));
                                    //     // $$ = new string(temp);
                                    //     genCode("! " + notTemp + ", " + temp);
                                    //     string execLabel = newLabel();
                                    //     string skipLabel = newLabel();
                                    //     string checkLabel = pop_goto();

                                    //     if (checkLabel.compare("") != 0) {
                                    //         execLabel = checkLabel;
                                    //         genCode("?:= " + execLabel + ", " + notTemp);
                                    //     } else {
                                    //         genCode("?:= " + execLabel + ", " + notTemp);
                                    //         genCode(":= " + skipLabel);
                                    //         genCode(": " + execLabel);
                                    //         push_goto(skipLabel);
                                    //         $$  = new string(skipLabel);
                                    //     }
                                    //     $$ = new string(skipLabel);
                                    // } else {
                                    //     cerr << "Variable does not exist" << endl;
                                    // }
                                }
                        |   NOT TRUE                        {/*printf("relation_expr -> NOT TRUE\n");*/ $$ = new string("0");}
                        |   NOT FALSE                       {/*printf("relation_expr -> NOT FALSE\n");*/ $$ = new string("1");}
                        |   NOT L_PAREN bool_expr R_PAREN   
                                {
                                    /*printf("relation_expr -> NOT L_PAREN b ool_expr R_PAREN\n");*/
                                    string temp = newTemp();
                                    genCode("! " + temp + ", " + *($3));
                                    $$ = new string(temp);

                                }
                        ;

comp:               EQ      {/*printf("comp -> EQ\n");*/ $$ = new string("== ");}
                |   NEQ     {/*printf("comp -> NEQ\n");*/ $$ = new string("!= ");}
                |   LT      {/*printf("comp -> LT\n");*/ $$ = new string("< ");}
                |   GT      {/*printf("comp -> GT\n");*/ $$ = new string("> ");}
                |   LTE     {/*printf("comp -> LTE\n");*/ $$ = new string("<= ");}
                |   GTE     {/*printf("comp -> GTE\n");*/ $$ = new string(">= ");}
                ;

expression:         multiplicative_expr expression_loop         
                        {
                            /*printf("expression -> multiplicative_expr expression_loop\n");*/

                            if (($2)->compare("") != 0) {   //if an expression loop exists
                                //local vars
                                string code = *($2);
                                string temp = newTemp();

                                //only applies to local code
                                code.insert(1, " " + temp + ", " + *($1));
                                genCode(code);
                                //"return" code
                                $$ = new string(temp);
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

                            //might need later but works w/o it atm
                            // $$ = new string("");
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
                                        string temp = newTemp();
                                        //inserting code
                                        code.insert(1," " + temp + ", " + *($1));
                                        genCode(code);

                                        //"return" statement
                                        $$ = new string(temp);
                                    } else {
                                        $$ = $1;
                                    }
                                }
                        ;

term:               IDENT L_PAREN expressions R_PAREN   
                        {
                            /*printf("term -> IDENT L_PAREN expressions R_PAREN\n");*/

                            //THIS IS A FUNCTION CALL
                            //SHOULD HANDLE MAYBE AT THE END WITH A STACK OR SOMETHING?
                            //IDK ATM
                            string temp = newTemp();
                            string paramTemp = newTemp();
                            string expr = *($3);
                            genCode("= " + paramTemp + ", " + expr);
                            genCode("param " + paramTemp);
                            string code = "call " + *($1) + ", " + temp;
                            genCode(code);
                            $$ = new string(temp);
                            //TODO: ADD GO TO STATEMENT
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
                                $$ = new string(arrHandler(*($1)));
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
                            //SUB A FUNCTION CALL
                            
                        }
                ;

var:                IDENT                                                 
                        {
                            /*printf("var -> IDENT\n");*/
                            $$ = $1;
                        }
                |   IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET    
                        {
                            /*printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");*/ 
                            //arr is $1; index is $3
                            string base = *($1) + ", " + *($3);
                            //"return" temp b/c it now stores the array value
                            $$ = new string(base);

                        }
                ;

vars:               /* empty */                 
                        {
                            /*printf("vars -> epsilon\n");*/
                            $$ = new string("");
                        }
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
