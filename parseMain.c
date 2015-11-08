#include "symtab.h"

extern int yyparse();

void main () {
  
  int result = yyparse();
  printSymTab();

} 
