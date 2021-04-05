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
	setImagem("Potion", "../assets/Potion.png");
	tipo = tm;
	//setImagem(nome , endereço);
	switch (tipo)
	{
	case 1:
		setPreco(15);
		setValor(25);

	case 2:
		setPreco(30);
		setValor(50);
	case 3:
		setPreco(60);
		setValor(100);
	default:
		break;
	}
	
}
