#include <iostream>
#include <cstdlib>

using namespace std;


class Stack {

	private:

		int* stack_;
		int size_;
		int top_;

	public:

		Stack(int size):
			size_(size),
			top_(-1),
			stack_(NULL){
				stack_ = new int [size_];
			}

		~Stack(){

			if (stack_){
				delete stack_;
				stack_ = NULL;
			}
		}

		void push(int dato){

			if (!full()){
				top_++;
				stack_[top_] = dato;
			}

			else
				cout << "Pila llena!" << endl;
		}

		int pop(){

			if (!empty()){
				int dato = stack_[top_];
				top_--;
				return dato;
			}

			else{
				cout << "Pila vacia!" << endl;
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

		int top(){
			if (!empty())
				return stack_[top_];

			else{
				cout << "Pila vacia!" << endl;
				exit(1);		
			}			

		}
};



int main(void){
	

	Stack Pila(10);

	cout << "Mostrar pila: "; Pila.show(); cout << endl;
	Pila.push(1);
	Pila.push(5);
	Pila.push(4);
	Pila.push(2);
	cout << "Mostrar pila: "; Pila.show(); cout << endl;
	int pop = Pila.pop();
	pop = Pila.pop();
	Pila.push(9);
	cout << "Mostrar pila: "; Pila.show(); cout << endl;

	return 0;
}