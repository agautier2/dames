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
void action_automatique(char tab[][COLONNE_DAMIER], char couleur);
int validation_manger_pion(char tab[][COLONNE_DAMIER], char couleur,int ligne_pion_selectionner,int colonne_pion_selectionner);
int manger_haut_gauche(char tab[][COLONNE_DAMIER] ,char couleur_oposant, int ligne_pion_selectionner, int colonne_pion_selectionner);
int manger_haut_droite(char tab[][COLONNE_DAMIER],char couleur_oposant, int ligne_pion_selectionner, int colonne_pion_selectionner);
int manger_bas_gauche(char tab[][COLONNE_DAMIER],char couleur_oposant, int ligne_pion_selectionner, int colonne_pion_selectionner);
int manger_bas_droite(char tab[][COLONNE_DAMIER],char couleur_oposant, int ligne_pion_selectionner, int colonne_pion_selectionner);
int deplacement_manger(char tab[][COLONNE_DAMIER],char couleur, char couleur_oposant, int ligne_pion_selectionner, int colonne_pion_selectionner);
int changement_dans_damier(char tab[][COLONNE_DAMIER],char tab2[][COLONNE_DAMIER]);
#endif