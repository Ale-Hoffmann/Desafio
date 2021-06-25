#include "Portal.h"

Portal::Portal()
{
	X = 500;
	Y = 500;
}

Portal::Portal(int tp)
{
	tipo = tp;

	if (tipo == 1)
	{
		X = 500;
		Y = 500;
	}
	if (tipo == 2)
	{
		X = 500;
		Y = 200;
	}
}

void Portal::inicializar()
{
	inicializarSprite();
}

void Portal::executar()
{
	executarSprite();
}

void Portal::inicializarSprite()
{
	if (!gRecursos.carregouSpriteSheet("nPorta"))
	{
		gRecursos.carregarSpriteSheet(("nPorta"), ("../assets/PortaAux.png"));
	}
	porta.setSpriteSheet("nPorta");
	porta.setEscala(0.2, 0.2);
}

void Portal::executarSprite()
{
	porta.desenhar(X, Y);
}

void Portal::setTipo(int tp)
{
	tipo = tp;

	if (tipo == 1)
	{
		X = 500;
		Y = 500;
	}
	if (tipo == 2)
	{
		X = 500;
		Y = 200;
	}
}

Sprite Portal::getSprite()
{
	return porta;
}

int Portal::getX()
{
	return X;
}

int Portal::getY()
{
	return Y;
}

int Portal::getTipo()
{
	return tipo;
}
