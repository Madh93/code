#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>      //entrada/salida
#include <vector>       //vector dinamico

using namespace std;


typedef struct{

    int estado;
    char entrada;
    char escribir;
    char mover;
    int siguiente;
}tupla;

typedef vector<tupla> t_vector;
typedef vector<char> a_vector;
typedef vector<int> id_vector;


class TURING{

    int q_;                         //Nº total de estados
    int q0_;                        //Estado inicial...
    int f_;                         //1º estado final
    int num_;                       //Nº de t-tuplas
    int i_;                         //Estado actual
    int cab_;                       //Cabezal: Señala en que posicion de la cinta se esta
    bool ready_;            //Condicion de programa cargado correctamente
    t_vector tupla_;        //Tupla
    a_vector alf_;          //Alfabeto
    a_vector cinta_;        //Vector de la cinta
    id_vector* id_;         //Indentificador de estado: dentro del id_[0] estaria la tupla {0,1}


    public:

        TURING(char nombreTM[]);                        //Leer maquina
        ~TURING();                                                      //Limpiar
        void eliminar();
        void leer_cinta(char nombreTMT[]);      //Leer cinta
        void iniciar_cinta();                           //Añadir blancos en los laterales de la cinta 

        void alf_update(int val);               //Actualizar alfabeto
        void identificar();                             //Añadir identificadores por simbolo de estado
        void mostrar();                                 //Mostrar maquina y cinta por pantalla
        void analizar(int val);                 //Analizar cadena directamente
        void byStep(int val);                   //Analizar cadena paso por paso

        void entrada(int val, int step);        //Dentro del identificador, a que tupla se corresponde
        void escribir(int val);                         //Sobreescribir
        void desplazar(char val, int pos);      //Desplazar cabezal
        void parar(int val);                            //Parar, dependiendo del estado sera aceptado o no

        void ready(int val);                            //Comprobar si el programa esta listo sin fallos
        void checkFails();                                      //Comprobar fallos
        void typeFails(int val, int pos);       //Tipo de errores y fallos
};
