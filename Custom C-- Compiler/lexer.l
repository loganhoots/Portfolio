%option noyywrap

%{
#include <stdio.h>
#include <string.h>

#define YY_DECL int yylex()
#include "parser.tab.h"

int words = 0;
int chars = 0;
int lines = 0;

%}

letter      [a-zA-Z]
digit       [0-9]
ASCII       [\']{letter}[\']
ID          {letter}({letter}|{digit})*
delim       [ \t\n]
NUMBER      {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
ws          {delim}+

%%
"/*"    {
            int c;
            while((c = input()) != 0) {
                if (c == '*') {
                    if ((c = input()) == '/') break;
                    else unput(c);
                }
            }
        }
        
"int"	{
			words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"char"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"return"	{words++; chars += strlen(yytext);
			printf("%s : RETURN\n", yytext);
			yylval.string = strdup(yytext); 
			return RETURN;
		}

"read"	{words++; chars += strlen(yytext);
			printf("%s : READ\n", yytext);
			yylval.string = strdup(yytext); 
			return READ;
		}

"write"	{words++; chars += strlen(yytext);
			printf("%s : WRITE\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITE;
		}

"writeln"	{words++; chars += strlen(yytext);
			printf("%s : WRITELN\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITELN;
		}

"break"	{words++; chars += strlen(yytext);
			printf("%s : BREAK\n", yytext);
			yylval.string = strdup(yytext); 
			return BREAK;
		}

"if"	{words++; chars += strlen(yytext);
			printf("%s : IF\n", yytext);
			yylval.string = strdup(yytext); 
			return IF;
		}

"else"	{words++; chars += strlen(yytext);
			printf("%s : ELSE\n", yytext);
			yylval.string = strdup(yytext); 
			return ELSE;
		}

"while"	{words++; chars += strlen(yytext);
			printf("%s : WHILE\n", yytext);
			yylval.string = strdup(yytext); 
			return WHILE;
		}

";"		{chars++;
		  printf("%s : SEMICOLON\n\n", yytext);
		  yylval.string = strdup(yytext); 
		  return SEMICOLON;
		}

","		{chars++;
		  printf("%s : COMMA\n", yytext);
		  yylval.string = strdup(yytext); 
		  return COMMA;
		}

"="		{   
            chars++;
		    printf("%s : ASSIGN\n", yytext);
		    yylval.string = strdup(yytext); 
		    return ASSIGN;
		}

"["		{   
            chars++;
		    printf("%s : BRACK_L\n", yytext);
		    yylval.string = strdup(yytext); 
		    return BRACK_L;
		}

"]"		{   
            chars++;
		    printf("%s : BRACK_R\n", yytext);
		    yylval.string = strdup(yytext); 
		    return BRACK_R;
		}

"("		{   
            chars++;
		    printf("%s : PAREN_L\n", yytext);
		    yylval.string = strdup(yytext); 
		    return PAREN_L;
		}

")"		{   
            chars++;
		    printf("%s : PAREN_R\n", yytext);
		    yylval.string = strdup(yytext); 
		    return PAREN_R;
		}

"{"		{   
            chars++;
		    printf("%s : CURLY_L\n", yytext);
		    yylval.string = strdup(yytext); 
		    return CURLY_L;
		}

"}"		{   
            chars++;
		    printf("%s : CURLY_R\n", yytext);
		    yylval.string = strdup(yytext); 
		    return CURLY_R;
		}

"=="|"!="|"<"|"<="|">"|">=" {   
            chars++;
		    printf("%s : BOOLOP\n", yytext);
		    yylval.string = strdup(yytext); 
		    return BOOLOP;
		}

"&&"|"||" {
        chars++;
        printf("%s : LOGICOP\n", yytext);
        yylval.string = strdup(yytext); 
        return LOGICOP;
}

"*"	{   
            chars++;
		    printf("%s : MUL", yytext);
		    yylval.string = strdup(yytext); 
		    return MUL;
	}

"/"	{   
			chars++;
			printf("%s : DIV", yytext);
			yylval.string = strdup(yytext); 
			return DIV;
	}

"+" {
            chars++;
            printf("%s : ADD", yytext);
            yylval.string = strdup(yytext);
            return ADD;
    }

"-" {
            chars++;
            printf("%s : SUB", yytext);
            yylval.string = strdup(yytext);
            return SUB;
    }

"++"|"--"|"!" 	{   
            chars++;
		    printf("%s : UNOP\n", yytext);
		    yylval.string = strdup(yytext); 
		    return UNOP;
		}

{ASCII}	{
            chars += strlen(yytext);
		    printf("%s : ASCII\n", yytext);
		    yylval.string = strdup(yytext); 
		    return ASCII;
		}

{ID}	{
            words++; chars += strlen(yytext);
            printf("%s : IDENTIFIER\n",yytext);
            yylval.string = strdup(yytext); 
            return ID;
        }

{NUMBER}	{
                chars += strlen(yytext);
			    printf("%s : NUMBER\n",yytext);
			    yylval.number = atoi(strdup(yytext)); 
			    return NUMBER;
			}

[\n]	{ lines++; }
[ \t]	{ chars++; }
.		{ chars++; printf("%s : Unrecognized symbol at line %d char %d\n", yytext,lines,chars); }
		
%%