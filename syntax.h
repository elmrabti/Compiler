#ifndef SYNTAX_H_INCLUDED
#define SYNTAX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
  STARTPROGRAM_ERR, ID_ERR, PATIENT_ERR,START_ERR, END_ERR, IF_ERR,
  THEN_ERR, WHILE_ERR,FUNCTION_ERR, PUT_ERR, PRINT_ERR, PV_ERR,
  PLUS_ERR,MOINS_ERR, MULT_ERR, DIV_ERR, VIR_ERR, AFF_ERR,
  INF_ERR,INFEG_ERR, SUP_ERR, SUPEG_ERR, DIFF_ERR, PO_ERR,
  PF_ERR,ENDPROGRAM_ERR, NUM_ERR, EG_ERR, EOF_ERR,SWITCH_ERR,
  CASE_ERR, BREAK_ERR,DEFAULT_ERR, FOR_ERR, MAIN_ERR, RETURN_ERR,
  ELSE_ERR, ELSIF_ERR, AND_ERR, TYPE_ERR, PP_ERR, CHAINE_ERR, COND_ERR, OPPER_ERR
}ERREURS;
int analyse_syntaxique();
void Sym_Suiv();
void Test_Symbole(CODES_LEX token,ERREURS erreur);
void PROGRAM();
void START();
void CHOICE();
void PATIENTS();
void INSTS();
void INST();
void AFFEC();
void EXPR();
void TERM();
void FACT();
void SI();
void COND();
void TANTQUE();
void LIRE();
void ECRIRE();
void FUNCTION();
void FOR();
void SWITCH();
int i;
int syntax;
int ligne;


#endif // SYNTAX_H_INCLUDED
