#include "Bala.h"

void Bala::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = alto = 30;
	canvas->DrawImage(sprite, x, y, ancho, alto);
}

Bala::Bala(int x, int y, Movimiento movimiento) : Entidad(x, y, "Images/bala.png", 1, 1)
{
	this->movimiento = movimiento;
	dx = dy = 10;
}

void Bala::mover(Graphics^ canvas)
{
	switch (movimiento)
	{
	case Arriba:
		y -= dy;
		break;
	case Abajo:
		y += dy;
		break;
	case Derecha:
		x += dx;
		break;
	case Izquierda: 
		x -= dx;
		break;
	default:
		break;
	}
}
