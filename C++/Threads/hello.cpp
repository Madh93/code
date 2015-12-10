#include <iostream>
#include <thread>

void hello() {
    std::cout<<"Hola Concurrent World\n";
}

int main() {

    std::thread t(hello);
    t.join();
}