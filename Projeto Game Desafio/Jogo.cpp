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
		telaAtual = teste[telaAtual]->proximaTela();
		Voltar.impilhar(telaAtual);
	}
	if (gTeclado.pressionou[TECLA_T])
	{
		telaAtual = Voltar.desempilhar();
	}
	/*if (teste[telaAtual]->Jogou() == true && telaAtual == qTelas-1)
	{
		finalizar();
		
	}*/
	/*if (gTeclado.pressionou[TECLA_T]&& telaAtual<qTelas-1)
	{
		telaAtual++;
	}
	if (gTeclado.pressionou[TECLA_T] && telaAtual == qTelas-1)
	{
		telaAtual = 0;
	}*/
	teste[telaAtual]->executar();
}



