#include "Bicho.h"

Bicho::Bicho()
{
	setSprite("imagemInimigo", "../assets/zumbi.png");
	setTipo(1);
	vid = 1;
}

void Bicho::morrer()
{
	vid = 0;
}

bool Bicho::getVivo()
{
	if (vid == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
