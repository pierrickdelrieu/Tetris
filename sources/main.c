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
    Tableau2D plateau;
    int taille; //taille plateau saisie par l'utilisateur
    int choix_forme; //choix de la forme du plateau de jeu
    int choix_politique_blocs; //1 pour afficher l'ensemble des blocs; 2 pour afficher 3 blocs aléatoirement
    int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS];
    int nombre_blocs; //nombre de blocs dans le plateau en fonction de la forme choisie

    
                    //....................................MENU....................................
    
    //Saisie utilisateur (sécurisé) 
    supr_console();
    ecran_accueil(); //affichage commencer a jouer ou regles du jeu
    choix_plateau(&choix_forme); //choix de la forme du plateau de jeu
    saisie_taille(&taille, choix_forme); //saisie de la taille du plateau de jeu
    choix_politique_suggestion_blocs(&choix_politique_blocs); //choix de la taille du plateau de jeu

    //Allocation et initialisation en fonction du choix de la forme du plateau
    if(choix_forme == PLATEAU_CERCLE) //cercle
    {
        plateau.tableau = creation_plateau_cercle(taille);
        plateau.hauteur = taille;
        plateau.largeur = taille;
        nombre_blocs = 32;
    }
    else if (choix_forme == PLATEAU_LOSANGE) //losange
    {
        plateau.tableau = creation_plateau_losange(taille);
        plateau.hauteur = taille;
        plateau.largeur = taille;
        nombre_blocs = 34;
    }
    else //triangle
    {
        plateau.tableau = creation_plateau_triangle(taille);
        plateau.hauteur = (taille/2) + 1;
        plateau.largeur = taille;
        nombre_blocs = 31;
    }


    
    creation_tableau_blocs(tableau_blocs, choix_forme); //creation du tableau de blocs a partir du fichier csv
    
    
                    //....................................JEU....................................

    //Initialisation
    int choix_num_bloc; //saisie utilisateur choix du numero du bloc
    Coord choix_coord; //saisie par l'utilisateur des coordonée en x et en y sous forme d'un caractere retranscrit en entier
    int continuer; //condition d'arret (nombre d'essai max de saisie de coordonnées)
    int cpt; //compteur
    Score score;

    score.valeur = 0; //initialisation du score

    //Boucle de jeu
    do
    {
        continuer = 0; //initialisation de la condition d'arret

        //affichage des blocs + plateau
        if(choix_politique_blocs == 1) //affichage de l'ensemble des blocs
        {
            choix_num_bloc = affichage_plateau_blocs_politique1(plateau, score, tableau_blocs, nombre_blocs);
        }
        else if(choix_politique_blocs == 2) //affichage de trois blocs aléatoire
        {
            choix_num_bloc = affichage_plateau_blocs_politique2(plateau, score, tableau_blocs, nombre_blocs);
        }

        //Saisie coordonnée bloc
        do
        {
            continuer ++;

            if(continuer > 1)
            {
                printf("\nERREUR DE SAISIE %d",continuer-1);
            }

            saisie_coord_bloc(&choix_coord, plateau, choix_num_bloc, tableau_blocs);
        }while((continuer < NOMBRE_ESSAI_SAISIE) && (validite_coord_bloc(choix_coord, choix_num_bloc, tableau_blocs, plateau) == 0)); 

        supr_console();


        //Placement du bloc
        if(validite_coord_bloc(choix_coord, choix_num_bloc, tableau_blocs, plateau) == 1)
        {
            placement_bloc(choix_num_bloc, tableau_blocs, plateau, choix_coord);

            //gestion de la descende et la suppresion des lignes
            for(cpt=0; cpt<plateau.hauteur; cpt++)
            {
                if(etat_ligne(plateau, cpt) == 1) //la ligne cpt est pleine
                {
                    empilement_lignes(plateau,cpt,&score); //empilement + annulation de la ligne
                }
            }

            //gestion de la suppresion des colonnes
            for(cpt=0; cpt<plateau.largeur; cpt++)
            {
                if(etat_colonne(plateau, cpt) == 1) //la colonne cpt est pleine
                {
                    annuler_colonne(plateau,cpt,&score);
                }
            }

            affichage_plateau(plateau, score);
        }
        else
        {
            continuer = 4; // si le bloc n'est pas valide au troiseme coup a lors on quitte la boucle de jeu 
        }
        
        supr_console();

    }while(continuer <= NOMBRE_ESSAI_SAISIE);


                    //...............................AFFICHAGE.RESULTAT...............................

    printf("          ................................................................................          \n");
    printf("                                          FIN DE LA PARTIE                                          \n");
    printf("          ................................................................................          \n\n\n\n");
    printf("                              Vous avez dépassé le nombres d'essai\n\n\n");
    printf("                                     Votre score est - %d\n\n\n", score.valeur);
    printf("       Merci pour votre participation\n\n");
    






    //Desalocation de l'espace mémoire dynamique
    desalocation_tableau2D(plateau.tableau,plateau.hauteur);
 
    return 0;
}
