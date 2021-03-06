/* 
Christine Fossaceca
Project 2

Name: cminus.l

Do

flex cminus.1

gcc -c lex.yy.c 

to compile 
 */
%{

#include "cminus.tab.h"

int value;
int  row = 1;
int col = 1;
%}

%option noyywrap

digit                  [0-9]

letter                   [a-z]|[A-Z]

%%

                                {col = col +yyleng;}                       /*Information from textbook, multiline comment rule*/      
"/*" 				{ char c; int done = 0;
			 	 do{
                                 /*incr row each new line*/
			   	 while ((c=input())!='*')
					{ if ( c == '\n')
						row++;}
				 while ((c=input())=='*'){}
					/* star w/0 slash gets incr*/
                                        if ( c == '\n')
						row++;
					if(c =='/'){
                                             done = 1;}
				   } while (done!=1);
				}

"("                             {col = col + strlen(yytext);return LPAR;}

")"                             {col = col + strlen(yytext);return RPAR;}

";"                             {col = col + strlen(yytext);return SEMI;}

"-"                             {col = col + strlen(yytext);return SUB;}

"+"                             {col = col + strlen(yytext);return ADD;}

\=\=                           {col = col + strlen(yytext);return EQUAL;} 

"="                            {col = col + strlen(yytext);return ASSIGN;}

"&"                            {col = col + strlen(yytext);return AMP;}

"else"                         {col = col + strlen(yytext);return ELSE;}

"if"                           {col = col + strlen(yytext);return IF;}

"int"                          {col = col + strlen(yytext);return INT;}

"return"                       {col = col + strlen(yytext);return RET;}

"void"                         {col = col + strlen(yytext);return VOID;}

"while"                        {col = col + strlen(yytext);return WHILE;}

"*"                            {col = col + strlen(yytext);return MULT;}

"/"                            {col = col + strlen(yytext);return DIV;}

"<"                            {col = col + strlen(yytext);return LESS;}

"<="                           {col = col + strlen(yytext);return LESSEQ;}

">"                            {col = col + strlen(yytext);return GREAT;}

">="                           {col = col + strlen(yytext);return GREATEQ;}

"!="                           {col = col + strlen(yytext);return NOTEQ;}

","                            {col = col + strlen(yytext);return COMMA;}

"["                            {col = col + strlen(yytext);return LBRACK;}

"]"                            {col = col + strlen(yytext);return RBRACK;}

"{"                            {col = col + strlen(yytext);return LCURLY;}

"}"                            {col = col + strlen(yytext);return RCURLY;}

"printf"                       {col = col + strlen(yytext);return PRINTF;}

"\"%d\\n\""                    {col = col + strlen(yytext);return FSTRING;}
					/*note escape chars*/

"\"%d\""                       {col = col + strlen(yytext);return DSTRING;}

"scanf"                        {col = col + strlen(yytext);return SCANF;}
               
\/\/.+                            { } /* ignore // comments*/

"\n"				{row++; col = 1;}

{digit}+                 {col = col + strlen(yytext); value = yylval.intval = atoi(yytext); return NUM;}

{letter}+                {col = col + strlen(yytext); yylval.strval = (char*)strdup(yytext);return ID;}

\r                         {/* Nothing*/}

[\t]                       {col = col + 3;}

[ \t\r]+                      { col = col +yyleng; }
 
   /* final rule to trap everything else */
.                               {return ERROR;}



%%
