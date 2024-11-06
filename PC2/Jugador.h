#pragma once
#include "Entidad.h"
class Jugador : public Entidad
{
private:
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);
public:
	Jugador(int x, int y); 
	void MoverTeclar(Graphics^ canvas, Movimiento movimiento); 
	Movimiento getMovimiento(); 
};

