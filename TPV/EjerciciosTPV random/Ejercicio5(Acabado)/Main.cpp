#include "Score.h"

int main(){
	string file = "Fichero.txt";
	Score datos;
	datos.Load(file);
	string name = "d";
	uint score;
	bool finish = false;
	int n;
	while (!finish) {
		cout << "Introduce nombre: ";
		getline(cin, name);
		if (!name.empty()) {
			cout << "Introduce puntuacion: ";
			cin >> score;
			datos.addScore(name, score);
			cout << "Introduce N para mostrar los N mejores resultados: ";
			cin >> n;
			datos.printTopScores(n);
			cin.ignore();
		}
		else {
			finish = true;
		}
	}
	datos.save(file);
	system("pause");
	return 0;
}