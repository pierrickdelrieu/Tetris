//
//  menu.c
//  Tetris
//
//  Created by Pierrick Delrieu on 24/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"


void saisie_taille_losange_ou_triangle(int* taille)
{
    /*On a : TAILLE_MIN_PLATEAU <= taille <= nombre de lettre de l'alphabet et ta
        et la taille doit etre impaire pour que le losange se positionne correctemment*/
    
    int cpt = 0; //compteur
    do
    {
        if(cpt == 0) //Si c'est la première saisie
        {
            printf("Saisir une taille impaire pour le plateau (compris entre %d et 26) : ",TAILLE_MIN_PLATEAU);
        }
        else //Si la saisie prècedentes n'était pas correctes
        {
            printf("ERREUR\nSaisir une taille impaire pour le plateau (compris entre %d et 26) : ",TAILLE_MIN_PLATEAU);
        }
        
        scanf("%d",taille);
        fflush(stdin); //suprimer le buffer après avoir saisie la valeur pour éviter de faire crasher le programme (boucle infinie)
        printf("\n"); //Saut de ligne
        cpt ++;
    }while((*taille<TAILLE_MIN_PLATEAU) || (*taille>26) || (*taille % 2 == 0));
}

