#pragma once
#include"Tela.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

	
private:
	Tela teste;
};

