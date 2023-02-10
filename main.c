#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.c"
#include "syn.c"
#include "lex.h"
#include "syntax.h"

int main(int argc, const char * argv[]) {
  int a;
  char c;
  /* ouverture de fichier à tester */
  openfile("C:/Users/PC ASUS/Documents/TRAVAUX C/HPP COMPILER 2.0/test.txt");
  /* analyse lexicale */
  a=analyse_lexicale();
  /* analyse_syntaxique */
  if (a==0)
  analyse_syntaxique();

  return 0;
}
