#include <iostream>
using namespace std;


int main(void){
	
	int* p1 = new int(5);
	const int* p2 = new int(5); //valor constante, puntero variable
	int* const p3 = new int(5);	//puntero constante, valor variable


	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p3 << endl;

	*p1 = 6;
//	*p2 = 6;
	p2 = p1;
//	p3 = p1;
	*p3 = 6;


	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p3 << endl;


	return 0;
}