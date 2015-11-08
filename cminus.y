/*
Christine Fossaceca
Project 4

Gencode Added

Name: cminus.y

Bison file to generate the header file for token values.

Do 

bison -d cminus.y 

to generate cminus.tab.h and then #include
this in the .l file. To generate the lexer, do

flex cminus.l
gcc lex.yy.c  

*/
%{
#include <stdio.h>
#include "symtab.h"
#include <stdlib.h>
#include <string.h>

extern char * yytext;
extern int yylex();
extern int row; //count the rows
extern int col; //count the columns
void yyerror (char const *s);
char * concat( char * str1, char * str2);
int JVM = 0;//count the jvm number
int location = 0;//increment the memory location
int scope = 0;//keep track of the scope
int size = 0;//size for arrays--everything else default 0
char * kind;//keep track if function, variable, or array
char * print;//temp string to print out when calling fxns
int params= 0;//keep track of the number of params
int type = 0;//type = INT or VOID (ret type)
int mainFlag;//has the main function been set yet?
int count=0;//count the number of params
int inserted;//if the function has been inserted, flag
int flag =0;//this flag keeps track of strcpy vs strcat for printing, if function has no params
char * compare;//this lets you look at a name, or variable type and compare it
char * string; //this is printed, depending on if the function has variable or not (I, [I)
char save[80]; //this is the final printed string, and is cleared each time a function is called
int refresh;//this is the variable that runs the loop to reset the "save" string
char * blank = " ";//just needed a blank space
int scopeChange = 0;//keep track of changing scope for redeclarations in the symtab
int callFlag = 0;//if a function is called set this flag
int oppFlag = 0;//if an operator is used, set this flag.  Keeps it from having too many args in the call bytecode
int brackFlag= 0;//if a bracket is seen (because it detects an array)
int scanCalled=0;//check if scan is called
int relopsFlag = 0;//flag for relative operators

char * parmName = "notarealname";//must initialize to something
%}

%union
{ 
	int intval;
	char * strval;
	
}

%error-verbose
/*%expect 1 got rid of this */


/*tokens*/
%token WHILE INT RET VOID ELSE IF MULT DIV ADD SUB LESS LESSEQ GREAT GREATEQ
%token EQUAL NOTEQ ASSIGN SEMI COMMA LPAR RPAR LBRACK RBRACK LCURLY RCURLY
%token ERROR PRINTF FSTRING DSTRING SCANF AMP 

/*special tokens*/
%token <intval> NUM
%token <strval> ID
%% 

/*context-free grammar*/

program		: 	{genBegin(); }declarationlist { {if (mainFlag!=1){printf("Semantic Error: No Main function at row = %d\tcol = %d.\n", row, col);}}genConstruct();if(count!= 0)
{printGlobArr(); genRet();} genEnd();}
		;

declarationlist	:	declarationlist declaration
		|	declaration
		;
	
declaration	:	vardeclaration
		|	fundeclaration
		;

vardeclaration	:	INT ID SEMI
				{
				
				if(st_lookup($2, "variable", INT, scope) ==-1){
					st_insert($2,location, JVM, scope, "variable", size, INT, params); 
				if(scope == 0)
				{
				genVar(scope, $2, jvm_lookup($2, "variable",INT, scope));
				}
					
				JVM++; location++;scopeChange=0;}
					
				
				else if(st_lookup($2, "variable", INT, scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two variables %s of different  RETURN types. The return of %s is VOID\n", row, col, $2, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "variable", INT, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d.Can't have two names %s of different types. %s is an array\n", row, col,$2, $2);}
				else if (st_lookup($2, "variable",INT, scope) ==-4) {if((scopeChange ==1)&&(strcmp(parmName, $<strval>2)!= 0)){st_insert($2,location, JVM, scope, "variable", size, INT, params); JVM++; location++;scopeChange = 0;changeTwice ($2);}
	
}
else {                         printf("Semantic Error: row = %d\tcol = %d. Can't redeclare name %s in current scope.\n", row, col, $2);}}
		|	VOID ID SEMI  
				{
				if(st_lookup($2, "variable", VOID, scope) ==-1){
				
					printf("Semantic Error: row = %d\tcol = %d. Can't have variable %s of type VOID\n",row, col, $2);
				}
				
				else if(st_lookup($2, "variable", VOID, scope) >=0)
				{
				
				printf("Semantic Error: row = %d\tcol = %d. Can't have two variables %s of different  RETURN types. Already exists with return INT\n", row, col, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "variable", INT, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d.Can't have two names %s of different types. %s is a variable\n",row, col, $2, $2);}
				else if (st_lookup($2, "variable", returnType($2), scope) ==-4) {printf("Semantic Error: row = %d\tcol = %d. Can't redeclare variable in same scope\n",row, col);}
	else {printf("Semantic Error:row = %d\tcol = %d. Variable %s has already been declared\n",row, col,$2); 
				}
}
		|       INT ID LBRACK NUM RBRACK SEMI
			
				{if (st_lookup($2, "array", INT, scope) ==-1) 
					{	
				 
					st_insert($2,location, JVM, scope, "array", $4, INT, params); genArr(scope, $2, $4, jvm_lookup($2, "array",INT, scope));JVM++; location++;scopeChange = 0; if(scope ==0) {count = count + 1 ;}			
					
				}
				else if(st_lookup($2, "array", returnType($2),scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two arrays %s of different RETURN types. Already exists with return type VOID\n",row, col, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "array", returnType($2), scope) ==-3){
				printf("Semantic Error: row = %d\tcol = %d.Can't have two names %s of different types.  %s is a variable\n",row, col, $2,$2);}
				else if (st_lookup($2, "array", returnType($2),scope) ==-4) {if(scopeChange ==1) {st_insert($2,location, JVM, scope, "variable", size, INT, params); JVM++; location++;scopeChange = 1;changeTwice($2);} else{printf("Semantic Error: row = %d\tcol = %d. Can't redeclare name %s in current scope.\n", row, col, $2);}}
				else
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't redeclare name %s in current scope.\n", row, col, $2);	
				}
			}
		
		|       VOID ID LBRACK NUM RBRACK SEMI
			
				{if (st_lookup($2, "array", VOID, scope) ==-1) 
				{
				printf("Semantic Error:row = %d\tcol = %d. Can't have array %s of type VOID\n",row, col, $2);
				}
				else if(st_lookup($2, "array", VOID,scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two arrays %s of different RETURN types. The return type of %s is %d\n",row, col, $2, $2, returnType($2));
				}
				else if (st_lookup($2, "array", VOID, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is a variable\n",row, col, $2,$2);}
				else if (st_lookup($2, "array", VOID,scope) ==-4) {printf("Semantic Error: row = %d\tcol = %d.Can't redeclare array in same scope\n",row,col);}
				else
				{
				printf("Semantic Error: row = %d\tcol = %d.Array %s has already been declared\n",row, col, $2); 
				}
			}
		;


fundeclaration	:	INT ID LPAR 
			{ 	scanCalled = 0;parmName = $2;
				inserted = 0;
				if (mainFlag ==1)
				{printf("Semantic Error: row = %d\tcol = %d.Cannot insert function %s after main",row, col, $2);
				} 
				else{  
					if(st_lookup($2, "function", INT, scope) ==-1) 						{		
						if(strcmp($<strval>2, "main") ==0) 
							{
								printf("Semantic Error: row = %d\tcol = %d. Cannot assign main type int\n", row, col);
							}
					else {JVM = 0;}
					type = INT;
					if (strcmp($<strval>2, "main") !=0)
					{ params = 0; 
					  st_insert($2,location, JVM, scope, "function", size, type, params); inserted = 1;
					} 
					if(mainFlag==1)
					{ /*Don't do anything*/   }
					else{printf(";>> FUNCTION %s <<\n", $2);printf(".method static %s(",$2);location++; params = 0;/*reset the value of params*/ }
					}		        
					else if(st_lookup($2, "function", INT, scope) ==-2)					{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two functions %s of different RETURN types. Already exists as type VOID\n", row, col, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "function", returnType($2), scope) ==-3){printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is a function\n",row, col, $2,$2);}
		else if (st_lookup($2, "function", returnType($2),scope) ==-4){printf("Semantic Error: row = %d\tcol = %d. Can't redeclare function in same scope\n", row, col);}

				else {
				printf("Semantic Error: row = %d\tcol = %d. Function %s already in scope\n",row, col, $2); }
			}
}
			parameters{if(mainFlag!=1){st_update($2, params);}} RPAR {if((inserted ==1)&& (mainFlag!=1))
					{
					printf(")");
					if(returnType($2) == INT)
					{printf("I\n"); }
					else{	printf("V\n");
					}
				 genFunc();					
					} }compoundstmt {  printf("ireturn\n");
  printf(".end method\n\n");}

		|	VOID ID LPAR 
			{ 	scanCalled = 0;  parmName=$2;inserted = 0;
				if (mainFlag ==1)
				{printf("Semantic Error: row = %d\tcol = %d. Cannot insert function %s after main\n", row, col, $2);
				} 
				else{  
				if(st_lookup($2, "function", VOID, scope) ==-1) {		
					if(strcmp($<strval>2, "main") ==0) {
					
					mainFlag = 1;	JVM = 1;			
					}
					else {JVM = 0;}
					type = VOID;
					params = 0;
					st_insert($2,location, JVM, scope, "function", size, type, params); inserted = 1; if(mainFlag==1)
	{genMain();}else{printf(";>> FUNCTION %s <<\n", $2);printf(".method static %s(",$2);location++; params = 0;/*reset the value of params*/ }
					}			        
				else if(st_lookup($2, "function", VOID, scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Can't have two functions %s of different RETURN types. Already exists of type INT\n",row, col, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "function", VOID, scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is a function\n", row, col, $2,$2);}
		else if (st_lookup($2, "function", VOID,scope) ==-4) {printf("Semantic Error: row = %d\tcol = %d.Can't redeclare function in same scope\n", row , col);}

				else {
				printf("Semantic Error:row = %d\tcol = %d. Function %s already in scope\n",row, col, $2); 	
					}
			}
}
			parameters{if(mainFlag!=1){st_update($2, params);}} RPAR {if((inserted ==1)&& (mainFlag!=1))
					{
					printf(")");
					if(returnType($2) == INT)
					{printf("I\n"); }
					else{	printf("V\n");
					}
				 genFunc();					
					} /*genFunc();*/} compoundstmt {genRet();}

		;


parameters          :	paramslist
		|	VOID 
		;

paramslist	:       paramslist COMMA param
		|	param
		;

param		: 	INT ID
			{
			if (st_lookup($2, "variable", INT, scope) ==-1)                  {parmName=$2;
				params++;
				scope++; scopeChange = 1;
			st_insert($2,location, JVM, scope, "variable", size, INT, params);printf("I"); JVM++; location++; scope--; 

			}
			else if(st_lookup($2, "variable", returnType($2), scope) ==-2)				{
				printf(" Semantic Error: row = %d\tcol = %d. Variable %s was declared with a different RETURN type. The return type of %s is VOID\n",row, col, $2, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "variable", returnType($2), scope)==-3)
				
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s was already declared as a variable\n",row, col, $2,$2);}
		
					
			else {  printf("I"); 
				params++;
				scope++;scopeChange = 1;
			st_insert($2,location, JVM, scope, "variable", size, INT, params); JVM++; location++; scope--;parmName=$2;changeTwice($2);
				}
		}
			
		
		|	VOID ID
			{
			if (st_lookup($2, "variable",VOID, scope) ==-1)                  	{
				printf("Semantic Error: row = %d\tcol = %d. Can't have variable %s of type VOID\n",row, col, $2);	
			}

			
			else if(st_lookup($2, "variable", VOID, scope) ==-2)			{	printf("Semantic Error: row = %d\tcol = %d. Variable %s was declared with a different RETURN type. The return type of %s is INT", row, col, $2, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "variable", VOID, scope)==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s was already declared as a variable\n",row, col, $2,$2);}		
			else {
				
				printf("Semantic Error: row = %d\tcol = %d. Param Variable %s already declared\n",row, col, $2); 
				}
			
		}

		|	INT ID LBRACK RBRACK
			{if (st_lookup($2, "array", INT, scope) ==-1) 
			{
				parmName=$2;
				params++; scope++;scopeChange = 1;
				st_insert($2,location, JVM, scope, "array", size, INT, params); printf("[I");JVM++; location++; scope--;
		        }
			else if(st_lookup($2, "array", returnType($2),scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Array %s was declared with a different RETURN type. Already delcared type VOID\n", row, col, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "array", returnType($2),scope) ==-3)
				{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s is was declared as an array\n", row, col, $2,$2);}		
			
			else {   printf("[I");
				 params++;
				 scope++;scopeChange = 1; 
				st_insert($2,location, JVM, scope, "array", size, INT, params); JVM++; location++; scope--;changeTwice($2);
			parmName=$2;}
			
		}

		|	VOID ID LBRACK RBRACK
			{if (st_lookup($2, "array", VOID, scope) ==-1) 
			{
				printf("Semantic Error: row = %d\tcol = %d. Can't have array %s of type VOID\n",row, col,$2);						}
			
			else if(st_lookup($2, "array", VOID,scope) ==-2)
				{
				printf("Semantic Error: row = %d\tcol = %d. Array %s was declared with a different RETURN type. Already returns type INT\n", row, col, $2);//this is a little redundant, already taken care of above, but needed to account for all outputs to lookup function
				}
				else if (st_lookup($2, "array", VOID,scope) ==-3)
				{printf("Can't have two names %s of different types.  %s is was declared as an array\n", $2,$2);}	
			

			else {
				printf("Semantic Error: row = %d\tcol = %d. Param Array %s already declared\n",row, col,$2); 
			}
		}		
		;		
		

compoundstmt	: 	LCURLY{scope++;scopeChange = 1;} localdeclarations stmtlist RCURLY {scope--;scopeChange = 1;}
		;

localdeclarations :	localdeclarations vardeclaration
		|	/* empty */
		;	

stmtlist	:	stmtlist stmt
		|	/* empty */
		;

stmt		:	assignstmt
		|	compoundstmt
		|	selectionstmt
		|	iterationstmt
		|	returnstmt
		|	printstmt
		|	scanstmt
		|	callstmt
		|	SEMI
		;

callstmt	: 	call SEMI
		;

/*selectionstmt	:	IF LPAR expression RPAR	stmt
		|	IF LPAR	expression RPAR stmt ELSE stmt
		;*/

selectionstmt	:	IF LPAR{$<strval>$ = genLabel();}{$<strval>$ = genLabel();} expression RPAR {if(relopsFlag ==1){printf("%s\n", $<strval>3);}else{printf("ifeq %s\n", $<strval>3);}relopsFlag = 0;} stmt {printf("goto %s\n",$<strval>4); }ELSE{printf("%s:\n", $<strval>3);} stmt{printf("%s:\n", $<strval>4);}
		;

iterationstmt	:	WHILE {$<strval>$ = genLabel();} {$<strval>$ = genLabel();} LPAR {printf("%s:\n",$<strval>2);} expression {if(relopsFlag ==1){printf("%s\n",$<strval>3);}else{printf("ldc 0\nif_icmple %s\n", $<strval>3);}} RPAR{relopsFlag = 0;} stmt {printf("goto %s\n",$<strval>2); printf("%s:\n", $<strval>3);}
		;

returnstmt	:	RET SEMI
		|	RET expression SEMI
		;

printstmt	:	PRINTF {genBeginPrint();} LPAR FSTRING COMMA expression RPAR SEMI {genEndPrint();} 
		;

scanstmt	: 	SCANF  LPAR DSTRING COMMA AMP ID RPAR SEMI
				{if (st_lookup($6, "variable", INT,scope) ==-1)
	 			{
				printf("Semantic Error:row = %d\tcol = %d.  Scan Variable %s not previously declared\n",row, col, $6);
				} 
else if(st_lookup($6, "variable", INT,scope) ==-2)
				{
				//this probably won't happen but
			printf("Semantic Error: row = %d\tcol = %d. Variable was declared of type VOID. Abort Operation.\n",row, col);
				}
				else if (st_lookup($6, "variable", INT,scope) ==-3)
				//this won't happen either
{printf("Semantic Error: row = %d\tcol = %d. Can't have two names %s of different types.  %s was already declared as an array or function\n", row, col, $6,$6);}
				else{
				/*It worked*/if(scanCalled ==0){printf("new java/util/Scanner\ndup\ngetstatic java/lang/System/in Ljava/io/InputStream;\ninvokenonvirtual java/util/Scanner/<init>(Ljava/io/InputStream;)V\nastore 1\n");}scanNow(1);scanCalled =1;;if(returnScope($6) ==0)
					{printf("putstatic Main/%s I\n", $6);}
					else{
					printf("istore %d\n",jvm_lookup($6, "variable",INT, scope));}
				}				
				}

		;

assignstmt	:	ID {
			if (st_lookup($1, "variable", INT, scope) ==-1) {
				printf("Semantic Error:row = %d\tcol = %d. Exp Variable %s not previously declared\n",row, col, $1);  
				}
				else {/*genLoadVar(scope,jvm_lookup($1, "variable",INT, scope), $1);*/}}
			ASSIGN expression SEMI
			{
			if (st_lookup($1, "variable", INT,scope) ==-1) {
				printf("Semantic Error:row = %d\tcol = %d. Exp Variable %s not previously declared\n",row, col, $1); 
				} 
			else if(st_lookup($1, "variable", INT,scope) ==-2)
			 {printf("Semantic Error: row = %d\tcol = %d. Mismatched return type\n", row, col);}

			else if (st_lookup($1, "variable", INT,scope) ==-3) 
			{printf("Semantic Error: row = %d\tcol = %d. Mismatched type \n", row, col);}
                           else {if(returnScope($1) ==0)
					{printf("putstatic Main/%s I\n", $1);}
					else{
					printf("istore %d\n",jvm_lookup($1, "variable",INT, scope));}}
}
		|	ID {if (st_lookup($1, "array", INT, scope) ==-1) {
	printf("Semantic Error: row = %d\tcol = %d.Exp Array %s not previously declared\n",row, col, $1); }else {genLoadArr(returnScope($1),jvm_lookup($1, "array",INT, returnScope($1)), $1);}}LBRACK expression RBRACK ASSIGN expression SEMI
		{if (st_lookup($1, "array", INT,scope) ==-1) {
	printf("Semantic Error: row = %d\tcol = %d.Exp Array %s not previously declared\n",row, col, $1); }  else if (st_lookup($1, "array", INT,scope) ==-2) {printf("Semantic Error: row = %d\tcol = %d.Mismatched return type\n", row,col);}else if (st_lookup($1, "array", INT,scope) ==-3) {printf("Semantic Error:row = %d\tcol = %d. Mismatched type \n",row, col);}
			else { 
					printf("iastore\n");
					}
}
		;

expression	:	addexpression relop addexpression {$<intval>$ = $<intval>3;  printf("%s", $<strval>2);}
		|	addexpression {$<intval>$ = $<intval>1;}
		;

relop		:       LESSEQ  {$<strval>$ = "if_icmpgt ";relopsFlag = 1;}
		|	LESS    {$<strval>$ = "if_icmpge ";relopsFlag = 1;}
		|	GREAT   {$<strval>$ = "if_icmple ";relopsFlag = 1;}
		|	GREATEQ {$<strval>$ = "if_icmplt ";relopsFlag = 1;}
		|	NOTEQ   {$<strval>$ = "if_icmpeq ";relopsFlag = 1;}
		|	EQUAL   {$<strval>$ = "if_icmpne ";relopsFlag = 1;}
		;

addexpression	:	addexpression addop term{$<intval>$ = $<intval>3;printf("%s\n", $<strval>2);}/*{if($<intval>2 == ADD){$<intval>$ = returnType($2) + $<intval>3; genCodeAdd();} else{$<intval>$ = returnType($2) - $<intval>3; genCodeSub();}}*/
		|	term {$<intval>$ = $<intval>1; }
		;

addop		:	ADD {oppFlag = 1;$<strval>$ = "iadd"; }
		|	SUB {oppFlag = 1;$<strval>$ = "isub"; }
		;

term		: 	term mulop factor {$<intval>$ = $<intval>3;printf("%s\n", $<strval>2);}/*{if($<strval>2 == MULT){$<intval>$ = returnType($2) * $<intval>3; genCodeMul();} else{$<strval>$ = returnType($2) / $<intval>3; genCodeDiv();}}*/
		|	factor {$<intval>$ = $<intval>1; }
		;

mulop		:	MULT {oppFlag = 1;$<strval>$ = "imul"; }
		|	DIV  {oppFlag = 1;$<strval>$ = "idiv"; };
		;

factor		:	LPAR expression	RPAR
		|	call
		|	NUM{genLoadConst($1);if ((callFlag ==1)&&(brackFlag==0) ){  if ((flag == 0)){strcpy(save, print);flag = 1;}
			else{}}}
		|	ID LBRACK {brackFlag = 1;if (st_lookup($1, "array", INT, scope) ==-1) {
	printf("Semantic Error: row = %d\tcol = %d.Factor Array %s not previously declared\n",row, col, $1); 
				}else {print = "[I";genLoadArr(returnScope($1),jvm_lookup($1, "array",INT, returnScope($1)), $1); }}expression RBRACK {brackFlag = 0;printf("iaload\n");}
		
		|	ID
			{  if (nameUsed($1) ==-1) {
			printf("Semantic Factor Error:  row = %d\tcol = %d. %s not previously declared \n",row, col, $1);
			} 
                     
			else{ 
                   	     string = returnKind($1);
			     if(strcmp(string, "variable") ==0)
				{
				print = "I"; 
				if ((mainFlag !=0)||(returnTwice($1)==0)){genLoadVar(returnScope($1), jvm_lookup($1, "variable", INT, returnScope($1)),$1);} 
				else {genLoadVar( scope, jvm_lookup($1, "variable", INT, returnScope($1)),$1);}}
			      else
			      {   
				print = "[I";
				genLoadArr(returnScope($1), jvm_lookup($1, "variable", INT, returnScope($1)),$1);
                              }  
		        if ((flag == 0) && (oppFlag ==0)){strcpy(save, print);flag = 1;}
			else{if(oppFlag ==0){strcat(save, print);}}
	  	}}	
		;

call		: ID {callFlag=1;flag=0;oppFlag = 0;for(refresh = 0; refresh < 80;refresh++)
				{strcpy(save, blank); }
				} LPAR args
		{if (st_lookup($1, "function", type, scope) ==-1) 
	    		{
			printf("Semantic Error: Function %s not previously declared\n",$1); }		
		/*else if(returnType($1) !=type){
			if(returnType($1)==261){compare = "VOID";} else {compare = "INT"; }
			printf("Semantic Error:  Function %s is already declared of type %s ", $1, compare );
	}      */else if(returnKind($1)!="function"){printf("Semantic Error: row = %d\tcol = %d. Function %s not previously declared\n",row, col, $1); }else{printf("invokestatic Main/%s(",$1);
	if(flag ==1){printf("%s", save);}}}  RPAR  

		{scopeChange=1;if(returnType($1)==INT){printf(")I\n");} else{printf(")V\n");}callFlag=0;}
		;


args		:	arglist  {$<strval>$ = $<strval>1; }
		|	/* empty */
		;

arglist		:	arglist COMMA expression   {$<strval>$ = concat(concat($<strval>1, ","),$<strval>1); }
		|	expression { oppFlag = 0;$<strval>$ = $<strval>1; }
		;		

%%
void yyerror (char const *s)  /* Called by yyparse on error */
{
  printf("Error: syntax error at row = %d\tcol = %d. Got: %s\t\n", row, col,yytext);
  printf ("%s\n", s);
}

char * concat( char * str1, char * str2) {

 char *str3;
 str3 = (char *)calloc(strlen(str1) + strlen(str2) + 1,
 sizeof(char));
 strcpy(str3, str1);
 strcat(str3, str2);

 return str3;
}


