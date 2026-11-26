#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
  
  //   création d'une map de string:
  map<string, string> config;
  
  // insertion de données
  config.insert(pair<string,string>("option1","on"));
  // remarque : la méthode insert renvoi faux si il existe déjà une clé de même valeur
  config.insert(pair<string,string>("option2","off"));
  config.insert(pair<string,string>("option3","tiptop"));
  config.insert(pair<string,string>("option4","quatro"));
  config.insert(pair<string,string>("option5","555"));
  config.insert(pair<string,string>("option6","666"));
  config.insert(pair<string,string>("option7","777"));
  // autre méthode d'insertion:
  config["option8"] = "888";
  config["option9"] = "999";
  config["option0"] = "0000000";
  
  // déclaration d'un itérateur pour le parcours de la map :
  map<string, string>::iterator i;
  
  // parcours de la map
  for( i = config.begin(); i != config.end(); ++i){
    cout << (*i).first << ": \"" << (*i).second << "\"" << endl;
  }

  // taille de la map
  cout << "taille de la config (nombre d'enregistrements) : " << config.size() << endl;
  
  // affichage d'une valeur :
  cout << "l'option1 vaut \"" << config["option1"] << "\"" << endl;
  
  // recherche de l'existance d'une clé : renvoi un itérateur
  map<string, string>::iterator position;
  position = config.find("option5");
  if (position == config.end())
    cout << "pas trouvé ! " << endl;
  else
    cout << "trouvé ! " << position->first << " : \"" << position->second << "\"" << endl;
  
  // autre solution de recherche : count
  if (config.count("option5"))
    cout << "l'option5 est une clé qui fait partie de la map" << endl;
  
  // modif d'une valeur :
  config["option1"] = "terminée";
  cout << "l'option1 vaut \"" << config["option1"] << "\"" << endl;
  
  // suppression d'un ou plusieurs éléments :
  config.erase("option7");	// par clé
  config.erase(position);	// par itérateur
  config.erase(config.find("option4"), config.end());
  
   return 0;
}

