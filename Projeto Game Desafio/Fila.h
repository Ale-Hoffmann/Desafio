#pragma once
#include"NodoF.h"
template<class A>
class Fila
{
public:
	Fila();
	void addNaFila(A cont);
	A tiraDaFila();
	A getFim();
	A getInicio();
	int getTamanho();

private:
	int tamanho;
	NodoF<A>* fim, * inicio;
};

template<class A>
inline Fila<A>::Fila()
{
	tamanho = 0;
	fim = nullptr;
	inicio = nullptr;
}

template<class A>
inline void Fila<A>::addNaFila(A cont)
{
	NodoF<A>* aux;
	aux = new Nodo<A>;
	aux->addConteudo(cont);

	if (tamanho == 0)
	{
		inicio = aux;
		fim = aux;
	}
	else
	{
		fim->setAnterior(aux);
		fim = aux;
	}
	tamanho++;
}

template<class A>
inline A Fila<A>::tiraDaFila()
{
	A aux;
	if (tamanho == 0)
	{
		return 0;
	}
	else if (tamanho == 1)
	{
		aux = inicio->getConteudo();
		inicio = nullptr;
		fim = nullptr;
	}
	else
	{
		aux = inicio->getConteudo();
		inicio = inicio->getAnterior();
	}
	tamanho--;
	return aux;
}

template<class A>
inline A Fila<A>::getFim()
{
	return fim->getConteudo();
}

template<class A>
inline A Fila<A>::getInicio()
{
	return inicio->getConteudo();
}

template<class A>
inline int Fila<A>::getTamanho()
{
	return tamanho;
}
