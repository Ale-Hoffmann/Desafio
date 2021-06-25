#pragma once
#include"NodoA.h"

template<class A>
class Arvore
{
public:
	Arvore();
	void Add(A a);
	bool contem(A a);
	A getExpecifico(A a);
	A getPaiExpecifico(A a);
	A getEsqExpecifico(A a);
	A getDirExpecifico(A a);
	A getRaiz();

private:
	void AlocarNodo(NodoA<A>* a, NodoA<A>* b);
	bool contem(NodoA<A>* a, A b);
	NodoA<A>* getExpecifico(A a, NodoA<A>* b);
	NodoA<A>* raiz;
	bool vazio;

};

template<class A>
inline Arvore<A>::Arvore()
{
	raiz = nullptr;
	vazio = true;
}

template<class A>
inline void Arvore<A>::Add(A a)
{
	NodoA<A>* aux;
	aux = new NodoA<A>;
	aux->AddConteudo(a);
	if (vazio == true)
	{
		raiz = aux;
		vazio = false;
		return;
	}
	else
	{
		AlocarNodo(raiz, aux);
	}
}

template<class A>
inline bool Arvore<A>::contem(A a)
{
	if (raiz->getConteudo() == a)
	{
		return true;
	}
	else
	{
		return contem(raiz, a);
	}
}

template<class A>
inline A Arvore<A>::getExpecifico(A a)
{
	if (raiz->getConteudo() == a)
	{
		return raiz->getConteudo();
	}
	else
	{
		return getExpecifico(a, raiz)->getConteudo();
	}
	
}

template<class A>
inline A Arvore<A>::getPaiExpecifico(A a)
{
	return getExpecifico(a,raiz)->getPai()->getConteudo();
}

template<class A>
inline A Arvore<A>::getEsqExpecifico(A a)
{
	return getExpecifico(a,raiz)->getEsq()->getConteudo();
}

template<class A>
inline A Arvore<A>::getDirExpecifico(A a)
{
	return getExpecifico(a,raiz)->getDir()->getConteudo();
}

template<class A>
inline A Arvore<A>::getRaiz()
{
	return raiz->getConteudo();
}



template<class A>
inline void Arvore<A>::AlocarNodo(NodoA<A>* a, NodoA<A>* b)
{
	if (a->getConteudo() > b->getConteudo())
	{
		if (a->getEsq() == nullptr)
		{

			a->AddEsq(b);
			b->AddPai(a);
		}
		else
		{
			AlocarNodo(a->getEsq(), b);
		}
	}
	else
	{
		if (a->getDir() == nullptr)
		{
			a->AddDir(b);
			b->AddPai(a);
		}
		else
		{
			AlocarNodo(a->getDir(), b);
		}
	}
}

template<class A>
inline bool Arvore<A>::contem(NodoA<A>* a, A b)
{
	if (a->getConteudo() == b)
	{
		return true;
	}

	if (b > a->getConteudo() && a->getDir() != nullptr)
	{
		return contem(a->getDir(), b);
	}

	if (b < a->getConteudo() && a->getEsq() != nullptr)
	{
		return contem(a->getEsq(), b);
	}

	return false;
}

template<class A>
inline NodoA<A>* Arvore<A>::getExpecifico(A a, NodoA<A>* b)
{
	if (b->getConteudo() == a)
	{
		return b;
	}

	if (a > b->getConteudo() && b->getDir() != nullptr)
	{
		return getExpecifico(a, b->getDir());
	}

	if (a < b->getConteudo() && b->getEsq() != nullptr)
	{
		return getExpecifico(a, b->getEsq());
	}

}
