#pragma once
#include "libUnicornio.h"
class Bala
{
public:
	Bala();
	Bala(int t);
	void inicializar();
	void executar();
	void carregarSprite();
	void atualizarSprite();
	void setTipo(int tp);
	void setPos(int x, int y);
	void setDirecao(int dir);
	void voar();


	int getDano();
	int getX();
	int getY();
	Sprite getImagem();
private:
	Sprite corpo;
	int tipo, dano, X,Y, direcao;
	string nCorpo, endCorpo;
};

