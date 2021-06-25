#pragma once
#include"Arma.h"
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
	void contatoInimigo(int x, int y);
	void morrer();


	int getX();
	int getY();
	int getVida();
	Sprite getImagem();
	string getDirecao();
	string getTxtVida();
	bool getVivo();
	Arma getArma();

private:
	Sprite player;
	Arma arma;
	string direcao;
	int xPer, yPer,vida,energia;
	bool vivo;
};

