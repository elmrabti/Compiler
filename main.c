#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.c"
#include "syn.c"
#include "lex.h"
#include "syntax.h"

int main(int argc, const char * argv[]) {
  int a;
  char c[100];
  scanf("%s",c) ;
  /* ouverture de fichier � tester */
  openfile(c);
  /* analyse lexicale */
  a=analyse_lexicale();
  /* analyse_syntaxique */
  if (a==0)
  analyse_syntaxique();

  return 0;
}
