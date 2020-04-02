//
//  menu.c
//  Tetris
//
//  Created by Pierrick Delrieu on 24/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"


void ecran_accueil(void)
{
    int choix;
    int cpt = 0;
    
    do
    {
        printf("EFREI PARIS                                                                            L1 PROMO 2024\n");
        printf("projet C                      ....................................                  Pierrick DELRIEU\n");
        printf("                              .      COMME UN AIR DE TETRIS      .                     Romain JOREAU\n");
        printf("                              ....................................                                  \n\n\n");

        printf("                                         - BIENVENUE -\n\n\n");

    
        printf("                    1 - Commencer a jouer                     2 - Regles du jeu                     \n\n\n");
    
        if(cpt != 0) //si l'utilisateur c'est trompé au moins une fois
        {
            printf("             ERREUR - Taper 1 pour commencer a jouer, 2 pour consulter les règles du jeu             \n");
        }
        
        printf("     SAISIR : ");
        scanf("%d",&choix); // saisie de 1 ou 2
        fflush(stdin);//suprimer le buffer d'entré après avoir saisie la valeur pour éviter de faire crasher le programme (boucle infinie)
        cpt++;
        supr_console();
    }while((choix != 1) && (choix != 2));
    
    //Affichage des régles du jeu
    if(choix == 2)
    {
        do
        {
            printf("                                        - REGLE DU JEU -                                            \n\n\n\n");
            printf("Le Tetris est un jeu qui se présente sous forme d’une matrice où des blocs de différentes formes\n doivent être posés de sorte que le plateau soit gardé le plus longtemps possible non plein. L’idée est de\n placer chaque bloc à l’emplacement qui permet d’éliminer un maximum de lignes et/ou de colonnes. Ces dernières\n sont supprimées automatiquement lorsqu’elles sont pleines.\n\n\n\n");
            
            printf("Taper 1 pour commencer a jouer : ");
            scanf("%d",&choix);
            fflush(stdin); //suprimer le buffer d'entré après avoir saisie la valeur pour éviter de faire crasher le programme (boucle infinie)
        
            supr_console();
            
        }while(choix != 1);
    }
    
}


void choix_plateau(int* choix_forme)
{
    /*l'utilisateur doit saisir
        1 pour cercle; 2 pour losange et 3 pour triangle*/
    
    int cpt = 0; // compteur
    
    do
    {
        printf("          ................................................................................           \n");
        printf("                                          CHOIX DU PLATEAU                                           \n");
        printf("          ................................................................................          \n\n\n\n\n");
        
        printf("                       1 - Cercle          2 - Losange          3 - Triangle\n\n\n\n\n");
          
        
        if(cpt != 0) //Si ce n'est pas la premier saisie
        {
            printf("                                              ERREUR\n");
        }
        printf("     Saisir le numero correspondant a la forme voulu : ");
        scanf("%d",choix_forme);
        fflush(stdin); //suprimer le buffer après avoir saisie la valeur pour éviter de faire crasher le programme (boucle infinie)
        supr_console();
        cpt++;
    } while((*choix_forme != 1) && (*choix_forme != 2) && (*choix_forme != 3)); 
    
}

void saisie_taille(int* taille, int choix_plateau)
{
    /*On a : TAILLE_MIN_PLATEAU <= taille <= nombre de lettre de l'alphabet et ta
        et la taille doit etre impaire pour que le losange se positionne correctemment*/
    
    int cpt = 0; //compteur
    
    do
    {
        printf("          ................................................................................          \n");
        printf("                                          CHOIX DU PLATEAU                                          \n");
        printf("          ................................................................................          \n\n\n\n");
        
        if(choix_plateau == 1) //Cercle
        {
             printf("                               Vous avez choisit un plateau en tiangle\n\n\n");
        }
        else if(choix_plateau == 2)//Losange
        {
            printf("                               Vous avez choisit un plateau en losange\n\n\n");
        }
        else //Triangle
        {
            printf("                               Vous avez choisit un plateau en cercle\n\n\n");
        }
        
        if(cpt != 0) //Si c'est pas la première saisie
        {
            printf("                                              ERREUR\n");
        }
        printf("     Saisir une taille impaire pour le plateau (compris entre %d et 26) : ",TAILLE_MIN_PLATEAU);
        
        
        scanf("%d",taille);
        fflush(stdin); //suprimer le buffer après avoir saisie la valeur pour éviter de faire crasher le programme (boucle infinie)
        cpt ++;
        supr_console();
    }while((*taille<TAILLE_MIN_PLATEAU) || (*taille>26) || (*taille % 2 == 0));
}

void choix_politique_suggestion_blocs(int* choix)
{
    /* 1 - Afficher à chaque tour de jeu l’ensemble des blocs disponibles et l’utilisateur en sélectionne un.
       2 - Afficher uniquement 3 blocs sélectionnés aléatoirement. */
    
    int cpt = 0; //compteur
    
    do
    {
        printf("          ................................................................................          \n");
        printf("                           CHOIX DE LA POLITIQUE DE SUGGESTION DES BLOCS                            \n");
        printf("          ................................................................................          \n\n\n\n\n");
        
        
        printf("               1 - Afficher à chaque tour de jeu l’ensemble des blocs disponibles\n               2 - Afficher uniquement 3 blocs sélectionnés aléatoirement\n\n\n");
        
        if(cpt != 0) //Si c'est pas la première saisie
        {
            printf("                                              ERREUR\n");
        }
        printf("     Saisir le numero correspondant à la politique de jeu souhaitée : ");
        
        
        scanf("%d",choix);
        fflush(stdin); //suprimer le buffer après avoir saisie la valeur pour éviter de faire crasher le programme (boucle infinie)
        cpt ++;
        supr_console();
    }while((*choix != 1) && (*choix != 2));;
}

void supr_console(void)
{
    system(SYSTEME_EXPLOITATION == "win" ? "cls" : "clear");
}


