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
    void colisão();

private:

    bool inimigosVivos();

    int  quantInim, quantItens, pTela, tipo,quantPortas;
    Texto vida, dinheiro;
    Sprite fundo,core;
    Lista<Inimigo*> spawn;
    Lista<Cura*> itens;
    Personagem principal;
    string nSprite, EndSprite, nTexto, EndTexto;
    Bicho *vagabundo;
    bool acabou;
    Lista<Portal*> portas;
};

