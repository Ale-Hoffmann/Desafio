#include "TelaCreditos.h"

void TelaCreditos::inicializar()
{
	carregarArquivo();
	carregarSprite();
	//carregarTexto();
	carregarBotao();
}

void TelaCreditos::executar()
{
	atualizarSprite();
	//atualizarTexto();
	atualizarBotao();
}

void TelaCreditos::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1, 1);
}

void TelaCreditos::carregarTexto()
{

}

void TelaCreditos::carregarArquivo()
{
	string dado;

	ifstream lerArq;
	lerArq.open("arqTelaCreditos.txt", ios::in);
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

void TelaCreditos::carregarBotao()
{
	gRecursos.carregarSpriteSheet(nBotao, EndBotao, 2, 1);
	menu.setSpriteSheet(nBotao);
	menu.setPos(gJanela.getLargura() / 2 - 100, 550);
	menu.getSprite()->setEscala(0.2, 0.2);
}

void TelaCreditos::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void TelaCreditos::atualizarTexto()
{

}

void TelaCreditos::atualizarBotao()
{
	menu.atualizar();
	menu.desenhar();
}

bool TelaCreditos::NovoJogo()
{
	return false;
}

int TelaCreditos::qualSave()
{
	return 0;
}

bool TelaCreditos::Jogou()
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

int TelaCreditos::proximaTela()
{
	return 0;
}