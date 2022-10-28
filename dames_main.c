#include <stdio.h>
#include "dames.h"


int main(){

    char tableau[COLONNE_DAMIER][LIGNE_DAMIER];
    char couleur='W';
    char partie='N';
    char init_pion_damier ='Y';
    print_damier(tableau,init_pion_damier);
    
    printf("Voulez vous commencer une nouvelle partie ? (Y/N) : ");
    scanf("%c", &partie);
    if(partie == 'Y' || partie =='y'){

        jouer_dames(tableau,couleur);   
    }   
    
   


}