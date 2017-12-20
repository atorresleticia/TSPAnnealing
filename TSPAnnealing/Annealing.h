#ifndef ALGORITMO_GENETICO_H
#define ALGORITMO_GENETICO_H

#pragma once
#include "Individuo.h"
#include "Populacao.h"

class annealing
{
public:
	
	annealing() = default;
	~annealing() = default;

	void mutacao(individuo a) const;
	populacao evolucao(populacao p);

private:
	float tx_mutacao_;
	float tx_cruzamento_;
	bool elitismo_;
	std::vector<individuo> rotas_;
		
};

#endif