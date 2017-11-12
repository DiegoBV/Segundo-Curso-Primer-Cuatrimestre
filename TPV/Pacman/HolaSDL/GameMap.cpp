#include "GameMap.h"
#include "Game.h"


GameMap::GameMap(/*int fils, int colum, Texture* vit, Texture* m, Texture* com*/)
{
	rows = 200;
	cols = 200;
	/*
	tablero = new MapCell*[rows];
	for (int i = 0; i < rows; i++) {
		tablero[i] = new MapCell[cols];
	}*/
}


GameMap::~GameMap()
{
	for (int i = 0; i < rows; i++) {
		delete[] tablero[i];
	}
	delete[] tablero;
}

void GameMap::crea_Mapa(Texture* vit, Texture* m, Texture* com, MapCell** tab) {
	vitamina = vit;
	muro = m;
	comida = com;
	tablero = new MapCell*[rows];
	for (int i = 0; i < rows; i++) {  //lo tiene q hacer el constructor pero aun no tengo ni zorraaaa
		tablero[i] = new MapCell[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			tablero[i][j] = tab[i][j];
		}
	}
}
string GameMap::consulta_Posicion(int x, int y) {
	string pos;
	switch (tablero[x][y]) {
	case Empty:
		pos = "Empty";
		break;
	case Wall:
		pos = "Wall";
		break;
	case Food:
		pos = "Food";
		break;
	case Vitamins:
		pos = "Vitamins";
		break;
	default:
		pos = "Error";
		break;	
	}

	return pos;
}

void GameMap::modifica_Posicion(int x, int y, MapCell nuevoObjeto) {
	tablero[x][y] = nuevoObjeto;
}

void GameMap::render_Mapa(SDL_Renderer* &rnd) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			SDL_Rect des;
			des.x = i;
			des.y = j;
			des.w = 30; //pruebas, deberia coger la anchura del game
			des.h = 30;
			switch (tablero[i][j]) {
			case Empty:
				//algo
				break;
			case Wall:
				muro->RenderFrame(rnd, des);
				break;
			case Food:
				comida->RenderFrame(rnd, des);
				break;
			case Vitamins:
				vitamina->RenderFrame(rnd, des);
				break;
			}
		}
	}
}
