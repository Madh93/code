#include <iostream>
using namespace std;


int** array = NULL;
int* a = NULL;

void destruir(){

    if (array){

        for (int i=0; i<10; i++){
            delete [] array[i];
        }

        delete [] array;
        array = NULL;


    }

    if (a){

        delete [] a;
        a = NULL;       

    }
}


void construir(int x){

    array = new int* [10];
    for (int i=0; i<10; i++){
        array[i] = new int [10];
        for (int j=0; j<10; j++)
            array[i][j] = x;
    }
}

int main(void){

    a = new int [5];
    for (int i=0; i<5; i++)
        a[i]=i;

    construir(1);
    cout << array[0][0] << endl;
    destruir();
    construir(2);
    cout << array[0][0] << endl;    
    destruir();


    return 0;

}