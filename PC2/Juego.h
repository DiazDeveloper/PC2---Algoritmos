#pragma once
#include "Juego.h"
#include "Jugador.h"
#include "Zombi.h"
#include "Bala.h"
#include <vector>

class Juego
{

private:
	Jugador* player;
	vector <Zombi*> enemies; 
	vector <Bala*> balas;

public:
	Juego(int width, int height);
	void mostrar(Graphics^ canvas);
	void mover(Graphics^ canvas);
	void moverTeclas(Graphics^ canvas, Movimiento movimiento);
	void disparar();
	void CrearZombi(int widht, int height);   
	int getTotalPuntos();
};
