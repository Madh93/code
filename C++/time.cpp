#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>		//limpiar pantalla

using namespace std;


int main(void){


	unsigned int microseconds = 1000000;

	for (int i=1; i<=10; i++){

		system("clear");

		cout << i << " seconds!" << endl;
		usleep(microseconds);
	}

	return 0;
}