#ifndef Serveur_h
#define Serveur_h

class Client;
class Barman;

class Serveur
{
  friend class Amie;

  Client * client;
  Barman * barman;

public:
  float rendremonaie();
  void servircafe();
  void demarrerfonctionnement();
};
#endif
