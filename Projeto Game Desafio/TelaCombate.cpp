#include "TelaCombate.h"

TelaCombate::TelaCombate()
{
	quantInim = 3;

	spawn.adicionarNoInicio(new Bicho);
	spawn.adicionarNoInicio(new Bicho);
	spawn.adicionarNoInicio(new Zumbi);
	
	spawn.getEspecifico(0)->setPosicao(500, 500);
	spawn.getEspecifico(1)->setPosicao(500, 200);
	spawn.getEspecifico(2)->setPosicao(500, 100);

	
	quantItens = 1;

	itens.adicionarNoInicio(new Cura(1));

	itens.getEspecifico(0)->setXY(100, 100);
	

}

TelaCombate::TelaCombate(int tp)
{
	switch (tp)
	{
	case 1:
		quantInim = 1;
		spawn.adicionarNoInicio(new Zumbi);
		spawn.getEspecifico(0)->setPosicao(500, 500);

		quantItens = 1;
		itens.adicionarNoInicio(new Cura(1));
		itens.getEspecifico(0)->setXY(100, 100);

		break;
	case 2:
		quantInim = 2;
		spawn.adicionarNoInicio(new Bicho);
		spawn.adicionarNoInicio(new Zumbi);

		spawn.getEspecifico(0)->setPosicao(500, 500);
		spawn.getEspecifico(1)->setPosicao(500, 200);

		quantItens = 1;
		itens.adicionarNoInicio(new Cura(1));
		itens.getEspecifico(0)->setXY(100, 100);

		break;
	case 3:
		quantInim = 3;

		spawn.adicionarNoInicio(new Bicho);
		spawn.adicionarNoInicio(new Bicho);
		spawn.adicionarNoInicio(new Zumbi);

		spawn.getEspecifico(0)->setPosicao(500, 500);
		spawn.getEspecifico(1)->setPosicao(500, 200);
		spawn.getEspecifico(2)->setPosicao(500, 100);


		quantItens = 1;

		itens.adicionarNoInicio(new Cura(1));

		itens.getEspecifico(0)->setXY(100, 100);


		break;
	case 4:

		break;


	default:
		break;
	}











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
		itens.getEspecifico(i)->carregar();
	}
	for (int i = 0; i < quantInim; i++)
	{
		spawn.getEspecifico(i)->inicializar();
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
		itens.getEspecifico(i)->executar();
	}
	for (int i = 0; i < quantInim; i++)
	{
		spawn.getEspecifico(i)->executar();
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
	dinheiro.setFonte(nTexto);
	dinheiro.setAlinhamento(TEXTO_CENTRALIZADO);
	dinheiro.setEscala(1.5, 1.5);
	dinheiro.setCor(0, 0, 0);
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
	dinheiro.setString("dinheiro: 0");
	dinheiro.desenhar(500, 30);
	vida.setString(principal.getTxtVida());
	vida.desenhar(110, 30);
}


void TelaCombate::colisão()
{
	for (int i = 0; i < quantItens; i++)
	{
		if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
			itens.getEspecifico(i)->getImagem(), itens.getEspecifico(i)->getX(), itens.getEspecifico(i)->getY(), 0))
		{
			principal.contato(itens.getEspecifico(i)->getTag(), itens.getEspecifico(i)->getValor());

			itens.getEspecifico(i)->setXY(1200, 400);
		}
	}
	for (int i = 0; i < quantInim; i++)
	{
		if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
			spawn.getEspecifico(i)->getSprite(), spawn.getEspecifico(i)->getX(), spawn.getEspecifico(i)->getY(), 0))
		{
			principal.contatoInimigo(spawn.getEspecifico(i)->getX(), spawn.getEspecifico(i)->getY());


		}
		if (gTeclado.pressionou[TECLA_ESPACO] && uniTestarColisao(principal.getArma().getImagem(), principal.getArma().getX(), principal.getArma().getY(), 0,
			spawn.getEspecifico(i)->getSprite(), spawn.getEspecifico(i)->getX(), spawn.getEspecifico(i)->getY(), 0))
		{
			spawn.getEspecifico(i)->setPosicao(1200, 400);
		}
	}
}
