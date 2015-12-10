#include <iostream>
#include <functional>

using namespace std;

int main(void){
	

	auto algorithm = [&]( double x, double m, double b ) -> double {
		return m*x+b;
	};

	int a=algorithm(1,2,3);

	cout << a << endl;

	return 0;
}