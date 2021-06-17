#include "TelaCombate.h"

TelaCombate::TelaCombate()
{
	quantInim = 3;
	spawn[0] = new Bicho;
	spawn[1] = new Bicho;
	spawn[2] = new Zumbi;
	quantItens = 1;
	itens = new Cura[quantItens];
	
	Cura a(1);
	itens[0] = a;
	itens[0].setXY(100, 100);
	spawn[0]->setPosicao(500, 500);
	spawn[1]->setPosicao(500, 200);
	spawn[2]->setPosicao(200, 100);

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
		spawn[i]->inicializar();
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
		spawn[i]->executar();
	}
	
}

void TelaCombate::carregarSprite()
{
	gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	fundo.setSpriteSheet(nSprite);
	fundo.setEscala(1, 1);
	
	if (!gRecursos.carregouSpriteSheet("CoracaoU"))
	{
		gRecursos.carregarSpriteSheet("CoracaoU", "../assets/CoracaoU.png", 1, 1);
	}
	
	core.setSpriteSheet("CoracaoU");
	core.setEscala(0.7, 0.7);
	core.setAnimacao(0);
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

int TelaCombate::proximaTela()
{
	return 3;
}



void TelaCombate::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	core.desenhar(122, 30);
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
			spawn[i]->getSprite(), spawn[i]->getX(), spawn[i]->getY(), 0))
		{
			principal.contatoInimigo(spawn[i]->getX(), spawn[i]->getY());


		}
		if (gTeclado.pressionou[TECLA_ESPACO] && uniTestarColisao(principal.getArma().getImagem(), principal.getArma().getX(), principal.getArma().getY(), 0,
			spawn[i]->getSprite(), spawn[i]->getX(), spawn[i]->getY(), 0))
		{
			spawn[i]->setPosicao(1200, 400);
		}
	}
}
