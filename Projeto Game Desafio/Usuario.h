#pragma once
#include"libUnicornio.h"
class Usuario
{
public:
	void inicializar();
	void executar();
	void setNome(string nm);
	void addValorNaCarteira(int coin);
	void retiraDaCarteira(int coin);

	string getNome();
	int getCarteira();
	//terminar usuario


private:
	int carteira;
	string nome;
};

