#include <iostream>
using namespace std;

int main(void){


	int* pa = new int;
	*pa = 5;
	cout << *pa << endl;
	
	*pa = 6;
	cout << *pa << endl;




	return 0;
}