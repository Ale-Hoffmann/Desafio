#include "TelaMorte.h"

void TelaMorte::inicializar()
{
	carregarArquivo();
	carregarSprite();
	carregarTexto();
	carregarBotao();
}

void TelaMorte::executar()
{
	atualizarSprite();
	atualizarTexto();
	atualizarBotao();
}

void TelaMorte::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1.2, 1.5);
}

void TelaMorte::carregarTexto()
{
	gRecursos.carregarFonte(nTexto, EndTexto);
	morreu.setFonte(nTexto);
	morreu.setEscala(3, 3);
	morreu.setAlinhamento(TEXTO_CENTRALIZADO);
	morreu.setCor(1, 0, 0);
}

void TelaMorte::carregarArquivo()
{
	string dado;

	ifstream lerArq;
	lerArq.open("arqTelaMorte.txt", ios::in);
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

void TelaMorte::carregarBotao()
{
	gRecursos.carregarSpriteSheet(nBotao, EndBotao);
	menu.setSpriteSheet(nBotao);
	menu.setPos(500, 300);
}

void TelaMorte::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void TelaMorte::atualizarTexto()
{
	morreu.setString("Você Morreu");
	morreu.desenhar(505, 100);
}

void TelaMorte::atualizarBotao()
{
	menu.atualizar();
	menu.desenhar();
}

bool TelaMorte::Jogou()
{
	if (menu.estaClicado())
	{
		return true;
	}
	else
	{
		return false;
	}
}
