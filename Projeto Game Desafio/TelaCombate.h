#pragma once
#include"Portal.h"
#include "Tela.h"
#include "Lista.h"
class TelaCombate :
    public Tela
{
public:
    TelaCombate();
    TelaCombate(int tp);
    ~TelaCombate();

    bool operator<( TelaCombate a);
    bool operator>( TelaCombate b);
    bool operator==( TelaCombate c);

  
    void inicializar() override;
    void executar() override;

    void carregarSprite() override;
    void carregarTexto() override;
    void carregarArquivo() override;
    bool Jogou() override;
    int proximaTela();
    
    void faseTerminou();

    void atualizarSprite() override;
    void atualizarTexto() override;

    bool NovoJogo();
    int qualSave();

    int getTipo();
    void colis�o();

private:
<<<<<<< HEAD

    bool inimigosVivos();

    int  quantInim, quantItens, pTela, tipo,quantPortas;
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
    Lista<Portal*> portas;
=======
>>>>>>> parent of d7dc273 (chapéus implementados e saves também)
};

