#pragma once
#include"Inimigo.h"
class Zumbi : public Inimigo
{
public:
    Zumbi();
    void morrer();
    bool getVivo();
private:
    int vida;
};

