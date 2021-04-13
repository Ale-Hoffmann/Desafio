#pragma once
#include"Personagem.h"
#include"Cura.h"
class Tela
{
public:
	Tela();
	void inicializar();
	void executar();

	void carregarSprite();
	void carregarTexto();
	void atualizarSprite();
	void atualizarTexto();
	void colisão();

private:
	Personagem principal;
	Cura* teste;
	Texto TxtVida;
	Sprite fundo;
};

