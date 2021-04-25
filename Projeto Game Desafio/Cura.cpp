#include "Cura.h"

Cura::Cura()
{
	setTag("cura");
	setPreco(15);
	setValor(25);
	setImagem("Potion", "../assets/Potion.png");
}

Cura::Cura(int tm)
{
	setTag("cura");
	setImagem("Potion", "../assets/Potion.png");
	
	//setImagem(nome , endere�o);
	switch (tm)
	{
	case 1:
		setPreco(15);
		setValor(1);
		break;

	case 2:
		setPreco(30);
		setValor(2);
		break;
	case 3:
		setPreco(60);
		setValor(3);
		break;
	default:
		break;
	}
	
}
