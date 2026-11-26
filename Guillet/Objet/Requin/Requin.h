#ifndef Requin_h
#define Requin_h
class Requin
{
	private :
	unsigned short nbDents ;
	float masse ;
	public :
	Requin();
	~Requin();
	void manger(float m);
	void nager();
	void regeneration(int r);
	unsigned short get_nbDents();
	float get_masse();


};
#endif