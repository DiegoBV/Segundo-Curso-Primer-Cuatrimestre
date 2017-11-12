#include <iostream>
#include <string>
using namespace std;

const int Fils = 3, Cols = 3;

void vaciarTablero(char vect[Fils][Cols]);
void dibujarTablero(char vect[Fils][Cols]);
bool tableroLleno(char vect[Fils][Cols]);
bool ganador(char vect[Fils][Cols], char jugador);  
bool posibilidad00(char vect[Fils][Cols], char jugador);
bool posibilidad11(char vect[Fils][Cols], char jugador);    //cubren las 3 posibilades de ganar
bool posibilidad22(char vect[Fils][Cols], char jugador);
int jugadorX(char vect[Fils][Cols]);
int jugadorO(char vect[Fils][Cols]);
void turnos(char vect[Fils][Cols]);

int main() {
	char tablero[Fils][Cols];
	vaciarTablero(tablero);
	/*dibujarTablero(tablero);
	//bool lleno = tableroLleno(tablero);
	bool lleno = ganador(tablero, '0');
	if (lleno) {
		cout << "true";
	}
	else {
		cout << "false";
	}*/
	dibujarTablero(tablero);
	turnos(tablero);
	system("pause");
	return 0;
}

void vaciarTablero(char vect[Fils][Cols]) {
	for (int i = 0; i < Fils; i++) {
		for (int j = 0; j < Cols; j++) {
			vect[i][j] = '_';
		}
	}
}

void dibujarTablero(char vect[Fils][Cols]) {
	system("cls");
	for (int i = 0; i < Fils; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << vect[i][j] << "  ";
		}
		cout << endl;
	}
}

bool tableroLleno(char vect[Fils][Cols]) {
	bool lleno = true;
	int i = 0;
	while (i < Fils && lleno) {
		int j = 0;
		while (j < Cols && lleno) {
			if (vect[i][j] == '_') {
				lleno = false;
			}
			j++;
		}
		i++;
	}
	return lleno;
}

bool ganador(char vect[Fils][Cols], char jugador) {

	if (posibilidad00(vect, jugador)) {
		return true;
	}
	else if (posibilidad00(vect, jugador)) {
		return true;
	}
	else if (posibilidad22(vect, jugador)) {
		return true;
	}
	else return false;

		
}

bool posibilidad00(char vect[Fils][Cols], char jugador) {

	bool haGanado = false;
	if (vect[0][0] == jugador) {
		if (vect[0][1] == jugador &&  vect[0][2] == jugador) {
			haGanado = true;
			return haGanado; //ha ganado
		}
		else if (vect[1][0] == jugador &&  vect[2][0] == jugador) {
			haGanado = true;
			return haGanado;
		}
		else if (vect[1][1] == jugador &&  vect[2][2] == jugador) {
			haGanado = true;
			return haGanado;
		}
	}
	return haGanado;
}

bool posibilidad11(char vect[Fils][Cols], char jugador) {
	bool haGanado = false;
	if (vect[1][1] == jugador) {
		if (vect[1][0] == jugador &&  vect[1][2] == jugador) {
			haGanado = true;
			return haGanado; //ha ganado
		}
		else if (vect[0][1] == jugador &&  vect[2][1] == jugador) {
			haGanado = true;
			return haGanado;
		}
		else if (vect[0][2] == jugador &&  vect[2][0] == jugador) {
			haGanado = true;
			return haGanado;
		}
	}
	return haGanado;
}

bool posibilidad22(char vect[Fils][Cols], char jugador) {
	bool haGanado = false;
	if (vect[2][2] == jugador) {
		if (vect[2][1] == jugador &&  vect[2][0] == jugador) {
			haGanado = true;
			return haGanado; //ha ganado
		}
		else if (vect[1][1] == jugador &&  vect[0][0] == jugador) {
			haGanado = true;
			return haGanado;
		}
		else if (vect[1][2] == jugador &&  vect[0][2] == jugador) {
			haGanado = true;
			return haGanado;
		}
	}
	return haGanado;
}

int jugadorX(char vect[Fils][Cols]) {
	if (!ganador(vect, 'O')) {
		int x, y;
		do
		{
			cout << "Elija posicion X (x) ";
			cin >> x;
			cout << "Elija posicion X (y) ";
			cin >> y;
		} while (x < 0 || x >= 3 || y < 0 || y >= 3);

		if (vect[x][y] == '_') {
			vect[x][y] = 'X';
		}
		dibujarTablero(vect);
		if (tableroLleno(vect)) {
			cout << "Empate";
		}
		jugadorO(vect);
	}
	else {
		cout << "El jugador O ha ganado!!";
		return 0;
	}	
}

int jugadorO(char vect[Fils][Cols]) {
	if (!ganador(vect, 'X')) {
		int x, y;
		do
		{
			cout << "Elija posicion O (x) ";
			cin >> x;
			cout << "Elija posicion O (y) ";
			cin >> y;
		} while (x < 0 || x >= 3 || y < 0 || y >= 3);

		if (vect[x][y] == '_') {
			vect[x][y] = 'O';
		}
		dibujarTablero(vect);
		if (tableroLleno(vect)) {
			cout << "Empate";
		}
		jugadorX(vect);
	}
	else {
		cout << "El jugador X ha ganado!!";
		return 0;
	}
}

void turnos(char vect[Fils][Cols]) {
	jugadorO(vect);
}

