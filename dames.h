#ifndef DAMES_HEADER
#define DAMES_HEADER
#define COLONNE_DAMIER 10
#define LIGNE_DAMIER 10

void print_axes_damier(int ligne,int colonne);
void print_damier(char tab[][COLONNE_DAMIER],char init_pion_damier);
char pion_init(int ligne, int colonne);

void jouer_dames(char tab[][COLONNE_DAMIER], char couleur);
void Choix_du_Pion(char tab[][COLONNE_DAMIER],char couleur);
int validation_donnees_utilisateur(int ligne_choix, int colonne_choix);
int Validation_pion_selectionner(char tab[][COLONNE_DAMIER], char couleur,int ligne_pion_selectionner,int colonne_pion_selectionner);
void Deplacement_du_Pion(char tab[][COLONNE_DAMIER],char couleur,int colonne_pion_selectionner, int ligne_pion_selectionner);
int Validation_pion_deplacement(char tab[][COLONNE_DAMIER], char couleur,int ligne_pion_deplacement,int colonne_pion_deplacement, int ligne_pion_selectionner, int colonne_pion_selectionner);
void Affichage_deplacement(char tab[][COLONNE_DAMIER], char couleur,int ligne_pion_deplacement,int colonne_pion_deplacement, int ligne_pion_selectionner, int colonne_pion_selectionner);

#endif