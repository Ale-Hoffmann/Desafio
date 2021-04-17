#include "Tela.h"

Tela::Tela()
{
	teste = new Cura(1);
}

void Tela::inicializar()
{
	teste = new Cura(1);
	teste->setXY(100, 100);
	carregarArquivo();
	principal.inicializar();
	teste->carregar();
	carregarSprite();
	carregarTexto();
}

void Tela::executar()
{
	atualizarSprite();
	atualizarTexto();
	principal.executar();
	teste->executar();
	colisão();
}

void Tela::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite,EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1.2, 1.5);
}

void Tela::carregarTexto()
{
	gRecursos.carregarFonte(nTexto, EndTexto);
	TxtVida.setFonte(nTexto);
	TxtVida.setAlinhamento(TEXTO_CENTRALIZADO);
}

void Tela::carregarArquivo()
{
	string dado;

		ifstream lerArq;
		lerArq.open("arqTela.txt", ios::in);
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
				if (dado == "sprite")
				{
					lerArq >> dado;
					nSprite = dado;
					lerArq >> dado;
					EndSprite = dado;
				}
			} while (!lerArq.eof());

		}
	
}

void Tela::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void Tela::atualizarTexto()
{
	TxtVida.setString(principal.getTxtVida());
	TxtVida.desenhar(500, 100);
}

void Tela::colisão()
{
	//testando colisão com a cura
	if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
		teste->getImagem(), teste->getX(), teste->getY(), 0))
	{
		principal.contato(teste->getTag(), teste->getValor());

		teste->setXY(400, 400);
	}
}
