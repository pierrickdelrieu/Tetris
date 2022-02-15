//
//  plateau.c
//  Teris
//
//  Created by Pierrick Delrieu on 23/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"


int **creation_plateau_losange(int taille) {
    int i, j; //compteur lignes et colonnes
    int **plateau = NULL; //retour = adresse du tableau 2D créé

    creation_tableau_2D(&plateau, taille, taille);

    //Initialisation d'un tableau remplit de point et d'espace pour former un losange
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            //haut droit; haut gauche; bas gauche; bas droit affichage d'espace
            if ((j > (taille / 2) + i) || (j < (taille / 2) - i) || (j < i - (taille / 2)) || (j >= (taille / 2) + (taille - i))) {
                plateau[i][j] = CASE_VIDE_INJOUABLE;
            } else {
                plateau[i][j] = CASE_VIDE_JOUABLE;
            }
        }
    }

    return plateau; //retour de l'adresse du tableau 2D
}

int **creation_plateau_triangle(int taille) {
    int i, j; //compteur lignes et colonnes
    int **plateau = NULL; //retour = adresse du tableau 2D créé

    creation_tableau_2D(&plateau, (taille / 2) + 1, taille);

    //Initialisation d'un tableau remplit de point et d'espace pour former un losange
    for (i = 0; i < (taille / 2) + 1; i++) {
        for (j = 0; j < taille; j++) {
            //haut droit; haut gauche; bas gauche; bas droit affichage d'espace
            if ((j > (taille / 2) + i) || (j < (taille / 2) - i) || (j < i - (taille / 2)) || (j >= (taille / 2) + (taille - i))) {
                plateau[i][j] = CASE_VIDE_INJOUABLE;
            } else {
                plateau[i][j] = CASE_VIDE_JOUABLE;
            }
        }
    }

    return plateau; //retour de l'adresse du tableau 2D
}

int **creation_plateau_cercle(int taille) {
    int i, j; //compteur lignes et colonnes
    int **plateau = NULL; //retour = adresse du tableau 2D créé
    int taille_espace; //taille des espaces dans chaques angles pour former le cercle

    //Attribution de la taille des espaces en fonction de la taille demander par l'utilisateur
    if ((taille == 19) || (taille == 21)) {
        taille_espace = 3;
    } else // si taille = 23 ou 25
    {
        taille_espace = 4;
    }

    creation_tableau_2D(&plateau, taille, taille);

    //Initialisation d'un tableau remplit de point et d'espace pour former un losange
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            //haut droit; haut gauche; bas gauche; bas droit - affichage d'espace
            if ((i < taille_espace) && ((j > taille - taille_espace + i - 1) || (j < taille_espace - i))) {
                plateau[i][j] = CASE_VIDE_INJOUABLE;
            } else if ((i > taille - taille_espace - 1) && ((j < i - taille + taille_espace + 1) || (j > taille - taille_espace - 1 + (taille - i - 1)))) {
                plateau[i][j] = CASE_VIDE_INJOUABLE;
            } else {
                plateau[i][j] = CASE_VIDE_JOUABLE;
            }
        }
    }

    return plateau; //retour de l'adresse du tableau 2D
}


void affichage_plateau(Tableau2D plateau, Score score) {
    //affichage en fonctions des trois types de plateau (losange, cercle, triangle)

    int i, j;
    int hauteur_totale_plateau = plateau.hauteur + 3; //hauteur totale = hauteur + colonnes numeros + 2 lignes de contours plateau
    int largeur_totale_plateau = plateau.largeur + 3; //largeur totale = largeur + lignes numeros + 2 colonnes de contours plateau

    //parcours le plateau
    for (i = 0; i < hauteur_totale_plateau; i++) {
        for (j = 0; j < largeur_totale_plateau; j++) {
            //Affichage des espaces
            if (((i == 0) || (i == 1)) && ((j == 0) || (j == 1) || (j == largeur_totale_plateau - 1))) {
                printf("%c ", ESPACE);
            } else if ((i == hauteur_totale_plateau - 1) && (j == 0)) {
                printf("%c ", ESPACE);
            }

                //Affichage des numéros de lignes
            else if ((j == 0) && (i > 1)) {
                printf("%c ", A + i - 2);
            }

                //Affichage des numéros de colonnes
            else if (i == 0 && (j > 1)) {
                printf("%c ", a + j - 2);
            }

                //Affichage des contours du plateau
            else if ((i > 1) && ((j == 1) || (j == largeur_totale_plateau - 1))) {
                printf("%c ", COTE_LATERAL);
                if ((i < hauteur_totale_plateau - 1) && (j == largeur_totale_plateau - 1)) {
                    printf("%c", A + i - 2);
                }
            } else if (((j > 1) && (j <= largeur_totale_plateau - 2)) && ((i == 1) || (i == hauteur_totale_plateau - 1))) {
                printf("%c%c", COTE_TRANSVERSAL, COTE_TRANSVERSAL);
            }

                //Affichage du contenu du plateau de jeu
            else {
                if (plateau.tableau[i - 2][j - 2] == CASE_VIDE_JOUABLE) {
                    printf("%c ", POINT);
                } else if (plateau.tableau[i - 2][j - 2] == CASE_VIDE_INJOUABLE) {
                    printf("%c ", ESPACE);
                } else if (plateau.tableau[i - 2][j - 2] == CASE_PLEINE) {
                    printf("◼︎"); //sur mac étant pas possible d'afficher les codes ascii au dessus de 127, on affiche un carré brut
                }
            }
        }


        //affichage du score
        if (i == 10) {
            printf("         Score : %d", score.valeur);
        }

        printf("\n"); //retour à la ligne après l'affichage d'une ligne
    }
}


int etat_ligne(Tableau2D plateau, int num_ligne) {
    //retourne 1 si la ligne est pleine, 0 sinon

    int j; //compteur
    int retour = 1; //valeur de retour initialisé à 1 (on considere que le plateau est plein)

    for (j = 0; j < plateau.largeur; j++) {
        if (plateau.tableau[num_ligne][j] == CASE_VIDE_JOUABLE) {
            retour = 0;
        }
    }

    return retour;
}


int etat_colonne(Tableau2D plateau, int num_colonne) {
    //retourne 1 si la colonne est pleine, 0 sinon

    int i; //compteur
    int retour = 1; //valeur de retour initialisé à 1 (on considere que le plateau est plein)

    for (i = 0; i < plateau.hauteur; i++) {
        if (plateau.tableau[i][num_colonne] == CASE_VIDE_JOUABLE) {
            retour = 0;
        }
    }

    return retour;
}

void annuler_ligne(Tableau2D plateau, int num_ligne, Score *score) {
    int j; //compteur

    for (j = 0; j < plateau.largeur; j++) {
        if (plateau.tableau[num_ligne][j] == CASE_PLEINE) {
            plateau.tableau[num_ligne][j] = CASE_VIDE_JOUABLE;

            if (score->validite == 1) {
                score->valeur = score->valeur + 1;
            }
        }
    }
}


void annuler_colonne(Tableau2D plateau, int num_colonne, Score *score) {
    int i; //compteur

    for (i = 0; i < plateau.hauteur; i++) {
        if (plateau.tableau[i][num_colonne] == CASE_PLEINE) {
            plateau.tableau[i][num_colonne] = CASE_VIDE_JOUABLE;

            score->valeur = score->valeur + 1;
        }
    }
}

void empilement_lignes(Tableau2D plateau, int num_ligne, Score *score) {
    //l'empilement de ligne et une copie de la ligne qui prècède sur la ligne qui vient d'etre supprimer

    int i, j; //compteur


    for (i = num_ligne; i >= 0; i--) {
        //verif si le score doit etre calculer (seuelment pour la premeire ligne annuler)
        if (i == num_ligne) {
            score->validite = 1;
        } else {
            score->validite = 0;
        }


        annuler_ligne(plateau, i, score); //annulation de la ligne + sans calcul score

        //si i ≠ 0 car sinon on annule juste la ligne, pas de remplacment a prévoir
        if (i != 0) {
            //copie de la ligne precedente dans la ligne actuelle
            for (j = 0; j < plateau.largeur; j++) {
                if (plateau.tableau[i - 1][j] == CASE_PLEINE) {
                    if (plateau.tableau[i][j] == CASE_VIDE_JOUABLE) {
                        plateau.tableau[i][j] = CASE_PLEINE;
                    } else {
                        plateau.tableau[i - 1][j] = 3; //case qui n'ont pas pu descendre
                    }
                }
            }
        }
    }

    //reabilitation des trois en case pleine
    for (i = num_ligne; i > 0; i--) {
        for (j = 0; j < plateau.largeur; j++) {
            if (plateau.tableau[i][j] == 3) {
                plateau.tableau[i][j] = CASE_PLEINE;
            }

        }
    }
}
