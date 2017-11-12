#include <iostream>
#include <string>
using namespace std;

const int Fils = 3, Cols = 3;

void vaciarTablero(char vect[Fils][Cols]);
void dibujarTablero(char vect[Fils][Cols]);

int main() {
	char tablero[Fils][Cols];
	vaciarTablero(tablero);
	dibujarTablero(tablero);
	system("pause");
	return 0;
}

void vaciarTablero(char vect[Fils][Cols]) {
	for (int i = 0; i < Fils; i++) {
		for (int j = 0; j < Cols; j++) {
			vect[i][j] = 'X';
		}
	}
}

void dibujarTablero(char vect[Fils][Cols]) {
	for (int i = 0; i < Fils; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << vect[i][j];
		}
		cout << endl;
	}
}