#pragma once
#include"TelaCombate.h"
#include"TelaMenu.h"
#include"TelaMorte.h"
#include"TelaControles.h"
#include "TelaJogar.h"
#include "Pilha.h"
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
	Pilha<int> Voltar;
	Tela *teste[5];
	int qTelas, telaAtual;
};

