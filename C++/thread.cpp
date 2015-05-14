#include <iostream>
#include <unistd.h>
#include <thread>
#include <ctime>

using namespace std;


void h1(){

   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "Hilo 1: " << dt << endl;
   sleep(3);
}

void h2(){

   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "Hilo 2: " << dt << endl;
   sleep(3);
}

void h3(){

   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "Hilo 3: " << dt << endl;
   sleep(3);
}

void h4(){

   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "Hilo 4: " << dt << endl;
   sleep(3);
}


int main(void){

   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "Inicio de Main: " << dt << endl;

   thread t1(h1);
   thread t2(h2);
   thread t3(h3);
   thread t4(h4);
   t1.join();
   t2.join();
   t3.join();
   t4.join();

   now = time(0);
   dt = ctime(&now);
   cout << "Fin de Main: " << dt << endl;

	return 0;
}