#include "Gps.h"
#include <cstring>
#include <cstdlib>

float Gps::get_lattitude() {
  return lattitude;
}

float Gps::get_longitude() {
  return longitude;
}

short Gps::get_heure(){
  return heure;
}

short Gps::get_minute() {
  return minute;
}

float Gps::get_seconde() {
  return seconde;
}

Gps::Gps(char * tGPGGA){
  // déclaration du tableau (suffisament grand)
	char heureEnvoie_char[15] = {0};
	// recherche de position de ','
	char * pos = strchr(tGPGGA, ',');
	// décalage sur le premier caractère concernant l'heure
	pos++;
	// recopie des caractères dans heureEnvoie
	int i = 0;
	while (*pos != ',')
	{
		heureEnvoie_char[i] = *pos;
		i++;
		pos++;
	}
  //récup heureenvoie complet et le mettre dans heure puis minute puis seconde











	// ajout du caractère null
	heureEnvoie_char[i] = '\0';

	char latitude_char[15] = {0};

	pos++;
	// recopie des caractères dans latitude
	i = 0;
	while (*pos != ',')
	{
		latitude_char[i] = *pos;
		i++;
		pos++;
	}

  lattitude = atof(latitude_char);

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

	char longitude_char[15] = {0};

	pos++;
	// recopie des caractères dans longitude
	i = 0;
	while (*pos != ',')
	{
		longitude_char[i] = *pos;
		i++;
		pos++;
	}

  longitude = atof(longitude_char);

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

	while (*pos != ',')
	{
		Unite[i] = *pos;
		i++;
		pos++;
	}

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

	char parametre_supp_3[10] = {0};

	pos++;
	// recopie des caractères dans altitude
	i = 0;

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
}

Gps::~Gps(){}
