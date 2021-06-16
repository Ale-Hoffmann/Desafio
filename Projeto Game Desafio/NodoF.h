#pragma once
template<class F>
class NodoF
{
public:
	NodoF();
	void addConteudo(F cont);
	void setAnterior(NodoF<F>* a);

	F getConteudo();
	NodoF<F>* getAnterior();

private:
	F conteudo;
	NodoF<F>* anterior;
};


template<class F>
inline NodoF<F>::NodoF()
{
	anterior = nullptr;
}

template<class F>
inline void NodoF<F>::addConteudo(F cont)
{
	conteudo = cont;
}

template<class F>
inline void NodoF<F>::setAnterior(NodoF<F>* a)
{
	anterior = new NodoF<F>;
	anterior = a;
}

template<class F>
inline F NodoF<F>::getConteudo()
{
	return conteudo;
}

template<class F>
inline NodoF<F>* NodoF<F>::getAnterior()
{
	return anterior;
}
