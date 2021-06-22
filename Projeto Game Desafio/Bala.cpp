#include "Bala.h"


Bala::Bala()
{
}

Bala::Bala(int t)
{
	setTipo(t);
}

void Bala::inicializar()
{
	carregarSprite();
}

void Bala::executar()
{
	atualizarSprite();
}

void Bala::carregarSprite()
{
	if (!gRecursos.carregouSpriteSheet(nCorpo))
	{
		gRecursos.carregarSpriteSheet(nCorpo, endCorpo);
	}
	corpo.setSpriteSheet(nCorpo);
	corpo.setEscala(1, 1);
}

void Bala::atualizarSprite()
{
	corpo.desenhar(X, Y);
	voar();
}

void Bala::setTipo(int tp)
{
	tipo = tp;
	switch (tipo)
	{
	case 1:
		dano = 2;
		nCorpo = "tiroBruxa";
		endCorpo = "../assets/poderBruxa.png";
		break;
	case 2:
		dano = 1;
		nCorpo = "tiroCartola";
		endCorpo = "../assets/tirinho.png";
		break;
	case 3:
		dano = 3;
		nCorpo = "tiroFormando";
		endCorpo = "../assets/lgUnisinos.png";
		break;

	default:
		break;
	}
}

void Bala::setPos(int x, int y)
{
	X = x;
	Y = y;
}

void Bala::setDirecao(int dir)
{
	direcao = dir;
}

void Bala::voar()
{
	if (direcao == 1)
	{
		Y--;
	}
	if (direcao == 2)
	{
		X--;
	}
	if (direcao == 3)
	{
		Y++;
	}
	if (direcao == 4)
	{
		X++;
	}
}

int Bala::getDano()
{
	return dano;
}

int Bala::getX()
{
	return X;
}

int Bala::getY()
{
	return Y;
}

Sprite Bala::getImagem()
{
	return corpo;
}
