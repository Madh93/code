#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Nodo{

    int dato;
    bool marca;

    bool operator < (const Nodo& str) const
    {
        return (dato < str.dato);
    }    
};



int main(void){


    Nodo* array = new Nodo [10];
    for (int i=0; i<10; i++){
            array[i].dato = i;
            array[i].marca = false;
    }

    vector<Nodo> lista;

    lista.push_back(array[8]);
    lista.push_back(array[5]);
    lista.push_back(array[9]);
    lista.push_back(array[1]);
    lista.push_back(array[2]);


    sort(lista.begin(), lista.end());

    for (int i=0; i<lista.size(); i++)
        cout << lista[i].dato << endl;



    return 0;
}