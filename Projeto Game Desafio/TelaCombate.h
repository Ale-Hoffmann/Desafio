#pragma once
#include "Tela.h"
#include "Lista.h"
class TelaCombate :
    public Tela
{
public:
    TelaCombate();
    TelaCombate(int tp);
    ~TelaCombate();
    void inicializar() override;
    void executar() override;

    void carregarSprite() override;
    void carregarTexto() override;
    void carregarArquivo() override;
    bool Jogou() override;
    int proximaTela();

    void atualizarSprite() override;
    void atualizarTexto() override;
   
  
    void colis�o();
private:
<<<<<<< HEAD
<<<<<<< HEAD

    bool inimigosVivos();

    int  quantInim, quantItens, pTela, tipo,quantPortas;
=======
    int  quantInim, quantItens;
>>>>>>> parent of 011bbc3 (arvore implementando)
    Texto vida, dinheiro;
=======
    int  quantInim, quantItens;
    Texto vida;
>>>>>>> parent of d7dc273 (chapéus implementados e saves também)
    Sprite fundo,core;
    Lista<Inimigo*> spawn;
    Lista<Cura*> itens;
    Personagem principal;
    string nSprite, EndSprite, nTexto, EndTexto;
    Bicho *vagabundo;
<<<<<<< HEAD
    bool acabou;
<<<<<<< HEAD
    Lista<Portal*> portas;
=======
>>>>>>> parent of d7dc273 (chapéus implementados e saves também)
=======
>>>>>>> parent of 011bbc3 (arvore implementando)
};

