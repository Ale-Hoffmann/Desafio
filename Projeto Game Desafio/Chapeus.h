#pragma once
#include"Bala.h"
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
	 void setBala(int tp);
	 void tiro();
	 void atirar();

	 Bala getBala();
	
    
private:
	Bala *a;
	string nCorpo, endCorpo;
	Sprite corpo;
	int X,Y;
	bool atirando;

};

