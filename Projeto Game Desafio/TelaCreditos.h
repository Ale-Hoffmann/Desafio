#pragma once
#include"Tela.h"
class TelaCreditos: public Tela
{
public:
	void inicializar() override;
	void executar()override;

	void carregarSprite()override;
	void carregarTexto()override;
	void carregarArquivo()override;
	void carregarBotao();

	void atualizarSprite()override;
	void atualizarTexto()override;
	void atualizarBotao();

	bool NovoJogo();
	int qualSave();

	bool Jogou();
	int proximaTela();

private:
	string nSprite, EndSprite, nTexto, EndTexto, nBotao, EndBotao;
	Sprite fundo;
	BotaoSprite menu;

	bool voltar;
};

