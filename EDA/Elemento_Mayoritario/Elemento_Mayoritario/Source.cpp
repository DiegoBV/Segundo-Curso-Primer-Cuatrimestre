#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Numero_Contador {
	int numero, contador;
};

void busca_Elemento(vector <Numero_Contador> &nc, int elemento) {
	int i = 0;
	bool encontrado = false;

	while (i < nc.size() && !encontrado) {
		if (nc[i].numero == elemento) {          //búsqueda simple en un vector, O(n)
			nc[i].contador++;
			encontrado = true;
		}
		i++;
	}
}

//coste 0(n*log(n))... 2T(n/2) + n
void encuentra_Elemento_Mayoritario(const vector <int> &v, int ini, int fin, vector <Numero_Contador> &nc) {
	int n = fin - ini;

	if (n < 2) {
		busca_Elemento(nc, v[ini]);
	}
	else {
		int mid = (fin + ini) / 2;
		encuentra_Elemento_Mayoritario(v, ini, mid, nc);
		encuentra_Elemento_Mayoritario(v, mid, fin, nc);       //las dos llamadas recursivas a ambos lados...
	}
}

int main() {
	vector <Numero_Contador> nc;
	vector <int> v;
	v.resize(1);
	for (int i = 0; i < v.size(); i++) {         //pruebas con vectores
		v[i] = rand() % 2;
		cout << v[i] << " ";
	}
	cout << endl;
	nc.resize(v.size());

	for (int i = 0; i < nc.size(); i++) {
		nc[i].numero = v[i];                   //relleno el vector de nc con lois numeros de v
		nc[i].contador = 0;
	}

	encuentra_Elemento_Mayoritario(v, 0, v.size(), nc);

	int i = 0;
	bool encontrado = false;

	while (i < nc.size() && !encontrado) {
		if (nc[i].contador > v.size() / 2) {  //si el elemento aparece más de n veces es mayoritario
			cout << "El elemento mayoritario es " << nc[i].numero << " y aparece " << nc[i].contador << " veces" << endl;
			encontrado = true;
		}
		i++;
	}

	if (!encontrado) {
		cout << "No existe elemento mayoritario" << endl;
	}
	system("pause");
	return 0;
}