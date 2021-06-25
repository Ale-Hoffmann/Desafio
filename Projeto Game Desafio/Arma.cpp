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
<<<<<<< HEAD
<<<<<<< HEAD
	
     gRecursos.carregarSpriteSheet("nArma", "../assets/espada.png",4,1);
	
=======
	gRecursos.carregarSpriteSheet("nArma", "../assets/espada.png",4,1);
>>>>>>> parent of 011bbc3 (arvore implementando)
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
