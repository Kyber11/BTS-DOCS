#ifndef De_h
#define De_h
class De {
  private :
  int nbface;
  unsigned int valeur;

  public :
  De();
  De(int nombreface);
  void lancer();
  unsigned int get_valeur();
  int get_nbface();
  ~De();
};
#endif
