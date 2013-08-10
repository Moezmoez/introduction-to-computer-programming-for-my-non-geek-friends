# lesson 2

Le but ici est de developper un programme capable de generer des images, et de les enregistrer dans  un fichier.

Nous allons inventer notre propre format d'image, le .jmc .
Ces images seront affichable par un le programme ci-join "jmcReader"

### step 1

Dans un premier temps nous allons faire un programme qui prend en argument 2 paramettre la largeur et la hauteur en pixel de l'image desisree.

L'image de la taille indique sera une image noir.

Le noir en RGBA = 0, 0, 0

Je rappelle la composition des couleurs en RGB :

Red [0, 255]
Green [0, 255]
Blue [0, 255]

Les images seront enregistree dans un fichier .jmc qui sera compose ainsi :
3 3 --> largeur x hauteur en pixel
0,0,0 0,0,0 0,0,0 
0,0,0 0,0,0 0,0,0 
0,0,0 0,0,0 0,0,0 

Exemple d une image de 3x3 avec le pixel central blanc et les contour magenta :
3 3
255,0,255 255,0,255 255,0,255
255,0,255 255,255,255 255,0,255
255,0,255 255,0,255 255,0,255

Pour tester vos images :
> ./reader nomdelimage.jmc

### step 2

Faire un programme qui genere une image de la taille desiree qui alterne 2 couleurs tout les X pixel sur la haute (une image rayee quoi)

### step 3

Faire un programme capable de dessiner des cercles

https://banu.com/blog/7/drawing-circles/

### step 4

Creer un generateur d'image de feu.

http://lodev.org/cgtutor/fire.html