#include <iostream>

using namespace std;

int** copia;

void swap1(int** &original_){

    copia = original_;

   // cout << "copia" << endl;
    //cout << *copia[0] << endl;
    //cout << *copia[1] << endl;
}

void swap2(int* a){

    (*a)++;
}

//int** devolver(){

  //  return aux;
//}

int main(void){
    //int** original = devolver();
    int** aux = new int* [2];
    aux[0] = new int(5);
    aux[1] = new int(8);
    swap1(aux);

    delete [] copia;
    copia = NULL;


    cout << *aux[0] << endl;
    cout << *aux[1] << endl;
    cout << *copia[0] << endl;
    cout << *copia[1] << endl;

    // delete [] aux;
    // aux = NULL;

    //delete [] copia;
    //copia = NULL;

    //cout << *copia[0] << endl;
    //cout << *copia[1] << endl;    

    // int** pos_ini_fin = new int* [2];
    // for (int i=0; i<2; i++){
    //     pos_ini_fin[i] = new int [2];
    //     for (int j=0; j<2; j++)
    //         pos_ini_fin[i][j] = -1;
    // }

    // cout << pos_ini_fin[0][0] << endl;
    // //cout << pos_ini_fin[1][1] << endl;

    // for (int i=0; i<2; i++){
    //         delete [] pos_ini_fin[i];
    // }
    // delete [] pos_ini_fin;
    // pos_ini_fin = NULL;    

    // cout << *pos_ini_fin << endl;

    return 0;
}