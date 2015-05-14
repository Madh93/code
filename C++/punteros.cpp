#include <iostream>

using namespace std;


void suma1(int b){

	b = b+2;
}

void suma2(int& b){

	b = b+2;
}

void suma3(int* b){

	*b = (*b)+2;
}

int main(void){


	int a = 12;
	int* pa;

	pa = &a;

	cout << "Valor de a: " << a << endl;
	cout << "Direccion de a: " << &a << endl;
	cout << "Valor de pa: " << *pa << endl;
	cout << "Direccion de pa: " << pa << endl;
	cout << endl;


	int* c = pa +1;

	char cadena[5] = "Hola";
	char* d = cadena;
	d = d+1;
	char* e = d+1;

	cout << "Direccion de d: " << d << endl;
	cout << "Direccion de e: " << e << endl;




/*
	int b = 12;
	suma1(b);
	cout << "Suma1: " << b << endl;
	
	b = 12;
	suma2(b);
	cout << "Suma2: " << b << endl;

	b = 12;
	suma3(&b);
	cout << "Suma3: " << b << endl;
*/

	return 0;
}