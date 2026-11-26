#include <iostream>
#include <thread>
using namespace std;
class C{
public:
    void operator()();
};
void C::operator()()
{
  thread::id identifiant = this_thread::get_id();
  cout << "dans operator(), identifiant est " << identifiant << endl;
    cout << "operateur() de la classe C" << endl;;


    for (int i = 0 ; i < 1000; i++)
      cout << '+' << flush;
}
int main()
{
    C objet;
    thread t(objet);
    thread::id identifiant = this_thread::get_id();
    cout << identifiant << endl;
    cout << "le thread à pour identifiant ; " << t.get_id()<< endl;
    for (int i = 0 ; i < 1000; i++)
      cout << 'o' << flush;
    t.join();
    return 0;
}
