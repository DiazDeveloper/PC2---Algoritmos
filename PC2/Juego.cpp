#include "Juego.h"
int totalPuntos = 0;  
Juego::Juego(int widht, int height) 
{
	player = new Jugador(10, 150);
	Random r;

	for (int i = 0; i < 7; i++)
	{
		int PosicionX = r.Next(0, widht - 35);
		int PosicionY = r.Next(0, height - 46);
		enemies.push_back(new Zombi(PosicionX, PosicionY, 1));  
	}
}

void Juego::mostrar(Graphics^ canvas)
{
	player->mostrar(canvas);  

	for (int i = 0; i < enemies.size(); i++) 
	{
		enemies[i]->mostrar(canvas); 
	}

	for (int i = 0; i < balas.size(); i++)
	{
		balas[i]->mostrar(canvas);  
	}
}

void Juego::mover(Graphics^ canvas)
{
	int totalEnemigos = enemies.size(); 
	int totalBalas = balas.size();  


	for (int i = 0; i < totalEnemigos; i++) 
	{
		enemies[i]->mover(canvas);
	}

    for (int i = totalBalas - 1; i >= 0; i--) {
        balas[i]->mover(canvas);

     
        for (int j = totalEnemigos - 1; j >= 0; j--) {
            if (balas[i]->hayColision(enemies[j])) {

                totalPuntos = totalPuntos + 10; 
                delete balas[i];
                delete enemies[j];

                balas.erase(balas.begin() + i);
                enemies.erase(enemies.begin() + j);  

               
                totalBalas--; 
                totalEnemigos--; 
                break; 
            }
        }

        if (i < totalBalas) {
            if (balas[i]->getX() < 0 ||
                balas[i]->GetXancho() > canvas->VisibleClipBounds.Width ||
                balas[i]->getY() < 0 ||
                balas[i]->GetYalto() > canvas->VisibleClipBounds.Height) {

                delete balas[i];
                balas.erase(balas.begin() + i);
                totalBalas--;
            }
        }
    }
}

void Juego::moverTeclas(Graphics^ canvas, Movimiento movimiento)
{
    player->MoverTeclar(canvas, movimiento);
}

void Juego::disparar()
{
    balas.push_back(new Bala(player->getX(), player->getY(), Derecha)); 
}

void Juego::CrearZombi(int widht, int height)
{
    Random r;
    int PosicionX = r.Next(0, widht - 35);
    int PosicionY = r.Next(0, height - 46);
    enemies.push_back(new Zombi(PosicionX, PosicionY, 1)); 
}

int Juego::getTotalPuntos()
{
    return totalPuntos;  
}


