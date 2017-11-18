#include "Game.h"
using namespace std;


int main(int argc, char* argv[]) {
	Game juego;
	juego.menu();
	//juego.carga_Archivo("..\\level02.dat");
	juego.run();
	SDL_Quit();
	return 0;
}

