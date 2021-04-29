#pragma once
#include"libUnicornio.h"
class Inimigo
{
public:
	void inicializar();
	void executar();

	void andar();

	void setSprite(string a, string b);

	void carregarSprite();
	void executarSprite();

	void setPosicao(int x, int y);
	void setTarget(int x, int y);
	void setTipo(int t);
	void setDano(int d);

	int getDano();
	int getX();
	int getY();
	Sprite getSprite();

	string getTag();

private:
	Sprite corpo;
	int vida, X, Y, Xtarget, Ytarget, Mdistancia, distancia, tipo ,dano;
	string tag, nCorpo, EndCorpo;
	bool ir;
};

