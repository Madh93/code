#include <iostream>
using namespace std;


int main(void){
	
	char a = 'a';
	char b = 'b';

	// PUNTERO APUNTA A VARIABLE 'a'

	char* pa = &a;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "pa: " << *pa << endl;

	// PUNTERO APUNTA A VARIABLE 'b'

	pa = &b;

	cout << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "pa: " << *pa << endl;

	// REFERENCIA APUNTA A VARIABLE 'a'

	pa = &a;
	char& ra = a;

	cout << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "pa: " << *pa << endl;
	cout << "ra: " << ra << endl;

	// REFERENCIA APUNTA A VARIABLE 'b' Y EN CONSECUENCIA 'a' y 'pa' TAMBIEN CAMBIAN

	ra = b;

	cout << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "pa: " << *pa << endl;
	cout << "ra: " << ra << endl;



	return 0;
}