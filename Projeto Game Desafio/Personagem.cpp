#include "Personagem.h"

Personagem::Personagem()
{
	vida = 2;
	vivo = true;
	cap = new Cartola;

}

Personagem::Personagem(int x, int y, int v, int e)
{
	xPer = x;
	yPer = y;
	vida = v;
	energia = e;
	cap = new Cartola;
}

void Personagem::inicializar()
{
	gRecursos.carregarSpriteSheet("Player", "../assets/Player1.png",6,3);
	player.setSpriteSheet("Player");
	player.setEscala(1, 1);
	player.setAnimacao(0);
	xPer = gJanela.getLargura() / 2;
	yPer = gJanela.getAltura() / 2;
	arma.inicializar();
	cap->inicializar();
}

void Personagem::executar()
{ 
	 arma.executar();
	 cap->executar();
     player.desenhar(xPer,yPer);
	 mover();
	 morrer();
	 
}



void Personagem::mover()
{
	cap->setAncora(xPer, yPer);
	if (gTeclado.segurando[TECLA_D] && xPer < gJanela.getLargura())
	{
		xPer++;
		direcao = "direita";
		player.setAnimacao(0);
		player.avancarAnimacao();
		arma.setarPosicao(xPer + 30, yPer);
		return;
	}
	if (gTeclado.segurando[TECLA_A] && xPer > 0)
	{
		xPer--;
		direcao = "esquerda";
		arma.setarPosicao(xPer - 30, yPer);
		player.setAnimacao(1);
		player.avancarAnimacao();
		return;
	}
	if (gTeclado.segurando[TECLA_W] && yPer > 0)
	{
		yPer--;
		direcao = "cima";
		arma.setarPosicao(xPer, yPer - 30); 
		player.setAnimacao(5);
		player.avancarAnimacao();
		return;
	}
	if (gTeclado.segurando[TECLA_S] && yPer < gJanela.getAltura())
	{
		yPer++;
		direcao = "baixo";
		arma.setarPosicao(xPer, yPer+30);
		player.setAnimacao(4);
		player.avancarAnimacao();
		return;
	}
}

void Personagem::atacar()
{

}

void Personagem::contato(string tp, int vl)
{
		if (tp == "cura")
		{
			vida = vida + vl;
		}
	
	
}

void Personagem::contatoInimigo(int x, int y)
{
	if (vida > 1)
	{
		vida--;
		if (x > xPer)
		{
			xPer = xPer - 20;
		}
		else
		{
			xPer = xPer + 20;
		}
		if (y > yPer)
		{
			yPer = yPer - 20;
		}
		else
		{
			yPer = yPer + 20;
		}
	}
	else
	{
		vida = 0;
	}
}

void Personagem::morrer()
{
	if (vida == 0)
	{
		vivo = false;
	}
}

int Personagem::getX()
{
	return xPer;
}

int Personagem::getY()
{
	return yPer;
}

int Personagem::getVida()
{
	return vida;
}

Sprite Personagem::getImagem()
{
	return player;
}

string Personagem::getDirecao()
{
	return direcao;
}

string Personagem::getTxtVida()
{
	string vd;
	switch(vida)
	{
	case 1:
	
		vd = " 1x";
		break;
	case 2:
	
		vd = " 2x";
		break;
	case 3:

		vd = " 3x";
		break;
	case 4:

		vd = " 4x";
		break;
	default:
		break;
	}




	return vd;
}

bool Personagem::getVivo()
{
	return vivo;
}

Arma Personagem::getArma()
{
	return arma;
}

Chapeus Personagem::getChapeu()
{
	return *cap;
}



