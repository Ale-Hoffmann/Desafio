#include "Inimigo.h"

void Inimigo::inicializar()
{
	tag = "inimigo";
	Mdistancia = 150;
	distancia = 0;
    ir = false;
	carregarSprite();
}

void Inimigo::executar()
{
	executarSprite();
	andar();
}

void Inimigo::andar()
{
	switch (tipo)
	{
	case 1:
		 
		if (distancia==0)
		{
			ir = true;
		}
		if (distancia == Mdistancia)
		{
			ir=false;
		}

		if (ir)
		{

			distancia++;
			X++;
		}
		else
		{
			distancia--;
			X--;
		}


		break;

	case 2:

		if (distancia == 0)
		{
			
			ir = true;
		}
		if (distancia == Mdistancia)
		{
			
			ir = false;
		}

		if (ir)
		{
			
			distancia++;
			Y++;
		}
		else
		{
			
			distancia--;
			Y--;
		}


		break;

	default:
		break;
	}
}

void Inimigo::setSprite(string a, string b)
{
	nCorpo = a;
	EndCorpo = b;
}

void Inimigo::carregarSprite()
{
	if (!gRecursos.carregouSpriteSheet(nCorpo))
	{ gRecursos.carregarSpriteSheet(nCorpo, EndCorpo, 1, 2); }

		corpo.setSpriteSheet(nCorpo);
		corpo.setEscala(0.4, 0.4);
		corpo.setAnimacao(0);
	
}

void Inimigo::executarSprite()
{
	corpo.desenhar(X, Y);
	corpo.avancarAnimacao();
}

void Inimigo::setPosicao(int x, int y)
{
	X = x;
	Y = y;
}

void Inimigo::setTarget(int x, int y)
{
	Xtarget = x;
	Ytarget = y;
}

void Inimigo::setTipo(int t)
{
	tipo = t;
}

void Inimigo::setDano(int d)
{
	dano = d;
}

int Inimigo::getDano()
{
	return dano;
}

int Inimigo::getX()
{
	return X;
}

int Inimigo::getY()
{
	return Y;
}

Sprite Inimigo::getSprite()
{
	return corpo;
}

string Inimigo::getTag()
{
	return tag;
}
