#include <iostream>
using namespace std;


class Animal{

private:

	int edad_;

public:

	Animal():

		edad_(0){}

	Animal(int edad):

		edad_(edad){}

	~Animal(){}

	int getEdad(){

		return edad_;
	}

	void setEdad(int edad){

		edad_ = edad;
	}
};


class Perro : public Animal{

private:

	char* raza_;
	int hijos_;

public:

	Perro():
		Animal(){}

	Perro(int edad, char* raza, int hijos):

		Animal(edad){
			raza_ = raza;
			hijos_ = hijos;
	}

/*	CONSTRUCTOR DE COPIA MEDIANTE REFERENCIAS

	Perro(const Perro& cperro){

		edad_ = cperro.getEdad();
		hijos_ = cperro.getHijos();
	}
*/

	//CONSTRUCTOR DE COPIA MEDIANTE PUNTEROS
/*
	Perro(const Perro* cperro){

		edad_ = (*cperro).getEdad();
		hijos_ = cperro->getHijos();
	}
*/
	~Perro(){}


	char* getRaza() const{
		return raza_;
	}

	int getHijos() const {
		return hijos_;
	}

	void setRaza(char* raza){
		raza_ = raza;
	}

	void setHijos(int hijos){
		hijos_ = hijos;
	}
};

int main(void){


	Perro* Toby = new Perro(5,(char *)"terrier",4);

	cout << Toby->getEdad() << endl;
	cout << Toby->getRaza() << endl;
	cout << Toby->getHijos() << endl;


	return 0;
}
