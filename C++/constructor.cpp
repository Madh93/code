#include <iostream>
using namespace std;


class Perro{

private:

	int* edad;

public:

	Perro(int e){

		edad = new int (5);
	}


	~Perro(){

		delete edad;
		edad = NULL;
	}

	int getEdad(){
		return *edad;
	}

};


int main(void){
	

	Perro Cookie(5);
	cout << Cookie.getEdad() << endl;


	return 0;
}