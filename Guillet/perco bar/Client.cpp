#include "Client.h"
#include "Serveur.h"
#include <iostream>
using namespace std;

void Client::commanderCafe(){
  cout << "2. CLient : ricard maggle " << endl;
}

void Client::payer(){
  cout << "8. Client : tiens la thune" << endl;
  serveur->rendremonaie();
  boire();
}

void Client::boire(){
  cout << "10. glugluglu" << endl;

}
