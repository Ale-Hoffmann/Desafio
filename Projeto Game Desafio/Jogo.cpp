#include "Jogo.h"

Jogo::Jogo()
{
	//polimorfismo
	aux = nullptr;
	teste[0] = new TelaMenu;
	teste[1] = new TelaControles;
<<<<<<< HEAD
	teste[2] = new TelaCreditos;
	teste[3] = new TelaJogar;
	teste[4] = new TelaCombate(1);
	teste[5] = new TelaMorte;
=======
	teste[2] = new TelaJogar;
	teste[3] = new TelaCombate;
	teste[4] = new TelaMorte;
>>>>>>> parent of d7dc273 (chap√©us implementados e saves tamb√©m)
	qTelas = 5;

	telaAtual = 0;
	Voltar.impilhar(telaAtual);
	telaCombateAtual = 10;
	aux = new TelaCombate(15);
	combates.Add(*aux);
	aux = new TelaCombate(10);
	combates.Add(*aux);
	aux = new TelaCombate(20);
	combates.Add(*aux);
	*aux = combates.getRaiz();
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
	aux->inicializar();
	combates.getDirExpecifico(*aux).inicializar();
	//combates.getDirExpecifico(combates.getDirExpecifico(aux))->inicializar();
	combates.getEsqExpecifico(*aux).inicializar();
}

void Jogo::finalizar()
{
	//	O resto da finalizaÁ„o vem aqui (provavelmente, em ordem inversa a inicializaÁ„o)!
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
	if (teste[telaAtual]->Jogou() == true && telaAtual != 4)
	{
		Voltar.impilhar(telaAtual);
		telaAtual = teste[telaAtual]->proximaTela();
	}
	if (gTeclado.pressionou[TECLA_T]&& telaAtual != 4)
	{
		telaAtual = Voltar.desempilhar();
	}
	if (telaAtual == 4)
	{
		if (combates.getExpecifico(*aux).Jogou() == true && combates.getExpecifico(*aux).proximaTela() != 5)
		{
			//ger.escreverNoSave(play.getNome(), aux->getTipo(), play.getCarteira(), 3, 0);
			if (aux->proximaTela() == 5)
			{
				*aux = combates.getEsqExpecifico(*aux);
			}
			if (aux->proximaTela() == 10)
			{
				*aux = combates.getDirExpecifico(*aux);
			}
		}
		if (aux->proximaTela() == 5)
		{
			telaAtual = 5;
		}
		if (aux->proximaTela() != 5)
		{
			aux->executar();
		}
	}
	if (telaAtual != 4)
	{
		teste[telaAtual]->executar();
	}
}



