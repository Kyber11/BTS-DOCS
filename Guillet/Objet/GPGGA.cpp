/**
* auteur : fg
* utilité :
	manipulation de chaînes (tableaux de caractères) en langage C : dechiffrer une trame GPGGA

	plusieurs fonctions pratiques à utiliser :
		strlen pour calculer la longueur d'une chaîne.
		strcpy pour copier une chaîne dans une autre.
		strcat pour concaténer 2 chaînes.
		strcmp pour comparer 2 chaînes.
		strchr pour rechercher un caractère.
		strpbrk pour rechercher le premier caractère de la liste.
		strstr pour rechercher une chaîne dans une autre.
		sprintf pour écrire dans une chaîne.

    à consulter : https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/7672681-manipulez-du-texte-avec-les-chaines-de-caracteres
* date création : 16/11/2025
* date modification :
*/

#define NB 100

#include <stdio.h>
#include <string.h>

// struct __GPSTime gpsTime;

char Checksum(char * trame);

int main(int argc, char * argv[])
{

// La norme NMEA 0183 est une spécification pour la communication entre équipements marins, dont les équipements GPS.
// Elle est définie et contrôlée par la National Marine Electronics Association, association américaine de fabricants d'appareils électroniques maritimes,
// basée à Severna Park au Maryland (États-Unis d'Amérique).
// Il existe plus d'une trentaine de trames NMEA différentes. Chaque trame a sa syntaxe propre mais selon le cas,
// elles peuvent ou doivent se terminer, après le caractère '*', par une somme de contrôle. Ce mécanisme permet de vérifier que la trame n'a pas été altérée lors de sa transmission

// La trame GGA (Global Positioning System Fix Data) est une trame de type NMEA très courante car
// elle fait partie de celles qui sont utilisées pour connaître la position courante d'un récepteur GPS.
//


// exemple de trame $GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E :
// signification :
// $GPGGA       : Type de trame
// 064036.289   : Trame envoyée à 06 h 40 min 36 s 289 (heure UTC)
// 4836.5375,N  : Latitude 48,608958° Nord = 48° 36' 32.25" Nord
// 00740.9373,E : Longitude 7,682288° Est = 7° 40' 56.238" Est
// 1            : Type de positionnement (le 1 est un positionnement GPS)
// 04           : Nombre de satellites utilisés pour calculer les coordonnées
// 3.2          : Précision horizontale ou HDOP (Horizontal dilution of precision)
// 200.2,M      : Altitude 200,2, en mètres
// ,,,,,0000    : D'autres informations peuvent être inscrites dans ces champs
// *            : séparateur de checksum
// 0E           : Somme de contrôle de parité, un simple XOR sur les caractères entre $ et *


	// L'objectif du tp est de réliser un programme qui à partir d'un trame GPGGA donne
	// l'heure UTC où la trame a été envoyèe,
	// la position du récepteur,
	// le nombre de satellites utilisés,
	// et la hauteur du récepteur.

	// on donne une trame exemple: :
	char trame_GPGGA[] = "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E";

	printf("retour de Checksum : %X\n", Checksum(trame_GPGGA));
    // "$GPGGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    // $GPGGA,122755.095,4849.7970,N,00134.7688,W,1,03,2.3,-48.0,M,48.0,M,,0000*54
    // $GPGGA, 201815.752,4355.343, N, 00208.628, E, 1,12,1.0,0.0, M, 0.0, M,,*64
    // $GPGGA,073727.745,4714.301,N,00600.761,E,1,12,1.0,0.0,M,0.0,M,,*6C
    // il est possible de fabriquer d'autres trames de type NMEA sur le site nmeagen.org

	// Pour isoler l'heure on recherche de la première position du caractère ',' et on
	// recopie les caractères jusqu'à la deuxième position de ',' dans le tableau de caractères heureEnvoie

	// déclaration du tableau (suffisament grand)
	char heureEnvoie[15] = {0};
	// recherche de position de ','
	char * pos = strchr(trame_GPGGA, ',');
	// décalage sur le premier caractère concernant l'heure
	pos++;
	// recopie des caractères dans heureEnvoie
	int i = 0;
	while (*pos != ',')
	{
		heureEnvoie[i] = *pos;
		i++;
		pos++;
	}
	// ajout du caractère null
	heureEnvoie[i] = '\0';
	printf("la partie réservée à l'heure est \"%s\"\n", heureEnvoie);



	char latitude[15] = {0};

	pos++;
	// recopie des caractères dans latitude
	i = 0;
	while (*pos != ',')
	{
		latitude[i] = *pos;
		i++;
		pos++;
	}



	char N[2] = {0};

	pos++;
	// recopie des caractères dans N
	i = 0;
	while (*pos != ',')
	{
		N[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée à la latitude est \"%s,%s\"\n", latitude, N);



	char longitude[15] = {0};

	pos++;
	// recopie des caractères dans longitude
	i = 0;
	while (*pos != ',')
	{
		longitude[i] = *pos;
		i++;
		pos++;
	}



	char E[2] = {0};

	pos++;
	// recopie des caractères dans E
	i = 0;
	while (*pos != ',')
	{
		E[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée à la longitude est \"%s,%s\"\n", longitude, E);



	char type[2] = {0};

	pos++;
	// recopie des caractères dans type
	i = 0;
	while (*pos != ',')
	{
		type[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée au type de positionnement est \"%s\"\n", type);



	char nombre_satellite[3] = {0};

	pos++;
	// recopie des caractères dans nombre_satellite
	i = 0;
	while (*pos != ',')
	{
		nombre_satellite[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée au nombre de satellite est \"%s\"\n", nombre_satellite);




	char precision_horizontale[10] = {0};

	pos++;
	// recopie des caractères dans precision_horizontale
	i = 0;
	while (*pos != ',')
	{
		precision_horizontale[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée à la précision horizontale est \"%s\"\n", precision_horizontale);



	char altitude[10] = {0};

	pos++;
	// recopie des caractères dans altitude
	i = 0;
	while (*pos != ',')
	{
		altitude[i] = *pos;
		i++;
		pos++;
	}

	char Unite[2] = {0};

	pos++;
	// recopie des caractères dans altitude
	i = 0;;
	while (*pos != ',')
	{
		precision_horizontale[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée à la précision horizontale est \"%s\"\n", precision_horizontale);

	while (*pos != ',')
	{
		Unite[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée à l'altitude est \"%s,%s\"\n", altitude, Unite);

	char parametre_supp_1[10] = {0};

	pos++;
	// recopie des caractères dans altitude
	i = 0;
	while (*pos != ',')
	{
		parametre_supp_1[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée au paramètre supplémentaire 1 est \"%s\"\n", parametre_supp_1);

	char parametre_supp_2[10] = {0};

	pos++;
	// recopie des caractères dans altitude
	i = 0;

	while (*pos != ',')
	{
		parametre_supp_2[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée au paramètre supplémentaire 2 est \"%s\"\n", parametre_supp_2);

	char parametre_supp_3[10] = {0};

	pos++;
	// recopie des caractères dans altitude
	i = 0;

	printf("la partie réservée au paramètre supplémentaire 3 est \"%s\"\n", parametre_supp_3);

	char parametre_supp_4[10] = {0};

	pos++;
	// recopie des caractères dans altitude
	i = 0;

	while (*pos != '*')
	{
		parametre_supp_4[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée au paramètre supplémentaire 4 est \"%s\"\n", parametre_supp_4);

	char checksum[3] = {0};

	pos++;
	// recopie des caractères dans checksum
	i = 0;

	while (*pos != '\0')
	{
		checksum[i] = *pos;
		i++;
		pos++;
	}

	printf("la partie réservée au checksum est \"%s\"\n", checksum);

// À finaliser (détail de l'heure)

// lorsque toutes les données ont été extraites, les ranger dans une structure de type struct :
	// gpsTime.tm_ms = printf("%s%s", heureEnvoie[6], heureEnvoie[7]);
	// gpsTime.tm_sec = printf("%s%s", heureEnvoie[4], heureEnvoie[5]);
	// gpsTime.tm_min = printf("%s%s", heureEnvoie[2], heureEnvoie[3]);
	// gpsTime.tm_hour = printf("%s%s", heureEnvoie[0], heureEnvoie[1]);

// pour information, on trouve sur internet des logiciels libres comportant les structures suivantes :

    // struct __GPSTime
    // {
    //     short tm_ms;
    //     short tm_sec;
    //     short tm_min;
    //     short tm_hour;
    // } typedef GPSTime;
		//
    // struct __GPGGA
    // {
    //     GPSTime time;
    //     double latitude;
    //     double longitude;
    //     short fixQuality;
    //     short numSatellites;
    //     double horizontalDilution;
    //     double altitude;
    //     double heightOfGeoid;
    // } typedef GPGGA;

	return 0;
}

char Checksum(char * trame)
{
	char resultat = 0;
	char * pt = trame;
	pt++;
	while (*pt != '*')
	{
		char c = *pt;
		// resultat = ~resultat xor (*pt);
		resultat = (resultat & *pt) | (~resultat & ~c);
		pt++;
	}

	return resultat;
}
