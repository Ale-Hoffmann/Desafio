#include "TelaMenu.h"



TelaMenu::TelaMenu()
{
	botoes = new BotaoSprite [3];
	nBotao = new string [3];
	EndBotao = new string [3];
}

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
	int btAtual=0;
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
				nBotao[btAtual] = dado;
				lerArq >> dado;
				EndBotao[btAtual] = dado;
				btAtual++;
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
	for (int i = 0; i < 3; i++)
	{
		gRecursos.carregarSpriteSheet(nBotao[i], EndBotao[i],1,2);
		botoes[i].setSpriteSheet(nBotao[i]);
	
	}
	botoes[0].setPos(500, 250);
	botoes[1].setPos(500, 350);
	botoes[2].setPos(500, 450);
	
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
	for (int i = 0; i < 3; i++)
	{
		botoes[i].atualizar();
		botoes[i].setAnimacaoDoEstadoComMouseEmCima(0);
		botoes[i].desenhar();
	}
	
}

bool TelaMenu::Jogou()
{
	if (botoes[0].estaClicado())
	{
		pTela = 2;
		return true;
		
	}
	if (botoes[1].estaClicado())
	{
		pTela = 0;
		return true;
		
	}
	if (botoes[2].estaClicado())
	{  
		pTela = 1;
		return true;	
	}
	else
	{
		return false;
	}
}

int TelaMenu::proximaTela()
{
	return pTela;
}


