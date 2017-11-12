#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

//Funcion con coste O(Log(n)), donde n es fin - ini, es decir, el espacio recorrido en el vector
bool elemento_situado(const vector < int >& v, int ini, int fin){
	//Atributes
	int med = (ini + fin)/ 2;
	int n = fin - ini;

	//Function
	if (n < 2){
		return (n == 0) ? false : (v[ini] == ini);
		/*return false;
	else if (fin - ini == 1){
		if (v[ini] == ini)
			return true;
		else
			return false;*/
	}
	else if (v[med] == med) {
		return true;
	}
	else if (v[med] < med) {
		elemento_situado(v, med, fin);
	}
	else if (v[med] > med) {
		elemento_situado(v, ini, med);
	}
	/*else if(elemento_situado(v, ini, med)){
		return true;	
	}
	else if (elemento_situado(v, med, fin)) {     //esto es válido para vectores desordenados
		return true;
	}
	else return false;*/
}

void rellenaVector(vector < int >& v) {
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
}

void creaVector(vector < int >& v){
	//Atributes
	int tamanyo;

	//Function
	cin >> tamanyo;
	v.resize(tamanyo); //adapta el vector (?) al tamaño que le indicamos
	rellenaVector(v);
}

int main(){
	//Atributes
	int n;
	int i = 0;
	vector <int> v;

	//Function
	cin >> n; //pide el numero de vectores que se quieres comprobar
	while (i < n) {
		creaVector(v);

		if (elemento_situado(v, 0, v.size())) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		i++;
	}
	return 0;
}