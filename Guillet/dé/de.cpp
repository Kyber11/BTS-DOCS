#include "de.h"
#include <cstdlib>
#include <random>

De::De(int nombreface){
  nbface=nombreface;
  valeur=rand() % nbface + 1;
}

unsigned int De::get_valeur(){
  return valeur;
}

int De::get_nbface(){
  return nbface;
}

void De::lancer(){
  valeur=rand() % 6 + 1;
}

De::~De(){}
