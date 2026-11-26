#include <iostream>
#include "Gps.h"
using namespace std;
int main (int argc, char* argv[]){
  Gps *g = new Gps(0);
  cout << g->get_lattitude() << endl;
  cout << g->get_longitude() << endl;
  delete g;
  return 0;
}
