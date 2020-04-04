//
//  bloc.c
//  Tetris
//
//  Created by Pierrick Delrieu on 02/04/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"

// typedef struct
// {
//     int coord_x;
//     int coord_y;
//     int hauteur;
//     int largeur;
// } Bloc;

void creation_tableau_blocs(int tableau[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], int forme)
{
    //recuperation fichier csv
    FILE* fichier_blocs = NULL; //declaration d'un pointeur sur le fichier
    int i = 0, j = 0; //declaration et initialisation compteur ligne et colonne
    
    
    //ouverture du fichier correspondant a la forme
    if(forme == PLATEAU_CERCLE) //Cercle
    {
         fichier_blocs = fopen("../blocs/blocs_cercle.csv", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier
    }
    else if(forme == PLATEAU_LOSANGE)//Losange
    {
       fichier_blocs = fopen("../blocs/blocs_losange.csv", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier
    }
    else //Triangle
    {
        fichier_blocs = fopen("../blocs/blocs_triangle.csv", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier
    }
    
    
    
    //tester l'ouverture du fichier
    if(fichier_blocs != NULL)
    {
        char cara = '0'; //initialisation de caractère différent de '/'
        
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
        printf("Erreur au niveau de l'ouverture du fichiers contenants tous les blocs\n");
        exit(0); //Fin du programme
    }
}



void affichage_tous_blocs(int tableau[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    int i,j; //declaration compteur de ligne et de colonne
    
    //affichage du tableau
    for(i = 0; i < HAUTEUR_TAB_BLOCS; i++)
    {
        for(j = 0; j < LARGEUR_TAB_BLOCS; j++)
        {
            if(tableau[i][j] == CASE_VIDE_JOUABLE)
            {
                printf("%c ", ESPACE);
            }
            else if(tableau[i][j] == CASE_PLEINE)
            {
                printf("◼︎ "); //sur mac étant pas possible d'afficher les codes ascii au dessus de 127, on affiche un carré brut
            }
        }
        printf("\n");
    }
}
