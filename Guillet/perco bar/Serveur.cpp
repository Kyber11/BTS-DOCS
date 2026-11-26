#include "Serveur.h"
#include "Client.h"
#include "Barman.h"
#include <iostream>
using namespace std;

float Serveur::rendremonaie(){
  cout << "9. Serveur : voila la monaie" << endl ;
  return 0;
}

void Serveur::servircafe(){
  cout << "7. Serveur : café servit" << endl;
  client->payer();
}

void Serveur::demarrerfonctionnement(){
  cout << "1. Serveur : tu veux quoi slp " << endl;
  client->commanderCafe();
  barman->preparercafe();
}
