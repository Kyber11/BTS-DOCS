#ifndef Client_h
#define Client_h
class Serveur;
class Client
{
  friend class Amie;
  Serveur * serveur;
public:
  void commanderCafe();
  void payer();
  void boire();
};
#endif
