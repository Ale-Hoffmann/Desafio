#include "GerenciadorDeArquivo.h"

void GerenciadorDeArquivo::criarArquivoSave(string a, int tp)
{
	gerenciador = new Save;
	gerenciador->setSave(a, 0, 0, 3, 0);
	saveAtual = tp;

	string nmArq;
	switch (saveAtual)
	{
	case 1:
		nmArq = "primArq.txt";
	break;
	case 2:
		nmArq = "segArq.txt";
	break;

	case 3:
		nmArq = "tercArq.txt";
	break;
	
	default:
		break;
	}
	ofstream primeiro_arquivo(nmArq, ios::out);

	if (!primeiro_arquivo)
	{
		cout << "Nao deu nao" << endl;
	}
	else
	{
		primeiro_arquivo << gerenciador->getNome();
		primeiro_arquivo << gerenciador->getFase();
		primeiro_arquivo << gerenciador->getMoeda();
		primeiro_arquivo << gerenciador->getVida();
		primeiro_arquivo << gerenciador->getChaps();
	}
	primeiro_arquivo.close();
}

void GerenciadorDeArquivo::setSaveAtual(int at)
{
	saveAtual = at;
}

void GerenciadorDeArquivo::escreverNoSave(int tp, string nmUsuario, int nFase, int moedas, int vida, int quantChap)
{
	gerenciador->setSave(nmUsuario, nFase, moedas, vida, quantChap);
	string nmArq;
	switch (saveAtual)
	{
	case 1:
		nmArq = "primArq.txt";
		break;
	case 2:
		nmArq = "segArq.txt";
		break;

	case 3:
		nmArq = "tercArq.txt";
		break;

	default:
		break;
	}

	ofstream primeiro_arquivo(nmArq, ios::out);

	if (!primeiro_arquivo)
	{
		cout << "Nao deu nao" << endl;
	}
	else
	{
		primeiro_arquivo << gerenciador->getNome();
		primeiro_arquivo << gerenciador->getFase();
		primeiro_arquivo << gerenciador->getMoeda();
		primeiro_arquivo << gerenciador->getVida();
		primeiro_arquivo << gerenciador->getChaps();
	}
	primeiro_arquivo.close();

}

void GerenciadorDeArquivo::excluirSave(int tp)
{

}

void GerenciadorDeArquivo::lerSave(int tp)
{
	ifstream pri_arq_leitura;
	string nmArq;
	switch (tp)
	{
	case 1:
		nmArq = "primArq.txt";
		break;
	case 2:
		nmArq = "segArq.txt";
		break;

	case 3:
		nmArq = "tercArq.txt";
		break;

	default:
		break;
	}


	pri_arq_leitura.open(nmArq, ios::in);

	string nome_lido;
	int dado_lido;
	if (!pri_arq_leitura.is_open())
	{
		cout << "leitura n deu" << endl;
	}
	else
	{
		pri_arq_leitura >> nome_lido;
		gerenciador->guardarNome(nome_lido);
		pri_arq_leitura >> dado_lido;
		gerenciador->guardarFaseAtual(dado_lido);
		pri_arq_leitura >> dado_lido;
		gerenciador->guardarMoedas(dado_lido);
		pri_arq_leitura >> dado_lido;
		gerenciador->guardarVida(dado_lido);
		pri_arq_leitura >> dado_lido;
		gerenciador->guardarChaps(dado_lido);
	}
	pri_arq_leitura.close();

}

Save* GerenciadorDeArquivo::getSave()
{
	return gerenciador;
}
