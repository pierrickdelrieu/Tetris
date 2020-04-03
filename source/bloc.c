//
//  bloc.c
//  Tetris
//
//  Created by Pierrick Delrieu on 02/04/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"

void creation_tableau_blocs(int tableau[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    //recuperation fichier csv
    FILE* fichier_blocs = NULL; //declaration d'un pointeur sur le fichier
    int i = 0, j = 0; //declaration et initialisation compteur ligne et colonne
    
    //ouverture du fichier
    fichier_blocs = fopen("../blocs/blocs_communs.strings", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier
    
    
    //tester l'ouverture du fichier
    if(fichier_blocs != NULL)
    {
        char cara = '0'; //initialisation de caractère différent de '/'
        printf("Le fichier a bien était ouvert\n");
        //Création d'un tableau correspondant
        while(cara != '/') //condition fin
        {
            cara = fgetc(fichier_blocs);
            if(cara == '\n') //si saut de lignedans le fichier  alors saut de ligne dans le tableau aussi
            {
                i++; //incrémentation numero de ligne
                j=0; //reinitialise numero colonne à 0
            }
            else if(cara != ';') //on affiche pas les ;
            {
                if(cara == '0')
                {
                    tableau[i][j] = CASE_VIDE_JOUABLE;
                }
                else if(cara == '1')
                {
                    tableau[i][j] = CASE_PLEINE;
                }
            
                j++; //si ajout alors on incrémente le numero de colonne
            }
        }
    
        //Fermeture du fichier
        fclose(fichier_blocs);
    }
    else //le pointeur sur le fichier est toujours = NULL soit le fichier n'a pas était ouvert
    {
        printf("Echec de l'ouverture\n");
    }
}
