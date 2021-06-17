#pragma once
#include"Arma.h"
#include"libUnicornio.h"
class Chapeus
{
public:
	
	 void inicializar();
	 void executar();
	 void setSprite(string n,string end);
	 void carregarSprite();
	 void atualizarSprite();
	 void setAncora(int x, int y);
	 void setArma(Arma *atual);
	
    
private:
	Arma* a;
	string nCorpo, endCorpo;
	Sprite corpo;
	int X,Y;

};

