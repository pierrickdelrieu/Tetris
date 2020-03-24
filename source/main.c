//
//  main.c
//  "tetris"
//
//  Created by Pierrick Delrieu on 23/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include <stdio.h>
#include "fonctions.h"

int main()
{
    int** plateau = NULL; //initialisation du pointeur du tableau 2D
    int taille; //taille plateau saisie par l'utilisateur
    
    //Saisie sécurisée taille du tableau
    saisie_taille_losange(&taille);
    
    
    plateau = creation_plateau_losange(taille);
    
   
    affichage_plateau(plateau,taille);
 
    return 0;
}
