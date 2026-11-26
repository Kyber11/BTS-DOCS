/**
* auteur : fg
* utilité : première manipulation de chaînes de carctère en C, usage des pointeurs.
* date création : 23/11/2022
* date modification :
*/

#define NB 100
// taille du tableau qui sera allouer dans la RAM

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

bool estPalindrome(char* s);

int main(int argc, char * argv[])
{

    char c = 'b';       // à partir d'ici un octet est réservé dans la RAM. On peut voir à quelle adresse grace à l'opérateur & :
    printf("c vaut '%c', %d, 0x%X. Il réside à l'adresse 0x%X \n", c, c, c, &c);
                        // on aurait pu tout aussi bien écrire "char c = 0x61" ou "char c = 97"
                        // remarque : à la compilation si la valeur vaut 'é', ça plante : "overflow in implicit constant conversion"
                        // c'est normal car le caractère 'é' n'appartient pas à la table ASCII originelle donc il ne tient pas dans un octet.

    char * pt;          // déclaration d'un pointeur sur un octet : Le caractère * indique que la "variable" pt va pouvoir contenir une adresse de char.
                        // remarque on peut écrire sans rien changer : char * pt; ou char* pt; ou char *pt;
                        // autre exemple : int * pi; désigne un pointeur sur un int.
                        // il est intéressant de savoir que *pt désigne la valeur de l'octet pointé par pt.
 //   printf("pt vaut 0x%X et *pt vaut '%c' (valeur imprévisible ou par défaut) \n", pt, *pt);
    pt = &c;            // pt "pointe" vers c : il contient l'adresse de c.
//    printf("pt vaut 0x%X et *pt vaut '%c'\n", pt, *pt);

    char phrase[NB];    // à partir d'ici, un tableau de char d'une longueur de NB octets réside en mémoire RAM.
                        // "phrase" désigne l'adresse du tableau, plus exactement l'adresse du premier octet du tableau.
                        // IL Y A UNE ANALOGIE ENTRE POINTEUR ET TABLEAU
    printf("l'adresse de \"phrase\" : 0x%0X\n", phrase);

    pt = phrase;        // maintenant pt pointe vers le premier octet du tableau (il a la même valeur d'adresse)
    printf("valeur de \"pt\" : 0x%0X\n", pt);

    puts ("saisir une phrase : (ENTRÉE pour finir)");

    // saisie avec une boucle while :
    while (c != 0x0A)       // on attend la fin de la phrase : lorsque le caractère LF (0x0A) sera généré par la touche ENTRÉE
    {
        c = getchar();      // getchar() renvoie la valeur du caractère frappé sur le clavier ; l'instruction range cette valeur dans c.
        *pt = c;            // la valeur de c est rangée à l'adresse pointée par pt quelque par dans le tableau.
        pt++;               // on incrémente pt (on le décale) pour qu'il pointe vers la case suivante du tableau
                            // remarque : pt étant un pointeur sur un char, il sera décalé d'un octet,
                            // si pt était un pointeur sur un int, il serait décalé de 4 octets.
    }

    // même saisie avec une boucle do-while :
    // do {
    //     c = getchar();      // getchar() renvoie la valeur du caractère frappé sur le clavier ; l'instruction range cette valeur dans c.
    //     *pt = c;            // la valeur de c est rangée à l'adresse pointée par pt : dans le tableau.
    //     printf("c vaut 0x%02X\n", c);
    // } while (pt++ && c != 0x0); // ceci est réalisé tant que la touche ENTRÉE n'est pas frappée :
    // on attend la fin de la phrase (le caractère LF (0x0A) qui est généré par la touche ENTRÉE),
    // EN MÊME TEMPS, on incrémente pt pour qu'il pointe vers le caractère suivant dans le tableau dansd la RAM

    // Attention à ne pas dépasser la taille du tableau (NB caractères) !!!
    // Il est quelquefois nécessaire d'ajouter une condition, si on ne veut pas de mauvaise surprise.


    // Il faut maintenant délimiter la fin de la phrase dans le tableau en RAM :
    pt--;       // on peut positionner le pointeur sur le caractère LF pour l'écraser
    *pt = 0;    // on écrase avec le caractère nul : la fin de la phrase est bien délimitée dans le tableau.

    // différents moyen d'afficher la phrase :
//     printf("affichage par printf : \n%s\n", phrase);

//     puts("affichage par puts (la fonction puts ajoute un saut de ligne à la fin) : ");
//     puts(phrase);

    puts("affichage par boucle : ");
    // on initialise pt à l'adresse du tableau
    pt = phrase;
    // tant que la valeur pointée n'est pas nulle, on affiche la valeur *pt et on décale pt (on l'incrémente)
    while(*pt)
    {
        putchar(*pt);
        pt++;
    }

    puts("");

    // EXERCICE : afficher la phrase en commençant par la fin
    // SOLUTION :
    // on décale pt à la fin de la phrase :
    pt = phrase;
    while (*pt != 0) pt++;          // peut être vérifié avec printf("0x%X\n", pt);
    // et on affiche en remontant :
    while (pt >= phrase)
    {
        putchar(*pt);
        pt--;
    }

    puts("");

    // estPalindrome((char *)phrase);
    if (estPalindrome(phrase))
        printf("palindrome !!!!\n");
    else
        printf("c'est pas un palindrome.\n");

    // estPalindrome est une fonction qui retourne vrai si la saisie est un palidrome (par exemple "kayak"), faut sinon.

    // une amélioration peut permettre de vérifier si une PHRASE est un palindrome.
    // indication il faut s'affranchir des espaces (caractère 0X20)
    // exemple : "la mariee ira mal", "mon nom", "engage le jeu que je le gagne".

    // on peut perfectionner en enlevant le point final (s'il existe) car il empèche tout calcul.
    // par exemple "ici." n'est pas un palindrome, mais "ici" oui.
    // on peut aussi perfectionner en s'affranchissant de la casse (majuscule/minuscule) Ici et ici.
    // grace aux fonctions tolower(int c) ou toupper(int c) de la librairie "ctype.h" (#include <ctype.h>)

    // on peut chercher à prendre en compte les accents (c'est plus difficile, mais fesable).

    puts("");

    return 0;

}

bool estPalindrome(char* s)
{

  char*deb = s;
  char*fin = s;

  // printf("fonction, deb : %c, fin : %c\n", *deb, *fin);

  while(*fin) fin++;

  fin--;

  while(fin > deb)
  {
    while (!isalpha(*fin)) fin--;
    while (!isalpha(*deb)) deb++;

    // printf("adr deb : %X adr fin : %x\n", deb, fin);

    // if (*deb ==0x20);
    // {
    //   continue;
    // }
    //
    // if (*fin ==0x20);
    // {
    //   continue;
    // }

    printf("adr deb : %X adr fin : %x\n", deb, fin);

    // printf("boucle, deb : %c, fin : %c\n", *deb, *fin);

    if(*deb != *fin)
      return false;


    fin--;
    deb++;

  }

  return true;
}
