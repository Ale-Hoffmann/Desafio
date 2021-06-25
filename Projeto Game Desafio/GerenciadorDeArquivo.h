#pragma once
#include"Lista.h"
#include"Save.h"
#include"libUnicornio.h"
#include <fstream>
class GerenciadorDeArquivo
{
public:
	void criarArquivoSave(string nm, int tp);
	void setSaveAtual(int at);
	void escreverNoSave( string nmUsuario, int nFase, int moedas, int vida, int quantChap);
	void excluirSave(int tp);
	void lerSave(int tp);

	Save* getSave();

private:
	
	Save* gerenciador;
	int saveAtual;
};

