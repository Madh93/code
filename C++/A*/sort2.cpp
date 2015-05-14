#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Nodo{

public:
    int dato;
    bool marca;

    bool operator < (const Nodo &str) const
    {
        return (dato < str.dato);
    }    

   // bool operator == (const Nodo& str) const
   //  {
   //      return (dato == str.dato);
   //  }
};

bool ordenar( Nodo *a, Nodo *b ){

    return *a < *b;
}
/*
void paso1(Nodo *a){

    cout << "paso1: " << &a << endl;
}

void paso2(Nodo &a){


}


void paso3(Nodo* &a){

    cout << "paso3: " << &a << endl;
}*/


int main(void){

    Nodo** array = new Nodo* [10];
    for (int i=0; i<10; i++){
            array[i] = new Nodo();
            array[i]->dato = i;
            array[i]->marca = false;
    }


    //INTRODUCIR DATOS EN VECTOR
    vector<Nodo*> lista;

    lista.push_back(array[8]);
    lista.push_back(array[5]);
    lista.push_back(array[2]);
    lista.push_back(array[9]);
    lista.push_back(array[6]);
    lista.push_back(array[1]);
/*
    cout << "actua: " << &lista[0] << endl;
    paso1(lista[0]);
   // paso2(*lista[0]);
    paso3(lista[0]);
*/

    //MOSTRAR POR PANTALLA
    for (int i=0; i<lista.size(); i++)
        cout << lista[i]->dato << ",";
    cout << endl;

    sort(lista.begin(), lista.end(),ordenar);

    for (int i=0; i<lista.size(); i++)
        cout << lista[i]->dato << ",";
    cout << endl;

/*
    vector<Nodo*>::iterator it = find(lista.begin(),lista.end(), array[6]);


    //cout << &array[6]->dato << endl;
    cout << *it << endl;


    lista.erase(it);

    for (int i=0; i<lista.size(); i++)
        cout << lista[i]->dato << ",";
    cout << endl;
*/
    return 0;
}