#pragma once
#include "libUnicornio.h"
class Arma
{
public:
	Arma();
	void inicializar();
	void executar();
	void carregarSprite();
	void executarSprite();
	void setarPosicao(int x,int y);

	int getX();
	int getY();
	Sprite getImagem();
private:
	int valor, X, Y;
	Sprite imagem;
};

