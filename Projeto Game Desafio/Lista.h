#pragma once
#include<iostream>
#include"Nodo.h"
template<class L>
class Lista
{
public:
	Lista();
	void adicionarNoFim(L novoConvidado);
	void adicionarNoInicio(L novoConvidado);
	void removerInicio();
	void removerFinal();
	void esvaziarLista();

	L  pegarUltimo();
	L  getUltimo();
	L  getPrimeiro();
	int insereEm(int pos, int a, L per);
	int Tamanho();
	bool NaoEstaVazio();

private:
	Nodo<L>* fim, * inicio, * corredor;
	int tamanho;
};

template<class L>
inline Lista<L>::Lista()
{
	fim = nullptr;
	inicio = nullptr;
	corredor = nullptr;
	tamanho = 0;
}

template<class L>
inline void Lista<L>::adicionarNoFim(L novoConvidado)
{
	Nodo<L>* a;
	a = new Nodo<L>;
	a->inserirConteudo(novoConvidado);
	if (NaoEstaVazio() == false)
	{

		inicio = a;


	}
	else
	{
		a->setAnterior(fim);
		fim->setProximo(a);

	}
	fim = a;
	tamanho++;

}

template<class L>
inline void Lista<L>::adicionarNoInicio(L novoConvidado)
{
	Nodo<L>* a;
	a = new Nodo<L>;
	a->inserirConteudo(novoConvidado);
	if (NaoEstaVazio() == true)
	{
		a->setProximo(inicio);
		inicio->setAnterior(a);
	}
	inicio = a;

	tamanho++;
}

template<class L>
inline void Lista<L>::removerInicio()
{
	if (NaoEstaVazio() == true)
	{
		if (tamanho == 1)
		{
			delete inicio;
			inicio = nullptr;
			fim = nullptr;

		}
		else
		{
			Nodo<L>* aux;
			aux = inicio;
			inicio = inicio->getProximo();
			delete aux;


		}
		tamanho--;
	}
}

template<class L>
inline void Lista<L>::removerFinal()
{
	if (NaoEstaVazio() == true)
	{
		if (tamanho == 1)
		{
			delete inicio;
			inicio = nullptr;
			fim = nullptr;

		}
		else
		{
			Nodo<L>* aux;
			aux = fim;
			fim = fim->getAnterior();
			fim->setProximo(nullptr);
			delete aux;
		}
		tamanho--;
	}
}

template<class L>
inline void Lista<L>::esvaziarLista()
{
	if (tamanho > 0)
	{
		do
		{
			removerFinal();

		} while (tamanho > 0);
	}
	else
	{
		std::cout << "n ha nada na lista" << std::endl;
	}
}

template<class L>
inline L Lista<L>::pegarUltimo()
{
	L aux;
	aux = getUltimo();
	removerFinal();
	return aux;
}

template<class L>
inline  L  Lista<L>::getUltimo()
{
	return fim->getConteudo();
}

template<class L>
inline  L  Lista<L>::getPrimeiro()
{
	return inicio->getConteudo();
}

template<class L>
inline int Lista<L>::insereEm(int pos, int a, L per)
{
	if (pos <= tamanho)
	{
		Nodo<L>* aux;
		aux->inserirConteudo(per);
		if (a == pos)
		{
			corredor = inicio;
		}

		if (!NaoEstaVazio)
		{
			inicio = aux;
			fim = aux;
			return 1;
		}
		if (NaoEstaVazio && a == 0)
		{
			aux->setAnterior(corredor->GetAnterior());
			aux->setProximo(corredor);
			corredor->setAnterior(aux);
			corredor = aux;
			return 1;
		}
		else
		{
			corredor = corredor->getProximo();
			insereEm(pos, a--, per);
			return 1;
		}

	}
	else
	{
		return 0;
	}
}

template<class L>
inline int Lista<L>::Tamanho()
{
	return tamanho;
}

template<class L>
inline bool Lista<L>::NaoEstaVazio()
{
	return tamanho;
}