#ifndef Gps_h
#define Gps_h
class Gps {
  private:
    float longitude;
    float lattitude;
    char * trameGPGGA;
  public:
    float get_lattitude();
    float get_longitude();
    Gps(char * tGPGGA);
    ~Gps();
};
#endif
