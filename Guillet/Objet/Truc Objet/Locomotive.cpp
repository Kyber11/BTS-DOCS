#include <iostream>
#include "Locomotive.h"
#include <string>

Locomotive::Locomotive(int nbWagons, int qttCharbon, int posi)
{
  nb_wagons=nbWagons;
  qtt_charbon=qttCharbon;
  pos=posi;
}

void Locomotive::avancer(int d) {
  pos += 1;
}

void Locomotive::ajouter(int a) {
 qtt_charbon += a;
}

int Locomotive::get_nb_wagons() {
  return nb_wagons;
}

int Locomotive::get_qtt_charbon() {
  return qtt_charbon;
}

int Locomotive::get_pos(){
  return pos;
}

Locomotive::~Locomotive() {}
