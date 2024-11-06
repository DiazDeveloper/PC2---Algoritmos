#pragma once
#include "Entidad.h"
class Zombi : public Entidad
{
private:
	int direccion;
public:
	Zombi(int x, int y, int direccion);
	void mover(Graphics^ canvas); 
};

