#include "Barman.h"
#include "Percolateur.h"
#include "Serveur.h"
#include <iostream>
using namespace std;

void Barman::preparercafe(){
  cout << "3. Serveur : tout de suite Mr" << endl;
  perco->lancerpreparation();
  preparerplateau();
}

void Barman::preparerplateau(){
  cout << "6. Barman : le plateau est ready mon gaillard" << endl;
  serveur->servircafe();
}
