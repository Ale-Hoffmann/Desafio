#include "TelaCombate.h"

TelaCombate::TelaCombate()
{
	quantInim = 2;
	spawn = new Inimigo[quantInim];
	quantItens = 1;
	itens = new Cura[quantItens];
	Cura a(1);
	itens[0] = a;
	itens[0].setXY(100, 100);
}

TelaCombate::~TelaCombate()
{
}

void TelaCombate::inicializar()
{
	
	carregarArquivo();
	principal.inicializar();

	for (int i = 0; i < quantItens; i++)
	{
		itens[i].carregar();
	}
	carregarSprite();
	carregarTexto();
}

void TelaCombate::executar()
{
	atualizarSprite();
	atualizarTexto();
	principal.executar();
	colisão();
	for (int i = 0; i < quantItens; i++)
	{
		itens[i].executar();
	}
	
}

void TelaCombate::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1.2, 1.5);
}

void TelaCombate::carregarTexto()
{
	gRecursos.carregarFonte(nTexto, EndTexto);
	vida.setFonte(nTexto);
	vida.setAlinhamento(TEXTO_CENTRALIZADO);
}

void TelaCombate::carregarArquivo()
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
			} while (dado!="fim");

		}

	

}

void TelaCombate::atualizarValorVida(int a)
{
}

void TelaCombate::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void TelaCombate::atualizarTexto()
{
	vida.setString(principal.getTxtVida());
	vida.desenhar(500, 100);
	

	
    
}

bool TelaCombate::Jogou()
{
	return false;
}

void TelaCombate::colisão()
{
	for (int i = 0; i < quantItens; i++)
	{
		if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
			itens[i].getImagem(), itens[i].getX(), itens[i].getY(), 0))
		{
			principal.contato(itens[i].getTag(), itens[i].getValor());

			itens[i].setXY(400, 400);
		}
	}
	for (int i = 0; i < quantInim; i++)
	{

	}
}
