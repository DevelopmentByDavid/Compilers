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
%type <myBlock> bool_expr
%type <myBlock> relation_and_expr
%type <myBlock> relation_expr
%type <myString> comp
%type <myBlock> expression
%type <myBlock> expressions
%type <myBlock> multiplicative_expr
%type <myBlock> terms
%type <myBlock> term
%type <myBlock> var
%type <myBlock> vars
%type <myBlock> idents
%type <myBlock> params

%type <myString> fnDecl
%type <myBlock> bool_expressions
%type <myBlock> relation_and_expressions
%type <myBlock> expression_loop

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
%right      UMINUS
%left       L_SQUARE_BRACKET
%left       R_SQUARE_BRACKET
%left       L_PAREN
%left       R_PAREN



%% 
program:            functions                
                        {
                            /*printf("program -> functions\n");*/
                            verify(); //post verification of stuff
                            print();
                        } 
		        ;

functions:          /* empty */              {/*printf("functions -> epsilon\n");*/}
                |   function functions       
                        {
                        // /*printf("functions -> function functions\n");*/
                        }
                ;

function:           fnDecl SEMICOLON params
                    BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY  
                        {
                            /*printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS
                            BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY\n");*/
                            CodeBlock block;
                            block.push_back("func " + *($1));
                            block = block + *($3) + *($5) + *($8) + *($10);
                            block.push_back("endfunc");
                            block.shipCode();
                            func(*($1));
                            block.danglingLabels();

                        }
                ;

fnDecl:             FUNCTION IDENT
                        {
                            addTable(*($2));
                            $$ = $2;
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
                            CodeBlock block;
                            block = *($1) + *($3);
                            $$ = new CodeBlock(block);
                        }
                ;

declaration:        IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER   
                        {
                            /*printf("delcaration -> IDENT idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");*/
                            CodeBlock temp;
                            if (addTable(*($1))) {
                                temp.push_back(".[] " + *($1) + ", " + *($6));
                                temp.setVal(*($1));
                            };

                            if (stoi(*($6)) <= 0) {
                                cerr << "Error Line " << currLine << ": declaring array with size <= 0" << endl;
                            }

                            addArr(*($1));

                            temp += *($2);
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
                            temp += *($2);
                            $$ = new CodeBlock(temp);
                        }
                ;

idents:             /* empty */         
                        {
                            /*printf("idents -> epsilon\n");*/
                            $$ = new CodeBlock();
                        }
                |   COMMA IDENT idents  
                        {
                            /*printf("idents -> COMMA IDENT idents\n");*/
                            CodeBlock temp;
                            temp = *($3);
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
                            CodeBlock block;
                            block = *($1) + *($3);
                            $$ = new CodeBlock(block);
                        }
                ;

statement:          var ASSIGN expression                                                                       
                        {
                            /*printf("statement -> var ASSIGN expression\n");*/
                            CodeBlock block;
                            block = *($1) + *($3);
                            if (exist(($1)->getVal()) && exist(($3)->getVal())) {             //if both variables exist, then simple assign statement
                                block.push_back("= " + ($1)->getVal() + ", " + ($3)->getVal());
                            } else if (!exist(($1)->getVal()) && exist(($3)->getVal())) {     //if left side is an array var and right side is not
                                string code = ($1)->getVal();
                                string toAppend = ($3)->getVal();
                                code.insert(0, "[]= ");
                                code.append(", " + toAppend);
                                block.push_back(code);
                            } 
                            $$ = new CodeBlock(block);
                        }
                |   IF bool_expr THEN statement SEMICOLON statements ENDIF                                      
                        {
                            /*printf("statement -> IF bool_expr THEN statement SEMICOLON statements ENDIF\n");*/                            
                            CodeBlock tempBlock;
                            string execLabel = newLabel();
                            string skipLabel = newLabel();
                            ($2)->push_back("?:= " + execLabel + ", " + ($2)->getVal());
                            ($2)->push_back(":= " + skipLabel);
                            ($2)->push_back(": " + execLabel);
                            tempBlock = *($2) + *($4) + *($6);
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
                            string skipIfLabel = newLabel();
                            string skipElseLabel = newLabel();

                            ($2)->push_back("?:= " + execLabel + ", " + ($2)->getVal());
                            ($2)->push_back(":= " + skipIfLabel);
                            ($2)->push_back(": " + execLabel);
                            ($8)->push_front(": " + skipIfLabel);
                            ($8)->push_front(":= " + skipElseLabel);
                            ($10)->push_back(": " + skipElseLabel);
                            tempBlock = *($2) + *($4) + *($6) + *($8) + *($10);
                            $$ = new CodeBlock(tempBlock);
                        }
                |   WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP                            
                        {
                            /*printf("statement -> WHILE bool_expr BEGINLOOP statement SEMICOLON statements ENDLOOP\n");*/
                            CodeBlock tempBlock;
                            string execLabel = newLabel();
                            string skipLabel = newLabel();
                            string loopLabel = newLabel();
                            ($2)->push_front(": " + loopLabel);
                            ($2)->pop_back_label_all();
                            ($4)->pop_back_label_all();
                            ($6)->pop_back_label_all();
                            ($2)->push_back("?:= " + execLabel + ", " + ($2)->getVal());
                            ($2)->push_back(":= " + skipLabel);
                            ($2)->push_back(": " + execLabel);
                            ($6)->push_back(":= " + loopLabel);
                            ($6)->push_back(": " + skipLabel);
                            tempBlock = *($2) + *($4) + *($6);
                            $$ = new CodeBlock(tempBlock);
                        }
                |   DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr
                        {
                            /*printf("statement -> DO BEGINLOOP statement SEMICOLON statements ENDLOOP WHILE bool_expr\n");*/ 
                            CodeBlock tempBlock;
                            string execLabel = newLabel();
                            tempBlock = *($3) + *($5);
                            tempBlock.push_front(": " + execLabel);
                            tempBlock.pop_back_label_all();
                            tempBlock += *($8);
                            tempBlock.push_back("?:= " + execLabel + ", " + ($8)->getVal());
                            $$ = new CodeBlock(tempBlock);
                        }
                |   READ var vars                                                                               
                        {
                            /*printf("statement ->  READ var vars\n");*/
                            CodeBlock tempBlock;
                            tempBlock = *($2);
                            if (!($3)->isNull()) {
                                tempBlock += *($3);
                            }
                            tempBlock.push_var(($2)->getVal());
                            tempBlock.pop_var("<");
                            $$ = new CodeBlock(tempBlock);
                        }
                |   WRITE var vars                                                                              
                        {
                            /*printf("statement -> WRITE var vars\n");*/
                            CodeBlock tempBlock;
                            tempBlock = *($2);
                            if (!($3)->isNull()) {
                                tempBlock += *($3);
                            }
                            tempBlock.push_var(($2)->getVal());
                            tempBlock.pop_var(">");
                            $$ = new CodeBlock(tempBlock);
                        }
                |   CONTINUE                                                                                    
                        {
                            /*printf("statement -> CONTINUE\n");*/
                            CodeBlock temp;
                            string label = newLabel();
                            temp.push_back_label(label);
                            temp.push_back(":= " + label);
                            $$ = new CodeBlock(temp);
                        }
                |   RETURN expression                                                                           
                        {
                            /*printf("statement -> RETURN expression\n");*/
                            CodeBlock temp;
                            temp = *($2);
                            temp.push_back("ret " + ($2)->getVal());
                            $$ = new CodeBlock(temp);
                        }
                ;

bool_expr:          relation_and_expr bool_expressions                 
                        {
                            /*printf("bool_expr -> relation_and_expr bool_expressions\n");*/
                            if (!($2)->isNull()) {           //if an bool_expression loop exists
                                string code = ($2)->getVal();
                                string temp = newTemp();
                                CodeBlock block;
                                block.push_back(". " + temp);
                                block += *($1) + *($2);
                                code.insert(2, " " + temp + ", " + ($1)->getVal());
                                block.push_back(code);
                                block.setVal(temp);
                                $$ = new CodeBlock(block);
                            } else {                        //if expression loop does not exist; i.e. just a number
                                $$ = $1;
                            }
                        }
                ;

bool_expressions:   /* empty */                                         
                        {
                            /*printf("bool_expressions -> epsilon\n");*/
                            $$ = new CodeBlock();
                        }
                |   OR relation_and_expr bool_expressions               
                        {
                            /*printf("bool_expressions -> OR relation_and_expr bool_expressions\n");*/

                            //declare base string to "return"
                            string base = (string) "||" +  (string) ", ";

                            if (!($3)->isNull()) {   //expression loop is not epsilon
                                CodeBlock block;
                                block = *($2) + *($3);
                                //store addition result into generated temp
                                string temp = newTemp();
                                block.push_back(". " + temp);
                                //code returned by the loop that is NOT empty
                                string code = ($3)->getVal();
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(2, " " + temp + ", " + ($2)->getVal());
                                block.push_back(code);
                                block.setVal(base + temp);
                                //now "return" the base + temp
                                //value of expression generated above is in the generated temp
                                $$ = new CodeBlock(block);
                            } else {                        //expression loop is epsilon
                                CodeBlock block;
                                block = *($2);
                                block.setVal(base + ($2)->getVal());
                                $$ = new CodeBlock(block);
                            }
                        }
                ;

relation_and_expr:      relation_expr relation_and_expressions          
                            {
                                /*printf("relation_and_expr -> relation_expr relation_and_expressions\n");*/
                                if (!($2)->isNull()) {
                                    //local vars
                                    string temp = newTemp();
                                    string code = ($2)->getVal();
                                    CodeBlock block;
                                    block.push_back(". " + temp);
                                    block += *($1) + *($2);
                                    //insert code 
                                    code.insert(2, " " + temp + ", " + ($1)->getVal());
                                    block.push_back(code);
                                    block.setVal(temp);
                                    $$ = new CodeBlock(block);
                                } else {
                                    $$ = $1;
                                }
                            }
                    ;

relation_and_expressions:   /* empty */                                 
                                {
                                    /*printf("relation_and_expressions -> epsilon\n");*/
                                    $$ = new CodeBlock();
                                }
                        |   AND relation_expr relation_and_expressions  
                                {
                                    /*printf("relation_and_expressions -> AND relation_expr relation_and_expressions\n");*/
                                    //declare base string to "return"
                                    string base = (string) "&&" +  (string) ", ";

                                    if (!($3)->isNull()) {   //expression loop is not epsilon
                                        CodeBlock block;
                                        block = *($2) + *($3);
                                        //store addition result into generated temp
                                        string temp = newTemp();
                                        block.push_back(". " + temp);
                                        //code returned by the loop that is NOT empty
                                        string code = ($3)->getVal();
                                        //need to add current $2 and $3 together and store in generated temp
                                        code.insert(2, " " + temp + ", " + ($2)->getVal());
                                        block.push_back(code);
                                        block.setVal(base + temp);
                                        //now "return" the base + temp
                                        //value of expression generated above is in the generated temp
                                        $$ = new CodeBlock(block);
                                    } else {                        //expression loop is epsilon
                                        //"return" base + $2
                                        CodeBlock block;
                                        block = *($2);
                                        block.setVal(base + ($2)->getVal());
                                        $$ = new CodeBlock(block);
                                    }
                                }
                        ;
relation_expr:              expression comp expression      
                                {
                                    /*printf("relation_expr -> expression comp expression\n");*/
                                    CodeBlock block;
                                    block = *($1) + *($3);
                                    string temp = newTemp();
                                    block.push_back(". " + temp);
                                    block.push_back(*($2) + temp + ", " + ($1)->getVal() + ", " + ($3)->getVal());
                                    block.setVal(temp);
                                    $$ = new CodeBlock(block);                                   
                                }
                        |   TRUE                            {/*printf("relation_expr -> TRUE\n");*/ $$ = new CodeBlock("1");}
                        |   FALSE                           {/*printf("relation_expr -> FALSE\n");*/ $$ = new CodeBlock("0");}
                        |   L_PAREN bool_expr R_PAREN       
                                {
                                    /*printf("relation_expr -> L_PAREN bool_expr R_PAREN\n");*/
                                    $$ = $2;
                                }
                        |   NOT expression comp expression  
                                {
                                    /*printf("relation_expr -> NOT expression comp expression\n");*/
                                    CodeBlock block;
                                    block = *($2) + *($4);
                                    string temp = newTemp();
                                    block.push_back(". " + temp);
                                    string notTemp = newTemp();
                                    block.push_back(". " + notTemp);
                                    block.push_back(*($3) + temp + ", " + ($2)->getVal() + ", " + ($4)->getVal());
                                    block.push_back("! " + notTemp + ", " + temp);
                                    block.setVal(notTemp);
                                    $$ = new CodeBlock(block);                                   
                                }
                        |   NOT TRUE                        {/*printf("relation_expr -> NOT TRUE\n");*/ $$ = new CodeBlock("0");}
                        |   NOT FALSE                       {/*printf("relation_expr -> NOT FALSE\n");*/ $$ = new CodeBlock("1");}
                        |   NOT L_PAREN bool_expr R_PAREN   
                                {
                                    /*printf("relation_expr -> NOT L_PAREN b ool_expr R_PAREN\n");*/
                                    CodeBlock block;
                                    block = *($3);
                                    string temp = newTemp();
                                    block.push_back(". " + temp);
                                    block.push_back("! " + temp + ", " + ($3)->getVal());
                                    block.setVal(temp);
                                    $$ = new CodeBlock(block);

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

                            if (!($2)->isNull()) {   //if an expression loop exists
                                //local vars
                                CodeBlock block;
                                block = *($1) + *($2);
                                string code = ($2)->getVal();
                                string temp = newTemp();
                                block.push_back(". " + temp);
                                //only applies to local code
                                code.insert(1, " " + temp + ", " + ($1)->getVal());
                                block.push_back(code);
                                block.setVal(temp);
                                //"return" code
                                $$ = new CodeBlock(block);
                            } else {                        //if expression loop does not exist; i.e. just a number
                                $$ = $1;
                            }
                        }
                ;

expression_loop:    /* empty */                                 
                        {
                            /*printf("expression_loop -> epsilon\n");*/
                            $$ = new CodeBlock();
                        }
                |   ADD multiplicative_expr expression_loop     
                        {
                            /*printf("expression_loop -> ADD multiplicative_expr expression_loop\n");*/

                            //declare base string to "return"
                            string base = (string) "+" +  (string) ", ";

                            if (!($3)->isNull()) {   //expression loop is not epsilon
                                CodeBlock block;
                                block = *($2) + *($3);
                                //store addition result into generated temp
                                string temp = newTemp();
                                block.push_back(". " + temp);
                                //code returned by the loop that is NOT empty
                                string code = ($3)->getVal();
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(1, " " + temp + ", " + ($2)->getVal());
                                block.push_back(code);
                                block.setVal(base + temp);
                                //now "return" the base + temp
                                //value of expression generated above is in the generated temp
                                $$ = new CodeBlock(block);
                            } else {                        //expression loop is epsilon
                                //"return" base + $2
                                CodeBlock block = *($2);
                                block.setVal(base + ($2)->getVal());
                                $$ = new CodeBlock(block);
                            }
                        }
                |   SUB  multiplicative_expr expression_loop    
                        {
                            /*printf("expression_loop -> SUB  multiplicative_expr expression_loop\n");*/

                            //declare base string to "return"
                            string base = (string) "-" +  (string) ", ";

                            if (!($3)->isNull()) {   //expression loop is not epsilon
                                CodeBlock block;
                                block = *($2) + *($3);
                                //store addition result into generated temp
                                string temp = newTemp();
                                block.push_back(". " + temp);
                                //code returned by the loop that is NOT empty
                                string code = ($3)->getVal();
                                //need to add current $2 and $3 together and store in generated temp
                                code.insert(1, " " + temp + ", " + ($2)->getVal());
                                //generate code
                                block.push_back(code);
                                block.setVal(base + temp);
                                //now "return" the base + temp
                                //value of expression generated above is in the generated temp
                                $$ = new CodeBlock(block);
                            } else {                        //expression loop is epsilon
                                //"return" base + $2
                                CodeBlock block = *($2);
                                block.setVal(base + ($2)->getVal());
                                $$ = new CodeBlock(block);
                            }
                        }
                ;


expressions:        expression COMMA expressions    
                        {
                            /*printf("expressions -> expression COMMA expressions\n");*/

                            //not sure if this is right
                            CodeBlock block;
                            block = *($1) + *($3);
                            $$ = new CodeBlock(block);
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
                            $$ = new CodeBlock();
                        }
                ;

terms:              /* empty */             
                        {
                            /*printf("terms -> epsilon\n");*/
                            $$ = new CodeBlock();
                        }
                |   MOD term terms          
                        {
                            /*printf("terms -> MOD term terms\n");*/
                            CodeBlock block;
                            block = *($2) + *($3);
                            if (!($3)->isNull()) {
                                string code = ($3)->getVal();
                                code.insert(1, " " + ($2)->getVal());
                                block.push_back(code);
                            }
                            string temp = (string) "%" + (string) ", " + ($2)->getVal();
                            block.setVal(temp);
                            $$ = new CodeBlock(block);
                        }
                |   DIV term terms          
                        {
                            /*printf("terms -> DIV term terms\n");*/
                            CodeBlock block;
                            block = *($2) + *($3);
                            if (!($3)->isNull()) {
                                string code = ($3)->getVal();
                                code.insert(1, " " + ($2)->getVal());
                                block.push_back(code);
                            }
                            string temp = (string) "/" + (string) ", " + ($2)->getVal();
                            block.setVal(temp);
                            $$ = new CodeBlock(block);
                        }
                |   MULT term terms         
                        {
                            /*printf("terms -> MULT term terms\n");*/
                            CodeBlock block;
                            block = *($2) + *($3);
                            if (!($3)->isNull()) {
                                string code = ($3)->getVal();
                                code.insert(1, " " + ($2)->getVal());
                                block.push_back(code);
                            }
                            string temp = (string) "*" + (string) ", " + ($2)->getVal();
                            block.setVal(temp);
                            $$ = new CodeBlock(block);
                        }
                ;

multiplicative_expr:        term terms      
                                {
                                    /*printf("multiplicative_expr -> term terms\n");*/
                                    if (!($2)->isNull()) {
                                        //local var
                                        CodeBlock block;
                                        block = *($1) + *($2);
                                        string code = ($2)->getVal();
                                        string temp = newTemp();
                                        block.push_back(". " + temp);
                                        //inserting code
                                        code.insert(1," " + temp + ", " + ($1)->getVal());
                                        block.push_back(code);
                                        block.setVal(temp);

                                        //"return" statement
                                        $$ = new CodeBlock(block);
                                    } else {
                                        $$ = $1;
                                    }
                                }
                        ;

term:               IDENT L_PAREN expressions R_PAREN   
                        {
                            /*printf("term -> IDENT L_PAREN expressions R_PAREN\n");*/
                            undeclared(*($1));
                            CodeBlock block;
                            block = *($3);
                            string temp = newTemp();
                            block.push_back(". " + temp);
                            string paramTemp = newTemp();
                            block.push_back(". " + paramTemp);
                            string expr = ($3)->getVal();
                            block.push_back("= " + paramTemp + ", " + expr);
                            block.push_back("param " + paramTemp);
                            string code = "call " + *($1) + ", " + temp;
                            block.push_back(code);
                            block.setVal(temp);
                            $$ = new CodeBlock(block);
                        }
                |   NUMBER                              
                        {
                            /*printf("term -> NUMBER\n");*/

                            //generate temp
                            CodeBlock block;
                            string temp = newTemp();
                            block.push_back(". " + temp);
                            //generate the code to store $1 into temp
                            block.push_back("= " + temp + ", " + *($1));
                            block.setVal(temp);
                            //"return" temp b/c it now stores the number
                            $$ = new CodeBlock(block);
                        }
                |   var                                 
                        {
                            /*printf("term -> var\n");*/
                            CodeBlock block;
                            block = *($1);
                            if (!exist(($1)->getVal())) {        //if $1 isn't just an identifier
                                string temp = newTemp();
                                block.push_back(". " + temp);
                                block.push_back("=[] " + temp + ", " + ($1)->getVal());
                                block.setVal(temp);
                                $$ = new CodeBlock(block);
                            } else {    
                                block.setVal(($1)->getVal());
                                $$ = new CodeBlock(block);
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
                            CodeBlock block;
                            block.setVal((string) "-" + *($2));
                            $$ = new CodeBlock(block);
                        }
                |   SUB var                             
                        {
                            /*printf("term -> SUB var\n");*/
                            CodeBlock block;
                            block = *($2);
                            block.setVal((string) "-" + ($2)->getVal());
                            $$ = new CodeBlock(block);
                        }
                |   SUB L_PAREN expression R_PAREN      
                        {
                            /*printf("term -> SUB L_PAREN expression R_PAREN\n");*/
                            CodeBlock block = *($3);
                            block.setVal((string) "-" + ($3)->getVal());
                            $$ = new CodeBlock(block);
                        }
                ;

var:                IDENT                                                 
                        {
                            /*printf("var -> IDENT\n");*/
                            undeclared(*($1));
                            inverseCheckArr(*($1));
                            $$ = new CodeBlock(*($1));
                        }
                |   IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET    
                        {
                            /*printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");*/ 
                            undeclared(*($1));
                            checkArr(*($1));
                            //arr is $1; index is $3
                            CodeBlock block;
                            block = *($3);
                            string base = *($1) + ", " + ($3)->getVal();
                            block.setVal(base);
                            //"return" temp b/c it now stores the array value
                            $$ = new CodeBlock(block);

                        }
                ;

vars:               /* empty */                 
                        {
                            /*printf("vars -> epsilon\n");*/
                            $$ = new CodeBlock();
                        }
                |   COMMA var vars              
                        {
                            /*printf("vars -> COMMA var vars \n");*/
                            CodeBlock block;
                            block = *($2);
                            if (!($3)->isNull()) {
                                block += *($3);
                            }
                            block.push_var(($2)->getVal());

                            $$ = new CodeBlock(block);
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
