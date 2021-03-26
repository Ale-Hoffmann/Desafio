#include "Personagem.h"

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
	 player.avancarAnimacao();
}

void Personagem::moverDir()
{
	xPer++;
}

void Personagem::moverEsc()
{
	xPer--;
}

void Personagem::moverCima()
{
	yPer--;
}

void Personagem::moverBaixo()
{
	yPer++;
}
