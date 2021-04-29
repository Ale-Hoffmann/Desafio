#pragma once
#include"TelaCombate.h"
#include"TelaMenu.h"
#include"TelaMorte.h"
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
	Tela *teste[3];
	int qTelas, telaAtual;
};

