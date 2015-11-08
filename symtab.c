/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

extern int scope;
extern int mainFlag;
/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
/*
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;
*/
/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
    // LineList lines;
     int memloc ; /* memory location for variable */
     int type;//INT or VOID
     int JVM;     /* This is only for local variables*/
     int scope;  //Nesting level
     char * kind;//variable, function, or array
     int size; //arrays only
     int params;
     int flag;
     int twice; //if has been declared more than once
     struct BucketListRec * next;
   } * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int loc, int JVM , int scope, char *kind, int size, int type, int params)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    //l->lines = (LineList) malloc(sizeof(struct LineListRec));
    //l->lines->lineno = lineno;
    l->memloc = loc;
    l->scope = scope;
    l->kind = kind;
    l-> size = size;
    l->type = type;
    l->params = params;
    l-> JVM = JVM;
    l->twice = 0;
    //l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; }
  else /* found in table, so just add line number */
  { //LineList t = l->lines;
    //while (t->next != NULL) t = t->next;
   // t->next = (LineList) malloc(sizeof(struct LineListRec));
    //t->next->lineno = lineno;
    //t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name,char *kind, int type, int scope )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l == NULL) return -1;//doesnt exist, go ahead
  else if (l->type != type)return -2;//wrong INT/VOIF
  else if (l->kind != kind)return -3;//wrong variable/array/funct
  else if (l->scope ==scope) return -4;//wrong scope
  else return l->memloc;
}

int jvm_lookup(char * name,char *kind, int type, int scope )
{ int h = hash(name);
  BucketList l = hashTable[h];
  while((l!= NULL) && (strcmp(name, l->name)!=0))
	{
	l = l->next;
	}
  if (l == NULL) return -1;//doesnt exist, go ahead
  else if(l->scope != 0) return l->JVM;
  else return 0;
}

void returnParams(char*name)
{ int h = hash(name);
  printf("******\n%s\n******\n",name);//function name
  int scope;
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  scope = (l->scope) +1;printf("******\n%d\n******\n",scope);//scope
  l->next;
  printf("******\n%s\n******\n",name);//function name
  while ((l != NULL) && (l->scope == scope) )
      printf("******\n%d\n******\n",scope);//scope	
      {if (l->kind == "variable")
	   {printf("I");
	    } 
	    else{
		printf("[I");
		}     
      	l->next;
        printf("******\n%s\n******\n",name);//function name
       }
    
}
/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab()
{ int i;
  printf("Symbol Table \n");
  printf("-------------------------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable[i] != NULL)
    { BucketList l = hashTable[i];
      while (l != NULL)
      { 
        printf("kind: %-14s", l->kind);	
	printf("name: %-14s ",l->name);
	printf("scope: %-14d", l->scope);
	printf("type: %-14d", l->type);
	if((strcmp(l->kind,"array") == 0) && (l->size !=0))
	{	
		printf("size: %-14d", l->size);
	}
	if(strcmp(l->kind,"function") ==0)
	{
		printf("params: %-14d", l->params);
	}
	if(l->scope!= 0)
	{
		printf("JVM: %-14d", l->JVM);
	}
      //  printf("JVM #: %-8d  ",l->JVM);
       
	printf("\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */


void printGlobArr(){
	int i;
	printf(".method static <clinit>()V\n");
	printf(".limit stack 1\n");
	printf(".limit locals 0\n");
	
  	for (i=0;i<SIZE;i++)
  	{ if (hashTable[i] != NULL)
    		{ BucketList l = hashTable[i];
      		while (l != NULL)
      		{ 
			if((l->scope== 0) && (strcmp(l->kind,"array") == 0))
			{
				printf("ldc %d\n",l->size);
				printf("newarray int\n");
       				printf("putstatic Main/%s [I\n", l->name);
			}
		l = l->next;
  		}      
  		}
	}
	
} /* print all global arrays */

int returnType(char*name)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l == NULL) return -1;//doesnt exist, go ahead
  else return l->type;
}

int returnScope(char*name)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l == NULL) return -1;//doesnt exist, go ahead
  else return l->scope;
}

int returnTwice(char*name)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l == NULL) return -1;//doesnt exist, go ahead
  else return l->twice;
}

void changeTwice(char*name)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l != NULL) ;//doesnt exist, go ahead
  {l->twice = 1;}
}

char * returnKind(char*name)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l != NULL)//doesnt exist, go ahead
  return l->kind;
}

void st_update( char * name, int params)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l != NULL) ;//name doesnt exist, go ahead
   {l->params = params;}
}

int nameUsed( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    {l = l->next;
    }
  if (l == NULL) return 0;//name doesnt exist, go ahead
  else return 1;
}
