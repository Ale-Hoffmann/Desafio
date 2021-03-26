#pragma once
#include"libUnicornio.h"
class Personagem
{
public:
	void inicializar();
	void executar();
	void moverDir();
	void moverEsc();
	void moverCima();
	void moverBaixo();
private:
	Sprite player;
	int xPer, yPer;
};

