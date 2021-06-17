#include "Chapeus.h"

void Chapeus::inicializar()
{
	carregarSprite();
}

void Chapeus::executar()
{
	atualizarSprite();
}

void Chapeus::setAncora(int x, int y)
{
	X = x;
	Y = y;
}

void Chapeus::setSprite(string n, string end)
{
	nCorpo = n;
	endCorpo = end;
}

void Chapeus::carregarSprite()
{
	if (!gRecursos.carregouSpriteSheet(nCorpo))
	{
		gRecursos.carregarSpriteSheet(nCorpo, endCorpo);
	}
	corpo.setSpriteSheet(nCorpo);
	corpo.setEscala(1, 1);

}

void Chapeus::atualizarSprite()
{
	corpo.desenhar(X, Y);
}

void Chapeus::setArma(Arma *atual)
{
	a = new Arma;
	a = atual;
}
