#pragma once
#include"NodoP.h"
template<class P>
class Pilha
{
public:
	Pilha();
	void impilhar(P c);
	P desempilhar();

	P getTopo();
	P getBase();
	int getTamanho();

private:
	NodoP<P>* topo, * base;
	int tamanho;
};

template<class P>
inline Pilha<P>::Pilha()
{
	tamanho = 0;
	topo = nullptr;
	base = nullptr;
}

template<class P>
inline void Pilha<P>::impilhar(P c)
{
	NodoP<P>* aux;
	aux = new NodoP<P>;
	aux->add(c);
	if (tamanho == 0)
	{
		topo = aux;
		base = aux;
	}
	else
	{
		aux->addBaixo(topo);
		topo = aux;
	}
	tamanho++;
}

template<class P>
inline P Pilha<P>::desempilhar()
{
	P aux;
	if (tamanho == 0)
	{
		return 0;
	}
	else if (tamanho == 1)
	{
		aux = topo->getConteudo();
		topo = nullptr;
		base = nullptr;

	}
	else
	{
		aux = topo->getConteudo();
		topo = topo->getBaixo();
	}
	tamanho--;
	return aux;
}

template<class P>
inline P Pilha<P>::getTopo()
{
	return topo->getConteudo();
}

template<class P>
inline P Pilha<P>::getBase()
{
	return base->getConteudo();
}

template<class P>
inline int Pilha<P>::getTamanho()
{
	return tamanho;
}
