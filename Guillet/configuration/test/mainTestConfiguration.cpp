#include <iostream>
using namespace std;

#include "Configuration.h"

int main()
{
  
	// exemple de variables dont un programme peut avoir besoin :
	int vitesseRs;
	string adrBase;
	string userBd;
	string pwdBd;
	short portBd;
	bool cle4;
	bool cle5;
	float cle1;
	long cle8;
	
	Configuration *config = new Configuration("config.conf");

	if (config->estValide())
	{
		// regarde si "vitesseDeTransfert" est une clé présente dans le fichier config.conf
		if (config->estPresent("clé4"))
			cout << "la clé \"clé4\" est présente" << endl;
		else
			cout << "la clé \"clé4\" est absente" << endl;
		
		// obtension d'une valeur sous forme de string
		if (config->estPresent("adresseServeurBD"))
			adrBase = config->getString("adresseServeurBD");
		
		// obtension d'une valeur sous forme de string
		if (config->estPresent("user"))
			userBd = config->getString("user");
		
		// obtension d'une valeur sous forme de string
		if (config->estPresent("pwd"))
			pwdBd = config->getString("pwd");
				
		// obtension d'un entier
		if (config->estPresent("vitesseDeLaLiaison"))
			vitesseRs = config->getInt("vitesseDeLaLiaison");

			// obtension d'un long
		if (config->estPresent("Clé8"))
		  cle8 = config->getLong("Clé8");
		
		// obtension d'un flottant
		if (config->estPresent("clé1"))
			cle1 = config->getFloat("Clé1");
		
		
	}
	
	delete config;
	

	// À partir d'ici les variables du débuts sont initialisées
	cout << "valeur liée à adresseServeurBD : " << adrBase << endl;
	cout << "valeur liée à vitesseDeLaLiaison : " << vitesseRs << endl;
	cout << "valeur liée à user : " << userBd << endl;
	cout << "valeur liée à pwd : " << pwdBd << endl;
	cout << "valeur liée à Clé8 : " << cle8 << endl;
	cout << "valeur liée à clé1 : " << cle1 << endl;
	
	return 0;
}
