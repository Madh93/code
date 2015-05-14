#include <iostream>
#include <thread>

using namespace std;

int main(void) {

    cout << "Nº máx de hilos: " << thread::hardware_concurrency() << endl;

    return 0;
}