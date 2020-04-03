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
//    int hauteur,largeur;
//    int choix_forme;
//    int choix_suggestion_blocs; //1 pour afficher l'ensemble des blocs; 2 pour afficher 3 blocs aléatoirement
//
    
                    //....................................MENU....................................
    
    //Saisie sécurisée choix forme plateau et taille du tableau
    supr_console();
//    ecran_accueil();
//    choix_plateau(&choix_forme);
//    saisie_taille(&taille, choix_forme);
//    choix_politique_suggestion_blocs(&choix_suggestion_blocs);
//
//    //Allocation en fonction du choix de la forme du plateau
//    if(choix_forme == 1) //cercle
//    {
//        plateau = creation_plateau_cercle(taille);
//        hauteur = taille;
//        largeur = taille;
//    }
//    else if (choix_forme == 2) //losange
//    {
//        plateau = creation_plateau_losange(taille);
//        hauteur = taille;
//        largeur = taille;
//    }
//    else //triangle
//    {
//        plateau = creation_plateau_triangle(taille);
//        hauteur = taille/2;
//        largeur = taille;
//    }
    
    
    
    //test
    taille = 21;
    plateau = creation_plateau_cercle(taille);
    affichage_plateau(plateau,taille,taille);
    
    //recuperation fichier csv
    FILE* fichier_blocs = NULL; //declaration d'un pointeur sur le fichier
    int tableau [10][31];
    int i = 0, j = 0;
    
    //ouverture du fichier
    fichier_blocs = fopen("../blocs/blocs_cercle.csv", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier


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

    //affichage du tableau
    printf("Affichage tableau\n");
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 31; j++)
        {
         printf("%d ",tableau[i][j]);
        }
        printf("\n");
    }
    
    
    
    
    desalocation_tableau2D(plateau, taille);
    
    
    
                    //....................................JEU....................................

   
//    affichage_plateau(plateau,hauteur,largeur);
//    desalocation_tableau2D(plateau, hauteur);
 
    return 0;
}
