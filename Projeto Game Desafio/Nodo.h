#pragma once
template<class T>
class Nodo
{
public:
	Nodo();
	void inserirConteudo(T cont);
	void setProximo(Nodo* p);
	void setAnterior(Nodo* a);

	Nodo<T>* getProximo();
	Nodo<T>* getAnterior();
	T getConteudo();
private:
	Nodo* proximo, * anterior;
	T conteudo;
};
template<class T>
inline Nodo<T>::Nodo()
{
	proximo = nullptr;
	anterior = nullptr;

}

template<class T>
inline void Nodo<T>::inserirConteudo(T cont)
{
	conteudo = cont;
}

template<class T>
inline void Nodo<T>::setProximo(Nodo* p)
{
	proximo = p;
}

template<class T>
inline void Nodo<T>::setAnterior(Nodo* a)
{
	anterior = a;
}

template<class T>
inline Nodo<T>* Nodo<T>::getProximo()
{
	return proximo;
}

template<class T>
inline Nodo<T>* Nodo<T>::getAnterior()
{
	return anterior;
}


template<class T>
inline T Nodo<T>::getConteudo()
{
	return conteudo;
}

