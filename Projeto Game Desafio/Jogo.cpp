#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	principal.inicializar();


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

		principal.executar();

		if (gTeclado.segurando[TECLA_D])
		{
			principal.moverDir();
		}
		if (gTeclado.segurando[TECLA_A])
		{
			principal.moverEsc();
		}
		if (gTeclado.segurando[TECLA_W])
		{
			principal.moverCima();
		}
		if (gTeclado.segurando[TECLA_S])
		{
			principal.moverBaixo();
		}
		


		uniTerminarFrame();
	}
}