#include <iostream>

using namespace std;


int** copia;

void swap1(int** &a){

	copia = a;

	cout << "copia" << endl;
	cout << *copia[0] << endl;
	cout << *copia[1] << endl;

	int rarito[2];

	rarito[0] = *copia[0];
	rarito[1] = *copia[1];

	cout << "rarito" << endl;
	cout << rarito[0] << endl;
	cout << rarito[1] << endl;	
}

void swap2(int* a){

	(*a)++;
}

int** devolver(){

	int** c = new int* [2];
	c[0] = new int(5);
	c[1] = new int(8);
	return c;
}


int main(){

	int** c = devolver();
	swap1(c);
	//cout << *c[0] << endl;
	//cout << *copia[0] << endl;


	int** array = new int* [10];
	for (int i=0; i<10; i++){
		array[i] = new int [10];
		for (int j=0; j<10; j++)
			array[i][j] = 0;
	}

	return 0;
}

/*
if x < 0  || y < 0 || x >= fil || y >= col
	return
else
	if mapa[x-1][y] != obstaculo
		setvecino[N]


void A*(){

	Pixmap* actual = NULL;
	Pixmap* inicio = cp_mapa[pos_ini_fin[0][0]][pos_ini_fin[0][1]];
	Pixmap* fin = cp_mapa[pos_ini_fin[1][0]][pos_ini_fin[1][1]];
	Pixmap* vecino = NULL;

	abierta.push_back(inicio);
	inicio->set_coste(0);
	inicio->set_heuristica(manhattan(pos[0],pos[1]);

	while (!abierta.empty()){

		sort(abierta.begin(), abierta.end(), wayToSort);	//menos a mas DEFINIR wayToSort
		actual = abierta.begin();

		if (actual == fin)
			return camino(actual->predecesor, fin)

		abierta.erase(actual);
		cerrada.push_back(actual); //si ya existe
		//quedarse con la de menor coste

		hallar_vecinos(actual);

		for(int i=0;i<4;i++){

			vecino = actual->get_vecinos(i);

			if (vecino){

				if (!find(cerrada.begin(), cerrada.end(), vecino) != cerrada.end())
					continue

				int tentativa = actual->get_coste() + distancia(actual,vecino);

				if ((find(abierta.begin(), abierta.end(), vecino) != abierta.end()) || (tentativa < vecino->get_coste())){

					vecino->set_predecesor(actual);
					vecino->set_coste(tentativa);
					vecino->set_heuristica(vecino->get_coste() + manhattan(coords vecino))
					
					if (find(abierta.begin(), abierta.end(), vecino) != abierta.end())
						abierta.push_back(vecino);
				}
			}
		}
	}
}
*/