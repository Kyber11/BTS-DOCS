#ifndef Locomotive_h
#define locomotive_h
#include <iostream>
#include <string>
using namespace std;

class Locomotive {
private:
  int nb_wagons;
  int qtt_charbon;
  int pos;
public :
  Locomotive(int nbWagons, int qttCharbon, int posi);
  void avancer(int d);
  void ajouter(int a);
  int get_nb_wagons();
  int get_qtt_charbon();
  int get_pos();
  ~Locomotive();
};
#endif
