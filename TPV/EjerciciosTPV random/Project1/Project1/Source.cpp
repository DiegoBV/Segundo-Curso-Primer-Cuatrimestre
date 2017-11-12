#include <iostream>
#include <string>
using namespace std;

struct Coordenadas
{
	int x, y;
};
void rellenaMatrizM(int matriz[10][10]);
void rellenaMatrizP(int matriz[3][3]);
void muestraMatrizM(int matriz[10][10]);
void muestraMatrizP(int matriz[3][3]);
Coordenadas encuentraMatrizP(const int matrizM[10][10], const int matrizP[3][3]);

int main() {
	int matrizM[10][10];
	int matrizP[3][3];
	rellenaMatrizM(matrizM);
	rellenaMatrizP(matrizP);
	muestraMatrizM(matrizM);
	muestraMatrizP(matrizP);
	Coordenadas cord = encuentraMatrizP(matrizM, matrizP);
	if (cord.x > 0) {
		cout << "La matriz pequenyita esta en la fila " << cord.x << " y en la columna " << cord.y << endl;
	}
	else {
		cout << "La matriz pequenyita no esta :( ";
	}
	system("pause");
	return 0;
}

void rellenaMatrizM(int matriz[10][10]) {
	for (int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++){
			matriz[i][j] = rand() % 10;

		}
	}
	//Pruebas
	matriz[1][7] = 1;
	matriz[1][8] = 2;
	matriz[1][9] = 3;
	matriz[2][7] = 4;
	matriz[2][8] = 5;
	matriz[2][9] = 6;
	matriz[3][7] = 7;
	matriz[3][8] = 8;
	matriz[3][9] = 9;
}

void rellenaMatrizP(int matriz[3][3]) {
	int cont = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cont += 1;
			matriz[i][j] = cont;

		}
	}
}

void muestraMatrizM(int matriz[10][10]) {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << matriz[i][j] << "  ";

		}
		cout << endl;
	}
	cout << endl;
}

void muestraMatrizP(int matriz[3][3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matriz[i][j] << "  ";

		}
		cout << endl;
	}
	cout << endl;

}


Coordenadas encuentraMatrizP(const int matrizM[10][10], const int matrizP[3][3]) {
	Coordenadas coord;
	coord.x = -1;
	coord.y = -1;
	int i = 0;
	bool existe = false;
	while (i < 10 && !existe) {
		int j = 0;
		while (j < 10 && !existe) {
			if (matrizM[i][j] == matrizP[0][0] && j <= 7 && i <= 7) { //comprobacion de los limites también
				if (matrizM[i][j + 1] == matrizP[0][1] && matrizM[i][j + 2] == matrizP[0][2]) {
					if (matrizM[i + 1][j] == matrizP[1][0] && matrizM[i + 1][j + 1] == matrizP[1][1] && matrizM[i + 1][j + 2] == matrizP[1][2]) {
						if (matrizM[i + 2][j] == matrizP[2][0] && matrizM[i + 2][j + 1] == matrizP[2][1] && matrizM[i + 2][j + 2] == matrizP[2][2]) {
							existe = true;
							coord.x = i;
							coord.y = j;
						}
					}
				}
			}
			j++;
		}
		i++;
	}

	return coord;
}
