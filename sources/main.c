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
    int hauteur,largeur;
    int choix_forme;
    int choix_suggestion_blocs; //1 pour afficher l'ensemble des blocs; 2 pour afficher 3 blocs aléatoirement
    int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS];

    
                    //....................................MENU....................................
    
    //Saisie sécurisée choix forme plateau et taille du tableau
    supr_console();
    ecran_accueil();
    choix_plateau(&choix_forme);
    saisie_taille(&taille, choix_forme);
    choix_politique_suggestion_blocs(&choix_suggestion_blocs);

    //Allocation en fonction du choix de la forme du plateau
    if(choix_forme == PLATEAU_CERCLE) //cercle
    {
        plateau = creation_plateau_cercle(taille);
        hauteur = taille;
        largeur = taille;
    }
    else if (choix_forme == PLATEAU_LOSANGE) //losange
    {
        plateau = creation_plateau_losange(taille);
        hauteur = taille;
        largeur = taille;
    }
    else //triangle
    {
        plateau = creation_plateau_triangle(taille);
        hauteur = taille/2;
        largeur = taille;
    }
    
    
    
    
                    //....................................JEU....................................

    creation_tableau_blocs(tableau_blocs, choix_forme);
    affichage_plateau(plateau,hauteur,largeur);
    
    desalocation_tableau2D(plateau, hauteur);
    affichage_tous_blocs(tableau_blocs);

 
    return 0;
}
