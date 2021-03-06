// TSPGenetico.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include "Populacao.h"
#include "Annealing.h"

using namespace std;

int main()
{
	float tamanho_populacao;
	int numero_cidades;
	float ls = 600;
	float li = 25;
	float const_r = 0.9;

	cout << "Parametros: tamanho_populacao numero_cidades" << endl;
	cin >> tamanho_populacao >> numero_cidades;

	cout << "PARAMETROS: " << endl;
	cout << "Temperatura incial: " << ls << endl;
	cout << "Temperatura final: " << li << endl;
	cout << "Constante de resfriamento: " << const_r << endl;
	cout << "Tamanho populacao: " << tamanho_populacao << endl;
	cout << "Numero de cidades por rota: " << numero_cidades << endl;

	populacao pop = populacao(tamanho_populacao, numero_cidades);
	double distancia_inicial = pop.get_melhor().distancia();

	cout << "\nPRE ANNEALING: " << endl;
	cout << "Tamanho populacao: " << pop.get_tamanho_populacao() << endl;
	cout << "Numero cidades: " << numero_cidades << endl;
	cout << "Distancia inicial: " << distancia_inicial << endl;

	annealing gen = annealing();

	const auto init = chrono::high_resolution_clock::now();

	pop = gen.evolucao(pop);

	const auto end = chrono::high_resolution_clock::now();

	const double melhoria = distancia_inicial - pop.get_melhor().distancia();

	cout << "RESULTADOS: " << endl;
	cout << "Menor distancia encontrada: " << pop.get_melhor().distancia() << endl;
	cout << "Melhoria de distancia: " << melhoria << endl;
	cout << "Qualidade da Solucao: " << melhoria / distancia_inicial * 100.0 << "% melhor que a distancia inicial" << endl;
	cout << "Duracao: " << chrono::duration_cast<chrono::duration<double>>(end - init).count() << "s" << endl;
	cout << endl;
}

