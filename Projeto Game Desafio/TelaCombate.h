#pragma once
#include "Tela.h"
class TelaCombate :
    public Tela
{
public:
    TelaCombate();
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
   
  
    void colisão();
private:
    int  quantInim, quantItens;
    Texto vida;
    Sprite fundo;
    Inimigo* spawn;
    Cura* itens;
    Personagem principal;
    string nSprite, EndSprite, nTexto, EndTexto;
    Bicho *vagabundo;
};

