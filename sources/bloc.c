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

Tableau2D creation_struct_bloc(int num_bloc, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
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

    
    Tableau2D bloc; //declaration d'une variable de type bloc
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



void desalocation_struct_bloc(Tableau2D bloc)
{
    desalocation_tableau2D(bloc.tableau, bloc.hauteur);
}



void affichage_3_blocs(int num_bloc1, int num_bloc2, int num_bloc3, int tab_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    Tableau2D bloc1, bloc2, bloc3; //initialisation des structures Bloc
    int i,j; //compteur
    int cpt; //cpt utilisé dans le calcul pour afficher les espaces
    int cpt_espace; //cpt d'espace dans le boucle while


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
    printf("%d\n",num_bloc3);


    //desalocation memoire des blocs afficher precedemment
    desalocation_struct_bloc(bloc1);
    desalocation_struct_bloc(bloc2);
    desalocation_struct_bloc(bloc3);
}

int affichage_plateau_blocs_politique1(Tableau2D plateau, Score score, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], int nombre_blocs)
{
    int num_bloc = 1; //initialisation du numeros des blocs
    int choix_num_bloc; //choix saisie par l'utilisateur
    int erreur = 0; //0 si pas d'erreur et 1 sinon pour afficher un message
    int valide;

    do
    {
        affichage_plateau(plateau,score);

        //affichage des numeros blocs en prenant en compte l'affichage de fin des blocs
        if(num_bloc + 2 <= nombre_blocs)
        {
            affichage_3_blocs(num_bloc, num_bloc + 1, num_bloc + 2, tableau_blocs);
        }
        else if(num_bloc + 1 <= nombre_blocs)
        {
            affichage_3_blocs(num_bloc, num_bloc + 1, num_bloc + 1, tableau_blocs);
        }
        else
        {
            affichage_3_blocs(num_bloc, num_bloc, num_bloc, tableau_blocs);

        }

        //affichage message d'erreur
        if (erreur == 1)
        {
            printf("\nERREUR");
            erreur = 0;
        }

        //saisie utilisateur
        printf("\nChoisir un bloc \n(taper 0 pour consulter les blocs suivants ou 40 pour consulter les blocs précedents) : ");
        valide = scanf("%d", &choix_num_bloc);
        fflush(stdin);



        //blocs suivants ou blocs précédents
        if((valide == 1) && (choix_num_bloc == 0) && (num_bloc+2 <= nombre_blocs))
        {
            num_bloc = num_bloc + 3;
            supr_console();
        }
        else if((valide == 1) && (choix_num_bloc == 40) && (num_bloc != 1))
        {
            num_bloc = num_bloc - 3;
            supr_console();
        }
        else if((valide != 1) || ((choix_num_bloc != num_bloc) && (choix_num_bloc != num_bloc + 1) && (choix_num_bloc != num_bloc + 2)))
        {
            erreur = 1;
            supr_console();
        }
        
    

    }while ((choix_num_bloc == 0) || (choix_num_bloc == 40) || (erreur == 1));
    
    return (choix_num_bloc);
}


int affichage_plateau_blocs_politique2(Tableau2D plateau, Score score, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], int nombre_blocs)
{
    int num_bloc1, num_bloc2, num_bloc3; //declaration des numéros des trois blocs que l'on va afficher
    int choix_num_bloc = 0; //initialisation a 0 rentrer dans la condition qui suit
    int erreur = 0; //0 si pas d'erreur et 1 sinon pour afficher un message

    //initialisation aléatoire de 3 blocs
    num_bloc1 = 1 + (rand() % nombre_blocs);

    do //securisation pour que les 3 blocs soit différents
    {
        num_bloc2 = 1 + (rand() % nombre_blocs);
    }while(num_bloc2 == num_bloc1);

    do
    {
        num_bloc3 = 1 + (rand() % nombre_blocs);
    }while((num_bloc3 == num_bloc1) || (num_bloc3 == num_bloc2)); //securisation pour que les 3 blocs soit différents

    //securisation de la saisie de un des trois blocs afficher 
    do
    {
        affichage_plateau(plateau, score);

        affichage_3_blocs(num_bloc1, num_bloc2, num_bloc3, tableau_blocs);

        //affichage message d'erreur
        if(erreur == 1)
        {
            printf("\nERREUR");
            erreur = 0;
        }

        //saisie utilisateur
        printf("\nChoisir un bloc : ");
        scanf("%d", &choix_num_bloc);
        fflush(stdin);

        if((choix_num_bloc != num_bloc1) && (choix_num_bloc != num_bloc2) && (choix_num_bloc != num_bloc3))
        {
            erreur = 1;
            supr_console();
        }
    

    }while (erreur == 1);
    
    return (choix_num_bloc);
}


void saisie_coord_bloc(Coord* choix_coord, Tableau2D plateau, int num_bloc, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS])
{
    //Les coordonnées prennet la valeur de -1 si lres coordonnées ne sont pas des lettres

    char coordx; //variable prpores a la fonctions 
    char coordy; //variable prpores a la fonctions 
    int valide; //permettra de verif si les coord sont valides
    int i; //compteur

    Tableau2D bloc; //declaration sturcture bloc
    bloc = creation_struct_bloc(num_bloc, tableau_blocs); //initialisation structure bloc

    //affichage
    printf("\nSaisir les coordonnées du blocs : \n");

    //saisie des coordonnées en x (num colonne)
    i=0;

    printf("          colonne : ");
    scanf(" %c", &coordx);
    fflush(stdin);

    while((coordx != a + i) && (i < plateau.largeur)) //verif si lettre saisie dans le plateau
    {
        i++;
    }
    if(i > plateau.largeur - bloc.largeur) //verif si le coord est valide
    {
        i = -1;
    }

    choix_coord->x = i; //attribution a y un entier correspondant a la lettre saisie par l'utilisateur (a noter le plateau commence a l'indice 0)


    //saisie des coordonnées en y (num ligne)
    i=0;

    printf("          ligne : ");
    scanf(" %c", &coordy);
    fflush(stdin);

    while((coordy != A + i) && (i < plateau.hauteur)) //verif si lettre saisie dans le plateau
    {
        i++;
    }

    if((i >= plateau.hauteur) || (i < bloc.hauteur-1)) //verif si le coord est valide
    {
        i = -1;
    }

    
    choix_coord->y = i; //attribution a y un entier correspondant a la lettre saisie par l'utilisateur (a noter le plateau commence a l'indice 0)

    desalocation_struct_bloc(bloc); //desalocation du tableau 2D de la structure
}


void placement_bloc(int num_bloc, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], Tableau2D plateau,Coord choix_coord)
{
    Tableau2D bloc; //declaration structure bloc
    int i; //compteur
    int j; //compteur

    bloc = creation_struct_bloc(num_bloc, tableau_blocs); //initialisation structure bloc

    //placement du bloc
    for(i = 0; i < bloc.hauteur; i++)
    {
        for(j = 0; j < bloc.largeur; j++)
        {
            if(bloc.tableau[i][j] == CASE_PLEINE)
            {
                plateau.tableau[choix_coord.y - bloc.hauteur + 1 + i][choix_coord.x + j] = CASE_PLEINE;
            }
        }
    }

    desalocation_struct_bloc(bloc); //desalocation tableau structure bloc
}


int validite_coord_bloc(Coord choix_coord, int num_bloc, int tableau_blocs[HAUTEUR_TAB_BLOCS][LARGEUR_TAB_BLOCS], Tableau2D plateau)
{
    //retour 1 si bloc + coord sont valide et 0 sinon

    int valide = 1; //contient la valeur de retour
    

    // verif coordonné
    if((choix_coord.x == -1) || (choix_coord.y == -1)) //si les coordonnées ne sont pas dans la taille du tableau
    {
        valide = 0;
    }
    else //verif si les cases sont vides et jouables
    {
        Tableau2D bloc; //declaration structure bloc
        int i, j; //compteur

        bloc = creation_struct_bloc(num_bloc, tableau_blocs); //initialisation structure bloc

        //verification
        for(j=0; j<bloc.largeur; j++)
        {
            for(i=0; i<bloc.hauteur; i++)
            {
                if(bloc.tableau[i][j] == CASE_PLEINE) //verif qui si la case necessite une verif
                {
                    if (plateau.tableau[choix_coord.y - bloc.hauteur + 1 + i][choix_coord.x + j] != CASE_VIDE_JOUABLE) // verif case jouable
                    {   
                        valide = 0;
                    }
                }
            }
        }

         desalocation_struct_bloc(bloc); //desalocation tableau structure bloc
    }

    return (valide);
}