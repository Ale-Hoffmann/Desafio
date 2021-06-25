#pragma once
#include"TelaCombate.h"
#include"TelaMenu.h"
#include"TelaMorte.h"
#include"TelaControles.h"
#include"TelaCreditos.h"
#include "TelaJogar.h"
#include "Pilha.h"
#include"Arvore.h"
#include"Usuario.h"
#include"GerenciadorDeArquivo.h"

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
	//GerenciadorDeArquivo ger;
	//Usuario play;
	Pilha<int> Voltar;
	Tela *teste[6];
	Arvore<TelaCombate> combates;
	int qTelas, telaAtual,telaCombateAtual;
	TelaCombate* aux;
};

