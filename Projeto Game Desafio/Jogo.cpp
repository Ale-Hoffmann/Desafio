#include "Jogo.h"

Jogo::Jogo()
{
	//polimorfismo
	
	teste[0] = new TelaMenu;
	teste[1] = new TelaControles;
	teste[2] = new TelaJogar;
	teste[3] = new TelaCombate;
	teste[4] = new TelaMorte;


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
	//	O resto da finaliza��o vem aqui (provavelmente, em ordem inversa a inicializa��o)!
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



