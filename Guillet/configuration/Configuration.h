#ifndef Configuration_h
#define Configuration_h

#include <map>
#include <string>

using namespace std;

class Configuration{

  private :

  map<string, string> config;
  bool valide;
  bool estCommentaire(string str);
  string getCle(string str);
  string getVal(string str);
  string enleverBlanc(string str);
  bool estVide(string str);

  public:

  Configuration(string monFichier);
  ~Configuration();
  bool estValide();
  int getInt(string cle);
  long getLong(string cle);
  long getDouble(string cle);
  float getFloat(string cle);
  string getStringVal(string cle);
  bool estPresent(string cle);

};
#endif
