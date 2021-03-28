#include "Item.h"

Item::Item()
{
}

void Item::setPreco(int p)
{
	preco = p;
}

void Item::setValor(int v)
{
	valor = v;
}

void Item::setTag(string t)
{
	tag = t;
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
