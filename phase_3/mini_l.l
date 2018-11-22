 /* cs152-fall18 */
   /* mini-l phase 1 */
   /*commented out code for now*/
%option noyywrap
%{
    #include "mini_l.tab.h"
    #include "header.h"
    int currLine = 1, currPos = 1;
%}

DIGIT       [0-9]
COMMENT     (##)+(.)*
LETTER      ([A-Z]|[a-z])
IDENTIFIER  ([A-Z]|[a-z])([A-Z]|[a-z]|[0-9])*(_([A-Z]|[a-z]|[0-9])+)*

%%

{COMMENT}       {/*printf("COMMENT\n");*/ currPos += yyleng;}

"function"      {/*printf("FUNCTION\n");*/ currPos += yyleng; yylval.char_pointer = strdup(yytext); return FUNCTION;}
"beginparams"   {/*printf("BEGIN_PARAMS\n");*/ currPos+=yyleng; return BEGIN_PARAMS;}
"endparams"     {/*printf("END_PARAMS\n");*/ currPos+=yyleng; return END_PARAMS;}
"beginlocals"   {/*printf("BEGIN_LOCALS\n");*/ currPos += yyleng; return BEGIN_LOCALS;}
"endlocals"     {/*printf("END_LOCALS\n");*/ currPos+=yyleng; return END_LOCALS;}
"beginbody"     {/*printf("BEGIN_BODY\n");*/ currPos+=yyleng; return BEGIN_BODY;}
"endbody"       {/*printf("END_BODY\n");*/ currPos += yyleng; return END_BODY;}
"integer"       {/*printf("INTEGER\n");*/ currPos+=yyleng; return INTEGER;}
"array"         {/*printf("ARRAY\n");*/ currPos+=yyleng; return ARRAY;}
"of"            {/*printf("OF\n");*/ currPos += yyleng; return OF;}
"if"            {/*printf("IF\n");*/ currPos+=yyleng; return IF;}
"then"          {/*printf("THEN\n");*/ currPos+=yyleng; return THEN;}
"endif"         {/*printf("ENDIF\n");*/ currPos += yyleng; return ENDIF;}
"else"          {/*printf("ELSE\n");*/ currPos+=yyleng; return ELSE;}
"while"         {/*printf("WHILE\n");*/ currPos+=yyleng; return WHILE;}
"do"            {/*printf("DO\n");*/ currPos += yyleng; return DO;}
"beginloop"     {/*printf("BEGINLOOP\n");*/ currPos+=yyleng; return BEGINLOOP;}
"endloop"       {/*printf("ENDLOOP\n");*/ currPos+=yyleng; return ENDLOOP;}
"continue"      {/*printf("CONTINUE\n");*/ currPos += yyleng; return CONTINUE;}
"read"          {/*printf("READ\n");*/ currPos+=yyleng; return READ;}
"write"         {/*printf("WRITE\n");*/ currPos+=yyleng; return WRITE;}
"and"           {/*printf("AND\n");*/ currPos += yyleng; return AND;}
"or"            {/*printf("OR\n");*/ currPos+=yyleng; return OR;}
"not"           {/*printf("NOT\n");*/ currPos+=yyleng; return NOT;}
"true"          {/*printf("TRUE\n");*/ currPos += yyleng; return TRUE;}
"false"         {/*printf("FALSE\n");*/ currPos+=yyleng; return FALSE;}
"return"        {/*printf("RETURN\n");*/ currPos+=yyleng; return RETURN;}

"-"             {/*printf("SUB\n");*/ currPos += yyleng; return SUB;}
"+"             {/*printf("ADD\n");*/ currPos+=yyleng; return ADD;}
"*"             {/*printf("MULT\n");*/ currPos+=yyleng; return MULT;}
"/"             {/*printf("DIV\n");*/ currPos += yyleng; return DIV;}
"%"             {/*printf("MOD\n");*/ currPos+=yyleng; return MOD;}

"=="            {/*printf("EQ\n");*/ currPos+=yyleng; return EQ;}
"<>"            {/*printf("NEQ\n");*/ currPos += yyleng; return NEQ;}
"<"             {/*printf("LT\n");*/ currPos+=yyleng; return LT;}
">"             {/*printf("GT\n");*/ currPos+=yyleng; return GT;}
"<="            {/*printf("LTE\n");*/ currPos += yyleng; return LTE;}
">="            {/*printf("GTE\n");*/ currPos+=yyleng; return GTE;}

{IDENTIFIER}    {/*printf("IDENT %s \n", yytext);*/ currPos+=yyleng; yylval.char_pointer = strdup(yytext); return IDENT;}
{DIGIT}+        {/*printf("NUMBER %s\n", yytext);*/ currPos += yyleng; /*yylval.char_pointer = strdup(yytext);*/ return NUMBER;}

";"             {/*printf("SEMICOLON\n");*/ currPos+=yyleng; return SEMICOLON;}
":"             {/*printf("COLON\n");*/ currPos+=yyleng; return COLON;}
","             {/*printf("COMMA\n");*/ currPos += yyleng; return COMMA;}
"("             {/*printf("L_PAREN\n");*/ currPos+=yyleng; return L_PAREN;}
")"             {/*printf("R_PAREN\n");*/ currPos+=yyleng; return R_PAREN;}
"["             {/*printf("L_SQUARE_BRACKET\n");*/ currPos+=yyleng; return L_SQUARE_BRACKET;}
"]"             {/*printf("R_SQUARE_BRACKET\n");*/ currPos+=yyleng; return R_SQUARE_BRACKET;}
":="            {/*printf("ASSIGN\n");*/ currPos += yyleng; return ASSIGN;}

({DIGIT}|(_))+{IDENTIFIER}      {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); currPos += yyleng; exit(0);}
{IDENTIFIER}(_)+                {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos, yytext); currPos += yyleng; exit(0);}
{IDENTIFIER}(_)+{IDENTIFIER}   {printf("Error at line %d, column %d: identifier \"%s\" cannot contain consecutive underscores\n", currLine, currPos, yytext); currPos += yyleng; exit(0);}

[ \t]+         {/* ignore spaces */ currPos += yyleng;}

"\n"           {currLine++; currPos = 1;}

.              {printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%

