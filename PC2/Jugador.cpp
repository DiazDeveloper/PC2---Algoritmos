#include "Jugador.h"

void Jugador::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = alto = 60; 
	canvas->DrawImage(sprite, x, y, ancho, alto); 
}

Jugador::Jugador(int x, int y) : Entidad(x, y, "Images/jugador.png", 1, 1)
{
	dx = dy = 10;  
	movimiento = Derecha;   
}

void Jugador::MoverTeclar(Graphics^ canvas, Movimiento movimiento)
{
	this->movimiento = movimiento;
	switch (movimiento)
	{
	case Arriba: 
		y -= dy;
		break;
	case Abajo:
		y += dy;
		break;
	default:
		break;
	}
	if (x < 0)
	{
		x = 0;
	}

	if (y < 0)
	{
		y = 0;
	}

	if (x + ancho > canvas->VisibleClipBounds.Width)
	{
		x = canvas->VisibleClipBounds.Width - ancho;
	}

	if (y + alto > canvas->VisibleClipBounds.Height)
	{
		y = canvas->VisibleClipBounds.Height - alto;
	}

}

Movimiento Jugador::getMovimiento()
{
	return movimiento;   
}
