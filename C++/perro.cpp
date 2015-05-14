#include <iostream>
using namespace std;


class Perro{

private:

	int edad_;
	int hijos_;

public:

	Perro(){}

	Perro(int edad, int hijos){

		edad_ = edad;
		hijos_ = hijos;
	}

/*	CONSTRUCTOR DE COPIA MEDIANTE REFERENCIAS

	Perro(const Perro& cperro){

		edad_ = cperro.getEdad();
		hijos_ = cperro.getHijos();
	}
*/

	//CONSTRUCTOR DE COPIA MEDIANTE PUNTEROS

	Perro(const Perro* cperro){

		edad_ = (*cperro).getEdad();
		hijos_ = cperro->getHijos();
	}


	~Perro(){}


	int getEdad() const{
		return edad_;
	}

	int getHijos() const {
		return hijos_;
	}

	void setEdad(int edad){
		edad_ = edad;
	}

	void setHijos(int hijos){
		hijos_ = hijos;
	}

};


int main(void){
	

	Perro Cookie(10,3);
	cout << "Cookie: " << Cookie.getEdad() << " y " << Cookie.getHijos() << endl;

	//Perro Gemelo(Cookie);		REFERENCIA
	Perro Gemelo(&Cookie);		//PUNTEROS

	cout << "Gemelo: " << Gemelo.getEdad() << " y " << Gemelo.getHijos() << endl;
	Gemelo.setEdad(11);
	Gemelo.setHijos(6);

	cout << "Cookie: " << Cookie.getEdad() << " y " << Cookie.getHijos() << endl;
	cout << "Gemelo: " << Gemelo.getEdad() << " y " << Gemelo.getHijos() << endl;


	return 0;
}