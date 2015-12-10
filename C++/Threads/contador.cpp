#include <iostream>
#include <thread>

using namespace std;

int cuenta = 0;

void contar() {
    for (int i=0; i<1000; i++)
        cuenta++;
    cout << this_thread::get_id << ": " << cuenta << endl;
}


int main() {

    thread t1(contar);
    thread t2(contar);

    cout << t1::id;

    t1.join();
    t2.join();

    return 0;
}