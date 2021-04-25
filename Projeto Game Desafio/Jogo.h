#pragma once
#include"TelaCombate.h"
#include"TelaMenu.h"
class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	void passaTela();

	
private:
	Tela *teste[2];
	int qTelas, telaAtual;
};

