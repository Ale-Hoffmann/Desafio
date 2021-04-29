#include "Arma.h"

Arma::Arma()
{
}

void Arma::inicializar()
{
	carregarSprite();
}

void Arma::executar()
{
	executarSprite();
}

void Arma::carregarSprite()
{
	gRecursos.carregarSpriteSheet("nArma", "../assets/espada.png");
	imagem.setSpriteSheet("nArma");
	
	imagem.setEscala(2, 2);
}

void Arma::executarSprite()
{
	
	imagem.desenhar(X, Y);
}

void Arma::setarPosicao(int x, int y)
{
	X = x;
	Y = y;
}

int Arma::getX()
{
	return X;
}

int Arma::getY()
{
	return Y;
}

Sprite Arma::getImagem()
{
	return imagem;
}
