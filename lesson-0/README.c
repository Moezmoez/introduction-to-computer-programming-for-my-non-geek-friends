/*

Il faut imaginer la memoire (la RAM) comme un espace de stockage lineaire, compose de cellule (pour simplifier).

-> Chaque cellule a une adresse et ses adresses se suivent (1, 2, 3, 10000, 10001, ...)
-> Chaque cellule fait la taille d'une octet.

| 1 | 2 | 3 | 4 | 5 | 6 | 7 | ... | 10000 | 10001 ...

Qu'est ce qu'un octet ?

-> Un octet est compose de 8 bits.
-> Un bit peu avoir la valeur 0 ou la valeur 1

Donc la memoire peut etre representee ainsi :

| 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 
|     1    |      2   |     3    |     4    |     5    |     6    |     7    |     8    |     9    | 

Un octet (= 8 bits) va servir a contenir des informations (des valeurs numeriques)

Un octet a lui tout seul ne peut contenir que 2 ^ 8 combinaisons, donc 256.

[Attention, en informatique on ne compte pas a partir de 1, mais de 0, par consequent, un octet pourra contenir un entier allant de 0 a 255]

:) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) 
Question de culture G !

255, ca ne vous rappelle rien ? Vous ne l'avez jamais rencontre sur photoshop ou paint lorsque que vous vouliez rentrer des couleur en RGB ?
Si oui, devinez combien d'octets prendrons en memoire une couler RGB ?
Et une couleur RGBA ?



Les caracteres alphanumeriques de la table ASCII (les caracteres simples, sans accents et caracteres speciaux) sont aussi limites a 255 !

Tapez 'man ascii' dans votre terminal
['man' signifie manuel -> c'est la notice d'une fonctionnalite grosso modo]

On remarque qu'il y a 127 caracteres differents.

// todo rectifier ca et parler des negatifs

Que tirer de cette decouvertes :)  ???

---------------------------------------->
Que les chaines de caracteres prendront en memoire, le meme nombre d'octet que la quantite de craracteres qu'ils contiennent !

Par consequent "Cesar" prendra 5 octets en memoire. "Le Vaudoue" en prendra combien ?

/////////////////////////

Les caracteres alphanumeriques en C, font parti de ce que l'on appelle des "types".
Il faut entendre par type, "type de donnee", chaques type de donnee occupera une place specifique en memoire.
Nous avons deja vu qu'un caractere alphaumerique prend 1 octet en memoire.

Un charactere se note comme cela en C :
*/

char			monCaractere = 'a';

// nous pourrions aussi ecrire

char			monCaractere = 97; // si vous ne comprenez pas -> `man ascii`

/*

Decryptons cette syntaxe !

Ce que nous avons fais ci dessus, c'est ce que l'on appelle une declaration de variable.
De maniere naive, cela signifie que lorsque l'ordinateur lit cette ligne de code, il ecrit dans une cellule de la rame
a une adresse qu'il definit lui meme 97
97 en decimal est egal a 01100001 en binaire.

Le nom "monCaractere" est une appellation de variable. Elle sert au developpeur a acceder a la valeur de cette zone memoire.
Par exemple il pourra plus loin dans le code ecrire

*/

monCaractere = monCaractere + 3; // ce qui donnera 100

/*

Retenez bien qu'ici c'est a la valeur contenu dans la zone memoire que nous avons avons acces
et non pas a son adresse dans la RAM.

Nous y reviendrons, mais si vous pouvez commencer a vous habitier avec cette idee des maintenant
ca serait genial :

monCaracter ici est egal a 97, le developpeur peut en etre certain si il n'a pas fait d'erreur,
cependant, l'adresse memoire de 97, le developpeur ne peut pas la connaitre, cette derniere sera differente a chaque execution
du programme.

Si le developpeur veut pouvoir avoir acces a l'adresse en memoire de la variable il faut la syntaxe de differente :

*/

char *monAdresse;
// l'etoile signifie que la variable mon adresse contiendra l'adresse d'un charactere en memoire

char maLettre = 'j'; //la variable maLettre est on ne sait ou en memoire, cependant on sait qu'elle est eguale a 'j'

monAdresse = &maLettre; // le & permet d'acceder a l'addresse de maLettre. Maintenant, monAdresse contient l'adresse de maLettre

char maLettre2; // on cree une nouvelle variable non instanciee (= pas de valeur) qui contiendra un char

maLettre2 = *monAdresse; // a l'aide de l'etoile, on "dereference" la variable monAdresse. En d'autre terme, on va chercher la valeur a l'adresse de monAdresse, et on la copie dans maLettre2

/*

Question pour un champion !

---
Si je modifie la valeur de maLettre (ex : maLettre = 'm'), est ce que maLettre2 va etre egale a 
- m ?
- j ?


----------------------------------
----------------------------------
----------------------------------


Il existe differents type de donnees,
Chaque type occupe une place differente en memoire,
et par consequent peut contenir des valeurs plus ou moins grandes
Parmis lesquels :

*/

char caractere = 'e'; // 1 caractere = 1 octet = [-128, ..., 127]
/* int entier = 2046; // 1 entier  = 4 octet = [0, ..., ] */
