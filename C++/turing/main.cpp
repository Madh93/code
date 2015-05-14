
#include "turing.cpp"
#include <iostream>
#include <fstream>
 
int main(void){
       
char nombreTM[50], nombreTMT[50], opcion=0;
 
    TURING *turing;

    cout << "\nIntroduzca el fichero que contiene la Maquina de Turing (.TM): ";
    cin.getline(nombreTM,50);
    turing = new TURING(nombreTM);
   
    cout << "Introduzca el fichero que contiene la cinta (.TMT): ";
    cin.getline(nombreTMT,50);
    turing->leer_cinta(nombreTMT);

    while (opcion != 5) {
   
        cout << "\n___|Practica 9, Computacion y Algoritmia: Simulacion de una Maquina de Turing|___" << endl;
        cout << "[1] Cargar maquina y cinta" << endl;
        cout << "[2] Mostrar maquina y cinta" << endl;
        cout << "[3] Analizar" << endl;
        cout << "[4] Analizar paso a paso" << endl;
        cout << "[5] Salir" << endl;
        cout << "Introduzca una opcion: ";

        cin>>opcion;
        cin.ignore();

        switch(opcion){
               
            case '1':
                                           
                    cout << "\nIntroduzca el fichero que contiene la Maquina de Turing (.TM): ";
                    cin.getline(nombreTM,50);
                    turing = new TURING(nombreTM);
                   
                    cout << "Introduzca el fichero que contiene la cinta (.TMT): ";
                    cin.getline(nombreTMT,50);
                    turing->leer_cinta(nombreTMT);
                   
                    break;
 
            case '2':
           
                    turing->mostrar();
                   
                    break;
 
            case '3':
   
                    turing->analizar(0);
                   
                    //volver a llamar al constructor...
                    turing = new TURING(nombreTM);
                    turing->leer_cinta(nombreTMT);
                   
                    break;
                   
            case '4':

                    turing->analizar(1);
                   
                    //volver a llamar al constructor...
                    turing = new TURING(nombreTM);
                    turing->leer_cinta(nombreTMT);
                   
                    break;
                   
            case '5':
           
                    return 0;
                   
                    break;
                   
            default:
           
                    cout << "Opcion incorrecta." << endl;
        }

    }

    return 0;
}
/*INPUT EXAMPLES INPUT EXAMPLES INPUT EXAMPLES INPUT EXAMPLES INPUT EXAMPLES INPUT EXAMPLES*/
/*
//.TM = Turing Machine
//.TMT = Turing Machine Tape
 
//1. S = 0^n 1^n (n>0)
//1.TM 1.TM 1.TM 1.TM 1.TM 1.TM 1.TM 1.TM 1.TM
5               //Q states.......(DELETE THESE COMMENTS)
4               //Final or Aceptation State
10              //Number of tuples/lines
0$0$X$R$1               //state$read$write$move$next_state
0$Y$Y$R$3
1$0$0$R$1
1$1$Y$L$2
1$Y$Y$R$1
2$0$0$L$2
2$X$X$R$0
2$Y$Y$L$2
3$Y$Y$R$3
3$$$$$L$4
//1.TMT 1.TMT 1.TMT 1.TMT 1.TMT 1.TMT 1.TMT 1.TMT
000111
 
//2. S = Palindromes {a,b}
//2.TM 2.TM 2.TM 2.TM 2.TM 2.TM 2.TM 2.TM 2.TM
7
6
16
0$a$$$R$1
0$b$$$R$2
0$$$$$R$6
1$a$a$R$1
1$b$b$R$1
1$$$$$L$3
2$a$a$R$2
2$b$b$R$2
2$$$$$L$4
3$a$$$L$5
3$$$$$R$6
4$b$$$L$5
4$$$$$R$6
5$a$a$L$5
5$b$b$L$5
5$$$$$R$0
//2.TMT 2.TMT 2.TMT 2.TMT 2.TMT 2.TMT 2.TMT 2.TMT
baaab
 
//3. S = Duplicate '1' at final {1}, example: $111$ -> $111$111111$
//3.TM 3.TM 3.TM 3.TM 3.TM 3.TM 3.TM 3.TM 3.TM
7
6
11
0$1$X$R$1
0$$$$$R$6
1$1$1$R$1
1$$$$$R$2
2$1$1$R$2
2$$$1$R$3
3$$$1$L$4
4$1$1$L$5
5$1$1$L$5
5$$$$$L$5
5$X$X$R$0
//3.TMT 3.TMT 3.TMT 3.TMT 3.TMT 3.TMT 3.TMT 3.TMT

*/