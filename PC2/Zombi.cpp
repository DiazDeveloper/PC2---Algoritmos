#include "Zombi.h"

Zombi::Zombi(int x, int y, int direccion) : Entidad(x, y, "Images/enemigo.png", 8, 2)
{
	dx = 15; 
	this->direccion = direccion;  
}

void Zombi::mover(Graphics^ canvas)
{
	if (direccion == 1)
	{
		if (x + ancho > canvas->VisibleClipBounds.Width || x < 0)
		{
			dx *= -1; 
		}
		indiceAlto = dx > 0 ? 1 : 0; 
		x += dx;
	}

	indiceAncho++;

	if (indiceAncho > 7)
	{
		indiceAncho = 0;
	}
}
