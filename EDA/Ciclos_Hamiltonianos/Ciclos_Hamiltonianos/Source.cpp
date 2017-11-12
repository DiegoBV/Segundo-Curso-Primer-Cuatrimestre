#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

bool es_Solucion(const vector <vector<bool>> &matriz, vector<bool> usados, int k, const int n, const vector <int> &sol) {
	if (k == (n - 1) && !usados[sol[k]] && matriz[sol[k - 1]][sol[k]] && matriz[sol[k]][sol[0]]) {
		return true;
	}
	else {
		return false;
	}
}

bool es_Completable(const vector <vector<bool>> &matriz, vector<bool> usados, int k, const int n, const vector <int> &sol) {
	if (k < (n - 1) && !usados[sol[k]] && matriz[sol[k - 1]][sol[k]]) {
		return true;
	}
	else {
		return false;
	}
}

void procesar_Solucion(const vector <int> &sol) {
	//ofstream archivo;
	//archivo.open("soluciones.txt");
	for (int i = 0; i < sol.size(); i++) {
		//archivo << sol[i] << "--> ";
		cout << sol[i] << "--> ";
	}
	cout << endl;
	//archivo << endl;
	//archivo.close();

}
void delay(int secs) {
	for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void ciclos_Hamiltonianos(const vector <vector<bool>> &matriz, vector<bool> usados, int k, const int n, vector <int> &sol) {
	for (int i = 1; i < n; i++) {
		sol[k] = i;

		/*for (int j = 0; j < sol.size(); j++) {
			cout << sol[j] << "--> ";
		}
		cout << endl << endl << endl;
		delay(3);*/

		if (es_Solucion(matriz, usados, k, n, sol)) {
			procesar_Solucion(sol);
		}
		else if (es_Completable(matriz, usados, k, n, sol)) {
			usados[i] = true;
			ciclos_Hamiltonianos(matriz, usados, k + 1, n, sol);
			usados[i] = false;
		}

		
	}
}

int main() {
	vector <vector<bool>> matriz (5, vector<bool>(5));
	matriz[0][1] = true;
	matriz[0][2] = true;
	matriz[1][0] = true;
	matriz[1][2] = true;
	matriz[1][3] = true;
	matriz[1][4] = true;
	matriz[2][0] = true;
	matriz[2][1] = true;
	matriz[2][3] = true;
	matriz[2][4] = true;
	matriz[3][1] = true;
	matriz[3][2] = true;
	matriz[3][4] = true;
	matriz[4][1] = true;
	matriz[4][2] = true;
	matriz[4][3] = true;
	vector<bool> usados;
	usados.resize(5);
	vector <int> sol;
	sol.resize(5);
	//ciclos_Hamiltonianos(matriz, usados, 1, 5, sol);
	system("pause");
	return 0;
}