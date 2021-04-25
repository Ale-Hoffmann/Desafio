#include "Jogo.h"

Jogo::Jogo()
{
	teste[0] = new TelaMenu;
	teste[1] = new TelaCombate;
	qTelas = 2;
	telaAtual = 0;
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
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
		telaAtual++;
	}
	if (gTeclado.pressionou[TECLA_T]&& telaAtual<qTelas)
	{
		telaAtual++;
	}
	if (gTeclado.pressionou[TECLA_T] && telaAtual == qTelas)
	{
		telaAtual = 0;
	}
	teste[telaAtual]->executar();
}

