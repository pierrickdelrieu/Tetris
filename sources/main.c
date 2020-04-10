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
    int hauteur_plateau,largeur_plateau;
    int choix_forme;
    int choix_politique_blocs; //1 pour afficher l'ensemble des blocs; 2 pour afficher 3 blocs aléatoirement
    int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS];
    int nombre_blocs;

    
                    //....................................MENU....................................
    
    //Saisie sécurisée choix forme plateau et taille du tableau et politique d'affichage
    supr_console();
    ecran_accueil();
    choix_plateau(&choix_forme);
    saisie_taille(&taille, choix_forme);
    choix_politique_suggestion_blocs(&choix_politique_blocs);

    //Allocation et initialisation en fonction du choix de la forme du plateau
    if(choix_forme == PLATEAU_CERCLE) //cercle
    {
        plateau = creation_plateau_cercle(taille);
        hauteur_plateau = taille;
        largeur_plateau = taille;
        nombre_blocs = 32;
    }
    else if (choix_forme == PLATEAU_LOSANGE) //losange
    {
        plateau = creation_plateau_losange(taille);
        hauteur_plateau = taille;
        largeur_plateau = taille;
        nombre_blocs = 34;
    }
    else //triangle
    {
        plateau = creation_plateau_triangle(taille);
        hauteur_plateau = taille/2;
        largeur_plateau = taille;
        nombre_blocs = 31;
    }
    
    
    
    
                    //....................................JEU....................................

    
    creation_tableau_blocs(tableau_blocs, choix_forme);
    
    int choix_num_bloc;

    //affichage des blocs + plateau
    if(choix_politique_blocs == 1) //affichage de l'ensemble des blocs
    {
        int num_bloc = 1;
        do
        {
            affichage_plateau(plateau,hauteur_plateau,largeur_plateau);
            affichage_3_blocs(num_bloc, num_bloc + 1, num_bloc + 2, tableau_blocs);

            //saisie utilisateur
            printf("\nChoisir un bloc ou taper 0 pour consulter les blocs suivants: ");
            scanf("%d", &choix_num_bloc);
            fflush(stdin);

            if(choix_num_bloc == 0)
            {
                num_bloc = num_bloc + 3;
            }

            supr_console();

        }while ((choix_num_bloc == 0) || (choix_num_bloc > nombre_blocs) || ((choix_num_bloc != num_bloc) && (choix_num_bloc != num_bloc + 1) && (choix_num_bloc != num_bloc + 2)));
    }
 
    return 0;
}
