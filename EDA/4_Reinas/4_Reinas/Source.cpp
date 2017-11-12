#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;




bool Cuatro_Reinas(vector<int> &v, int fila);
bool es_Solucion(const vector<int> &v, int posicion_Vector);
bool es_Completable(const vector<int> &v, int posicion_Vector);
bool no_Peligro(const vector<int> &v, int posicion_Vector);
int diagonal_Ascendente(int x, int y);
int diagonal_Descendente(int x, int y);
void procesa_Solucion(const vector <int> &v);
void muestra_Reinas(const vector <int> &v);
void delay(int secs);

bool Cuatro_Reinas(vector<int> &v, int fila) {  //No se como funciona pero lo hace (?)

	if (fila < 4) {

		for (v[fila] = 0; v[fila] < 4; v[fila]++) {
			muestra_Reinas(v);
			delay(1);
			if (es_Solucion(v, fila)) {
				procesa_Solucion(v);
				return true;
			}
			else if (es_Completable(v, fila)) {
				Cuatro_Reinas(v, fila + 1);
			}
		}
	}
}

bool es_Solucion(const vector<int> &v, int posicion_Vector) {

	if (posicion_Vector == 3 && !no_Peligro(v, posicion_Vector)) {
		return true;
	}
	else
		return false;
}

bool es_Completable(const vector<int> &v, int posicion_Vector) {

	if (posicion_Vector < 3 && !no_Peligro(v, posicion_Vector)) {
		return true;
	}
	else
		return false;
}

bool no_Peligro(const vector<int> &v, int posicion_Vector) {
	bool danger = false;
	int i = 0;

	while (!danger && i < posicion_Vector) {
		if (v[i] == v[posicion_Vector]) {  //misma columna
			danger = true;
		}
		else if (diagonal_Descendente(i, v[i]) == diagonal_Descendente(posicion_Vector, v[posicion_Vector])) {
			danger = true;
		}
		else if (diagonal_Ascendente(i, v[i]) == diagonal_Ascendente(posicion_Vector, v[posicion_Vector])) {
			danger = true;
		}
		i++;
	}

	return danger;
}

void procesa_Solucion(const vector <int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << "La Reina " << i + 1 << " se coloca en la fila " << i << " y en la columna " << v[i] << endl;
	}
	system("pause");
}
int diagonal_Descendente(int x, int y) {
	return x - y;
}

int diagonal_Ascendente(int x, int y) {
	return x + y;
}

void delay(int secs) {
	for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void muestra_Reinas(const vector <int> &v) {
	system("cls");
	for (int i = 0; i < 4;  i++) {
		for (int j = 0; j < 4; j++) {
			if (v[i] == j) {
				cout << "Q";	
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
}
int main() {
	vector <int> v = { -1,-1,-1,-1 };
	Cuatro_Reinas(v, 0);
	system("pause");
	return 0;
}