#include "turing.hpp"

TURING::TURING(char nombreTM[]){

    fstream in;
    int i=0;
    char sep;
    tupla aux;

    eliminar();             //Borrar todo contenido anterior

    in.open(nombreTM, fstream::in);   //Abrir el fichero


    if(in.is_open()){    //Si se abre, empezar a leer


        in >> (int &)q_ >> (int &)f_ >> (int &)num_;    //Leer nº estados, estado final y nº de tuplas

        while (i < num_){                                                       //Leer valores de cada tupla

            in >> (int &)aux.estado >> (char &)sep;
            in >> (char &)aux.entrada >> (char &)sep;
            in >> (char &)aux.escribir >> (char &)sep;
            in >> (char &)aux.mover >> (char &)sep;
            in >> (int &)aux.siguiente;

            tupla_.push_back(aux);                  //Guardar datos en el vector tupla_

            if (alf_.size() == 0)                                   //Actualizar alfabeto
                alf_.push_back(tupla_[i].entrada);
            else
                alf_update(i);

            i++;
        }

        id_= new id_vector [q_];        //INICIALIZAR Vector de vectores (matriz)
        identificar();                          //Añadir identificadores de estado
        ready(1);
        checkFails();                           //Comprobar fallos en los datos leidos
    }

    else                //Problemas al abrir o encontrar el fichero especifico
        typeFails(0,0);


    in.close();   //Cerrar fichero
}

TURING::~TURING(){

    eliminar();
}


void TURING::eliminar(){

    q_ = 0;         //Inicializar
    f_ = 0;
    num_ = 0;
    i_ = 0;
    cab_ = 1;

    tupla_.clear();         //Borrar contenido
    alf_.clear();

    if (id_!=NULL)                                  //Borrar id_
        for (int i=0; i<q_; i++)
            while (!id_[i].empty())
                id_[i].pop_back();
}


void TURING::leer_cinta(char nombreTMT[]){

    fstream in;
    char c;

    cinta_.clear();

    in.open(nombreTMT, fstream::in);   //Abrir el fichero

    if(in.is_open()){    //Si se abre, empezar a leer

        while (!in.eof()){                      //Mientras no se llegue al final leer

            in >> (char &)c;
            cinta_.push_back(c);
        }

       cinta_.pop_back();             //Sobra el ultimo por lo que hay que quitarlo
        iniciar_cinta();                               //Añadir laterales "infinitos"
    }

    else                //Problemas al abrir o encontrar el fichero especifico
        typeFails(0,1);

    in.close();   //Cerrar fichero
}

void TURING::iniciar_cinta(){

    int sizeOld = cinta_.size();                    //Aumentar tamaño de la cinta en uno (el nuevo estara vacio)
    cinta_.resize(sizeOld+1);

    for (int i=sizeOld; i >= 0; i--){               //Pasar cada valor al siguiente

        cinta_[i+1] = cinta_[i];
    }

    cinta_[0] = '$';                                        //Modificar el inicial y añadir el ultimo como blancos
    cinta_.push_back('$');
}

void TURING::alf_update(int val){

    int i=0, j=0;

    for (i=0; i<alf_.size(); i++){                          //recorrer alfabeto

        if (alf_[i] != tupla_[val].entrada)             //Comprobar que la entrada actual es diferente
            j++;
        else                                                    //En caso de ser igual, ya existe, por lo que salir
            i=alf_.size();
    }

    if (j == alf_.size())                                           //Si siempre fue diferente, no esta en el alfabeto: añadir
        alf_.push_back(tupla_[val].entrada);
}


void TURING::identificar(){

    for (int i=0; i < q_; i++)                              //Vector[q_][num_]  = Vector[5][10]
        for (int j=0; j < num_; j++)

            if (tupla_[j].estado == i)              //Almacendando en id[0]...[4] las tuplas con mismo estado -> id[0][2] = {0,1}
                id_[i].push_back(j);            //se almancena la linea en la que esta la correspondiente tupla

}

void TURING::mostrar(){

    if (!ready_)
        typeFails(7,0);

    else{

        cout << "\n__________________________________________________" << endl;
        cout << "MAQUINA DE TURING:\n" << endl;
        cout << "Numero de estados: " << q_ << endl;
        cout << "Primer estado final: " << f_ << endl;
        cout << "\nestado | entrada | escribir | mover | siguiente" << endl;

        for (int i=0; i<tupla_.size(); i++){
            cout << "   " << tupla_[i].estado;
            cout << "\t" << "   " << tupla_[i].entrada;
            cout << "\t" << "      " << tupla_[i].escribir;
            cout << "\t\t" << tupla_[i].mover;
            cout << "\t" << "  " << tupla_[i].siguiente;   
            cout << endl;
        }

        cout << "__________________________________________________" << endl;
        cout << "CINTA:\n" << endl;

        for (int i=0; i<cinta_.size(); i++)
            cout << cinta_[i];

        cout << "\n__________________________________________________" << endl;
    }
}


void TURING::analizar(int val){


    if (!ready_)
    typeFails(7,0);

    else{

        int j=0;

        while (i_ != -1){

            if (val != 0){

                cout << "\n________________" << endl;
                cout << "*" << j << "º iteracion*" << endl;;   //Nº iteracion
                cout << "Cinta:  ";                                                             //Cinta
                for (int k=0; k < cinta_.size(); k++)                  
                    cout << cinta_[k];
                cout << endl;
                cout << "Cabezal:";                                                             //Cabezal
                for (int i=0; i<cab_; i++)
                    cout << " ";
                cout << "^" << endl;   
            }

            entrada(i_,val);       
            j++;
        }
    }
}


void TURING::byStep(int val){

    cout << "Se sobreescribira: " << tupla_[val].escribir << endl;          //Escritura
    cout << "El cabezal ";                                                                                          //Movimiento
    switch (tupla_[val].mover){
        case 'R':       cout << "avanzara a la derecha" << endl; break;
        case 'L':       cout << "retrocedera a la izquierda" << endl; break;
        case 'S':       cout << "no se movera" << endl; break;
        default:        cout << " " << endl;
    }
    cout << "Esta en Q" << tupla_[val].estado << ". Se movera al estado Q" << tupla_[val].siguiente << endl;//Siguiente estado
    cout << "\nPULSE 'ENTER' PARA CONTINUAR...";
    if (cin.get() == '\n')
        cout;
}


void TURING::entrada(int val, int step){

    int j=0,k;

    for (int i=0; i < id_[val].size(); i++){        //Recorriendo el vector de identificador correspondiente id_[val]

        k = id_[val][i];                                        //Corresponde al nº de tupla del actual identificador

        if (tupla_[k].entrada == cinta_[cab_]){ //Si un elmento de entrada es igual al de la cinta, se escribe
            escribir(k);                                            //Si ninguno es igual, se para la maquina
            if (step != 0)
                byStep(k);

            i=id_[val].size();
        }
        else
            j++;
    }

    if (j == id_[val].size())
        parar(val);    

}


void TURING::escribir(int val){                                         //Sobreescribir la cinta con el valor de la tupla a escribir

    if ((cab_ == cinta_.size()-1) && (tupla_[val].mover == 'R')){   //Si se llega al final de la cinta, y se sigue avanzando a
                                                                    //la derecha se añade un nuevo espacio en el vector cinta
        cinta_[cab_] = tupla_[val].escribir;                                            //sin olvidarse de añadir un espacio blanco
        cinta_.push_back('$');
    }

    else if ((cab_ == 0) && (tupla_[val].mover == 'L')){
                                                    //Si se llega al principio de la cinta, y se sigue avanzando a
        cinta_[cab_] = tupla_[val].escribir;                    //la izquierda se añade un nuevo blanco al principio
        iniciar_cinta();                                                        //hay que tener en cuenta que sobra un blanco final y cab_ tiene que  
        cinta_.pop_back();                                                      //sumar 1 unidad para que en desplazar() no sea -1.
        cab_++;
    }

    else
        cinta_[cab_] = tupla_[val].escribir;   

    desplazar(tupla_[val].mover, val);              //Desplazar con el siguiente y actual estado
}

void TURING::desplazar(char val, int pos){

    switch (val){

        case 'R':       cab_++; break;                  //Dependiendo del simbolo de movimiento
        case 'L':       cab_--; break;                  //el cabezal se movera a un lado o al otro
        case 'S':       break;
        default:        parar(pos);
    }

    i_ = tupla_[pos].siguiente;
}

void TURING::parar(int val){

    if (val == f_)
        cout << "\n¡CADENA ACEPTADA!" << endl;
    else
        cout << "\nCadena Denegada..." << endl;

    i_=-1;
}


void TURING::ready(int val){    //Antes de poder elegir cualquier accion
    //Previamente es necesario inicializar ready_
    if (val == 1)                           //Establece si puede o no trabajar
        ready_ = true;                  //El programa ya con los datos correctos
    else
        ready_ = false;
}

void TURING::checkFails(){

    int i,j,k=0;

    //Comprobar que estado final existe
    if (f_ >= q_)
        typeFails(1,0);

    //Comprobar que hay un minimo de tuplas

    if (num_ == q_)
        typeFails(2,0);

    //Comprobar si los simbolos de estado son validos
    for (i=0; i<tupla_.size(); i++)
        if (tupla_[i].estado >= q_)
            typeFails(3,i);

    //Comprobar si los simbolos de escritura son validos
    for (i=0; i<tupla_.size(); i++){
        for (j=0; j<alf_.size(); j++){

            if (tupla_[i].escribir == alf_[j])
                j=alf_.size();
            else           
            k++;
        }

        if (k == alf_.size())
            typeFails(4,i);
        k=0;
    }

    //Comprobar si los simbolos de mover son validos
    for (i=0; i<tupla_.size(); i++){

        switch (tupla_[i].mover){

        case 'R':       break;
        case 'L':       break;
        case 'S':       break;
        default:        typeFails(5,i);
        }
    }

    //Comprobar si los simbolos siguientes son validos
    for (i=0; i<tupla_.size(); i++)
        if (tupla_[i].siguiente >= q_)
            typeFails(6,i);

}

void TURING::typeFails(int val, int pos){

    int i,j,k;
    char error[9] = "ERROR [#";

    switch (val){

        case 0: if(pos == 0)
                    cout << error << val << "]: El fichero .TM no existe o no se ha podido abrir correctamente." << endl;
                else
                    cout << error << val << "]: El fichero .TMT no existe o no se ha podido abrir correctamente." << endl;
                    ready(0);
                    break;

        case 1: cout << error << val << "]: El estado final no pertenece al conjunto de estado Q." << endl;
                ready(0);
                break;

        case 2: cout << error << val << "]: El numero de tuplas es inferior al numero de estados." << endl;
                ready(0);
                break;

        case 3: cout << error << val << "]: Tupla[" << pos << "] -> Simbolo de estado no permitido." << endl;
                ready(0);
                break;

        case 4: cout << error << val << "]: Tupla[" << pos << "] -> Simbolo de escritura no existe en el alfabeto." << endl;
                ready(0);
                break;

        case 5: cout << error << val << "]: Tupla[" << pos << "] -> Simbolo de movimiento difiere de R|L|S." << endl;
                ready(0);
                break;

        case 6: cout << error << val << "]: Tupla[" << pos << "] -> Simbolo de siguiente estado invalido." << endl;
                ready(0);
                break;

        case 7: cout << error << val <<"]: Se han encontrado fallos. Debe volver a cargar los datos." << endl;
                ready(0);
                break;

        default:
                ready(0);
    }
}