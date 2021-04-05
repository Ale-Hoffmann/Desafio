#pragma once
#include"libUnicornio.h"
class Item
{
public:
	Item();
	void carregar();
	void executar();
	void setPreco(int p);
	void setValor(int v);
	void setXY(int x,int y);
	void setTag(string t);
	void setImagem(string nome, string endereço);

	
	string getTag();
	int getPreco();
	int getValor();
	int getX();
	int getY();
	Sprite getImagem();


private:
	int preco, valor,X,Y;
	string tag,endImagem,nomeImagem;
	Sprite imagem;
};

