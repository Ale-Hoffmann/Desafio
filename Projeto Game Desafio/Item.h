#pragma once
#include"libUnicornio.h"
class Item
{
public:
	Item();
	void setPreco(int p);
	void setValor(int v);
	void setTag(string t);
	
	
	string getTag();
	int getPreco();
	int getValor();



private:
	int preco, valor;
	string tag;
	Sprite imagem;
};

