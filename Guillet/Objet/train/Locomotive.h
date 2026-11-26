#ifndef Locomotive_h
#define locomotive_h
#include <iostream>
#include <string>
using namespace std;

class Locomotive {
private:
  int nb_wagons;
  int qtt_charbon;
public :
  Locomotive(int nbWagons, int qttCharbon);
  void avancer(int d);
  void compter(int p);
  void ajouter(int a);
  void retirer(int r);
  int get_nb_wagons();
  int get_qtt_charbon();
  ~Locomotive();
};
#endif
