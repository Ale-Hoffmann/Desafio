#pragma once
#include"libUnicornio.h"
class Portal
{
public:
	Portal();
	Portal(int tp);
	void inicializar();
	void executar();
	void inicializarSprite();
	void executarSprite();
	void setTipo(int tp);

	Sprite getSprite();
	int getX();
	int getY();
	int getTipo();


private:
	Sprite porta;
	int tipo,X,Y;
};

