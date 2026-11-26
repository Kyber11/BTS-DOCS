#include <iostream>
#include "Gps.h"
using namespace std;

int main (int argc, char* argv[]){

  Gps *g = new Gps((char *)"$GPGGA,135442.367,47.38501013970953,N, 6.853872227314253,E,1,12,1.0,0.0,M,0.0,M,,*63");

  cout << g->get_lattitude() << endl;
  cout << g->get_longitude() << endl;
  cout << g->get_heure() << endl;
  cout << g->get_minute() << endl;
  cout << g->get_seconde() << endl;

  delete g;
  return 0;
}
