#include "Zumbi.h"

Zumbi::Zumbi()
{
	setSprite("imagemzumbi", "../assets/zumbi.png");
	setTipo(2);
	vida = 1;
}

void Zumbi::morrer()
{
	vida = 0;
}

bool Zumbi::getVivo()
{
	if (vida == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
