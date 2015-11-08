#include <stdio.h>
#include "symtab.h"

extern int yyparse();

main() {

  if (yyparse() == 0) {
    /* generated code written to stdout */
  } else {
    printf("Compilation error.");
  }

}
