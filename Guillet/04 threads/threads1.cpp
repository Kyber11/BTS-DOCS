#include <iostream>
#include <thread>
using namespace std;
void fonction_thread(){
    cout << "mon premier thread" << endl;;
}
int main(){
    thread t(fonction_thread);
    t.join();
    return 0;
}
