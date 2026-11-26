#include "Truc.h"
#include <string>
#include <iostream>
using namespace std;

int Truc::get_i()
{
  return i;
}

float Truc::get_z()
{
  return z;
}

string Truc::get_truc()
{
  return truc;
}

Truc::Truc(string trucG)
{
  truc = trucG;
  cout << "je truque des choses" << endl;
}

Truc::~Truc()
{

}
