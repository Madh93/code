#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Stack {

	private:

		T* stack_;
		int size_;
		int top_;

	public:

		Stack(int size):
			size_(size),
			top_(-1),
			stack_(NULL){
				stack_ = new T [size_];
			}

		~Stack(){

			if (stack_){
				delete stack_;
				stack_ = NULL;
			}
		}

		void push(T dato){

			if (!full()){
				top_++;
				stack_[top_] = dato;
			}

			else
				cout << "Pila llena!" << endl;
		}

		T pop(){

			if (!empty()){
				T dato = stack_[top_];
				top_--;
				return dato;
			}

			else{
				cout << "Pila llena!" << endl;
				exit(1);		
			}
		}

		bool empty(){

			return (top_ == -1);
		}

		bool full(){

			return (top_ >= size_-1);
		}

		void show(){

			for (int i=0; i<=top_; i++)
				cout << stack_[i] << ", ";
		}

		T top(){
			if (!empty())
				return stack_[top_];

			else{
				cout << "Pila vacia!" << endl;
				exit(1);		
			}			

		}
};



int main(void){
	

	Stack<int> PilaInt(10);
	Stack<float> PilaFloat(10);
	Stack<char> PilaChar(10);

	for (int i=0; i<5; i++){

		PilaInt.push(i*2);
		PilaFloat.push(i*2.3);
		PilaChar.push('a'+i);
	}

	cout << "Mostrar pila: "; PilaInt.show(); cout << endl;
	cout << "Mostrar pila: "; PilaFloat.show(); cout << endl;
	cout << "Mostrar pila: "; PilaChar.show(); cout << endl;

	return 0;
}