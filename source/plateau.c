//
//  plateau.c
//  Teris
//
//  Created by Pierrick Delrieu on 23/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"

int** creation_plateau_losange(int taille)
{
    int i,j; //compteur lignes et colonnes
    int** plateau = NULL; //retour = adresse du tableau 2D créé
    
    plateau = (int**) malloc(taille * sizeof(int*)); //création du tableau de référence contenant les adresses de chaques lignes
    
    for(i=0; i<taille; i++)
    {
        *(plateau + i) = (int*) calloc(taille, sizeof(int)); //création de taille tableau de taille dimension
    }
    
    //Initialisation d'un tableau remplit de point et d'espace pour former un losange
    for(i=0; i<taille; i++)
    {
        for(j=0; j<taille; j++)
        {
            //haut droit; haut gauche; bas gauche; bas droit affichage d'espace
            if((j > (taille/2) + i) || (j < (taille/2) - i) || (j < i - (taille/2)) ||  (j >= (taille/2) + (taille - i)))
            {
                plateau[i][j] = ESPACE;
            }
            else
            {
                plateau[i][j] = POINT;
            }
        }
    }
    
    return (plateau); //retour de l'adresse du tableau 2D
}

int** creation_plateau_triangle(int taille)
{
    int i,j; //compteur lignes et colonnes
    int** plateau = NULL; //retour = adresse du tableau 2D créé
    
    plateau = (int**) malloc(taille * sizeof(int*)); //création du tableau de référence contenant les adresses de chaques lignes
    
    for(i=0; i<taille; i++)
    {
        *(plateau + i) = (int*) calloc(taille, sizeof(int)); //création de taille tableau de taille dimension
    }
    
    //Initialisation d'un tableau remplit de point et d'espace pour former un losange
    for(i=0; i<(taille/2); i++) //(taille / 2) (necessaire pour un bon affichage du triangle)
    {
        for(j=0; j<taille; j++)
        {
            if((j > (taille/2) + i) || (j < (taille/2) - i)) //haut droit; haut gauche;
            {
                plateau[i][j] = ESPACE;
            }
            else
            {
                plateau[i][j] = POINT;
            }
        }
    }
    
    return (plateau); //retour de l'adresse du tableau 2D
}

int** creation_plateau_cercle(int taille)
{
    int i,j; //compteur lignes et colonnes
    int** plateau = NULL; //retour = adresse du tableau 2D créé
    
    plateau = (int**) malloc(taille * sizeof(int*)); //création du tableau de référence contenant les adresses de chaques lignes
    
    for(i=0; i<taille; i++)
    {
        *(plateau + i) = (int*) calloc(taille, sizeof(int)); //création de taille tableau de taille dimension
    }
    
    //Initialisation d'un tableau remplit de point et d'espace pour former un losange
    for(i=0; i<(taille/2); i++)
    {
        for(j=0; j<taille; j++)
        {
            //haut droit; haut gauche; bas gauche; bas droit
            if((j > (taille/2) + i) || (j < (taille/2) - i))
            {
                plateau[i][j] = ESPACE;
            }
            else
            {
                plateau[i][j] = POINT;
            }
        }
    }
    
    return (plateau); //retour de l'adresse du tableau 2D
}




void affichage_plateau(int** plateau, int hauteur, int largeur)
{
    //affichage en fonctions des trois types de plateau (losange, cercle, triangle)
    
    int i,j;
    int hauteur_totale = hauteur + 3; //hauteur totale = hauteur + colonnes numeros + 2 lignes de contours plateau
    int largeur_totale = largeur + 3; //largeur totale = largeur + lignes numeros + 2 colonnes de contours plateau

    
    for(i=0; i<hauteur_totale; i++)
    {
        for(j=0; j<largeur_totale; j++)
        {
            //Affichage des espaces
            if(((i == 0) || (i == 1)) && ((j == 0) || (j == 1) || (j == largeur_totale-1)))
            {
                printf("%c ",ESPACE);
            }
            else if((i == hauteur_totale-1) && (j == 0))
            {
                printf("%c ",ESPACE);
            }
            
            //Affichage des numéros de lignes
            else if((j == 0) && (i > 1))
            {
                printf("%c ", A+i-2);
            }
            
            //Affichage des numéros de colonnes
            else if((i == 0) && (j > 1))
            {
                printf("%c ", a+j-2);
            }
            
            //Affichage des contours du plateau
            else if((i > 1) && ((j == 1) || (j == largeur_totale-1)))
            {
                printf("%c ",COTE_LATERAL);
            }
            else if(((j > 1) && (j <= largeur_totale-2)) && ((i == 1) || (i == hauteur_totale-1)))
            {
                printf("%c%c",COTE_TRANSVERSAL,COTE_TRANSVERSAL);
            }
            
            //Affichage du contenu du plateau
            else
            {
                printf("%c ",plateau[i-2][j-2]);
            }
        }
        printf("\n"); //retour à la ligne après l'affichage d'une ligne
    }
}
