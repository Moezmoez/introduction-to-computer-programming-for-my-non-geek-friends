# Lesson 1

Exercices a realiser dans l'ordre

## Ex 1

Introduction a la compilation.

Le but est de realiser un programme qui :
- se lance
- ne fait rien
- puis quitte

## Ex 2

Introduction a l'output

Le but est d'ecrire un programme qui :
- se lance
- Ecrit votre prenom suivi d'un retour a la ligne sur la sortie standard a l'aide de la fonction `write` (man 2 write)
- Ecrit "J'ai X ans" (X = votre age) sur la sortie standard suivi d'un retour a la ligne a l'aide de la fonction `printf` (man 2 printf)
- Quitte

Exemple :
> ./exec
Cesar
J'ai 24 ans
> 

## Ex 3

Introduction aux arguments, aux structures conditionnels et a l'arithmétique

Le but est d'ecrire un programme qui prend en argument :
- un operateur (-, +, /, *)
- un entier
- un deuxieme entier

Le programme doit ecrire sur la sortie standard le resultat de l'operation suivit d'un retour a la ligne.
Exemple :
> ./exec "*" 4 3
12
>

Conseil :
man atoi


## Ex 4

Introduction aux chaines de caracteres et aux boucles

Ecrire un programme qui prend en argument 2 chaines de caractere.
Le programme doit ecrire sur la sortie standard suivi d'un retour a la ligne :
- "oui" si toute les lettres de la deuxieme chaine de caractere sont presentent dans la premier
- "non" dans le cas contraire

Exemple :
> ./exec "bonjour mon ami" "coucou"
non
> ./exec "bonjour mon copain" "coucou jaco"
oui
>

Conseil :
man strlen

## Ex 5

Introduction aux tableaux et a malloc / free

Cet exercice est important pour pouvoir realiser la lecon 3

Le programme va prendre 3 chiffres positifs en arguments
- 1 : la largeur du tableau
- 2 : la hauteur du tableau
- 3 : la valeur de depart qui sera enregistree dans le tableau en X:0 Y:0

Le tableau sera au prealable rempli de 0 a l exception de la case 0, 0 qui prendra la valeur du 3 eme argument.

Par exemple les argument 3, 5, 10, donnerons ce tableau :

10, 0, 0,
0,  0, 0, 
0,  0, 0, 
0,  0, 0, 
0,  0, 0, 

Le but est d'ensuite remplir le tableau en decrementant en Y la valeur initial, puis en incrementant chaque ligne sur les X

Exemple :

10, 0, 0,
9,  0, 0, 
8,  0, 0, 
7,  0, 0, 
6,  0, 0, 

...

10, 11, 12,
9,  10, 11, 
8,  9,  10, 
7,  8,  9, 
6,  7,  8, 

Le prgramme doit afficher le tableau sur la sortie standard puis le resultat de l' addition des valeurs de chaques colonnes
Ici par exemple

10 11 12
9 10 11
8 9 10
7 8 9
6 7 8

40, 45, 50


> ./exec 3 5 10
10 11 12
9 10 11
8 9 10
7 8 9
6 7 8

40 45 50
> 

Conseil `man malloc`, `man free`