#include <iostream>
#include <thread>
//#include <mutex>
using namespace std;

class Test{
    private: 
        int dato;
    public: 
        void stampa(int v){
            cout << v << " " << dato << endl;
        }
        void operator () (int v){
            cout << "[" << v << "]" << endl;
        }
};

int main() {
    Test miotest;
    thread tc(Test::stampa, &miotest, 5);
    thread tpar(miotest, 9);
    tc.join();
    tpar.join();
} 