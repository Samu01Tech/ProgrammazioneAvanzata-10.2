#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
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

void stampa(int dim, char c){
    mtx.lock();
    for(int i=0; i<dim; i++){
        cout << c;
    }
    mtx.unlock();
}

int main() {
    Test miotest;
    thread tc(Test::stampa, &miotest, 5);
    thread tpar(miotest, 9);
    tc.join();
    tpar.join();
    

    /*
    thread t1(stampa, 20, 'A');
    thread t2(stampa, 10, 'Z');
    t1.join();
    t2.join();
    */
} 