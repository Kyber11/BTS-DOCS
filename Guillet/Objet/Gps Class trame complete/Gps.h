#ifndef Gps_h
#define Gps_h
class Gps {
  private:
    float longitude;
    float lattitude;
    short heure;
    short minute;
    float seconde;
    char * trameGPGGA;

  public:
    short get_heure();
    short get_minute();
    float get_seconde();
    float get_lattitude();
    float get_longitude();
    short get_heureEnvoie();
    Gps(char * tGPGGA);
    ~Gps();
};
#endif
