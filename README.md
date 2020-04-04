# Tetris

Projet 1 C semestre 2 L1. 

Jeu similaire au jeu Tetris.

A FAIRE

PIERRICK
-    Création des 4 fichiers xsv avec les formes représentées par des 1(case pleine) et des 0 (case vide)

-    Vérification état ligne renvoie 0 ou 1 si elle est pleine
int etat_ligne(int numero_ligne);

-    Vérification état colonne renvoie 0 ou 1 si elle est pleine
int etat_ligne(int numero_ligne);

-    Annuler ligne 
void etat_ligne(int*** plateau, int numero_ligne);

-    Annuler colonne
void etat_ligne(int*** plateau, int numero_ligne);

-    recupération du fichier csv et création d'un tableau 2D statique d'entier correspondant
void creation_plateau_blocs(int *** plateau_bloc, int choix_forme);

FAIT



ROMAIN
-    suppression console

FAIT

-    création d'un tableau statique d'entier en fonction de la forme chosit par l'utilisateur 
void creation_bloc(int*** bloc, int plateau_bloc, int coord_x, int coord_y, int hauteur, int largeur);
les blocs sont tous numéroté. Il faudra donc appelé cette fonction plusieurs fois dans un switch

MAYBE : L'idéal serait de créer une structure pour chaque bloc... avec comme champs : hauteur, largeur, pointeur sur le bloc
cf : - voir les fichier xsv avec dans chaque fichier au meme endroit les corddonées et la taille de chaque bloc
peut etre plus simple comme ca que de créer une structure pour chaque bloc (economie de mémoire)
    - creer un tableau de taille N avec les coordonées de tous les blocs (stuctures coordonnées)








A FAIRE
- verification de la validité d'un bloc

- placement bloc sur le plateau

- selctionner bloc

- affichage bloc (politique 1 et politique 2)
