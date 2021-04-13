#include "Personagem.h"

Personagem::Personagem()
{
	vida = 3;
}

Personagem::Personagem(int x, int y, int v, int e)
{
	xPer = x;
	yPer = y;
	vida = v;
	energia = e;
}

void Personagem::inicializar()
{
	gRecursos.carregarSpriteSheet("Player", "../assets/Player.png",1,2);
	player.setSpriteSheet("Player");
	player.setEscala(1, 1);
	player.setAnimacao(0);
	xPer = gJanela.getLargura() / 2;
	yPer = gJanela.getAltura() / 2;
}

void Personagem::executar()
{
     player.desenhar(xPer,yPer);
	 mover();
}



void Personagem::mover()
{
	if (gTeclado.segurando[TECLA_D])
	{
		xPer++;
		direcao = "direita";
		player.avancarAnimacao();
		return;
	}
	if (gTeclado.segurando[TECLA_A])
	{
		xPer--;
		direcao = "esquerda";
		player.avancarAnimacao();
		return;
	}
	if (gTeclado.segurando[TECLA_W])
	{
		yPer--;
		direcao = "cima";
		player.avancarAnimacao();
		return;
	}
	if (gTeclado.segurando[TECLA_S])
	{
		yPer++;
		direcao = "baixo";
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
			vida += vl;
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
	
		vd = "um";
		break;
	case 2:
	
		vd = "dois";
		break;
	case 3:

		vd = "tres";
		break;
	case 4:

		vd = "quatro";
		break;
	default:
		break;
	}




	return vd;
}
