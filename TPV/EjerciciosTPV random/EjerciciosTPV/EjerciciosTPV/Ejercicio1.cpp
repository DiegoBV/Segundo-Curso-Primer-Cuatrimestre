#include <iostream>
#include <string>
#include <vector>
using namespace std;

void muestraVector(int hey[], int n); 
void mueveDerecha(int vect[], int n);
void swap(int& a, int& b);
int sumaPares(int vect[], int n);
int max(int vect[], int n);

int main() {
	int vect[10] = { 0,1,3,4,1,6,0,8,0,78 };
	muestraVector(vect, 10);
	/*mueveDerecha(vect, 10);
	muestraVector(vect, 10);*/
	/*int suma = sumaPares(vect, 10);
	cout << suma;*/
	int maxi = max(vect, 10);
	cout << maxi;
	system("pause");
	return 0;
}

void muestraVector(int hey[], int n) {
	for (int i = 0; i < n; i++) {
		cout << hey[i] << " ";
	}
	cout << endl;
}
void swap(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}

void mueveDerecha (int vect[], int n){
	
	for (int i = 0; i < n - 1; i++) {
		
		swap(vect[0], vect[i + 1]);
	}

}

int sumaPares(int vect[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i += 2) {
		suma += vect[i];
	}
	return suma;
}

int max(int vect[], int n) {
	int maxi = -10000; //guarradaaaaa
	for (int i = 0; i < n; i++) {
		if (vect[i] > maxi) {
			maxi = vect[i];
		}
	}
	return maxi;
}
