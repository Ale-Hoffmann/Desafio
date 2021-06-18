#include "Cura.h"

Cura::Cura()
{
	setTag("cura");
	setPreco(15);
	setValor(21);
	setImagem("Coracao", "../assets/CoracaoU.png");
}

Cura::Cura(int tm)
{
	setTag("cura");
	setImagem("Coracao", "../assets/CoracaoU.png");
	
	//setImagem(nome , endereço);
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
