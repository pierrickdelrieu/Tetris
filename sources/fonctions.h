//
//  fonctions.h
//  Teris
//
//  Created by Pierrick Delrieu on 23/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#ifndef fonctions_h
#define fonctions_h


//On établie que la taille de l'écran fait 100 cara x 70 cara

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <term.h>


//Code ascii
#define POINT 46
#define A 65 //le code ascii des lettres en majuscules est dans l'ordre A+i
#define a 97 //le code ascii des lettres en minuscules est dans l'ordre a+i
#define CHIFFRE 49 //1
#define ESPACE 32
#define COTE_LATERAL 124 // |
#define COTE_TRANSVERSAL 61 // =



//..................GENERAL................... (fonctions usuels)
#define NOMBRE_ESSAI_SAISIE 3 //nombre d'essai de saisie des coordonnées avant que la boucle de jeu quitte
typedef struct
{
    int x;
    int y;
} Coord;
typedef struct
{
    int** tableau;
    int hauteur;
    int largeur;
} Tableau2D;
void creation_tableau_2D(int*** tableau, int ligne, int colonne); //allocation dynamique
void desalocation_tableau2D(int** tableau, int ligne); //dealocation dynamique



//..................PLATEAU...................
#define TAILLE_MIN_PLATEAU 19 //taille minimal du plateau de jeu
#define CASE_VIDE_JOUABLE 0 //element du plateau de jeu
#define CASE_PLEINE 1 //element du plateau de jeu
#define CASE_VIDE_INJOUABLE -1 //element du plateau de jeu
#define PLATEAU_CERCLE 1
#define PLATEAU_LOSANGE 2
#define PLATEAU_TRIANGLE 3

int** creation_plateau_losange(int taille);
int** creation_plateau_triangle(int taille);
int** creation_plateau_cercle(int taille);
void affichage_plateau(Tableau2D plateau);
int etat_ligne(Tableau2D plateau, int num_ligne);
int etat_colonne(Tableau2D plateau, int num_colonne);
void annuler_ligne(Tableau2D plateau, int num_ligne);
void annuler_colonne(Tableau2D plateau, int num_colonne);



//....................BLOC.....................
#define HAUTEUR_TAB_BLOCS 20 //hauteur du tableau des blocs (fichiers csv)
#define LARGEUR_TAB_BLOCS 50 //largeur du tableau des blocs (fichiers csv)
#define TAILLE_MAX_BLOC 5 //taille des blocs dans le fichier csv
#define DELIMITATION_BLOC 3 //delimitation blocs dans le tableau (remplace les # du fichier csv) - taille réelle

void creation_tableau_blocs(int tableau[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], int forme);
int hauteur_bloc(int num_bloc, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS]);
int largeur_bloc(int num_bloc, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS]);
Tableau2D creation_struct_bloc(int num_bloc, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS]);
void desalocation_struct_bloc(Tableau2D bloc);
void affichage_3_blocs(int num_bloc1, int num_bloc2, int num_bloc3, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS]);
int affichage_plateau_blocs_politique1(Tableau2D plateau, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], int nombre_blocs);
int affichage_plateau_blocs_politique2(Tableau2D plateau, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], int nombre_blocs);
void saisie_coord_bloc(Coord* choix_coord, Tableau2D plateau, int num_bloc, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS]);
void placement_bloc(int num_bloc, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], Tableau2D plateau, Coord choix_coord);
int validite_coord_bloc(Coord choix_coord, int num_bloc, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], Tableau2D plateau);

//....................MENU....................
void ecran_accueil(void);
void supr_console(void);
void choix_plateau(int* choix_forme);
void saisie_taille(int* taille, int choix_plateau);
void choix_politique_suggestion_blocs(int* choix);



//...................SYSTEME D'EXLOITATION....................
#ifdef _WIN32
#define SYSTEME_EXPLOITATION "win" //windows
#elif __linux__
#define SYSTEME_EXPLOITATION "linux"
#elif __APPLE__
#define SYSTEME_EXPLOITATION "mac"
#else
#define SYSTEME_EXPLOITATION "unk" //systéme inconnu
#endif


#endif /* fonctions_h */
