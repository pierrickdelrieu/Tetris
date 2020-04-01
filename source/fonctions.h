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
#define ESPACE 32
#define COTE_LATERAL 124 // |
#define COTE_TRANSVERSAL 61 // =



//..................PLATEAU...................
#define TAILLE_MIN_PLATEAU 19
#define PLATEAU_CERCLE 1
#define PLATEAU_LOSANGE 2
#define PLATEAU_TRIANGLE 3
int** creation_plateau_losange(int taille);
int** creation_plateau_triangle(int taille);
int** creation_plateau_cercle(int taille);
void affichage_plateau(int** plateau, int hauteur, int largeur);

//....................BLOC.....................



//....................MENU....................
void ecran_accueil(void);
void supr_console(void);
void choix_plateau(int* choix_forme);
void saisie_taille(int* taille, int choix_plateau);
void choix_politique_suggestion_blocs(int* choix);






#endif /* fonctions_h */
