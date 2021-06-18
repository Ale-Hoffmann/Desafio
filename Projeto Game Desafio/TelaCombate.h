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
    int  quantInim, quantItens;
    Texto vida;
    Sprite fundo,core;
    Lista<Inimigo*> spawn;
    Lista<Cura*> itens;
    Personagem principal;
    string nSprite, EndSprite, nTexto, EndTexto;
    Bicho *vagabundo;
};

