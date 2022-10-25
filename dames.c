#include <stdio.h>
#include "dames.h"


//AFFICHAGE DAMIER + PION
void print_axes_damier(int ligne,int colonne){
    if(ligne == 0 && colonne ==0){
        printf("   ");
        for(int i = 0 ; i < COLONNE_DAMIER;i++){
         printf(" %d ", i);     
        }
    printf("\n");
       
    }
    if( colonne == 0){
        printf(" %d ",ligne);  
    }
       
}

void print_damier(char tab[][COLONNE_DAMIER],char init_pion_damier){

   
        
    for (int ligne = 0; ligne < LIGNE_DAMIER ; ligne++){
        for(int colonne = 0 ; colonne < COLONNE_DAMIER; colonne++){
            print_axes_damier(ligne,colonne);
            if(init_pion_damier=='Y'){
                tab[colonne][ligne]= pion_init(ligne,colonne); 
            }
            else{
                
            }

            if (tab[colonne][ligne]=='B'){
                printf("\033[0;37m["); 
                printf("\033[0;34m%c",tab[colonne][ligne]); 
                printf("\033[0;37m]");    
            }
            else if (tab[colonne][ligne]=='W')
            {
                printf("\033[0;37m["); 
                printf("\033[0;37m%c",tab[colonne][ligne]); 
                printf("\033[0;37m]"); 
            }
            else{
                printf("\033[0;37m[ ]"); 
      
            }
            
            
                                      
        } 
        printf("\n");   
    }
}

char pion_init(int ligne, int colonne){
   
    char pion;
    if( ((ligne%2==0 && colonne%2!=0) || (ligne%2!=0 && colonne%2==0)) && ligne<4){
        pion = 'B';   
    }
    else if (((ligne%2==0 && colonne%2!=0) || (ligne%2!=0 && colonne%2==0)) && ligne>LIGNE_DAMIER-5){
        pion = 'W';
    }
    else{
        pion= ' ';
    }

    return pion;
}





//DEBUT PARTIE
void jouer_dames(char tab[][COLONNE_DAMIER], char couleur){

    char partie= 'S';
    printf("Les BLANC commencent \n");
    while(partie != 'T')
    {
    Choix_du_Pion(tab,couleur);
    if (couleur == 'B'){
        couleur = 'W';
    }
    else{
        couleur = 'B';  
    }
    
    printf("pion %c, à vous de jouer !\n",couleur);

    }

}

void action_automatique(char tab[][COLONNE_DAMIER], char couleur){

    
    int validation;
    if (couleur == 'W'){

        for (int ligne = 0; ligne < LIGNE_DAMIER ; ligne++){
            for(int colonne = 0 ; colonne < COLONNE_DAMIER; colonne++){
            
                if (tab[colonne][ligne]== couleur){
                    validation = Validation_pion_selectionner(tab, couleur,ligne,colonne);
                    if (validation == 1){
                        
                    }
                    

                }
            }
        }

    }


    if (couleur == 'B'){

         for (int ligne = 0; ligne < LIGNE_DAMIER ; ligne++){
            for(int colonne = 0 ; colonne < COLONNE_DAMIER; colonne++){

            }
        }
        
    }

}





//CHOIX DU PION
void Choix_du_Pion(char tab[][COLONNE_DAMIER],char couleur){

    int colonne_pion_selectionner; 
    int ligne_pion_selectionner;
    int validation_pion;
    do{
        printf("entrez coordonnée du pion %c \n",couleur);
        printf("coordonnée en X :");
        scanf("%d",&colonne_pion_selectionner);
        printf("coordonnée en Y :");
        scanf("%d",&ligne_pion_selectionner);


        validation_pion =Validation_pion_selectionner(tab, couleur,ligne_pion_selectionner,colonne_pion_selectionner);
        if (validation_pion==1){    
                 
            Deplacement_du_Pion(tab,couleur,ligne_pion_selectionner,colonne_pion_selectionner);
        }
        else if (validation_pion==2){
            printf("aucun deplacement possible pour ce pion %c \nVeuillez ré",couleur); 
        }
        else if(validation_pion==3){
            printf("aucun pion %c au coordonnées indiquer \nVeuillez ré",couleur);   
        }
        else if (validation_pion==4){
           printf("Coordonnées hors damier\n");   
        }
    }while (validation_pion != 1);
    
    
    
}

int validation_donnees_utilisateur(int ligne_choix, int colonne_choix){

     if ((ligne_choix >=0 && colonne_choix >= 0)&&(ligne_choix<=9 && colonne_choix<=9)){
        return 1;
     }
     else{
        return 0;
     }
  
}

int Validation_pion_selectionner(char tab[][COLONNE_DAMIER], char couleur,int ligne_pion_selectionner,int colonne_pion_selectionner){

    int validation;
    validation = validation_donnees_utilisateur(ligne_pion_selectionner,colonne_pion_selectionner);
    if(validation){

        if (tab[colonne_pion_selectionner][ligne_pion_selectionner] == couleur) {
            if(couleur =='B'){

                if (((ligne_pion_selectionner < 9 && colonne_pion_selectionner<9) && colonne_pion_selectionner<9 && ligne_pion_selectionner<9 && tab[colonne_pion_selectionner+1][ligne_pion_selectionner+1]!=couleur) ||
                ((ligne_pion_selectionner < 9 && colonne_pion_selectionner > 0) && colonne_pion_selectionner > 0 && ligne_pion_selectionner<9 && tab[colonne_pion_selectionner-1][ligne_pion_selectionner+1]!=couleur )) {
                    return 1;
                }
                else{
                    return 2;
                }

            }
            else if(couleur =='W'){

                if (((ligne_pion_selectionner > 0 && colonne_pion_selectionner > 0) && colonne_pion_selectionner > 0 && ligne_pion_selectionner>0 && tab[colonne_pion_selectionner-1][ligne_pion_selectionner-1]!=couleur ) ||
                ((ligne_pion_selectionner > 0 && colonne_pion_selectionner < 9) && colonne_pion_selectionner <9 && ligne_pion_selectionner>0 &&tab[colonne_pion_selectionner+1][ligne_pion_selectionner-1]!=couleur )){
                    return 1;
                }
                else{
                    return 2;
                }

            } 
                
        }
        else{
            return 3;   
        }
                  
    } 
    else{
        return 4;
    }  

    return 0;
}





// DEPLACEMENT DU PION
void Deplacement_du_Pion(char tab[][COLONNE_DAMIER],char couleur, int ligne_pion_selectionner, int colonne_pion_selectionner){

    int colonne_pion_deplacement; 
    int ligne_pion_deplacement;
    int validation_deplacement;

    do{
        printf("entrez coordonnée du pion %c ou vous voulez le déplacer\n",couleur);
        printf("Nouvelle coordonnée en X :");
        scanf("%d",&colonne_pion_deplacement);
        printf("Nouvelle coordonnée en Y :");
        scanf("%d",&ligne_pion_deplacement);

        validation_deplacement = Validation_pion_deplacement(tab,couleur,ligne_pion_deplacement,colonne_pion_deplacement,ligne_pion_selectionner,colonne_pion_selectionner);
        if (validation_deplacement==1){         
           printf("piont deplacer en %d %d \n",ligne_pion_deplacement,colonne_pion_deplacement);
           Affichage_deplacement(tab, couleur,ligne_pion_deplacement, colonne_pion_deplacement,  ligne_pion_selectionner, colonne_pion_selectionner);
           
        }
      
        else if (validation_deplacement==2){
            printf("Vous ne pouvez pas deplacer ce pion %c ici \nVeuillez ré",couleur);
            
        }
        else if (validation_deplacement==3){
            printf("Coordonnées déplacement hors damier \n"); 
         
        }

        else if (validation_deplacement==4){
            printf("Tu ne peux pas écraser des pions !\n"); 
         
        }
            
    }while (validation_deplacement != 1);

}

int Validation_pion_deplacement(char tab[][COLONNE_DAMIER], char couleur,int ligne_pion_deplacement,int colonne_pion_deplacement, int ligne_pion_selectionner, int colonne_pion_selectionner){
    
    int validation;
    validation = validation_donnees_utilisateur(ligne_pion_deplacement,colonne_pion_deplacement);
    
    if(validation){
        if(tab[colonne_pion_deplacement][ligne_pion_deplacement] != ' ' ){
            return 4; // deplacement sur un autre pion   
        }
        
        if(couleur == 'B'){
            if (tab[colonne_pion_deplacement][ligne_pion_deplacement] == ' ' && 
            ((colonne_pion_deplacement == colonne_pion_selectionner +1  && ligne_pion_deplacement == ligne_pion_selectionner +1) ||
            (colonne_pion_deplacement == colonne_pion_selectionner -1  && ligne_pion_deplacement == ligne_pion_selectionner +1))) {
                return 1; // deplacement possible
            }

            else{
                return 2; // deplacement trop loin
            }  
        }
        else if (couleur =='W')
        {
            if (tab[colonne_pion_deplacement][ligne_pion_deplacement] == ' ' && 
            ((colonne_pion_deplacement == colonne_pion_selectionner -1  && ligne_pion_deplacement == ligne_pion_selectionner -1) ||
            (colonne_pion_deplacement == colonne_pion_selectionner +1  && ligne_pion_deplacement == ligne_pion_selectionner -1))) {
                return 1; // deplacement possible
            }

            else{
                return 2; // deplacement trop loin
            }  
        }
        
            
    }
    else{
        return 3; // deplacement hors damier
    }
return 0;
}

void Affichage_deplacement(char tab[][COLONNE_DAMIER], char couleur,int ligne_pion_deplacement,int colonne_pion_deplacement, int ligne_pion_selectionner, int colonne_pion_selectionner)
{
    char init = 'N';
    tab[colonne_pion_selectionner][ligne_pion_selectionner]=' ';
    tab[colonne_pion_deplacement][ligne_pion_deplacement]= couleur ;
    
    print_damier(tab,init);
    
}





