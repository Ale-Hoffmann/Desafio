#pragma once
#include "Tela.h"
class TelaMorte :
    public Tela
{
	void inicializar() override;
	void executar()override;

	void carregarSprite()override;
	void carregarTexto()override;
	void carregarArquivo()override;
	void carregarBotao(); 

	void atualizarSprite()override;
	void atualizarTexto()override;
	void atualizarBotao();

    bool Jogou();
	int proximaTela();

private:
	string nSprite, EndSprite, nTexto, EndTexto, nBotao, EndBotao;
	Sprite fundo;
	BotaoSprite menu;
	Texto morreu;
	bool voltar;
};

