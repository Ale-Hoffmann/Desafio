#pragma once
#include"Cura.h"
#include"Personagem.h"
#include "libUnicornio.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

	void colisão();
private:
	Personagem principal;
	Cura* teste;
};

