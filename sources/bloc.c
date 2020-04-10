//
//  bloc.c
//  Tetris
//
//  Created by Pierrick Delrieu on 02/04/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"


void creation_tableau_blocs(int tableau[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], int forme)
{
    //recuperation fichier csv
    FILE* fichier_blocs = NULL; //declaration d'un pointeur sur le fichier
    int i = 0, j = 0; //declaration et initialisation compteur ligne et colonne
    
    
    //ouverture du fichier correspondant a la forme
    if(forme == PLATEAU_CERCLE) //Cercle
    {
        fichier_blocs = fopen("blocs/blocs_cercle.csv", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier
    }
    else if(forme == PLATEAU_LOSANGE)//Losange
    {
        fichier_blocs = fopen("blocs/blocs_losange.csv", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier
    }
    else //Triangle
    {
        fichier_blocs = fopen("blocs/blocs_triangle.csv", "r"); //"r" correspond a la lecture seul (permet de limiter les erreurs) - fopen renvoie un pointeur sur le fichier
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
                /*dans le fichier .csv, les 0 représente des case vide, les 1 des cases pleines
                et les n l'endroit où il faut afficher le numéro du blocs*/
                if(cara == '0')
                {
                    tableau[i][j] = CASE_VIDE_JOUABLE;
                }
                else if(cara == '1')
                {
                    tableau[i][j] = CASE_PLEINE;
                }
                else if(cara == '#') //délimitation blocs
                {
                    tableau[i][j] = DELIMITATION_BLOC;
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



int hauteur_bloc(int num_bloc, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    int hauteur = 1; //declaration dans la fonction car besoin d'etre initialisé a 1
    // Calcul rang du bloc dans le tableau
    int rang = 0;
    int num_bloc_copie = num_bloc;
    while(num_bloc_copie > 10) //le tableau dans le fichier csv est composer de 3 rang de 10 blocs max
    {
        rang++;
        num_bloc_copie = num_bloc_copie - 10;
    }
    

    //Calcul coordonnées du bloc dans le tableau
    int x = ((num_bloc-1) % 10) * 5;
    int y = 4 + (5*rang) ;

    while((hauteur<=TAILLE_MAX_BLOC) && (tab_blocs[y-hauteur][x] != DELIMITATION_BLOC)) //condition d'arret
    {
        hauteur ++;
    }

    return (hauteur);
}

int largeur_bloc(int num_bloc, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    int largeur = 1; //declaration dans la fonction car besoin d'etre initialisé a 1

    // Calcul rang du bloc dans le tableau
    int rang = 0;
    int num_bloc_copie = num_bloc;
    while(num_bloc_copie > 10) //le tableau dans le fichier csv est composer de 3 rang de 10 blocs max
    {
        rang++;
        num_bloc_copie = num_bloc_copie - 10;
    }
    

    //Calcul coordonnées du bloc dans le tableau
    int x = ((num_bloc-1) % 10) * 5;
    int y = 4 + (5*rang) ;
    
    while((largeur<TAILLE_MAX_BLOC) && (tab_blocs[y][x+largeur] != DELIMITATION_BLOC)) //condition d'arret
    {
        largeur ++;
    }

    return (largeur);
}

Bloc creation_struct_bloc(int num_bloc, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    // Calcul rang du bloc dans le tableau
    int rang = 0;
    int num_bloc_copie = num_bloc;
    while(num_bloc_copie > 10) //le tableau dans le fichier csv est composer de 3 rang de 10 blocs max
    {
        rang++;
        num_bloc_copie = num_bloc_copie - 10;
    }
    

    //Calcul coordonnées du bloc dans le tableau
    int x = ((num_bloc-1) % 10) * 5;
    int y = 4 + (5*rang) ;

    
    Bloc bloc; //declaration d'une variable de type bloc
    int i,j; //compteur

    bloc.hauteur = hauteur_bloc(num_bloc,tab_blocs); //initialisation hauteur du bloc dans la structure
    bloc.largeur = largeur_bloc(num_bloc,tab_blocs); //initialisation largeur du bloc dans la structure

    creation_tableau_2D(&bloc.tableau, bloc.hauteur, bloc.largeur); //allocation de l'espace necessaire pour construire le bloc

    //initialisation des valeurs du tableau correspondant au bloc dans la structure
    for(i=0; i<bloc.hauteur; i++)
    {
       for(j=0; j<bloc.largeur; j++)
       {
           bloc.tableau[i][j] = tab_blocs[y - bloc.hauteur + i + 1][x + j];
       } 
    }

    return (bloc);
}



void desalocation_struct_bloc(Bloc bloc)
{
    desalocation_tableau2D(bloc.tableau, bloc.hauteur);
}



void affichage_3_blocs(int num_bloc1, int num_bloc2, int num_bloc3, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    Bloc bloc1, bloc2, bloc3;
    int i,j;
    int cpt;
    int cpt_espace;


    //creation des 3 blocs a afficher
    bloc1 = creation_struct_bloc(num_bloc1, tab_blocs);
    bloc2 = creation_struct_bloc(num_bloc2, tab_blocs);
    bloc3 = creation_struct_bloc(num_bloc3, tab_blocs);
        
    //afichage blocs
    for(i=0; i<TAILLE_MAX_BLOC; i++)
    {

        //affichage bloc 1
        cpt = 0;
        if(i < bloc1.hauteur)
        {
            for(j=0; j<bloc1.largeur; j++)
            {
                if(bloc1.tableau[i][j] == CASE_VIDE_JOUABLE)
                {
                    printf("%c ", ESPACE);
                }
                else if(bloc1.tableau[i][j] == CASE_PLEINE)
                {
                    printf("◼︎ "); //sur mac étant pas possible d'afficher les codes ascii au dessus de 127, on affiche un carré brut
                }
                cpt ++;
            } 
        }
    
        //affichage des espaces
        for(cpt_espace = 0; cpt_espace < bloc1.largeur + 3 - cpt; cpt_espace ++)
        {
            printf("%c ", ESPACE);
        }
            
            
        //affichage bloc 2
        cpt = 0;
        if(i < bloc2.hauteur)
        {
            for(j=0; j<bloc2.largeur; j++)
            {
                if(bloc2.tableau[i][j] == CASE_VIDE_JOUABLE)
                {
                    printf("%c ", ESPACE);
                }
                else if(bloc2.tableau[i][j] == CASE_PLEINE)
                {
                    printf("◼︎ "); //sur mac étant pas possible d'afficher les codes ascii au dessus de 127, on affiche un carré brut
                }
                cpt ++; 
            }
        }

        //affichage des espaces
        for(cpt_espace = 0; cpt_espace < bloc1.largeur + bloc2.largeur + 3 - cpt; cpt_espace ++)
        {
            printf("%c ", ESPACE);
        }

        //affichage bloc 3
        if(i < bloc3.hauteur)
        {
            for(j=0; j<bloc3.largeur; j++)
            {
                if(bloc3.tableau[i][j] == CASE_VIDE_JOUABLE)
                {
                    printf("%c ", ESPACE);
                }
                else if(bloc3.tableau[i][j] == CASE_PLEINE)
                {
                    printf("◼︎ "); //sur mac étant pas possible d'afficher les codes ascii au dessus de 127, on affiche un carré brut
                }
                cpt++;
            } 
        }
        if(cpt != 0)
        {
            printf("\n");
        }
    }

    printf("\n");
    //affichage des numeros des blocs
    printf("%d ",num_bloc1);
    for(cpt_espace = 0; cpt_espace < bloc1.largeur; cpt_espace ++) //(bloc1.largeur*2) / 2 = bloc1.largeur
    {
        printf("%c ", ESPACE);
    }
    printf("      ");
    printf("%d ",num_bloc2);
    for(cpt_espace = 0; cpt_espace < bloc2.largeur; cpt_espace ++) //(bloc1.largeur*2) / 2 = bloc1.largeur
    {
        printf("%c ", ESPACE);
    }
    printf("      ");
    printf("%d ",num_bloc3);


    //desalocation memoire des blocs afficher precedemment
    desalocation_struct_bloc(bloc1);
    desalocation_struct_bloc(bloc2);
    desalocation_struct_bloc(bloc3);
}

