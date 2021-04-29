#include "TelaCombate.h"

TelaCombate::TelaCombate()
{
	quantInim = 2;
	
	quantItens = 1;
	itens = new Cura[quantItens];
	vagabundo = new Bicho[quantInim];
	Cura a(1);
	itens[0] = a;
	itens[0].setXY(100, 100);
	vagabundo[0].setPosicao(500, 500);
	vagabundo[1].setPosicao(500, 200);
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
	for (int i = 0; i < quantInim; i++)
	{
		vagabundo[i].inicializar();
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
	for (int i = 0; i < quantInim; i++)
	{
		vagabundo[i].executar();
	}
	
}

void TelaCombate::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1.2, 1.07);
}

void TelaCombate::carregarTexto()
{
	gRecursos.carregarFonte(nTexto, EndTexto);
	vida.setFonte(nTexto);
	vida.setAlinhamento(TEXTO_CENTRALIZADO);
	vida.setEscala(1.5, 1.5);
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

bool TelaCombate::Jogou()
{
	if (principal.getVivo() == false)
	{
		return true;
	}
    
	else
	{
		return false;
	}
}



void TelaCombate::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void TelaCombate::atualizarTexto()
{
	vida.setString(principal.getTxtVida());
	vida.desenhar(110, 30);
}


void TelaCombate::colisão()
{
	for (int i = 0; i < quantItens; i++)
	{
		if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
			itens[i].getImagem(), itens[i].getX(), itens[i].getY(), 0))
		{
			principal.contato(itens[i].getTag(), itens[i].getValor());

			itens[i].setXY(1200, 400);
		}
	}
	for (int i = 0; i < quantInim; i++)
	{
		if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
			vagabundo[i].getSprite(), vagabundo[i].getX(), vagabundo[i].getY(), 0))
		{
			principal.contatoInimigo(vagabundo[i].getX(), vagabundo[i].getY());


		}
		if (gTeclado.pressionou[TECLA_ESPACO] && uniTestarColisao(principal.getArma().getImagem(), principal.getArma().getX(), principal.getArma().getY(), 0,
			vagabundo[i].getSprite(), vagabundo[i].getX(), vagabundo[i].getY(), 0))
		{
			vagabundo[i].setPosicao(1200, 400);
		}
	}
}
