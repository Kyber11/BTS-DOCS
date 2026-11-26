#include "Amie.h"
#include "Serveur.h"
#include "Client.h"
#include "Barman.h"
#include "Percolateur.h"

Amie::Amie(){
Barman * barman = new Barman();
Client * client = new Client();
Serveur * serveur = new Serveur();
Percolateur * percolateur = new Percolateur();

// client-> serveur = serveur;
serveur->client = client;
// barman->serveur = serveur;
serveur->barman = barman;

serveur->demarrerfonctionnement();

delete serveur;
delete client;
}

Amie::~Amie(){}
