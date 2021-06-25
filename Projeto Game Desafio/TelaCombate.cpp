#include "TelaCombate.h"

TelaCombate::TelaCombate()
{
	acabou = false;
	quantPortas = 2;
	portas.adicionarNoInicio(new Portal(1));
	portas.adicionarNoInicio(new Portal(2));
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
	tipo = tp;
	switch (tipo)
	{
	case 10:
		acabou = false;
		quantPortas = 2;
		portas.adicionarNoInicio(new Portal(1));
		portas.adicionarNoInicio(new Portal(2));

		quantInim = 1;
		spawn.adicionarNoInicio(new Zumbi);
		spawn.getEspecifico(0)->setPosicao(500, 500);

		quantItens = 1;
		itens.adicionarNoInicio(new Cura(1));
		itens.getEspecifico(0)->setXY(100, 100);

		break;
	case 15:
		acabou = false;
		quantPortas = 2;
		portas.adicionarNoInicio(new Portal(1));
		portas.adicionarNoInicio(new Portal(2));

		quantInim = 2;
		spawn.adicionarNoInicio(new Bicho);
		spawn.adicionarNoInicio(new Zumbi);

		spawn.getEspecifico(0)->setPosicao(500, 500);
		spawn.getEspecifico(1)->setPosicao(500, 200);

		quantItens = 1;
		itens.adicionarNoInicio(new Cura(1));
		itens.getEspecifico(0)->setXY(100, 100);

		break;
	case 20:
		acabou = false;
		

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
	case 5:

		break;


	default:
		break;
	}



}

TelaCombate::~TelaCombate()
{
}

bool TelaCombate::operator<(TelaCombate a)
{
	return this->tipo < a.getTipo();
}

bool TelaCombate::operator>(TelaCombate b)
{
	return this->tipo > b.getTipo();
}

bool TelaCombate::operator==( TelaCombate c)
{
	return this->tipo == c.getTipo();
}



void TelaCombate::inicializar()
{
	
	carregarArquivo();
	principal.inicializar();
	for (int p = 0; p < quantPortas; p++)
	{
		portas.getEspecifico(p)->inicializar();
	}

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
	faseTerminou();
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
	if (!gRecursos.carregouSpriteSheet("nSprite"))
	{
		gRecursos.carregarSpriteSheet(nSprite, EndSprite);
	}
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

	if (!gRecursos.carregouFonte(nTexto))
	{
      gRecursos.carregarFonte(nTexto, EndTexto);
	}
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
		pTela = 4;
		return true;
	}
	if (acabou == true)
	{
		acabou = false;
		return true;
	}
	else
	{
		return false;
	}
}

int TelaCombate::proximaTela()
{
	return pTela;
}

void TelaCombate::faseTerminou()
{
	if (inimigosVivos()==false)
	{
		for (int p = 0; p < quantPortas; p++)
		{
			portas.getEspecifico(p)->executar();
		}
	}
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

bool TelaCombate::NovoJogo()
{
	return false;
}

int TelaCombate::qualSave()
{
	return 0;
}


int TelaCombate::getTipo()
{
	return tipo;
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
 			spawn.getEspecifico(i)->tomarDano(principal.getArma().getDano());
			if (spawn.getEspecifico(i)->vivo() == false)
			{
				spawn.getEspecifico(i)->setPosicao(1200, 400);
			}
		}

	}
    for (int p = 0; p < quantPortas; p++)
	{
		if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
			portas.getEspecifico(p)->getSprite(), portas.getEspecifico(p)->getX(), portas.getEspecifico(p)->getY(), 0) && inimigosVivos()==false)
		{
			if (portas.getEspecifico(p)->getTipo() == 1)
			{
				acabou = true;
				pTela = 10;
			}
			if (portas.getEspecifico(p)->getTipo() == 2)
			{
				acabou = true;
				pTela = 5;
			}
		}

	}
}

bool TelaCombate::inimigosVivos()
{
	bool aux;
	for (int i = 0; i < quantInim; i++)
	{
		if(spawn.getEspecifico(i)->vivo()==true)
		{
			return true;
		}
	}
	return false;
}
