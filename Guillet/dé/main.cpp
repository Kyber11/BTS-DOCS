#include "de.h"
#include <iostream>
#include <ctime>
using namespace std;
int main (int argc, char* argv[])
{
  srand (time(NULL));

  De*de = new De(10);

  cout << "valeur à la création : " << de->get_valeur() << endl;
  de->lancer();
  cout << "valeur après lancement : "<< de->get_valeur() << endl;

  delete de;

  return 0;
}
