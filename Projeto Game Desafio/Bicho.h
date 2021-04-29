#pragma once
#include "Inimigo.h"
class Bicho :
    public Inimigo
   
{
public:
    Bicho();
    void morrer();
    bool getVivo();

private:
    int vid;
};

