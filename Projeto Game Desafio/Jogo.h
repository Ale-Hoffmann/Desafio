#pragma once
#include"TelaCombate.h"
#include"TelaMenu.h"
#include"TelaMorte.h"
#include"TelaControles.h"
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
	Tela *teste[4];
	int qTelas, telaAtual;
};

