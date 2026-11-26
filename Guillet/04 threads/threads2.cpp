#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
using namespace std;

void fct(int i, string str)
{
    cout << i << " " << str << endl;
}

int main(){
    // création du thread et initialisation des paramètres i et str :
    thread t(fct, 2, "bonjour");
    t.join();
    return 0;
}
