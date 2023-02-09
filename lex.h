#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  enum{
    STARTPROGRAM_TOKEN, ID_TOKEN, PATIENT_TOKEN,START_TOKEN, END_TOKEN, IF_TOKEN,
    THEN_TOKEN, WHILE_TOKEN,FUNCTION_TOKEN, PUT_TOKEN, PRINT_TOKEN, PV_TOKEN,
    PLUS_TOKEN,MOINS_TOKEN, MULT_TOKEN, DIV_TOKEN, VIR_TOKEN, AFF_TOKEN,
    INF_TOKEN,INFEG_TOKEN, SUP_TOKEN, SUPEG_TOKEN, DIFF_TOKEN, PO_TOKEN,
    PF_TOKEN,ENDPROGRAM_TOKEN, NUM_TOKEN, ERREUR_TOKEN, EG_TOKEN, EOF_TOKEN,
    COMMENT_TOKEN,SPCE_TOKEN,SAUT_TOKEN, SWITCH_TOKEN, CASE_TOKEN, BREAK_TOKEN,
    DEFAULT_TOKEN, FOR_TOKEN, MAIN_TOKEN, RETURN_TOKEN,TYPE_TOKEN, ELSE_TOKEN,
    ELSIF_TOKEN, AND_TOKEN, PP_TOKEN, CHAINE_TOKEN
} CODES_LEX;
typedef struct class
{
   CODES_LEX cls;
   char* nom;
   int val;
   struct class * next;
}class;

class* head;
class* temp;
char mot[500];
char Car_Cour;
FILE* fichier;
int analyse_lexicale();
char Lire_Car();
CODES_LEX lire_mot();
CODES_LEX lire_nombre();
CODES_LEX lire_Symbole();
CODES_LEX analyse();
void openfile(char * filename);
void resultfile(char * filename,char * chaine);
void ajouter();
void afficherListe();
char * conversion(CODES_LEX cls);



#endif // LEX_H_INCLUDED
