/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#ifndef _SYMTAB_H_
#define _SYMTAB_H_

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int loc, int JVM, int scope, char* kind, int size, int type, int params);

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name, char *kind, int type, int scope );
int jvm_lookup ( char * name, char *kind, int type, int scope );
/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab();

void printGlobArr();

int returnType(char * name);

int returnScope(char *name);

char * returnKind(char *name);

void returnParams(char *name);

void st_update( char * name, int params);

int nameUsed( char * name );

int returnTwice(char*name);

void changeTwice(char*name);
#endif
