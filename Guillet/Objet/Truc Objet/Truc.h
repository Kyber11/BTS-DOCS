#ifndef Truc_h
#define Truc_h

#include <string>
using namespace std;

class Truc
{
private:
  int i;
  float z;
  string truc;
public:
  Truc(string trucG);
  void truquer(int b);
  int get_i();
  float get_z();
  string get_truc();
  ~Truc();
};

#endif
