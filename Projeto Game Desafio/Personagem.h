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

	string getDirecao();

private:
	Sprite player;
	string direcao;
	int xPer, yPer,vida,energia;
};

