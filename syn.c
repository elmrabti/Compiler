  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "lex.h"
  #include "syntax.h"

/* passage d'un symbole � l'autre */
  void Sym_Suiv(){
      temp = temp->next;
  }
/* conversion d'enum en chaine de caractere pour affichage */
  void Erreur(ERREURS COD_ERR,int i){
    syntax+=1;
    switch(COD_ERR){
  case 0: printf("%d-ligne %d ERREUR-->STARTP_ERREUR\n",i,ligne);break;
  case 1: printf("%d-ligne %d ERREUR-->ID_ERREUR\n",i,ligne);break;
  case 2: printf("%d-ligne %d ERREUR-->PATIENT_ERREUR\n",i,ligne);break;
  case 3: printf("%d-ligne %d ERREUR-->START_ERREUR\n",i,ligne);break;
  case 4: printf("%d-ligne %d ERREUR-->END_ERREUR\n",i,ligne);break;
  case 5: printf("%d-ligne %d ERREUR-->IF_ERREUR\n",i,ligne);break;
  case 6: printf("%d-ligne %d ERREUR-->THEN_ERREUR\n",i,ligne);break;
  case 7: printf("%d-ligne %d ERREUR-->WHILE_ERREUR\n",i,ligne);break;
  case 8: printf("%d-ligne %d ERREUR-->FUNCTION_ERREUR\n",i,ligne);break;
  case 9: printf("%d-ligne %d ERREUR-->PUT_ERREUR\n",i,ligne);break;
  case 10: printf("%d-ligne %d ERREUR-->PRINT_ERREUR\n",i,ligne);break;
  case 11: printf("%d-ligne %d ERREUR-->PV_ERREUR\n",i,ligne);break;
  case 12: printf("%d-ligne %d ERREUR-->PLUS_ERREUR\n",i,ligne);break;
  case 13: printf("%d-ligne %d ERREUR-->MOINS_ERREUR\n",i,ligne);break;
  case 14: printf("%d-ligne %d ERREUR-->MULT_ERREUR\n",i,ligne);break;
  case 15: printf("%d-ligne %d ERREUR-->DIV_ERREUR\n",i,ligne);break;
  case 16: printf("%d-ligne %d ERREUR-->VIR_ERREUR\n",i,ligne);break;
  case 17: printf("%d-ligne %d ERREUR-->AFF_ERREUR\n",i,ligne);break;
  case 18: printf("%d-ligne %d ERREUR-->INF_ERREUR\n",i,ligne);break;
  case 19: printf("%d-ligne %d ERREUR-->INFEG_ERREUR\n",i,ligne);break;
  case 20: printf("%d-ligne %d ERREUR-->SUP_ERREUR\n",i,ligne);break;
  case 21: printf("%d-ligne %d ERREUR-->SUPEG_ERREUR\n",i,ligne);break;
  case 22: printf("%d-ligne %d ERREUR-->DIFF_ERREUR\n",i,ligne);break;
  case 23: printf("%d-ligne %d ERREUR-->PO_ERREUR\n",i,ligne);break;
  case 24: printf("%d-ligne %d ERREUR-->PF_ERREUR\n",i,ligne);break;
  case 25: printf("%d-ligne %d ERREUR-->ENDPROG_ERREUR\n",i,ligne);break;
  case 26: printf("%d-ligne %d ERREUR-->NUM_ERREUR\n",i,ligne);break;
  case 27: printf("%d-ligne %d ERREUR-->EG_ERREUR\n",i,ligne);break;
  case 28: printf("%d-ligne %d ERREUR-->EOF_ERREUR\n",i,ligne);break;
  case 29: printf("%d-ligne %d ERREUR-->SWITCH_ERREUR\n",i,ligne);break;
  case 30: printf("%d-ligne %d ERREUR-->CASE_ERREUR\n",i,ligne);break;
  case 31: printf("%d-ligne %d ERREUR-->BREAK_ERREUR\n",i,ligne);break;
  case 32: printf("%d-ligne %d ERREUR-->DEFFAULT_ERREUR\n",i,ligne);break;
  case 33: printf("%d-ligne %d ERREUR-->FOR_ERREUR\n",i,ligne);break;
  case 34: printf("%d-ligne %d ERREUR-->MAIN_ERREUR\n",i,ligne);break;
  case 35: printf("%d-ligne %d ERREUR-->RETURN_ERREUR\n",i,ligne);break;
  case 36: printf("%d-ligne %d ERREUR-->ELSE_ERREUR\n",i,ligne);break;
  case 37: printf("%d-ligne %d ERREUR-->ELSIF_ERREUR\n",i,ligne);break;
  case 38: printf("%d-ligne %d ERREUR-->AND_ERREUR\n",i,ligne);break;
  case 39: printf("%d-ligne %d ERREUR-->TYPE_ERREUR\n",i,ligne);break;
  case 40: printf("%d-ligne %d ERREUR-->DOUBLEPOINT_ERREUR\n",i,ligne);break;
  case 41: printf("%d-ligne %d ERREUR-->CHAINE_ERREUR\n",i,ligne);break;
  case 42: printf("%d-ligne %d ERREUR-->CONDITION_ERREUR\n",i,ligne);break;
  case 43 : printf("%d-ligne %d ERREUR-->OPERATION_ERREUR\n",i,ligne);break;

  }
  }
/* test de symobole passer ne param�tre avec les elts de la liste chain�e*/
  void Test_Symbole (CODES_LEX cl, ERREURS COD_ERR){

      if (temp->cls == cl)
        {
          //printf("%d- %s ok \n",i,conversion(temp->cls));
          Sym_Suiv();
        }
   else{
       Erreur(COD_ERR,i);
        }
  i=i+1;
  }
/* analyse de la liste des tokens */
  void PROGRAM(){
      Test_Symbole(STARTPROGRAM_TOKEN, STARTPROGRAM_ERR);
      while(temp->cls==SAUT_TOKEN){
        ligne+=1;
      Sym_Suiv();}
      PATIENTS();
      START();
      Test_Symbole(ENDPROGRAM_TOKEN, ENDPROGRAM_ERR);
  }
/* verification du PATIENT_TOKEN */
  void PATIENTS() {

    switch (temp->cls) {
      case PATIENT_TOKEN : Test_Symbole(PATIENT_TOKEN,PATIENT_ERR);
                       Test_Symbole(PO_TOKEN,PO_ERR);
                       while(temp->cls==SAUT_TOKEN)
                       {ligne+=1;
                       Sym_Suiv();}
                       if(temp->cls == PF_TOKEN)
                       Test_Symbole(PF_TOKEN,PF_ERR);
                       else if(temp->cls == TYPE_TOKEN){
                         while(temp->cls == TYPE_TOKEN){
                                Test_Symbole(TYPE_TOKEN,TYPE_ERR);
                                Test_Symbole(ID_TOKEN,ID_ERR);
                                if(temp->cls ==AFF_TOKEN){
                                          Sym_Suiv();
                                          Test_Symbole(NUM_TOKEN,NUM_ERR);
                                          while (temp->cls== VIR_TOKEN) {
                                                          Sym_Suiv();
                                                          while(temp->cls==SAUT_TOKEN)
                                                          {ligne+=1;
                                                          Sym_Suiv();}
                                                          Test_Symbole(ID_TOKEN,ID_ERR);
                                                          if(temp->cls ==AFF_TOKEN){
                                                              Test_Symbole(AFF_TOKEN,AFF_ERR);
                                                              Test_Symbole(NUM_TOKEN,NUM_ERR);

                                                            }
                                                        }
                                                    }
                                  else {
                                    while (temp->cls== VIR_TOKEN) {
                                                          Sym_Suiv();
                                                          while(temp->cls==SAUT_TOKEN)
                                                          {ligne+=1;
                                                          Sym_Suiv();}
                                                          Test_Symbole(ID_TOKEN,ID_ERR);
                                                          if(temp->cls ==AFF_TOKEN){
                                                            Test_Symbole(AFF_TOKEN,AFF_ERR);
                                                            Test_Symbole(NUM_TOKEN,NUM_ERR);
                                                          }
                                                        }
                                                      }
                           Test_Symbole(PV_TOKEN,PV_ERR);
                           while(temp->cls==SAUT_TOKEN)
                           {ligne+=1;
                           Sym_Suiv();}
                         }
                           Test_Symbole(PF_TOKEN,PF_ERR);
                       }
                       Test_Symbole(PV_TOKEN,PV_ERR);break;
                       while(temp->cls==SAUT_TOKEN)
                       {ligne+=1;
                       Sym_Suiv();}
      case START_TOKEN : break;
      default          : Erreur(START_ERR,i);break;
    }
    while(temp->cls==SAUT_TOKEN)
    {ligne+=1;
    Sym_Suiv();}
  }
/* analyse du corps du programme */
  void START(){
    while (temp->cls==START_TOKEN){
     switch (temp->cls) {
       case START_TOKEN: Test_Symbole(START_TOKEN,START_ERR);
                         Test_Symbole(TYPE_TOKEN,TYPE_ERR);
                         switch(temp->cls){
                           case FUNCTION_TOKEN : Test_Symbole(FUNCTION_TOKEN,FUNCTION_ERR);
                                                 Test_Symbole(ID_TOKEN,ID_ERR);
                                                 Test_Symbole(PO_TOKEN,PO_ERR);
                                                 if(temp->cls==TYPE_TOKEN){
                                                            Test_Symbole(TYPE_TOKEN,TYPE_ERR);
                                                            Test_Symbole(ID_TOKEN,ID_ERR);
                                                            while(temp->cls==VIR_TOKEN){
                                                                    Sym_Suiv();
                                                                    Test_Symbole(TYPE_TOKEN,TYPE_ERR);
                                                                    Test_Symbole(ID_TOKEN,ID_ERR);
                                                                  }
                                                            }
                                                 Test_Symbole(PF_TOKEN,PF_ERR);
                                                 while(temp->cls==SAUT_TOKEN)
                                                 {ligne+=1;
                                                 Sym_Suiv();}
                                                 INSTS();
                                                 Test_Symbole(END_TOKEN,END_ERR);
                                                 Test_Symbole(FUNCTION_TOKEN,FUNCTION_ERR);
                                                 Test_Symbole(ID_TOKEN,ID_ERR);break;
                           case MAIN_TOKEN     : Test_Symbole(MAIN_TOKEN,MAIN_ERR);
                                                 Test_Symbole(PO_TOKEN,PO_ERR);
                                                 Test_Symbole(PF_TOKEN,PF_ERR);
                                                 while(temp->cls==SAUT_TOKEN)
                                                 {ligne+=1;
                                                 Sym_Suiv();}
                                                 INSTS();
                                                 Test_Symbole(END_TOKEN,END_ERR);
                                                 Test_Symbole(MAIN_TOKEN,MAIN_ERR);break;
                           default             : Erreur(FUNCTION_ERR,i);break;
                         }break;
       default : Erreur(START_ERR,i);break;
     }
     while(temp->cls==SAUT_TOKEN)
     {ligne+=1;
     Sym_Suiv();}
  }
}
/* verification des instructions */
  void INSTS() {
    INST();
    while (temp->cls!=END_TOKEN)
    INST();
}
/* verification des BEGIN, WHILE, WRITE, READ .....*/
  void INST() {
    while(temp->cls==SAUT_TOKEN)
    {ligne+=1;
    Sym_Suiv();}
    switch (temp->cls) {
      case FUNCTION_TOKEN:Test_Symbole(FUNCTION_TOKEN,FUNCTION_ERR);FUNCTION();Test_Symbole(PV_TOKEN,PV_ERR);
                            while(temp->cls==SAUT_TOKEN)
                              {ligne+=1;
                              Sym_Suiv();}break;
      case SWITCH_TOKEN : SWITCH();break;
      case FOR_TOKEN    : FOR(); break;
      case ID_TOKEN     : Test_Symbole(ID_TOKEN,ID_ERR);
                          if (temp->cls==PV_TOKEN) Test_Symbole(PV_TOKEN,PV_ERR);
                          else  AFFEC();
                          while(temp->cls==SAUT_TOKEN)
                            {ligne+=1;
                            Sym_Suiv();}break;
      case IF_TOKEN    : SI(); break;
      case WHILE_TOKEN : TANTQUE();break;
      case PRINT_TOKEN : ECRIRE();Test_Symbole(PV_TOKEN,PV_ERR);
                         while(temp->cls==SAUT_TOKEN)
                              {ligne+=1;
                              Sym_Suiv();}break;
      case PUT_TOKEN   : LIRE();Test_Symbole(PV_TOKEN,PV_ERR); break;
      case RETURN_TOKEN: Test_Symbole(RETURN_TOKEN,RETURN_ERR);
                         EXPR();
                         Test_Symbole(PV_TOKEN,PV_ERR);
                         while(temp->cls==SAUT_TOKEN)
                           {ligne+=1;
                           Sym_Suiv();}break;
      case END_TOKEN   : Test_Symbole(END_TOKEN,END_ERR);break;
      default          : Sym_Suiv();break;
  }
  }
/* verification des AFFEC_TOKEN (affectation) */
  void AFFEC() {
    Test_Symbole(AFF_TOKEN,AFF_ERR);
    EXPR();
    Test_Symbole(PV_TOKEN,PV_ERR);
  }
/* verification des expresions + ou - */
  void EXPR() {
    TERM();
    while(temp->cls== PLUS_TOKEN || temp->cls== MOINS_TOKEN) {
      Sym_Suiv();
      TERM();
    }
  }
/* verification des termes */
  void TERM() {

    FACT();
      /* verification des expresions multiplication ou division */
    while(temp->cls== MULT_TOKEN || temp->cls == DIV_TOKEN) {
      Sym_Suiv();
      FACT();
    }
  }
/* verification des facteurs */
  void FACT() {

      switch(temp->cls) {
      case ID_TOKEN : Test_Symbole(ID_TOKEN,ID_ERR);
                      if(temp->cls==PO_TOKEN)
                      FUNCTION(); break ;
      case PO_TOKEN : Sym_Suiv();EXPR(); Test_Symbole(PF_TOKEN,PF_ERR); break ;
      case NUM_TOKEN : Test_Symbole(NUM_TOKEN,NUM_ERR);break;
      default      : Erreur(OPPER_ERR,i); break ;
    }
  }
/* verification fonction */
  void FUNCTION() {
    Test_Symbole(PO_TOKEN,PO_ERR);
    if (temp->cls!=PF_TOKEN)
     EXPR();
    while(temp->cls==VIR_TOKEN){
                                Sym_Suiv();
                                EXPR();
                              }
    Test_Symbole(PF_TOKEN,PF_ERR);
  }
/* verification FOR */
void FOR(){
  Test_Symbole(FOR_TOKEN,FOR_ERR);
  Test_Symbole(PO_TOKEN,PO_ERR);
  Test_Symbole(ID_TOKEN,ID_ERR);
  Test_Symbole(AFF_TOKEN,AFF_ERR);
  FACT();
  Test_Symbole(PV_TOKEN,PV_ERR);
  COND();
  Test_Symbole(PV_TOKEN,PV_ERR);
  Test_Symbole(ID_TOKEN,ID_ERR);
  Test_Symbole(AFF_TOKEN,AFF_ERR);
  EXPR();
  Test_Symbole(PF_TOKEN,PF_ERR);
  INSTS();
  Test_Symbole(END_TOKEN,END_ERR);
  Test_Symbole(FOR_TOKEN,FOR_ERR);
}
/* verification SWITCH */
void SWITCH(){
  Test_Symbole(SWITCH_TOKEN,SWITCH_ERR);
  Test_Symbole(PO_TOKEN,PO_ERR);
  Test_Symbole(ID_TOKEN,ID_ERR);
  Test_Symbole(PF_TOKEN,PF_ERR);
  while(temp->cls==SAUT_TOKEN)
       {ligne+=1;
       Sym_Suiv();}
  if (temp->cls!=CASE_TOKEN)
    Erreur(CASE_ERR,i);
  while (temp->cls==CASE_TOKEN) {
                                  Test_Symbole(CASE_TOKEN,CASE_ERR);
                                  FACT();
                                  Test_Symbole(PP_TOKEN,PP_ERR);
                                  while(temp->cls!=BREAK_TOKEN)
                                    INST();
                                  Test_Symbole(BREAK_TOKEN,BREAK_ERR);
                                  Test_Symbole(PV_TOKEN,PV_ERR);
                                  while(temp->cls==SAUT_TOKEN){
                                    ligne+=1;
                                    Sym_Suiv();}
                                }
  if(temp->cls==DEFAULT_TOKEN){
                                  Test_Symbole(DEFAULT_TOKEN,DEFAULT_ERR);
                                  Test_Symbole(PP_TOKEN,PP_ERR);
                                  while(temp->cls!=BREAK_TOKEN)
                                  INST();
                                  Test_Symbole(BREAK_TOKEN,BREAK_ERR);
                                  Test_Symbole(PV_TOKEN,PV_ERR);
                                  while(temp->cls==SAUT_TOKEN)
                                       {ligne+=1;
                                       Sym_Suiv();}
                                }
  Test_Symbole(END_TOKEN,END_ERR);
  Test_Symbole(SWITCH_TOKEN,SWITCH_ERR);
}
/* verification de IF_TOKEN */
  void SI() {

    Test_Symbole(IF_TOKEN,IF_ERR);
    COND();
    while(temp->cls==SAUT_TOKEN)
    {ligne+=1;
    Sym_Suiv();}
    Test_Symbole(THEN_TOKEN,THEN_ERR);
    INST();
    CHOICE();
    Test_Symbole(END_TOKEN,END_ERR);
    Test_Symbole(IF_TOKEN,IF_ERR);
  }
  void CHOICE(){
    switch (temp->cls) {
                    case ELSIF_TOKEN: Test_Symbole(ELSIF_TOKEN,ELSIF_ERR);
                                      COND();
                                      while(temp->cls==SAUT_TOKEN)
                                        {ligne+=1;
                                        Sym_Suiv();}
                                      Test_Symbole(THEN_TOKEN,THEN_ERR);
                                      INST();break;
                    case ELSE_TOKEN: Test_Symbole(ELSE_TOKEN,ELSE_ERR);
                                     while(temp->cls==SAUT_TOKEN)
                                      {ligne+=1;
                                      Sym_Suiv();}
                                     Test_Symbole(THEN_TOKEN,THEN_ERR);
                                     INST();break;
                    default : break;
                  }

  }
/* verification de la condition apres IF */
  void COND() {

    EXPR();
    switch(temp->cls) {
      case EG_TOKEN:Sym_Suiv();EXPR();break;
      case DIFF_TOKEN:Sym_Suiv();EXPR();break;
      case INF_TOKEN:Sym_Suiv();EXPR();break;
      case SUP_TOKEN:Sym_Suiv();EXPR();break;
      case INFEG_TOKEN:Sym_Suiv();EXPR();break;
      case SUPEG_TOKEN:Sym_Suiv();EXPR();break;
      default: Erreur(COND_ERR,i);break;
    }
  }
/* verification de ce qui est apr�s le  WHILE */
  void TANTQUE() {
    Test_Symbole(WHILE_TOKEN,WHILE_ERR);
    COND();
    while(temp->cls==SAUT_TOKEN)
         {ligne+=1;
         Sym_Suiv();}
    Test_Symbole(THEN_TOKEN,THEN_ERR);
    INST();
    Test_Symbole(WHILE_TOKEN,WHILE_ERR);

}
/* verification de ce qui est apr�s le  show_results */
  void ECRIRE(){
      Test_Symbole(PRINT_TOKEN,PRINT_ERR);
      Test_Symbole(PO_TOKEN,PO_ERR);
      while(temp->cls!=PF_TOKEN)
        { switch (temp->cls) {
              case CHAINE_TOKEN: Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);break;
              case ID_TOKEN: EXPR();break;
              case NUM_TOKEN: EXPR();break;
              case VIR_TOKEN: Test_Symbole(VIR_TOKEN,VIR_ERR);break;
              default:break;
            }
        }
      Test_Symbole(PF_TOKEN,PF_ERR);
    }
/* verification de ce qui est apr�s le  enter_params*/
  void LIRE() {

    Test_Symbole(PUT_TOKEN,PUT_ERR);
    Test_Symbole(PO_TOKEN,PO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    while(temp->cls== VIR_TOKEN) {
      Sym_Suiv();
      Test_Symbole(ID_TOKEN,ID_ERR);
    }
    Test_Symbole(PF_TOKEN,PF_ERR);
  }
/* fonction principale d'analayse syntaxique */
  int analyse_syntaxique(){
    /* initialisation*/
    i=0;syntax=0;ligne=1;
    /* initialisation du pointeur temp sur la tete de la liste */
    temp=head;
     printf("***************************TEST DES TOKENS****************************\n");
     printf("   ================================================================\n");
    /* analyse du programme propos� */
    PROGRAM();
    /* affichage du resultat d'analyse */
     printf("     ==========================================================\n");
     printf("         ===============FIN ANALYSE SYNTAXIQUE===========\n");

   if (syntax==0)
    {printf("                ********   SYNTAXE CORRECTE   ******\n");
     printf("                ====================================\n");
      return 0;}
   else{
     printf("      ********  !!!!SYNTAXE INCORRECTE!! %d ERREUR(S)  ******\n",syntax);

     printf("               =====================================\n");
     printf("       !!!!!!!!!!!!!!!!!VERIFIER VOTRE SYNTAXE!!!!!!!!!!!!!!!!!\n");
      return 1;}

  }
