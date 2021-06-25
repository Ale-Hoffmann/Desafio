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
<<<<<<< HEAD
	
     gRecursos.carregarSpriteSheet("nArma", "../assets/espada.png",4,1);
	
	imagem.setSpriteSheet("nArma");
	imagem.setEscala(0.15,0.15);
=======
	gRecursos.carregarSpriteSheet("nArma", "../assets/espada.png");
	imagem.setSpriteSheet("nArma");
	
	imagem.setEscala(4,4);
>>>>>>> parent of d7dc273 (chapéus implementados e saves também)
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
