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

    //Initialisation
    creation_tableau_blocs(tableau_blocs, choix_forme);
    int choix_num_bloc;

    //Boucle de jeu
    
    //affichage des blocs + plateau
    if(choix_politique_blocs == 1) //affichage de l'ensemble des blocs
    {
        choix_num_bloc = affichage_plateau_blocs_politique1(plateau, hauteur_plateau, largeur_plateau, tableau_blocs, nombre_blocs);
    }
    else if(choix_politique_blocs == 2) //affichage de trois blocs aléatoire
    {
        choix_num_bloc = affichage_plateau_blocs_politique2(plateau, hauteur_plateau, largeur_plateau, tableau_blocs, nombre_blocs);
    }
 
    return 0;
}
