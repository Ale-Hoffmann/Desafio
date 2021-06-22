#include "Save.h"

Save::Save()
{
}

Save::Save(string nm, int fa, int md, int vd, int qc)
{
	nome = nm;
	faseAtual = fa;
	moedas = md;
	vida = vd;
	quantidadeDeChapeus = qc;
}

void Save::setSave(string nm, int fa, int md, int vd, int qc)
{
	nome = nm;
	faseAtual = fa;
	moedas = md;
	vida = vd;
	quantidadeDeChapeus = qc;
}

void Save::guardarNome(string nm)
{
	nome = nm;
}

void Save::guardarFaseAtual(int fa)
{
	faseAtual = fa;
}

void Save::guardarMoedas(int md)
{
	moedas = md;
}

void Save::guardarVida(int vd)
{
	vida = vd;
}

void Save::guardarChaps(int qc)
{
	quantidadeDeChapeus = qc;
}

string Save::getNome()
{
	return nome;
}

int Save::getFase()
{
	return faseAtual;
}

int Save::getMoeda()
{
	return moedas;
}

int Save::getVida()
{
	return vida;
}

int Save::getChaps()
{
	return quantidadeDeChapeus;
}
