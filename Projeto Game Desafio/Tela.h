#pragma once
#include<fstream>
#include"Personagem.h"
#include"Cura.h"
#include"Bicho.h"
#include"Zumbi.h"

class Tela
{
public:
	Tela();
	virtual void inicializar() = 0;
	virtual void executar() = 0;

	virtual void carregarSprite() = 0;
	virtual void carregarTexto() = 0;
	virtual void carregarArquivo() = 0;
	virtual void atualizarSprite() = 0;
	virtual void atualizarTexto() = 0;

	virtual bool Jogou()=0;
	virtual int proximaTela()=0;
	

private:
	
};

