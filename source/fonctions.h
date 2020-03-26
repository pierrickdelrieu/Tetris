//
//  fonctions.h
//  Teris
//
//  Created by Pierrick Delrieu on 23/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#ifndef fonctions_h
#define fonctions_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Code ascii
#define POINT 46
#define A 65 //le code ascii des lettres en majuscules est dans l'ordre A+i
#define a 97 //le code ascii des lettres en minuscules est dans l'ordre a+i
#define ESPACE 32
#define COTE_LATERAL 124 // |
#define COTE_TRANSVERSAL 61 // =



//..................PLATEAU...................
#define TAILLE_MIN_PLATEAU 19
int** creation_plateau_losange(int taille);
int** creation_plateau_triangle(int taille);
int** creation_plateau_cercle(int taille);
void affichage_plateau(int** plateau, int hauteur, int largeur);


//....................MENU....................
void saisie_taille_losange_ou_triangle(int* taille);





#endif /* fonctions_h */
