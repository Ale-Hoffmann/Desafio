#include "Tela.h"

Tela::Tela()
{
	teste = new Cura(1);
}

void Tela::inicializar()
{
	teste = new Cura(1);
	teste->setXY(100, 100);
	principal.inicializar();
	teste->carregar();
	carregarSprite();
	carregarTexto();
}

void Tela::executar()
{
	atualizarSprite();
	atualizarTexto();
	principal.executar();
	teste->executar();
	colisão();
}

void Tela::carregarSprite()
{
	gRecursos.carregarSpriteSheet("fundoTela", "../assets/mapa.jpg");
	fundo.setSpriteSheet("fundoTela");
	fundo.setEscala(1.2, 1.5);
}

void Tela::carregarTexto()
{
	gRecursos.carregarFonte("TextoVida", "../assets/pixelplay.ttf");
	TxtVida.setFonte("TextoVida");
	TxtVida.setAlinhamento(TEXTO_CENTRALIZADO);
}

void Tela::atualizarSprite()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void Tela::atualizarTexto()
{
	TxtVida.setString(principal.getTxtVida());
	TxtVida.desenhar(500, 100);
}

void Tela::colisão()
{
	//testando colisão com a cura
	if (uniTestarColisao(principal.getImagem(), principal.getX(), principal.getY(), 0,
		teste->getImagem(), teste->getX(), teste->getY(), 0))
	{
		principal.contato(teste->getTag(), teste->getValor());

		teste->setXY(400, 400);
	}
}
