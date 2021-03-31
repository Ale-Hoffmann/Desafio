#include "Item.h"

Item::Item()
{
}

void Item::carregar()
{
	gRecursos.carregarSpriteSheet(nomeImagem, endImagem);
	imagem.setSpriteSheet(nomeImagem);
	imagem.setEscala(0.5, 0.5);
}

void Item::executar()
{
	imagem.desenhar(X, Y);
}

void Item::setPreco(int p)
{
	preco = p;
}

void Item::setValor(int v)
{
	valor = v;
}

void Item::setXY(int x,int y)
{
	X = x;
	Y = y;
}

void Item::setTag(string t)
{
	tag = t;
}

void Item::setImagem(string nome, string endereço)
{
	nomeImagem = nome;
	endImagem = endereço;
}



string Item::getTag()
{
	return tag;
}

int Item::getPreco()
{
	return preco;
}

int Item::getValor()
{
	return valor;
}
