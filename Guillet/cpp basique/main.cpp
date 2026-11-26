/*
auteur:Armand
date:22/09/2025
utilite: tp_1 Exercice basique C++
*/
#include <iostream>
#include <ctime>
using namespace std;
int main (int argc, char* argv[])
{
	int h, m, s, j, mi, a;
	/*
	//question 1et 2-----------------------------------------------
	int v;
	cout << "saisir un nombre " << endl;
	cin >> v;
	cout << "vous avez saisi " << v << endl;


	char c = 'a';

	cout << "c vaut " << c << endl;
	cout << "c vaut " << int(c) << endl;

	c = 98;
	cout << "c vaut " << c << endl;

	char phrase[] = "voila une chaine de caractere un peu longue";
	cout << phrase << endl;
	cout << "nb de caractères : " << sizeof(phrase) << endl;
	cout << (char) 0x23 << endl;
*/
	// question	3--------------------------------------------------
/*
	int v;
	cout << "saisir un nombre " << endl;
	cin >> v;
	cout << "vous avez saisi " << v << endl;
	if (v*10 > 100)
	{
		cout << "superieur"<< endl;
	}
	if (v*10 < 100)
	{
		cout <<"inferieur"<< endl;
	}
*/
	//question 4----------------------------------------------------
/*for (int i=0; i<=3000; ++i){
		cout << i << endl;
	}
*/
	//question 5----------------------------------------------------
/*
	for (int i=0; i<=400; i+=2){
		cout << i << endl;
	}
	cout <<'----------------------------' endl;
	for (int i=1; i<=401; i+=2){
		cout << i << endl;
	}
*/
	//question 6-----------------------------------------------------
	/*
	while (true){
				int valeur = 0 ;
				cout<<"menu :"<< endl;
				cout<<"pour choisir l\'option 1 tapper 1"<< endl;
				cout<<"pour choisir l\'option 2 tapper 2"<< endl;
				cout<<"pour choisir l\'option 3 tapper 3"<< endl;
				cout<<"pour sortir tapper 0"<< endl;
				cin >> valeur;
					if(valeur==1)
					{
						cout<<"l\'option choisit est 1"<<endl;
					}
					else if(valeur==2)
					{
						cout<<"l\'option choisit est 2"<<endl;
					}
					else if(valeur==3)
					{
						cout<<"l\'option choisit est 3"<<endl;
					}
					else if(valeur==0)
					{
						return 0;
					}
					else {
						cout<<"entrer une valeur posible"<< endl;
					}
	}
	*/
	//question 7-------------------------------------------------------
	/*
	int longueur =0 ;
	int largeur = 0;
	cin >> longueur;
	cin >> largeur;
	int resultat= longueur*largeur;
	cout << "L\'air est donc de "<< resultat << endl;
	*/
	//question 8 -------------------------------------------------------

	time_t dateActuelle = time(NULL);
	cout << "sec depuis 70 :" << dateActuelle << endl;
	struct tm *maintenant = localtime(&dateActuelle);

			int anneeanniv;
			cout << "année naissance : " << endl;
			cin >> anneeanniv;
			maintenant->tm_year=anneeanniv-1900;

			int moisanniv;
			cout << "mois naissance : " << endl;
			cin >> moisanniv;
			maintenant->tm_mon = moisanniv+1;

			int jouranniv;
			cout << "jour naissance : " << endl;
			cin >> jouranniv;
 			maintenant->tm_mday = jouranniv;


			int heureanniv;
			cout << "heure naissance : " << endl;
			cin >> heureanniv;
			maintenant->tm_hour=heureanniv;

			int minuanniv;
			cout << "minute naissance : " << endl;
			cin >> minuanniv;
			maintenant->tm_min=minuanniv;

			s= maintenant->tm_sec;

			time_t dateAnniv = mktime(maintenant);
			cout << "mktime(maintenant); : " << dateAnniv << endl;

// les années sont données en comptant à partir de 1900 = 0
cout << "------------------------------------------------ "<< endl;
cout << "sec depuis naissance :" << dateAnniv << endl;
cout << "années :"<< anneeanniv << endl;
cout << "mois :"<< moisanniv << endl;
cout << "jour :"<< jouranniv << endl;
cout << "heure :"<< heureanniv << endl;
cout << "minutes :"<< minuanniv << endl;

	// question 9
	return 0;
}
