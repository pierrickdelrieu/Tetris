# Tetris

Projet 1 C semestre 2 L1. 

Jeu similaire au jeu Tetris.


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

-   creation d'une fonction qui créée une structure en fonction du numéro du bloc

- affichage bloc

- desalocation structure bloc (A REVOIR)

- affichage et saisie choix bloque politique 1

- affichage et saisie choix bloque politique 2

- saisie coordonnées

- placement blocs sur le plateau

FAIT



ROMAIN
-    suppression console

FAIT








A FAIRE
- verification de la validité d'un bloc

- calcul du score



QUESTION
- utilisation tableau 3D pour les blocs (pas necessaire pour moi) vraiment obligatoire ?

- gestion de la supression des lignes, où mettre les blocs une fois une lignes pleine ...

- placement des blocs ...?

- type de calcul de score

- affichage aleatoire, proposer un reaffichage de blocs aléatoire ?