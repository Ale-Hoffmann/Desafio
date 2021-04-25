#include "TelaMenu.h"



void TelaMenu::inicializar()
{
	carregarArquivo();
	carregarSprite();
	carregarTexto();
	carregarBotao();
}

void TelaMenu::executar()
{
	
	atualizarSprite();
	atualizarTexto();
    atualizarBotao();
}

void TelaMenu::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1.2, 1.5);
}

void TelaMenu::carregarTexto()
{
	gRecursos.carregarFonte(nTexto, EndTexto);
	titulo.setFonte(nTexto);
	titulo.setEscala(3, 3);
	titulo.setAlinhamento(TEXTO_CENTRALIZADO);
	titulo.setCor(0, 0, 0);
}

void TelaMenu::carregarArquivo()
{

	string dado;

	ifstream lerArq;
	lerArq.open("arqTelaMenu.txt", ios::in);
	if (lerArq.is_open())
	{
		do
		{
			lerArq >> dado;
			if (dado == "texto")
			{
				lerArq >> dado;
				nTexto = dado;
				lerArq >> dado;
				EndTexto = dado;
			}
			if (dado == "botao")
			{
				lerArq >> dado;
				nBotao = dado;
				lerArq >> dado;
				EndBotao = dado;
			}
			if (dado == "sprite")
			{
				lerArq >> dado;
				nSprite = dado;
				lerArq >> dado;
				EndSprite = dado;
			}
		} while (dado != "fim");
		lerArq.close();
	}
}

void TelaMenu::carregarBotao()
{
	gRecursos.carregarSpriteSheet(nBotao, EndBotao);
	jogar.setSpriteSheet(nBotao);
	jogar.setPos(500,300);
}

void TelaMenu::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void TelaMenu::atualizarTexto()
{
	titulo.setString("O DESAFIO");
	titulo.desenhar(505, 100);
}

void TelaMenu::atualizarBotao()
{
	jogar.atualizar();
	jogar.desenhar();
}

bool TelaMenu::Jogou()
{
	if (jogar.estaClicado())
	{
		return true;
	}
	else
	{
		return false;
	}
}


