#include "Jogo.h"

Jogo::Jogo()
{
	//polimorfismo
	
	teste[0] = new TelaMenu;
	teste[1] = new TelaControles;
<<<<<<< HEAD
<<<<<<< HEAD
	teste[2] = new TelaCreditos;
	teste[3] = new TelaJogar;
	teste[4] = new TelaCombate(1);
	teste[5] = new TelaMorte;
=======
	teste[2] = new TelaJogar;
	teste[3] = new TelaCombate;
	teste[4] = new TelaMorte;
>>>>>>> parent of d7dc273 (chapÃ©us implementados e saves tambÃ©m)
=======
	teste[2] = new TelaJogar;
	teste[3] = new TelaCombate(1);
	teste[4] = new TelaMorte;
>>>>>>> parent of 011bbc3 (arvore implementando)
	qTelas = 5;
	telaAtual = 0;
	Voltar.impilhar(telaAtual);

}

Jogo::~Jogo()
{

}

void Jogo::inicializar()
{
	uniInicializar(1056, 695, false);
	for (int i = 0; i < qTelas; i++)
	{
		teste[i]->inicializar();
	}
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		passaTela();
		uniTerminarFrame();
	
	}
}

void Jogo::passaTela()
{
	if (teste[telaAtual]->Jogou() == true)
	{
		Voltar.impilhar(telaAtual);
		telaAtual = teste[telaAtual]->proximaTela();
	}
	if (gTeclado.pressionou[TECLA_T])
	{
		telaAtual = Voltar.desempilhar();
	}
	teste[telaAtual]->executar();
}



