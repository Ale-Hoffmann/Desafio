#pragma once
#include "libUnicornio.h"
class Save
{
public:
	Save();
	Save(string nm,int fa,int md,int vd,int qc);

	void setSave(string nm, int fa, int md, int vd, int qc);
	void guardarNome(string nm);
	void guardarFaseAtual(int fa);
	void guardarMoedas(int md);
	void guardarVida(int vd);
	void guardarChaps(int qc);

	string getNome();
	int getFase();
	int getMoeda();
	int getVida();
	int getChaps();
private:
	string nome;
	int faseAtual, moedas, vida, quantidadeDeChapeus;
};

