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
	void contato(string tp, int vl);


	int getX();
	int getY();
	int getVida();
	Sprite getImagem();
	string getDirecao();
	string getTxtVida();


private:
	Sprite player;
	string direcao;
	int xPer, yPer,vida,energia;
};

