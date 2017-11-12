#include "Score.h"


Score::Score()
{
}


Score::~Score()
{
}


bool Score::Load(const string& fileName){
	//Atributes
	int punt = 0;
	char c;
	ifstream ficha;
	ScoreReg datos;

	//Open file and read it
	ficha.open(fileName);
	
	getline(ficha, datos.nom);

	while (!ficha.fail()){
		ficha >> datos.punt;
		ficha.get(c);
		scores.push_back(datos);
		getline(ficha, datos.nom);
	}

	ficha.close();

	return true;
}


bool Score::save(const string& fileName){
	//Atributes
	ofstream ficha;
	//Function
	ficha.open(fileName);
	for (int i = 0; i < scores.size(); i++){
		ficha << scores[i].nom << endl;
		ficha << scores[i].punt << endl;
	}
	ficha.close();

	return true;
}

void Score::addScore(const string& name, uint score) {
	//Atributes
	int i = 0;
	ScoreReg datos;
	datos.nom = name;
	datos.punt = score;
	//Function
	while (i < scores.size() && score < scores[i].punt) {
		i++;
	}
	scores.insert(datos, i); //inserta los datos de score en la posicion i del vector

}

void Score ::printTopScores(uint number){
    cout << "Mejores puntuaciones: " << endl;

    for (int i = 0; i < number; i++){
        cout << scores[i].nom << endl;
        cout << scores[i].punt << endl;
    }
}