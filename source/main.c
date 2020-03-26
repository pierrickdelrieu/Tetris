//
//  main.c
//  "tetris"
//
//  Created by Pierrick Delrieu on 23/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"

int main()
{
    int** plateau = NULL; //initialisation du pointeur du tableau 2D
    int taille; //taille plateau saisie par l'utilisateur
    
    //Saisie sécurisée taille du tableau
    saisie_taille_losange_ou_triangle(&taille);
    
    
    plateau = creation_plateau_triangle(taille);
    
   
    affichage_plateau(plateau,taille/2,taille);
 
    return 0;
}
