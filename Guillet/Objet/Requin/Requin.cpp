#include "Requin.h"


unsigned short Requin::get_nbDents(){
	return nbDents;
}

float Requin::get_masse(){
	return masse;
}


void Requin::nager() {
	masse -= 50;
}


void Requin::manger(float m) {
	masse += m;
}

void Requin::regeneration(int r) {
	nbDents+=r;
}



Requin::Requin() {
	nbDents = 400;
	masse = 1000;
}




Requin::~Requin() {

}
