#include "Gps.h"

float Gps::get_lattitude() {
  return lattitude;
}

float Gps::get_longitude() {
  return longitude;
}

Gps::Gps(char * tGPGGA){
  trameGPGGA=tGPGGA;
}

Gps::~Gps(){}
