#include "Arma.h"

Arma::Arma()
{
	dir = 0;
	dano = 1;
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
	
     gRecursos.carregarSpriteSheet("nArma", "../assets/espada.png",4,1);
	
	imagem.setSpriteSheet("nArma");
	imagem.setEscala(0.15,0.15);
}

void Arma::executarSprite()
{
	imagem.desenhar(X, Y);
	imagem.setAnimacao(dir);
}

void Arma::setarPosicao(int x, int y)
{
	X = x;
	Y = y;
}

void Arma::setDirecao(int a)
{
	dir = a;
}

int Arma::getDano()
{
	return dano;
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
