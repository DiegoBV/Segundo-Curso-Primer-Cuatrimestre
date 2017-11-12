#include <iostream>
#include <string>
#include <vector>
using namespace std;
int suma_Min = 100000;

bool es_Solucion(const vector <vector<int>> &matriz, vector<bool> usados, int k, const int n, const vector <int> &sol) {
	return (k == (n - 1) && !usados[sol[k]] && matriz[sol[k - 1]][sol[k]] != 0 && matriz[sol[k]][sol[0]] != 0); //comprueba si el vertice ha sido usado,
	//si existe conexion entre el vértice y el anterior y si existe conexion entre el vértice y el 0 (para hacer un ciclo)
}

bool es_Completable(const vector <vector<int>> &matriz, vector<bool> usados, int k, const int n, const vector <int> &sol) {
	return (k < (n - 1) && !usados[sol[k]] && matriz[sol[k - 1]][sol[k]] != 0); 
}

void procesar_Solucion(const vector <int> &sol) { 
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << "--> ";
	}
	cout << endl;

}

bool es_Prometedora(const int suma_Total, const int suma_Min, const int k, const int n, const int min_Arista) {
	return (suma_Total + ((n - k) * min_Arista) < suma_Min); //es_Prometedora básico
}

void problema_Del_Viajante(const vector <vector<int>> &matriz, vector<bool> usados, int k, const int n, vector <int> &sol, int suma ,const int min_Arista, vector <int> &solMin) {
	for (int i = 1; i < n; i++) {
		sol[k] = i;// sol[k] = vertice i
		int sumaAux = suma;
		if (es_Solucion(matriz, usados, k, n, sol)) { //si es solucion, hace la suma con el vertice anterior y con el vertice 0
			sumaAux += matriz[sol[k - 1]][sol[k]];
			sumaAux += matriz[sol[k]][sol[0]];
			if (sumaAux < suma_Min) { //si la suma es menor que la actual, se procesa la solucion y se guarda la suma en la variable global suma_Min
				//procesar_Solucion(sol);
				solMin = sol;
				suma_Min = sumaAux;
			}
		}
		else if (es_Completable(matriz, usados, k, n, sol) && es_Prometedora(sumaAux, suma_Min, k, n, min_Arista)) {
			sumaAux += matriz[sol[k - 1]][sol[k]]; //si es completable y prometedora, hace la suma con la cantidad anterior y con la del vertice anterior
			usados[i] = true; //marcador del vertice i = true
			problema_Del_Viajante(matriz, usados, k + 1, n, sol, sumaAux, min_Arista, solMin);
			usados[i] = false; //desmarca el vertice i si sale de la recurrencia
		}


	}
}

int busca_Menor(const vector <vector<int>> &matriz) {  //busca la arista de menor valor para hacer el es_Prometedora
	int menor = 10000;
	for (int i = 0; i < matriz.size(); i++) {
		for (int j = 0; j < matriz[i].size(); j++) {
			if (matriz[i][j] < menor) {
				menor = matriz[i][j];
			}
		}
	}
	return menor;
}

int main() {
	vector <vector<int>> matriz(5, vector<int>(5));
	matriz[0][1] = 1;
	matriz[0][2] = 10;
	matriz[1][0] = 1;
	matriz[1][2] = 1;
	matriz[1][3] = 5;
	matriz[1][4] = 1;
	matriz[2][0] = 10;
	matriz[2][1] = 1;   
	matriz[2][3] = 32;
	matriz[2][4] = 4;
	matriz[3][1] = 5;
	matriz[3][2] = 32;
	matriz[3][4] = 2;
	matriz[4][1] = 1;
	matriz[4][2] = 4;
	matriz[4][3] = 2;
	vector<bool> usados;
	usados.resize(5);
	vector <int> sol;
	vector <int> min;
	sol.resize(5);
	int min_Arista = busca_Menor(matriz);
	problema_Del_Viajante(matriz, usados, 1, 5, sol, 0, min_Arista, min);
	procesar_Solucion(min);
	cout << suma_Min;

	system("pause");
	return 0;
}