#include <iostream>
#include <string>
#include <map>
using namespace std;

// ---------------------------LES FONCTIONS---------------------------
string enleverBlanc(string str){
  while (str[0]==0x20 || str[0]==0x09){
     str.erase(0, 1);
  }
  while (str[str.size()-1]==0x20 || str[str.size()-1]==0x09){
     str.erase(str.size()-1, 1);
   }
  return str;
}

bool estVide(string str){
  str = enleverBlanc(str);
  return str.empty();
}

bool estCommentaire(string str){
  str = enleverBlanc(str);
  return (str[0]==';' || str[0]=='#');
}

string getCle(string str){
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

string getValeur(string str){
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

int main ( int argc, char* argv[]){

  // --------------String et chaine de caractère-----------------------
  // string str;
  // str = "      J'adore manger des pâtes    ";
  //
  // cout << "phrase : " << str << " || taille : " << str.size() << endl;
  // // juste enlever l'espace ou la tabulation de début
  // string nouvellePhrase=enleverBlanc(str);
  // cout << "nouvelle phrase : " << nouvellePhrase << " || taille : " << nouvellePhrase.size() << endl;
  // str=nouvellePhrase;
  //
  // // juste tester si la chaine de caractère est vide
  // bool testVide = estVide(str);
  // cout << "vide : "  << (testVide ? "OUI" : "NON") << endl;
  //
  // //juste voir si la chaine est un commentaire ou pas
  // bool testCom = estCommentaire(str);
  // cout << "commentaire : "  << (testCom ? "OUI" : "NON") << endl;
  //
  // // juste récuperer ce qu'il y a avant un =
  // string str1 = "Cle4			= boulgour";
  // string recupCle;
  // recupCle=getCle(str1);
  // cout << "avant = :" << recupCle << endl;
  // // juste récuperer la valeur après un =
  // string recupValeur;
  // recupValeur=getValeur(str1);
  // cout << "après = :" << recupValeur << endl;

// -------------- MAP et String-------------------------------------
string VotreRecherche;
map<string, string> config;

// insertion de données
config.insert(pair<string,string>("Cle_adresseServeur" , "127.0.0.1"));
config.insert(pair<string,string>("Cle_portBd","3306"));
config.insert(pair<string,string>("Cle_userBd","root"));
config.insert(pair<string,string>("Cle_pwdUserBd","root"));
config.insert(pair<string,string>("Cle_bdd","root"));

std:cout << "Entrez une recherche" << endl;

cin >> VotreRecherche;
map<string, string>::iterator i;

for(i = config.begin(); i != config.end(); ++i){
  if((*i).first == VotreRecherche){
  cout << (*i).first << ": \"" << (*i).second << "\"" << endl;
  }
}
return 0;
}
