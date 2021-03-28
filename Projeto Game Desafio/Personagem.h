#pragma once
#include"libUnicornio.h"
class Personagem
{
public:
	Personagem();
	Personagem(int x,int y,int v, int e);
	void inicializar();
	void executar();
	void mover();
	void atacar();

private:
	Sprite player;
	int xPer, yPer,vida,energia;
};

