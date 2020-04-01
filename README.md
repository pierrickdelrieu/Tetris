# Tetris

Projet 1 C semestre 2 L1. 

Jeu similaire au jeu Tetris.

A FAIRE

PIERRICK
-    Création des 4 fichiers xsv avec les formes représentées par des 1(case pleine) et des 0 (case vide) identique à la page 8

-    Vérification état ligne renvoie 0 ou 1 si elle est pleine
int etat_ligne(int numero_ligne);

-    Vérification état colonne renvoie 0 ou 1 si elle est pleine
int etat_ligne(int numero_ligne);

-    Annuler ligne 
void etat_ligne(int*** plateau, int numero_ligne);

-    Annuler colonne
void etat_ligne(int*** plateau, int numero_ligne);


ROMAIN
-    suppression console

-    recupération du fichier csv et création d'un tableau 2D statique correspondant
void creation_plateau_blocs(int *** plateau_bloc, int choix_forme);

-    création d'un tableau statique en fonction de la forme chosit par l'utilisateur
void creation_bloc(int*** bloc, int plateau_bloc, int coord_x, int coord_y, int hauteur, int largeur);

MAYBE : L'idéal serait de créer une structure pour chaque bloc... avec comme champs : hauteur, largeur, pointeur sur le bloc

