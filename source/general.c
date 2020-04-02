//
//  general.c
//  Tetris
//
//  Created by Pierrick Delrieu on 02/04/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"


void creation_tableau_2D(int*** tableau, int ligne, int colonne) //création plateau dynamique
{
    int i;
    
     *tableau = (int**) malloc(ligne * sizeof(int*)); //création du tableau de référence contenant les adresses de chaques lignes
    
    for(i=0; i<ligne; i++)
       {
           *(*(tableau) + i) = (int*) calloc(colonne, sizeof(int)); //création de taille tableau de taille dimension
       }
}
