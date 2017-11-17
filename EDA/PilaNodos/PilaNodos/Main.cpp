#include <string>
#include <iostream>
#include "Pila_Nodos.h"
using namespace std;

int main() {
	Pila_Nodos<int> pila;
	pila.push(1);
	pila.push(2);
	pila.push(8);
	pila.push(9);
	pila.representa();
	system("pause");
	return 0;
}