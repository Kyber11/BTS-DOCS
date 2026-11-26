/**
* auteur : f guillet
* utilité : vérifie si un déplacement d'échec est valide sur un échiquier vide.
* remarque : pour afficher une image depuis le terminal, utiliser la commande xzgv "image.png"
* date création : 26/05/2023
* exercice : 
* la fonction "bool deplacementValide(Piece p, Case c)" permet de vérifier si un déplacement est valide pour une tour.
* on demande de compléter cette fonction pour les autres pièces : fou, dame, pion, roi et cavalier
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// définition d'une case
typedef struct
{
    char col ;  // de 'a' à 'h'
    char ran ;   // de '1' à '8'
} Case;

// définition d'une pièce sur une case
typedef struct
{
    char col ;  // de 'a' à 'h'
    char ran ;   // de '1' à '8'
    char type;      // R(oi), D(ame), T(our), F(ou), C(avalier), P(ion)
    char couleur;   // B(lanc) ou N(oir)
} Piece ;

// retourne une piece à partir d'un texte ayant une valeur ressemblant à "PBa2" (Pion Blanc en a2)
Piece poserPiece(char * texte);

// retourne un string ressemblant à "Pion Blanc en a2" en fonction de la pièce.
string afficherPiece(Piece p);

// retourne un string ressemblant à "a2" en fonction de la case.
string afficherCase(Case c);

// retourne vrai ou faux selon que la piece p peut se rendre sur la case c.
bool deplacementValide(Piece p, Case c);

// caseValide : ces 2 fonctions retournent vrai si la case est une case de l'échiquier.
bool caseValide(Case c);
bool caseValide(char c, char l);

// retourne une case à partir d'un texte ayant une valeur ressemblant à "e4"
Case creerCase(char * texte);


int main(int argc, char * argv[])
{
    cout << "saisir une pièce (2 majuscules) :" << endl;
    cout << "R(oi), D(ame), T(our), F(ou), C(avalier), P(ion), et B(lanc) ou N(oir)" << endl;
    cout << " et saisir la case (en minuscule, de a1 à h8)" << endl;
    cout << " exemple : RNe8 signifie roi noir en e8" << endl;
    
    char texte[5] = {0,0,0,0,0};
    scanf("%s", &texte);
    
    Piece p;
    
    p = poserPiece(texte);
    cout << afficherPiece(p) << endl;
    
    cout << "saisir la case de destination de la pièce (en minuscule, de a1 à h8)" << endl;
    memset(texte, 0, sizeof(texte));
    scanf("%s", &texte);

    Case c = creerCase(texte);
    cout << afficherCase(c) << endl;
    
    if (!caseValide(c))
    {
        cout << "case invalide" << endl;
        return 0;
    }
    
    if(deplacementValide(p, c))
        cout << "déplacement autorisé" << endl;
    else
        cout << "déplacement interdit" << endl;
    return 0;
    
}

// retourne un string ressemblant à "Pion Blanc en a2" en fonction de la pièce.
string afficherPiece(Piece p)
{
    string message = "";
    switch (p.type)
    {
        case 'R': message = "Roi "; break;
        case 'D': message = "Dame ";break;
        case 'T': message = "Tour ";break;
        case 'F': message = "Fou ";break;
        case 'C': message = "Cavalier ";break;
        case 'P': message = "Pion ";break;
    }  
    
    if (p.couleur == 'B')
        message = message + "Blanc ";
    else
        message = message + "Noir ";
    message = message + "en " + p.col + p.ran + ".";
    return message;
}


// retourne vrai ou faux selon que la piece p peut se rendre sur la case c.
bool deplacementValide(Piece p, Case c)
{
    // si la case c est en dehors de l'échiquier, le dépacement est faux
    if (!caseValide(c))
        return false;
    // si la piece p se trouve sur la case c, le déplacement est faux
    if (p.col == c.col && p.ran == c.ran)
        return false;
    
    // tour
    if (p.type == 'T')
    {
        // le déplacement est autorisé si la colonne ou la rangée ne change pas
        if ((p.col == c.col && p.ran != c.ran) || (p.col != c.col && p.ran == c.ran))
            return true;
        else
            return false;
    }
    
    // fou 
    if (p.type == 'F')
    {
        if ((p.col - c.col) == (p.ran - c.ran) || (p.col - c.col) == -(p.ran - c.ran))
            return true;
        else
            return false;
    }

    // dame
    if (p.type == 'D')
    {
        // le déplacement est autorisé si la colonne ou la rangée ne change pas
        if ((p.col == c.col && p.ran != c.ran) || (p.col != c.col && p.ran == c.ran) or (p.col - c.col) == (p.ran - c.ran) || (p.col - c.col) == -(p.ran - c.ran))
            return true;
        else
            return false;
    }

    
    // pion
    if (p.type == 'P')
    {
        if (p.col != c.col && p.ran == c.ran)
            return true;
        else
            return false;
    }

    
    // roi 
    
    // cavalier

    return true;
}


bool caseValide(Case c)
{
    if (c.ran < '1' or c.ran > '8')
        return false;
    if (c.col < 'a' or c.col > 'h')
        return false;
    return true;
}
bool caseValide(char c, char l)
{
    Case _case;
    _case.col = c;
    _case.ran = l;
    return caseValide(_case);
}

// retourne une piece à partir d'un texte ayant une valeur ressemblant à "PBa2" (Pion Blanc en a2)
Piece poserPiece(char * coordo)
{
    Piece p;
    p.col = coordo[2];  // de 'a' à 'h'
    p.ran = coordo[3];   // de '1' à '8'
    p.type = coordo[0];      // Roi, Dame, Tour, Fou, Cavalier, Pion
    p.couleur = coordo[1];   // Blanc ou Noir
    return p;
}

// retourne une case à partir d'un texte ayant une valeur ressemblant à "e4"
Case creerCase(char * texte)
{
    Case c;
    c.col = texte[0];
    c.ran = texte[1];
    return c;
    
}

// retourne un string ressemblant à "a2" en fonction de la case.
string afficherCase(Case c)
{
    string message = "";
    message = message + c.col + c.ran;
    return message;
}
