#include "Jogo.h"

Jogo::Jogo()
{
	teste = new Cura(1);
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	teste = new Cura(1);
	uniInicializar(800, 600, false);
	teste->setXY(100,100);
	principal.inicializar();
	teste->carregar();
	
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

		principal.executar();
		teste->executar();
		colis�o();


		uniTerminarFrame();
	}
}

void Jogo::colis�o()
{
	//testando colis�o com a cura
	if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
		teste->getImagem(),teste->getX(),teste->getY(),0))
	{
		 
		teste->setXY(gJanela.getLargura() / 2, gJanela.getAltura() / 2);




	}
}
