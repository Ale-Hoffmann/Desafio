#pragma once
template<class A>
class NodoA
{
public:
	NodoA<A>();
	void AddConteudo(A c);
	void AddEsq(NodoA<A>* e);
	void AddDir(NodoA<A>* d);
	void AddPai(NodoA<A>* p);

	A getConteudo();
	NodoA<A>* getEsq();
	NodoA<A>* getDir();
	NodoA<A>* getPai();
private:
	NodoA<A>* esq, * dir, * pai;
	A raiz;
};

template<class A>
inline NodoA<A>::NodoA()
{
	esq = nullptr;
	dir = nullptr;
	pai = nullptr;
}

template<class A>
inline void NodoA<A>::AddConteudo(A c)
{
	raiz = c;
}

template<class A>
inline void NodoA<A>::AddEsq(NodoA<A>* e)
{
	esq = new NodoA<A>;
	esq = e;
}

template<class A>
inline void NodoA<A>::AddDir(NodoA<A>* d)
{
	dir = new NodoA<A>;
	dir = d;
}

template<class A>
inline void NodoA<A>::AddPai(NodoA<A>* p)
{
	pai = new NodoA<A>;
	pai = p;
}

template<class A>
inline A NodoA<A>::getConteudo()
{
	return raiz;
}

template<class A>
inline NodoA<A>* NodoA<A>::getEsq()
{
	return esq;
}

template<class A>
inline NodoA<A>* NodoA<A>::getDir()
{
	return dir;
}

template<class A>
inline NodoA<A>* NodoA<A>::getPai()
{
	return pai;
}
