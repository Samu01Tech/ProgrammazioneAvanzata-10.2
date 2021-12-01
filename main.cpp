#include <iostream>
#include <thread>
using namespace std;

void stampa(int dato){
    cout << dato;
}

void stampa2(){
    cout << "Nulla";
}

int main() {
    thread stampaThread(stampa, 5);
    thread stampaNulla(stampa2);
    cout << "Ciao";
    stampaNulla.join();
    stampaThread.join();
    cout << "Fine";
} 