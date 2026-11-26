#ifndef Barman_h
#define Barman_h
class Percolateur;
class Serveur;
class Barman
{
  friend class Amie;
  Percolateur * perco;
  Serveur * serveur;
public:
  void preparercafe();
  void preparerplateau();
};
#endif
