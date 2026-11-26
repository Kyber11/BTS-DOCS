#include "Configuration.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

Configuration::Configuration(string monFichier){

  bool estValide=false;
  string cle;
  string valeur;

  ifstream fichier(monFichier, ios::in);  // on ouvre en lecture


  if(fichier)
  {
    string ligne;
    while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
    {
      cout << ligne << endl;  // on l'affiche
    }
    fichier.close();
  }
  else
    cout << "Impossible d'ouvrir le fichier !" << endl;

}

string Configuration::getStringVal(string cle){
  return config[cle];
}

float Configuration::getFloat(string cle){
  string valeur= config[cle];
  return atof(valeur.c_str());
}

long Configuration::getDouble(string cle){
  string valeur= config[cle];
  return atoi(valeur.c_str());
}

long Configuration::getLong(string cle){
  string valeur= config[cle];
  return atol(valeur.c_str());
}

int Configuration::getInt(string cle){
  string valeur= config[cle];
  return atoi(valeur.c_str());
}


bool Configuration::estPresent( string cle){
  bool result;
  map<string, string >::iterator it;
  for (it = config.begin(); it != config.end(); it++){
      if (it->first == cle){
        result = true;
      }
      else result = false;
    }
  return result;
}

bool Configuration::estValide() {
  if (config.size()!=0){
    return true;
  }
  else return false;
  //  alternative plus complexe : return (config.size() != 0 ? true : false)

}

string Configuration::enleverBlanc(string str){
  while (str[0]==0x20 || str[0]==0x09){
     str.erase(0, 1);
  }
  while (str[str.size()-1]==0x20 || str[str.size()-1]==0x09){
     str.erase(str.size()-1, 1);
   }
  return str;
}


bool Configuration::estVide(string str){
  str = enleverBlanc(str);
  return str.empty();
}


bool Configuration::estCommentaire(string str){
  str = enleverBlanc(str);
  return (str[0]==';' || str[0]=='#');
}


string Configuration::getCle(string str){
  str = enleverBlanc(str);
  string newstr;
  int i=0;
  while (str[i] != '='){
    newstr.push_back(str[i]);
    i++;
  }
  str=newstr;
  str = enleverBlanc(str);
  return str;
}


string Configuration::getVal(string str){
  str= enleverBlanc(str);
  string newstr;
  int i= str.size()-1;
  while (str[i]!= '='){
    newstr.insert(0, 1, str[i]);
    i--;
  }
  str=newstr;
  str=enleverBlanc(str);
  return str;
}


Configuration::~Configuration(){}
