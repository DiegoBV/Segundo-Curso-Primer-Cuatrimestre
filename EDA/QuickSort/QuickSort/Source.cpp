#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Ij {
	int  i, j;
};

void quick_Sort(vector <int> &v, int ini, int fin);
Ij partition(vector <int> &v, int ini, int fin, int pivote);
int elige_Pivote(const vector <int> &v, int ini, int fin);
void swap(int &x, int &y);

int main() {
	vector<int> v;
	v.resize(10);
	for (int i = 0; i < v.size(); i++) {
		v[i] = rand() % 20;
		cout << v[i] << "  ";
	}
	cout << endl;
	quick_Sort(v, 0, v.size());
	cout << "Vector ordenado yey" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "  ";
	}
	system("pause");
	return 0;
}


void swap(int &x, int &y) {
	int aux = x;
	x = y;
	y = aux;
}

int elige_Pivote(const vector <int> &v, int ini, int fin) {
	int a, b, c, med;
	a = ini; //primer elemento de v
	b = (ini + fin) / 2; //elemento intermedio de v
	c = fin - 1; //último elemento de v
	
	if ((v[a] >= v[b] && v[a] <= v[c]) || (v[a] <= v[b] && v[a] >= v[c])) {
		med = v[a];
	}
	else if ((v[b] >= v[a] && v[a] <= v[c]) || (v[b] <= v[a] && v[b] >= v[c])) {
		med = v[b];
	}
	else {
		med = v[c];
	}
	return med;
}

Ij partition(vector <int> &v, int ini, int fin, int pivote) {
	Ij punteros;
	punteros.i = ini;
	punteros.j = ini;
	int k = fin - 1;

	while (punteros.j <= k) {
		if (v[punteros.j] < pivote) {
			swap(v[punteros.j], v[punteros.i]);
			punteros.i++;
			punteros.j++;
		}
		else if (v[punteros.j] > pivote) {
			swap(v[punteros.j], v[k]);
			k--;
		}
		else {
			punteros.j++;
		}

	}

	return punteros;

}

void quick_Sort(vector <int> &v, int ini, int fin) {
	int n = fin - ini;
	if (n >= 2) {
		Ij punt;
		int piv = elige_Pivote(v, ini, fin);
		punt = partition(v, ini, fin, piv);
		quick_Sort(v, ini, punt.i);
		quick_Sort(v, punt.j, fin);
	}
}