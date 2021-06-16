#pragma once
template<class N>
class NodoP
{
public:
	NodoP();
	void add(N cont);
	void addBaixo(NodoP<N>* baixo);
	N getConteudo();
	NodoP<N>* getBaixo();

private:
	NodoP<N>* aBaixo;
	N conteudo;
};

template<class N>
inline NodoP<N>::NodoP()
{
	aBaixo = nullptr;
}

template<class N>
inline void NodoP<N>::add(N cont)
{
	conteudo = cont;
}

template<class N>
inline void NodoP<N>::addBaixo(NodoP<N>* baixo)
{
	aBaixo = new NodoP<N>;
	aBaixo = baixo;
}

template<class N>
inline N NodoP<N>::getConteudo()
{
	return conteudo;
}

template<class N>
inline NodoP<N>* NodoP<N>::getBaixo()
{
	return aBaixo;
}

