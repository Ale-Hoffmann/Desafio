#include "Chapeus.h"

void Chapeus::inicializar()
{
	atirando = false;
	carregarSprite();
	a->inicializar();
}

void Chapeus::executar()
{
	atualizarSprite();
	atirar();
}

void Chapeus::setAncora(int x, int y)
{
	X = x;
	Y = y;
}

void Chapeus::setBala(int tp)
{
	a = new Bala(tp);
}

void Chapeus::tiro()
{
	a->executar();
}

void Chapeus::atirar()
{
	if (gTeclado.pressionou[TECLA_F] && atirando == false)
	{
		atirando = true;
		tiro();
	}
	else
	{
		a->setPos(X, Y);
		a->setDirecao(3);
	}

}

Bala Chapeus::getBala()
{
	return *a;
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
	corpo.setEscala(0.2, 0.2);

}

void Chapeus::atualizarSprite()
{
	corpo.desenhar(X-50, Y-50);
}


