#include "TelaControles.h"
void TelaControles::inicializar()
{
	carregarArquivo();
	carregarSprite();
	//carregarTexto();
	carregarBotao();
}

void TelaControles::executar()
{
	atualizarSprite();
	//atualizarTexto();
	atualizarBotao();
}

void TelaControles::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1, 1);
}

void TelaControles::carregarTexto()
{
	
}

void TelaControles::carregarArquivo()
{
	string dado;

	ifstream lerArq;
	lerArq.open("arqTelaControle.txt", ios::in);
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

void TelaControles::carregarBotao()
{
	gRecursos.carregarSpriteSheet(nBotao, EndBotao);
	menu.setSpriteSheet(nBotao);
	menu.setPos(gJanela.getLargura()/2, 550);
}

void TelaControles::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void TelaControles::atualizarTexto()
{
	
}

void TelaControles::atualizarBotao()
{
	menu.atualizar();
	menu.desenhar();
}

bool TelaControles::Jogou()
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

int TelaControles::proximaTela()
{
	return 0;
}
