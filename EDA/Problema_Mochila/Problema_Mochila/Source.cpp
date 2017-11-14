#include <vector>
#include <string>
#include <iostream>
#include <float.h>
using namespace std;


const vector <int> valor = { 1, 2, 5, 10};
const vector <int> pesoObjeto = { 5, 10, 15, 20};
const int pesoMochila = 30;
int valor_Max = 0;

bool es_Solucion(int k, const vector <bool> &sol, int pesoActual) {
	return (k == sol.size() - 1 && pesoActual <= pesoMochila);
}
bool es_Completable(int k, const vector <bool> &sol, int pesoActual) {
	return (k < sol.size() - 1 && pesoActual <= pesoMochila);
}

void procesar_Solucion(int valorActual) {
	if (valorActual > valor_Max) {
		valor_Max = valorActual;
	}
}

void actualiza_Valores(int &peso, int &valorTemp, const vector <bool> &sol, int k) {
	if (sol[k]) {
		peso = peso + pesoObjeto[k];
		valorTemp = valorTemp + valor[k];
	}
}

bool es_Prometedora(int pesoActual, int valorActual, int densidad_Maxima) {
	int pesoRestante = pesoMochila - pesoActual;
	return ((valorActual + pesoRestante*densidad_Maxima) > valor_Max);
}

int busca_DensidadMax(int tam) {
	int i = 0;
	float densMax = 0;
	while (i < tam)
	{
		float densTemp = valor[i] / pesoObjeto[i]; //problemas de floats q no entiendo loko
		if (densTemp > densMax) {
			densMax = densTemp;
		}
		i++;
	}
	return densMax;
}

void rellenar_Mochila(int peso, int valorTemp, vector <bool> &sol, int k, float densidad_Maxima) {
	bool i =  false;
	int j = 0;
	while (k < sol.size() && j < 2) {
		sol[k] = i;
		int pesoAux = peso;
		int valorAux = valorTemp;
		actualiza_Valores(pesoAux, valorAux, sol, k);
		if (es_Solucion(k, sol, pesoAux)) {
			procesar_Solucion(valorAux);
		}
		else if (es_Completable(k, sol, pesoAux) /*&& es_Prometedora(pesoAux, valorAux, densidad_Maxima)*/) {
			rellenar_Mochila(pesoAux, valorAux, sol, k + 1, densidad_Maxima);
		}
		i = !i;
		sol[k] = i;
		j++;
	}
}
int main() {
	vector <bool> sol;
	sol.resize(4);
	for (int i = 0; i < sol.size(); i++) sol[i] = true;
	float densMax = busca_DensidadMax(valor.size());
	rellenar_Mochila(0, 0, sol, 0, densMax);
	cout << valor_Max;
	system("pause");
	return 0;
}