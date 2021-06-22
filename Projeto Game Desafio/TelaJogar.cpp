#include "TelaJogar.h"

TelaJogar::TelaJogar()
{
	botoes = new BotaoSprite[3];
	nBotao = new string[3];
	EndBotao = new string[3];
}

void TelaJogar::inicializar()
{
	carregarArquivo();
	carregarSprite();
	//carregarTexto();
	carregarBotao();
}

void TelaJogar::executar()
{
	atualizarSprite();
	//atualizarTexto();
	atualizarBotao();
}

void TelaJogar::carregarSprite()
{
	if (!gRecursos.carregouSpriteSheet(nSprite))
	{
		gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	}
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1, 1);
}

void TelaJogar::carregarTexto()
{

}

void TelaJogar::carregarArquivo()
{
	int aBotao = 0;
	string dado;

	ifstream lerArq;
	lerArq.open("arqTelaJogar.txt", ios::in);
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
				nBotao[aBotao] = dado;
				lerArq >> dado;
				EndBotao[aBotao] = dado;
				aBotao++;
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

void TelaJogar::carregarBotao()
{
	for (int i = 0; i < 3; i++)
	{
		if (!gRecursos.carregouSpriteSheet(nBotao[i]))
		{
			gRecursos.carregarSpriteSheet(nBotao[i], EndBotao[i],2,1);
			botoes[i].getSprite()->setEscala(0.3, 0.3);
		}
		botoes[i].setSpriteSheet(nBotao[i]);
	}
	botoes[0].getSprite()->setEscala(0.3, 0.3);
	botoes[0].setPos(500, 250);
	botoes[1].setPos(500, 350);
	botoes[2].setPos(500, 450);
}

void TelaJogar::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void TelaJogar::atualizarTexto()
{

}

void TelaJogar::atualizarBotao()
{
	for (int i = 0; i < 3; i++)
	{
		botoes[i].atualizar();
		botoes[i].desenhar();
	}
}

bool TelaJogar::Jogou()
{
	if (botoes[0].estaClicado())
	{
		return true;
	}
	if (botoes[1].estaClicado())
	{
		return true;
	}
	if (botoes[2].estaClicado())
	{
		return true;
	}

	else
	{
		return false;
	}
}

int TelaJogar::proximaTela()
{
	return 3;
}

