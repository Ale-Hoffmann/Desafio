#include "Item.h"

Item::Item()
{
}

void Item::carregar()
{
	gRecursos.carregarSpriteSheet(nomeImagem, endImagem,1,1);
	imagem.setSpriteSheet(nomeImagem);
	imagem.setEscala(0.5,0.5);
	imagem.setAnimacao(0);
}

void Item::executar()
{
	imagem.desenhar(X, Y);
	imagem.avancarAnimacao();
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

int Item::getX()
{
	return X;
}

int Item::getY()
{
	return Y;
}

Sprite Item::getImagem()
{
	return imagem;
}
