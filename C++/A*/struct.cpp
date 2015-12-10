#include <iostream>
using namespace std;


struct Nodo{

    int dato;
    bool marca;
};



Nodo*** copia;


void copiar(Nodo*** &original){

    copia = original;
}

int main(void){

    Nodo*** array = new Nodo** [10];
    for (int i=0; i<10; i++){
        array[i] = new Nodo* [10];
        for (int j=0; j<10; j++){
            array[i][j]= new Nodo;
            array[i][j]->dato = 5;
            array[i][j]->marca= false;
        }
    }

    copiar(array);

    cout << &array << endl;
    cout << &copia << endl;
    cout << array << endl;
    cout << copia[0][0]->dato << endl;    


    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            delete array[i][j];
        }
        delete [] array[i];
    }
    copia = NULL;
    delete [] array;
    array = NULL;
    copia = NULL;


    cout << "cambio" << endl;
    cout << &array << endl;
    cout << &copia << endl;
    cout << array << endl;
    cout << copia << endl;


    return 0;
}