#include "Usuario.h"

void Usuario::inicializar()
{
}

void Usuario::executar()
{
}

void Usuario::setNome(string nm)
{
	nome = nm;
}

void Usuario::addValorNaCarteira(int coin)
{
	carteira = carteira + coin;
}

void Usuario::retiraDaCarteira(int coin)
{
	carteira = carteira - coin;
}

string Usuario::getNome()
{
	return nome;
}

int Usuario::getCarteira()
{
	return carteira;
}
