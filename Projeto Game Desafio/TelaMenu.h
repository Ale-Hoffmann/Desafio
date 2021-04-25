#pragma once
#include "Tela.h"
class TelaMenu :
    public Tela
{
public:
    
        void inicializar() override;
    void executar() override;
    void carregarSprite() override;
    void carregarTexto() override;
    void carregarArquivo() override;
    void carregarBotao();


    void atualizarSprite() override;
    void atualizarTexto() override;
    void atualizarBotao();
    bool Jogou() override;

 

private:
    bool jogou;
    Sprite fundo;
    Texto titulo;
    string nSprite, EndSprite, nTexto, EndTexto,nBotao,EndBotao;
    BotaoSprite jogar;
};

