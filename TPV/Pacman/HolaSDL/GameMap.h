#pragma once
#include "Texture.h"
#include "SDL.h"
enum MapCell { Empty, Wall, Food, Vitamins };

class GameMap
{
private:
	MapCell** tablero;
	Texture* vitamina;
	Texture* muro;
	Texture* comida;
	int rows;
	int cols;
	//Game* game;
public:
	GameMap(/*int rows, int cols, Texture* vit, Texture* m, Texture* com*/);
	~GameMap();
	void crea_Mapa(Texture* vit, Texture* m, Texture* com, MapCell** tab);
	string consulta_Posicion(int x, int y);
	void modifica_Posicion(int x, int y, MapCell nuevoObjeto);
	void render_Mapa(SDL_Renderer* &rnd);
	void destruir_Mapa();

};

