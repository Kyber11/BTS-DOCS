#include <iostream>
//#include "Truc.h"
#include "Locomotive.h"
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
//------------------Truc-----------------------------------------------
  // Truc* truc;
  // truc= new Truc("jêtre content");
  //
  // cout << truc->get_i() << endl;
  // cout << truc->get_z() << endl;
  // cout << truc->get_truc() << endl;
  //
  // delete truc;

//------------------Locomotive----------------------------------------
  Locomotive* loco;
  loco= new Locomotive(8, 4, 0);

  int charbonInit=loco->get_qtt_charbon();
  int posInit=loco->get_pos();

  cout << "le train a "<< loco->get_nb_wagons() << " wagons " << endl;
  cout << "il a aussi "<< loco->get_qtt_charbon() << " tonnes de charbons " << endl;
  cout << "il est en position " << loco->get_pos() << endl;

  int distance = 3;
  int consommation = 2;

  loco->avancer(distance);
  posInit += distance;
  cout << "il a avancé de "<< distance <<  "\n" <<"il est donc à la position " << posInit<< endl;
  charbonInit -= consommation;
  cout << "cela a consommé " << consommation << " de tonnes de charbons, il en reste donc " << charbonInit << endl;



  delete loco;

  return 0;
}
