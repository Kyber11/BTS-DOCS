#include <iostream>
#include "Requin.h"
using namespace std;

int main(int argc, char const *argv[])
{


	Requin * requin;


	requin = new Requin();

	float mass_origine = requin->get_masse();
	int dents_origine = requin->get_nbDents();

	cout << "----------------------------------------------------------------" << endl;

	cout << "le requin a " << requin->get_nbDents() << " dents" << endl;
	cout << "le requin pèse " << requin->get_masse() << " Kg" << endl;
	cout << "GGGGGRRRRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;

	cout << "----------------------------------------------------------------" << endl;

	requin->nager();
	cout << "le requin a perdu " << mass_origine - requin->get_masse() << " Kg en nageant" << endl;
	mass_origine-= requin->get_masse();
	cout << "GGGGGRRRRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;

	cout << "----------------------------------------------------------------" << endl;

	int m=50;
	int d=4;
	dents_origine-=d;
	requin->manger(m);
	cout << "le requin a manger et a pris " << m << " kg en mangeant" << endl;
	cout << "il a perdu " << d << " dents et en a donc " << dents_origine << endl;
	cout << "GGGGGRRRRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;

	cout << "----------------------------------------------------------------" << endl;

	int rege=3;
	requin->regeneration(rege);
	cout << "le requin a fait pousser " << rege << " dents et en a donc " << dents_origine+rege << endl;

	cout << "----------------------------------------------------------------" << endl;

	delete requin; 
	return 0;
}